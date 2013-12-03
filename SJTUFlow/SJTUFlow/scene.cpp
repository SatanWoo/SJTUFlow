#include "scene.h"

#ifdef Q_OS_MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <QMouseEvent>
#include <time.h>

#include "objloader.h"

using namespace qglviewer;

GLUquadric *Scene::quadric = gluNewQuadric();

Scene::Scene( QWidget *parent ) : QGLViewer(parent)
{
	srand(time(NULL));

	dx = 0.01;

	setAnimate(false);

	clear(SCENE_2D);
}

SceneUnit::Primitive *Scene::getPrimitive( int id )
{
	int i = getPrimitiveIndex(id);
	if (i < 0)
	{
		return NULL;
	}
    return primitives.at(i);
}

bool Scene::importObject(QString filename)
{
	SceneUnit::Primitive *p = new SceneUnit::Object;
	SceneUnit::Object *o = (SceneUnit::Object *)p;
	if (ObjLoader::load(filename, o))
	{
		p->setColor(RAND_COLOR);
		p->setName(QString("object_%1").arg(++objectNum));
		p->setId(id++);
		primitives.append(p);
		connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

		updateGL();

		return true;
	}
	return false;
}

void Scene::newCircle()
{
	SceneUnit::Primitive *p = new SceneUnit::Circle();
	p->setColor(RAND_COLOR);
	p->setName(QString("circle_%1").arg(++circleNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
}

void Scene::newRectangle()
{
	SceneUnit::Primitive *p = new SceneUnit::Rectangle();
	p->setColor(RAND_COLOR);
	p->setName(QString("rect_%1").arg(++rectangleNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
}

void Scene::newBox()
{
	SceneUnit::Primitive *p = new SceneUnit::Box();
	p->setColor(RAND_COLOR);
	p->setName(QString("box_%1").arg(++boxNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
}

void Scene::newSphere()
{
	SceneUnit::Primitive *p = new SceneUnit::Sphere(quadric);
	p->setColor(RAND_COLOR);
	p->setName(QString("sphere_%1").arg(++sphereNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
}

void Scene::deleteObject( int id )
{
	int i = getPrimitiveIndex(id);
	if (i >= 0)
	{
		SceneUnit::Primitive *p = primitives.at(i);
		primitives.removeAt(i);
		delete p;
	}

	updateGL();
}

void Scene::clear(Mode m)
{
	circleNum = 0;
	rectangleNum = 0;
	boxNum = 0;
	sphereNum = 0;
	objectNum = 0;
	id = 0;	

	selectedId = -1;

	primitives.clear();

	setSceneMode(m);

	updateGL();
}

void Scene::init()
{
	setHandlerKeyboardModifiers(QGLViewer::CAMERA, Qt::ControlModifier);

#ifdef Q_OS_MAC
    setMouseBinding(int(Qt::ControlModifier) | int(Qt::LeftButton)
                    | int(Qt::MidButton),  NO_CLICK_ACTION);
#else
    setMouseBinding(Qt::ControlModifier | Qt::LeftButton | Qt::MidButton,  NO_CLICK_ACTION);
#endif

	setForegroundColor(QColor(255, 255, 255));
}

void Scene::draw()
{
	glPushMatrix();

	//glMultMatrixd(manipulatedFrame()->matrix());

	for (int i = 0; i < primitives.count(); i++)
	{
		glPushMatrix();
		if (primitives[i]->getId() == selectedId)
		{
			primitives[i]->draw(true);
            drawAxis(0.2f);
		}
		else
		{
			primitives[i]->draw(false);
		}
		glPopMatrix();
	}

	glPopMatrix();
}

void Scene::drawWithNames()
{
	for (int i = 0; i < primitives.count(); i++)
	{
		glPushName(primitives[i]->getId());
		glPushMatrix();
		primitives[i]->draw(false);
		glPopMatrix();
		glPopName();
	}
}

void Scene::postDraw()
{
	QGLViewer::postDraw();
	//drawCornerAxis();
}

void Scene::postSelection(const QPoint& point)
{
	camera()->convertClickToLine(point, orig, dir);

	bool found;
	selectedPoint = camera()->pointUnderPixel(point, found);
	selectedPoint -= 0.01f * dir;

	selectedId = selectedName();

	emit selectedObjChanged(selectedName());
}

void Scene::animate()
{
	if (ifAnimate)
	{
		for (int i = 0; i < primitives.count(); i++)
		{
			SceneUnit::Primitive *p = primitives.at(i);
			QVector3D center = p->getCenter();
			center += QVector3D(dx, 0, 0);
			if (center.x() < -0.5)
			{
				dx = 0.01;
			}
			else if (center.x() > 0.5)
			{
				dx = -0.01;
			}
			p->setCenter(center);
		}
	}
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	Qt::KeyboardModifiers kms = event->modifiers();
	Qt::MouseButtons mbs = event->buttons();
	if (((kms & Qt::ControlModifier) != Qt::ControlModifier) &&
		((mbs & Qt::LeftButton) == Qt::LeftButton))
	{
		select(event->pos());
		updateGL();
	}
	else if ((kms & Qt::ControlModifier) == Qt::ControlModifier)
	{
		QGLViewer::mousePressEvent(event);
	}

}

void Scene::timerEvent(QTimerEvent *e)
{
	QGLViewer::timerEvent(e);
	//updateGL();
}

int Scene::getPrimitiveIndex( int id )
{
	if (id < 0 || id >= this->id)
	{
		return -1;
	}
	for (int i = 0; i < primitives.count(); i++)
	{
		if (primitives.at(i)->getId() == id)
		{
			return i;
		}
	}
	return -1;
}

void Scene::drawCornerAxis()
{
	int viewport[4];
	int scissor[4];

	// The viewport and the scissor are changed to fit the lower left
	// corner. Original values are saved.
	glGetIntegerv(GL_VIEWPORT, viewport);
	glGetIntegerv(GL_SCISSOR_BOX, scissor);

	// Axis viewport size, in pixels
	const int size = 100;
	glViewport(0, 0, size, size);
	glScissor(0, 0, size, size);

	// The Z-buffer is cleared to make the axis appear over the
	// original image.
	glClear(GL_DEPTH_BUFFER_BIT);

	// Tune for best line rendering
	glDisable(GL_LIGHTING);
	glLineWidth(1.0);

	glMatrixMode(GL_PROJECTION);
	glPushMatrix();
	glLoadIdentity();
	glOrtho(-1, 1, -1, 1, -1, 1);

	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();
	glLoadIdentity();
	glMultMatrixd(camera()->orientation().inverse().matrix());

	glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(1.0, 0.0, 0.0);

	glColor3f(0.0, 1.0, 0.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 1.0, 0.0);

	glColor3f(0.0, 0.0, 1.0);
	glVertex3f(0.0, 0.0, 0.0);
	glVertex3f(0.0, 0.0, 1.0);
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_LIGHTING);

	// The viewport and the scissor are restored.
	glScissor(scissor[0],scissor[1],scissor[2],scissor[3]);
	glViewport(viewport[0],viewport[1],viewport[2],viewport[3]);
}

void Scene::setSceneMode( Mode m )
{
	AxisPlaneConstraint *constraint = new LocalConstraint;
	switch (m)
	{
	case SCENE_2D:
 		camera()->setPosition(Vec(0.0, 0.0, 1.0));
 		camera()->setOrientation(0.0, 0.0);
 		camera()->lookAt(sceneCenter());
		camera()->setType(Camera::ORTHOGRAPHIC);
		camera()->fitScreenRegion(rect());

		constraint->setTranslationConstraintType(AxisPlaneConstraint::PLANE);
		constraint->setTranslationConstraintDirection(Vec(0.0, 0.0, 1.0));

#ifdef Q_OS_MAC
        setMouseBinding(int(Qt::ControlModifier) | int(Qt::LeftButton),  CAMERA, TRANSLATE);
        setMouseBinding(int(Qt::ControlModifier) | int(Qt::RightButton), NO_CLICK_ACTION);
#else
        setMouseBinding(Qt::ControlModifier | Qt::LeftButton,  CAMERA, TRANSLATE);
        setMouseBinding(Qt::ControlModifier | Qt::RightButton, NO_CLICK_ACTION);
#endif

		break;
	case SCENE_3D:
	default:
		camera()->setType(Camera::PERSPECTIVE);
		camera()->fitScreenRegion(rect());

		constraint->setTranslationConstraintType(AxisPlaneConstraint::FREE);

#ifdef Q_OS_MAC
        setMouseBinding(int(Qt::ControlModifier) | int(Qt::LeftButton),  CAMERA, ROTATE);
        setMouseBinding(int(Qt::ControlModifier) | int(Qt::RightButton), CAMERA, TRANSLATE);
#else
        setMouseBinding(Qt::ControlModifier | Qt::LeftButton,  CAMERA, ROTATE);
        setMouseBinding(Qt::ControlModifier | Qt::RightButton, CAMERA, TRANSLATE);
#endif

		break;
	}
	camera()->frame()->setConstraint(constraint);
}
