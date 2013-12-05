#include "scene.h"

#ifdef Q_OS_MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <QMouseEvent>
#include <time.h>
#include <QDebug>

#include "objloader.h"

using namespace qglviewer;

GLUquadric *Scene::quadric = gluNewQuadric();
Vec Scene::axisDirs[3] = {Vec(1.0, 0.0, 0.0), Vec(0.0, 1.0, 0.0), Vec(0.0, 0.0, 1.0)};

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
    sceneMode = m;

	circleNum = 0;
	rectangleNum = 0;
	boxNum = 0;
	sphereNum = 0;
	objectNum = 0;
	id = 0;	

	selectedId = -1;

	primitives.clear();

    setSceneMode();

	updateGL();

	emit selectedObjChanged(selectedId);
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
	for (int i = 0; i < primitives.count(); i++)
	{
		glPushMatrix();
		if (primitives[i]->getId() == selectedId)
		{
			primitives[i]->draw(true);

			drawAxis(0.2, AXIS_X);
			drawAxis(0.2, AXIS_Y);
			if (sceneMode == SCENE_3D)
			{
				drawAxis(0.2, AXIS_Z);
			}
		}
		else
		{
			primitives[i]->draw(false);
		}
		glPopMatrix();
	}
}

void Scene::drawWithNames()
{
	for (int i = 0; i < primitives.count(); i++)
	{
		glPushMatrix();
		if (primitives[i]->getId() == selectedId)
		{
			glPushName(primitives[i]->getId());
			primitives[i]->draw(true);
			glPopName();

			drawAxis(0.2, AXIS_X);
			drawAxis(0.2, AXIS_Y);
			if (sceneMode == SCENE_3D)
			{
				drawAxis(0.2, AXIS_Z);
			}
		}
		else
		{
			glPushName(primitives[i]->getId());
			primitives[i]->draw(false);
			glPopName();
		}
		glPopMatrix();
	}
}

void Scene::postDraw()
{
	QGLViewer::postDraw();
	drawCornerAxis();
}

void Scene::postSelection(const QPoint& point)
{
	//camera()->convertClickToLine(point, orig, dir);

	//bool found;
	//selectedPoint = camera()->pointUnderPixel(point, found);
	//selectedPoint -= 0.01f * dir;

	if (selectedName() < AXIS_X)
	{
		selectedId = selectedName();
		emit selectedObjChanged(selectedName());
	}
}

void Scene::animate()
{
	if (ifAnimate)
	{
		for (int i = 0; i < primitives.count(); i++)
		{
			SceneUnit::Primitive *p = primitives.at(i);
			Vec center = p->getCenter();
			center += Vec(dx, 0, 0);
			if (center[0] < -0.5)
			{
				dx = 0.01;
			}
			else if (center[0] > 0.5)
			{
				dx = -0.01;
			}
			p->setCenter(center);
		}
	}
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	bool found;
	mousePos = camera()->pointUnderPixel(event->pos(), found);

	Qt::KeyboardModifiers kms = event->modifiers();
	Qt::MouseButtons mbs = event->buttons();
	if ((kms & Qt::ControlModifier) == Qt::ControlModifier)
	{
		QGLViewer::mousePressEvent(event);
	}
	else if ((mbs & Qt::LeftButton) == Qt::LeftButton)
	{
		select(event->pos());
		updateGL();
	}

}

void Scene::mouseMoveEvent(QMouseEvent *event)
{
	Qt::KeyboardModifiers kms = event->modifiers();
	if ((kms & Qt::ControlModifier) == Qt::ControlModifier)
	{
		QGLViewer::mouseMoveEvent(event);
	}
    else if (selectedName() >= AXIS_X && selectedName() <= AXIS_Z)
    {
		SceneUnit::Primitive *p = getPrimitive(selectedId);
		if (p != NULL)
		{
			bool found;
			Vec pos = camera()->pointUnderPixel(event->pos(), found);
			Vec d = pos - mousePos;
			mousePos = pos;

			if (sceneMode == SCENE_3D)
			{
				d *= 0.5;	// need to be related to zoom rate. 
			}

			p->translate(d, selectedName() - AXIS_X);

			updateGL();
		}
    }
    else
    {
        QGLViewer::mouseMoveEvent(event);
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

	if (sceneMode == SCENE_3D)
	{
		glColor3f(0.0, 0.0, 1.0);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(0.0, 0.0, 1.0);
	}
	glEnd();

	glMatrixMode(GL_PROJECTION);
	glPopMatrix();

	glMatrixMode(GL_MODELVIEW);
	glPopMatrix();

	glEnable(GL_LIGHTING);

	// The viewport and the scissor are restored.
	glScissor(scissor[0], scissor[1], scissor[2], scissor[3]);
	glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void Scene::setSceneMode()
{
	AxisPlaneConstraint *constraint = new LocalConstraint;
    switch (sceneMode)
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
		camera()->setPosition(Vec(0.0, 0.0, 1.0));
		camera()->setOrientation(0.0, 0.0);
		camera()->lookAt(sceneCenter());
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

void Scene::drawAxis( double length, Axis axis )
{
	int which = axis - AXIS_X;
	Vec axisVec = length * axisDirs[which];

	glPointSize(1.0);
	glDisable(GL_LIGHTING);

	glPushName(axis);

	glBegin(GL_LINES);
	glColor3dv(axisDirs[which]);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3dv(axisVec);
	glEnd();

	Vec inverseColor = Vec(1.0, 1.0, 1.0) - axisDirs[which];
	glPushMatrix();
	glTranslated(axisVec.x, axisVec.y, axisVec.z);
	glColor3dv(inverseColor);
	gluSphere(quadric, 0.01, 32, 32);
	glPopMatrix();

	glPopName();

	glEnable(GL_LIGHTING);
}
