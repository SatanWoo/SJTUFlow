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
Vec Scene::axisDirs[3] = 
	{
		Vec(1.0, 0.0, 0.0), 
		Vec(0.0, 1.0, 0.0), 
		Vec(0.0, 0.0, 1.0)
	};
double Scene::axisRot[3][4] = 
	{
		{90.0, 0.0, 1.0, 0.0}, 
		{90.0, 1.0, 0.0, 0.0}, 
		{0.0, 0.0, 0.0, 0.1}
	};

Scene::Scene(QWidget *parent) : QGLViewer(parent)
{
	srand(time(NULL));

	mousePressed = false;
	dx = 0.01;

	setAnimate(false);

	clear(SCENE_2D);
}

SceneUnit::Primitive *Scene::getPrimitive(int id)
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

QDomElement Scene::domElement(QDomDocument &doc)
{
	QDomElement node = doc.createElement(tr("Scene"));
	node.setAttribute(tr("mode"), sceneMode);
	node.setAttribute(tr("ids"), id);
	foreach (SceneUnit::Primitive *p, primitives)
	{
		node.appendChild(p->domElement(doc));
	}
	return node;
}

bool Scene::initFromDomElement(const QDomElement &node)
{
	bool ret = true;
	id = DomUtils::intFromDom(node, tr("ids"), 0);
	QDomNodeList children = node.childNodes();
	for (int i = 0; i < children.count(); i++)
	{
		QDomElement child = children.at(i).toElement();
		if (child.tagName() == tr("Primitive"))
		{
			SceneUnit::Primitive *p;
			int t = DomUtils::intFromDom(child, tr("type"), -1);

			if (sceneMode == SCENE_2D)
			{
				switch (t)
				{
				case SceneUnit::Primitive::T_Rect:
					p = new SceneUnit::Rectangle;
					p->initFromDomElement(child);
					id = id > p->getId() ?  id : (p->getId() + 1);
					primitives.append(p);
					break;
				case SceneUnit::Primitive::T_Circle:
					p = new SceneUnit::Circle;
					p->initFromDomElement(child);
					id = id > p->getId() ?  id : (p->getId() + 1);
					primitives.append(p);
					break;
				default:
					ret = false;
					break;
				}
			}
			else
			{
				switch (t)
				{
				case SceneUnit::Primitive::T_Box:
					p = new SceneUnit::Box;
					p->initFromDomElement(child);
					id = id > p->getId() ?  id : (p->getId() + 1);
					primitives.append(p);
					break;
				case SceneUnit::Primitive::T_Sphere:
					p = new SceneUnit::Sphere(quadric);
					p->initFromDomElement(child);
					id = id > p->getId() ?  id : (p->getId() + 1);
					primitives.append(p);
					break;
				case SceneUnit::Primitive::T_Object:
					p = new SceneUnit::Object;
					p->initFromDomElement(child);
					id = id > p->getId() ?  id : (p->getId() + 1);
					primitives.append(p);
					break;
				default:
					ret = false;
					break;
				}
			}
		}
	}
	return ret;
}

void Scene::newCircle()
{
	SceneUnit::Primitive *p = new SceneUnit::Circle;
	p->setColor(RAND_COLOR);
	p->setName(QString("circle_%1").arg(++circleNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
	emit sceneChanged();
}

void Scene::newRectangle()
{
	SceneUnit::Primitive *p = new SceneUnit::Rectangle;
	p->setColor(RAND_COLOR);
	p->setName(QString("rect_%1").arg(++rectangleNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
	emit sceneChanged();
}

void Scene::newBox()
{
	SceneUnit::Primitive *p = new SceneUnit::Box;
	p->setColor(RAND_COLOR);
	p->setName(QString("box_%1").arg(++boxNum));
	p->setId(id++);
	primitives.append(p);
	updateGL();

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
	emit sceneChanged();
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
	emit sceneChanged();
}

void Scene::deleteObject(int id)
{
	int i = getPrimitiveIndex(id);
	if (i >= 0)
	{
		SceneUnit::Primitive *p = primitives.at(i);
		primitives.removeAt(i);
		delete p;
	}

	updateGL();
	emit sceneChanged();
}

void Scene::clear(Mode m)
{
    sceneMode = m;
	curOp = OP_MOVE;

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
			Vec bmin, bmax;
			primitives[i]->getBoundingBox(bmin, bmax);
			drawOperator(primitives[i]->getCenter(), bmin, bmax);

			primitives[i]->draw(true);
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
			Vec bmin, bmax;
			primitives[i]->getBoundingBox(bmin, bmax);
			drawOperator(primitives[i]->getCenter(), bmin, bmax, true);

			glPushName(primitives[i]->getId());
			primitives[i]->draw(true);
			glPopName();
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
	if (mousePressed)
	{
		if (selectedName() < AXIS_X)
		{
			selectedId = selectedName();
			selectedAxis = -1;
			emit selectedObjChanged(selectedName());
		}
		else if (selectedName() >= AXIS_X && selectedName() <= AXIS_SCALE)
		{
			selectedAxis = selectedName();
		}
	}
	else
	{
		if (selectedName() >= AXIS_X && selectedName() <= AXIS_Z)
		{
			if (curOp == OP_MOVE)
			{
				setCursor(Qt::SizeAllCursor);
			}
			else if (curOp == OP_ROTATE)
			{
				QPixmap pix(":/SJTUFlow/Resources/RotateCursor.png");
				QCursor rotateCursor(pix);
				setCursor(rotateCursor);
			}
		}
		else if (selectedName() == AXIS_SCALE)
		{
			setCursor(Qt::SizeBDiagCursor);
		}
		else
		{
			setCursor(Qt::ArrowCursor);
		}
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
	mousePressed = true;
	bool found;
	mousePos = camera()->pointUnderPixel(event->pos(), found);
	mousePosInWin = event->pos();

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
	if (!mousePressed)
	{
		select(event->pos());
		return;
	}
	Qt::KeyboardModifiers kms = event->modifiers();
	if ((kms & Qt::ControlModifier) == Qt::ControlModifier)
	{
		QGLViewer::mouseMoveEvent(event);
	}
    else if (selectedAxis >= AXIS_X && selectedAxis <= AXIS_SCALE)
    {
		SceneUnit::Primitive *p = getPrimitive(selectedId);
		if (p != NULL)
		{
			bool found;
			Vec pos = camera()->pointUnderPixel(event->pos(), found);

			if (curOp == OP_MOVE)
			{
				Vec d = pos - mousePos;

				if (sceneMode == SCENE_3D)
				{
					d *= 0.5;	// need to be related to zoom rate. 
				}

				p->translate(d, selectedAxis - AXIS_X);
			}
			else if (curOp == OP_ROTATE)
			{
				Vec center = p->getCenter();
				Vec d0 = mousePos - center;
				Vec d1 = pos - center;

				double angle = acos(d0 * d1 / (d0.norm() * d1.norm()));
				if (cross(d0, d1) * camera()->viewDirection() > 0)
				{
					angle = -angle;
				}
				p->rotate(angle, axisDirs[selectedAxis - AXIS_X]);
			}
			else if (curOp == OP_SCALE)
			{
				double scalar = p->getScalar();
				Vec center = p->getCenter();
				Vec d0, d1;
				if (sceneMode == SCENE_3D)
				{
					d0 = mousePos - center;
					d1 = pos - center;
				}
				else
				{
					Vec c = camera()->projectedCoordinatesOf(center);
					d0 = Vec(mousePosInWin.x(), mousePosInWin.y(), c[2]) - c;
					d1 = Vec(event->pos().x(), event->pos().y(), c[2]) - c;
				}
				scalar *= d1.norm() / d0.norm();
				p->setScalar(scalar);
			}

			mousePos = pos;
			mousePosInWin = event->pos();
			updateGL();
		}
    }
    else
    {
        QGLViewer::mouseMoveEvent(event);
    }
}

void Scene::mouseReleaseEvent(QMouseEvent *event)
{
	mousePressed = false;
	QGLViewer::mouseReleaseEvent(event);
}

void Scene::timerEvent(QTimerEvent *e)
{
	QGLViewer::timerEvent(e);
	//updateGL();
}

int Scene::getPrimitiveIndex(int id)
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

void Scene::drawOperator(Vec center, Vec bmin, Vec bmax, bool withName)
{
	glPushMatrix();
	glTranslated(center[0], center[1], center[2]);

	Vec tmp = bmax - bmin;
	double length = tmp.norm() / 2;
	switch (curOp)
	{
	case OP_ROTATE:
		drawRotateRing(length, AXIS_Z, withName);
		if (sceneMode == SCENE_3D)
		{
			drawRotateRing(length, AXIS_X, withName);
			drawRotateRing(length, AXIS_Y, withName);
		}
		break;
	case OP_SCALE:
		drawScaleBox(bmin, bmax, withName);
		break;
	case OP_MOVE:
	default:
		drawMoveAxis(length, AXIS_X, withName);
		drawMoveAxis(length, AXIS_Y, withName);
		if (sceneMode == SCENE_3D)
		{
			drawMoveAxis(length, AXIS_Z, withName);
		}
		break;
	}

	glPopMatrix();
}

void Scene::drawMoveAxis(double length, Axis axis, bool withName)
{
	int which = axis - AXIS_X;
	Vec axisVec = length * axisDirs[which];

	glDisable(GL_LIGHTING);

	if (withName)
	{
		glPushName(axis);
	}

	glPushMatrix();
	if (sceneMode == SCENE_2D)
	{
		glTranslated(0.0, 0.0, 0.01);	// to make the 2D axis on the top
	}

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

	glLineWidth(3.0);
	glBegin(GL_LINES);
	if (axis == selectedAxis)
	{
		qglColor(Qt::yellow);
	}
	else
	{
		glColor3dv(axisDirs[which]);
	}
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3dv(axisVec);
	glEnd();

	Vec inverseColor = Vec(1.0, 1.0, 1.0) - axisDirs[which];
	glPushMatrix();
	glTranslated(axisVec.x, axisVec.y, axisVec.z);
	if (axis == selectedAxis)
	{
		qglColor(Qt::yellow);
	}
	else
	{
		glColor3dv(inverseColor);
	}
	gluSphere(quadric, length / 20, 32, 32);
	glPopMatrix();

	glPopMatrix();

	if (withName)
	{
		glPopName();
	}

	glEnable(GL_LIGHTING);
}

void Scene::drawRotateRing(double radius, Axis axis, bool withName)
{
	int which = axis - AXIS_X;

	glDisable(GL_LIGHTING);

	if (withName)
	{
		glPushName(axis);
	}

	glPushMatrix();

	glRotated(axisRot[which][0], axisRot[which][1], 
		axisRot[which][2], axisRot[which][3]);
	if (sceneMode == SCENE_2D)
	{
		glTranslated(0.0, 0.0, 0.01);
	}
	if (axis == selectedAxis)
	{
		qglColor(Qt::yellow);
	}
	else
	{
		glColor3dv(axisDirs[which]);
	}
	glutSolidTorus(0.003, radius, 32, 32);
	glPopMatrix();

	if (withName)
	{
		glPopName();
	}

	glEnable(GL_LIGHTING);
}

void Scene::drawScaleBox(Vec bmin, Vec bmax, bool withName)
{
	glDisable(GL_LIGHTING);

	glPushMatrix();
	Vec len = bmax - bmin;
	SceneUnit::Primitive *p;
	if (sceneMode == SCENE_2D)
	{
		p = new SceneUnit::Rectangle(Vec(), Qt::red, len[0], len[1], false);
		if (withName)
		{
			glPushName(selectedId);
		}
		p->draw(false);
		if (withName)
		{
			glPopName();
		}

		double minlen = len[0] < len[1] ? len[0] : len[1];
		if (withName)
		{
			glPushName(AXIS_SCALE);
		}
		glTranslated(0.0, 0.0, 0.01);
		drawSubScaleBox(minlen, bmin[0], bmin[1], 0.0, false);
		drawSubScaleBox(minlen, bmin[0], bmax[1], 0.0, false);
		drawSubScaleBox(minlen, bmax[0], bmin[1], 0.0, false);
		drawSubScaleBox(minlen, bmax[0], bmax[1], 0.0, false);
		if (withName)
		{
			glPopName();
		}
	}
	else
	{
		p = new SceneUnit::Box(Vec(), Qt::red, len[0], len[1], len[2], false);
		if (withName)
		{
			glPushName(selectedId);
		}
		p->draw(false);
		if (withName)
		{
			glPopName();
		}

		double minlen = len[0] < len[1] ? len[0] : len[1];
		minlen = minlen < len[2] ? minlen : len[2];
		if (withName)
		{
			glPushName(AXIS_SCALE);
		}
		drawSubScaleBox(minlen, bmin[0], bmin[1], bmin[2]);
		drawSubScaleBox(minlen, bmin[0], bmax[1], bmin[2]);
		drawSubScaleBox(minlen, bmax[0], bmin[1], bmin[2]);
		drawSubScaleBox(minlen, bmax[0], bmax[1], bmin[2]);
		drawSubScaleBox(minlen, bmin[0], bmin[1], bmax[2]);
		drawSubScaleBox(minlen, bmin[0], bmax[1], bmax[2]);
		drawSubScaleBox(minlen, bmax[0], bmin[1], bmax[2]);
		drawSubScaleBox(minlen, bmax[0], bmax[1], bmax[2]);
		if (withName)
		{
			glPopName();
		}
	}
	glPopMatrix();

	glEnable(GL_LIGHTING);
}

void Scene::drawSubScaleBox(double len, double x, double y, double z, bool s3d)
{
	QColor c = Qt::red;
	if (selectedAxis == AXIS_SCALE)
	{
		c = Qt::yellow;
	}

	glPushMatrix();
	glTranslated(x, y, z);
	if (s3d)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
		qglColor(c);
		glutSolidCube(len / 10);
	}
	else
	{
		SceneUnit::Rectangle r(Vec(), c, len / 10);
		r.draw(false);
	}
	glPopMatrix();
}
