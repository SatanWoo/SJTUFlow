#include "scene.h"

#include <QMouseEvent>
#include <GL/glut.h>
#include <time.h>

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

void Scene::newCircle()
{
	GLdouble center[2] = {0.2, 0.0};
	GLdouble radius = 0.1;
	QColor color = RAND_COLOR;

	SceneUnit::Primitive *p = new SceneUnit::Circle(center, color, radius);
	p->setName(QString("circle_%1").arg(++circleNum));
	p->setId(id++);
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}

void Scene::newRectangle()
{
	GLdouble center[2] = {-0.2, 0.0};
	GLdouble width = 0.1;
	QColor color = RAND_COLOR;

	SceneUnit::Primitive *p = new SceneUnit::Rectangle(center, color, width);
	p->setName(QString("rect_%1").arg(++rectangleNum));
	p->setId(id++);
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}

void Scene::newBox()
{
	GLdouble center[3] = {0.0, 0.2, -0.2};
	GLdouble len = 0.1;
	QColor color = RAND_COLOR;

	SceneUnit::Primitive *p = new SceneUnit::Box(center, color, len);
	p->setName(QString("box_%1").arg(++boxNum));
	p->setId(id++);
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}

void Scene::newSphere()
{
	GLdouble center[3] = {0.0, -0.2, 0.2};
	GLdouble radius = 0.1;
	QColor color = RAND_COLOR;

	SceneUnit::Primitive *p = new SceneUnit::Sphere(center, color, radius, quadric);
	p->setName(QString("sphere_%1").arg(++sphereNum));
	p->setId(id++);
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
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
	id = 0;	

	primitives.clear();

	setSceneMode(m);

	updateGL();
}

void Scene::init()
{
	setHandlerKeyboardModifiers(QGLViewer::CAMERA, Qt::ControlModifier);

	setMouseBinding(Qt::ControlModifier | Qt::LeftButton  | Qt::MidButton,  NO_CLICK_ACTION);

// 	setHandlerKeyboardModifiers(QGLViewer::FRAME,  Qt::NoModifier);
// 
// 	setManipulatedFrame(new qglviewer::ManipulatedFrame());

//	restoreStateFromFile();

//	setAxisIsDrawn();
}

void Scene::draw()
{
	glPushMatrix();

	//glMultMatrixd(manipulatedFrame()->matrix());

	for (int i = 0; i < primitives.count(); i++)
	{
		glPushMatrix();
		primitives.at(i)->draw(selectedName());
		if (primitives.at(i)->getId() == selectedName())
		{
			drawAxis(0.2);
		}
		glPopMatrix();
	}

	glPopMatrix();
}

void Scene::drawWithNames()
{
	for (int i = 0; i < primitives.count(); i++)
	{
		glPushMatrix();

		glPushName(primitives.at(i)->getId());
		primitives.at(i)->draw(-1);
		glPopName();

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
	camera()->convertClickToLine(point, orig, dir);

	bool found;
	selectedPoint = camera()->pointUnderPixel(point, found);
	selectedPoint -= 0.01f * dir;

	emit selectedObjChanged(selectedName());
}

void Scene::animate()
{
	if (ifAnimate)
	{
		for (int i = 0; i < primitives.count(); i++)
		{
			GLdouble center[3];
			SceneUnit::Primitive *p = primitives.at(i);
			p->getCenter(center);
			center[0] += dx;
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
	Qt::KeyboardModifiers kms = event->modifiers();
	Qt::MouseButtons mbs = event->buttons();
	if (((kms & Qt::ShiftModifier) == Qt::ShiftModifier) &&
		((mbs & Qt::LeftButton) == Qt::LeftButton))
	{
		select(event);
		updateGL();
	}
	else
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

		setMouseBinding(Qt::ControlModifier | Qt::LeftButton,  CAMERA, TRANSLATE);
		setMouseBinding(Qt::ControlModifier | Qt::RightButton, NO_CLICK_ACTION);

		break;
	case SCENE_3D:
	default:
		camera()->setType(Camera::PERSPECTIVE);
		camera()->fitScreenRegion(rect());

		constraint->setTranslationConstraintType(AxisPlaneConstraint::FREE);

		setMouseBinding(Qt::ControlModifier | Qt::LeftButton,  CAMERA, ROTATE);
		setMouseBinding(Qt::ControlModifier | Qt::RightButton, CAMERA, TRANSLATE);

		break;
	}
	camera()->frame()->setConstraint(constraint);
}