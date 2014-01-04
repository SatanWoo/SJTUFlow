#include "scene.h"

#ifdef Q_OS_MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <QApplication>
#include <QLocalSocket>
#include <QDataStream>
#include <QMouseEvent>
#include <time.h>

#include "objloader.h"
#include "scenecommand.h"

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

	allowSelect = true;
	mousePressed = false;
	dx = 0.01;
	undoStack = NULL;

	setMouseTracking(true);

	clear(SCENE_2D);

	memset(&spSPH, 0, sizeof(SocketPackageSPH));
	memset(&spEG, 0, sizeof(SocketPackageEuler));

	setAnimationPeriod(0);
	localServer = new QLocalServer(this);

	setSceneRadius(5.0f);
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

QDomElement Scene::domElement(QDomDocument &doc, bool withCamera)
{
	QDomElement node = doc.createElement(tr("Scene"));
	node.setAttribute(tr("mode"), sceneMode);
	node.setAttribute(tr("ids"), id);
	foreach (SceneUnit::Primitive *p, primitives)
	{
		node.appendChild(p->domElement(doc));
	}
	if (withCamera)
	{
		node.appendChild(camera()->domElement(tr("Camera"), doc));
	}
	return node;
}

Scene::Error Scene::initFromDomElement(
	const QDomElement &node, bool withCamera)
{
	int scnMode = DomUtils::intFromDom(node, tr("mode"), -1);
	sceneMode = scnMode == 0 ? SCENE_2D : SCENE_3D;
	clear(sceneMode);
	Error ret = OK;
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
					id = id > p->getId() ? id : (p->getId() + 1);
					primitives.append(p);
					connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
					break;
				case SceneUnit::Primitive::T_Circle:
					p = new SceneUnit::Circle;
					p->initFromDomElement(child);
					id = id > p->getId() ? id : (p->getId() + 1);
					primitives.append(p);
					connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
					break;
				default:
					ret = NOTMATCH;
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
					id = id > p->getId() ? id : (p->getId() + 1);
					primitives.append(p);
					connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
					break;
				case SceneUnit::Primitive::T_Sphere:
					p = new SceneUnit::Sphere(quadric);
					p->initFromDomElement(child);
					id = id > p->getId() ? id : (p->getId() + 1);
					primitives.append(p);
					connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
					break;
				case SceneUnit::Primitive::T_Object:
					{
						p = new SceneUnit::Object;
						QString pathname = child.attribute(tr("path"));
						bool r = ObjLoader::load(pathname, (SceneUnit::Object *)p);
						if (r)
						{
							p->initFromDomElement(child);
							id = id > p->getId() ? id : (p->getId() + 1);
							primitives.append(p);
							connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
						}
						else
						{
							ret = PATHERR;
						}
					}
					break;
				default:
					ret = NOTMATCH;
					break;
				}
			}
		}
	}
	if (withCamera)
	{
		QDomElement child = node.firstChildElement(tr("Camera"));
		camera()->initFromDOMElement(child);
	}
	updateGL();
	return ret;
}

void Scene::startAnimation()
{
	if (!localServer->listen(QApplication::applicationName()))
	{
		qDebug() << "failed to listen" << QApplication::applicationName() << endl;
	}

	memset(&spSPH, 0, sizeof(SocketPackageSPH));
	if (spEG.density)
	{
		delete[] spEG.density;
		spEG.density = NULL;
	}
	memset(&spEG, 0, sizeof(SocketPackageEuler));

	QGLViewer::startAnimation();
}

void Scene::stopAnimation()
{
	if (animationIsStarted())
	{
		localServer->close();
		QGLViewer::stopAnimation();
	}
}

void Scene::clone(Scene *scene)
{
	clear(scene->sceneMode);
	for (int i = 0; i < scene->primitives.count(); i++)
	{
		Primitive *p = scene->primitives[i];
		appendPrimitive(p);
	}
	QDomDocument doc;
	camera()->initFromDOMElement(
		scene->camera()->domElement(tr("Camera"), doc));
}

bool Scene::importObject(QString filename)
{
	if (undoStack != NULL)
	{
		SceneImportCommand *command = new SceneImportCommand(this);
		if (command->import(filename))
		{
			undoStack->push(command);
			return true;
		}
		return false;
	}
	else
	{
		SceneUnit::Primitive *p = new SceneUnit::Object;
		SceneUnit::Object *o = (SceneUnit::Object *)p;
		if (ObjLoader::load(filename, o))
		{
			o->adjust();
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
}

void Scene::newPrimitive(SceneUnit::Primitive::Type type)
{
	if (undoStack != NULL)
	{
		undoStack->push(new SceneNewCommand(type, this));
	}
	else
	{
		SceneUnit::Primitive *p;
		QString name;
		switch (type)
		{
		case SceneUnit::Primitive::T_Circle:
			p = new SceneUnit::Circle;
			name = QString("circle_%1").arg(++circleNum);
			break;
		case SceneUnit::Primitive::T_Rect:
			p = new SceneUnit::Rectangle;
			name = QString("rectangle_%1").arg(++rectangleNum);
			break;
		case SceneUnit::Primitive::T_Sphere:
			p = new SceneUnit::Sphere(quadric);
			name = QString("sphere_%1").arg(++sphereNum);
			break;
		case SceneUnit::Primitive::T_Box:
			p = new SceneUnit::Box;
			name = QString("box_%1").arg(++boxNum);
			break;
		default:
			p = NULL;
			break;
		}
		Q_ASSERT(p != NULL);
		p->setColor(RAND_COLOR);
		p->setName(name);
		p->setId(id++);

		primitives.append(p);
		connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

		updateGL();
		emit sceneChanged();
	}
}

QString Scene::defaultName(SceneUnit::Primitive::Type type)
{
	QString ret;
	switch (type)
	{
	case SceneUnit::Primitive::T_Circle:
		ret = QString("circle_%1").arg(circleNum + 1);
		break;
	case SceneUnit::Primitive::T_Rect:
		ret = QString("rectangle_%1").arg(rectangleNum + 1);
		break;
	case SceneUnit::Primitive::T_Sphere:
		ret = QString("sphere_%1").arg(sphereNum + 1);
		break;
	case SceneUnit::Primitive::T_Box:
		ret = QString("box_%1").arg(boxNum + 1);
		break;
	case SceneUnit::Primitive::T_Object:
		ret = QString("object_%1").arg(objectNum + 1);
		break;
	default:
		break;
	}
	return ret;
}

void Scene::deletePrimitive(int id)
{
	int i = getPrimitiveIndex(id);
	if (i >= 0)
	{
		SceneUnit::Primitive *p = getPrimitive(id);
		disconnect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));
		primitives.removeAt(i);

		selectedId = -1;
		emit selectedObjChanged(selectedId);

		updateGL();
		emit sceneChanged();
	}
}

void Scene::appendPrimitive(Primitive *p)
{
	if (p != NULL)
	{
		primitives.append(p);
		connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

		selectedId = -1;
		emit selectedObjChanged(selectedId);

		updateGL();
		emit sceneChanged();
	}
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

void Scene::increaseNum(SceneUnit::Primitive::Type t)
{
	switch(t)
	{
	case SceneUnit::Primitive::T_Circle:
		circleNum++;
		break;
	case SceneUnit::Primitive::T_Rect:
		rectangleNum++;
		break;
	case SceneUnit::Primitive::T_Sphere:
		sphereNum++;
		break;
	case SceneUnit::Primitive::T_Box:
		boxNum++;
		break;
	case SceneUnit::Primitive::T_Object:
		objectNum++;
		break;
	default:
		break;
	}
}

void Scene::decreaseNum(SceneUnit::Primitive::Type t)
{
	switch(t)
	{
	case SceneUnit::Primitive::T_Circle:
		circleNum--;
		break;
	case SceneUnit::Primitive::T_Rect:
		rectangleNum--;
		break;
	case SceneUnit::Primitive::T_Sphere:
		sphereNum--;
		break;
	case SceneUnit::Primitive::T_Box:
		boxNum--;
		break;
	case SceneUnit::Primitive::T_Object:
		objectNum--;
		break;
	default:
		break;
	}
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

	GLfloat light_ambient[4]={0.5, 0.5, 0.5, 1.0};
	GLfloat light_diffuse[4]={1.0, 1.0, 1.0, 1.0};
	GLfloat light_position[4]={0.0, 0.0, 2.0, 0.0};
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
}

void Scene::draw()
{
	// trick
	glPushMatrix();
	glTranslated(-1000.0, -1000.0, -1000.0);
	if (sceneMode == SCENE_3D)
	{
		SceneUnit::Sphere s(quadric, 10, 10);
		s.setRadius(0.0001);
		s.draw(false);
	}
	else
	{
		SceneUnit::Rectangle r;
		r.setLenX(0.0001);
		r.setLenY(0.0001);
		r.draw(false);
	}
	glPopMatrix();
	//

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

	if (animationIsStarted())
	{
		//camera()->setPosition(qglviewer::Vec(5.0, 5.0, 15.0));
		for(int i = 0; i < spSPH.particleNum; ++i)
		{
			SceneUnit::Primitive *p;
			if (sceneMode == SCENE_2D)
			{
				p = new SceneUnit::Circle;
				if (spSPH.particlesMass[i] > 1.0)
				{
					p->setColor(QColor(51, 153, 0));
				}
				else
				{
					p->setColor(QColor(51, 153, 204));
				}
				p->setCenter(Vec(spSPH.particles[i].x, spSPH.particles[i].y, 0.0));
				p->setRadius(spSPH.radius);
			}
			else
			{
				p = new SceneUnit::Sphere(quadric, 10, 10);
				p->setCenter(Vec(spSPH.particles[i].x, spSPH.particles[i].y, spSPH.particles[i].z));
				p->setRadius(0.001);
			}
			glPushMatrix();
			p->draw(false);
			glPopMatrix();
		}

		if (spEG.size > 0)
		{
			drawEuler();
		}
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
			setCursor(Qt::SizeAllCursor);
		}
		else
		{
			setCursor(Qt::ArrowCursor);
		}
	}
}

void Scene::animate()
{
	QLocalSocket *socket = localServer->nextPendingConnection();
	if (socket)
	{
		QDataStream ds(socket);
		socket->waitForReadyRead();

		int sizeEG = spEG.size;

		SceneType st;
		ds.readRawData((char *)(&st), sizeof(SceneType));
		if (sceneMode == SCENE_2D)
		{
			if (st == SC_3D)
			{
				sizeEG = 0;
				sceneMode = SCENE_3D;
				setSceneMode();
			}
		}
		else
		{
			if (st == SC_2D)
			{
				sizeEG = 0;
				sceneMode = SCENE_2D;
				setSceneMode();
			}
		}
		SocketType type;
		ds.readRawData((char *)(&type), sizeof(SocketType));
		if (type == SC_SPH)
		{
			ds.readRawData((char *)(&spSPH), sizeof(SocketPackageSPH));
		}
		else
		{
			ds.readRawData((char *)(&spEG.size), sizeof(int));
			ds.readRawData((char *)(&spEG.totalSize), sizeof(int));
			if (spEG.size != sizeEG)
			{
				if (spEG.density != NULL)
				{
					delete[] spEG.density;
				}
				spEG.density = new float[spEG.totalSize];
			}
			ds.readRawData((char *)(spEG.density), spEG.totalSize * sizeof(float));
		}
		socket->disconnectFromServer();
	}
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	if (!allowSelect)
	{
		QGLViewer::mousePressEvent(event);
		return;
	}
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

		SceneUnit::Primitive *p = getPrimitive(selectedId);
		if (p != NULL && selectedAxis >= AXIS_X && 
			selectedAxis <= AXIS_SCALE)
		{
			poCmd = new PrimitiveOperateCommand(p);
		}
	}

}

void Scene::mouseMoveEvent(QMouseEvent *event)
{
	if (!allowSelect)
	{
		QGLViewer::mouseMoveEvent(event);
		return;
	}
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

				double l = camera()->position().norm();

				if (sceneMode == SCENE_3D)
				{
					d *= 0.5 * l / 9.0;	// need to be related to zoom rate. 
				}

				p->translate(d, selectedAxis - AXIS_X);
			}
			else if (curOp == OP_ROTATE)
			{
				if (!rect().contains(event->pos()))
				{
					return;
				}
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
					d0 = Vec(event->pos().x(), event->pos().y(), 0.0) - c;
					d1 = Vec(mousePosInWin.x(), mousePosInWin.y(), 0.0) - c;
				}

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
				Vec c = camera()->projectedCoordinatesOf(center);
				d0 = Vec(mousePosInWin.x(), mousePosInWin.y(), c[2]) - c;
				d1 = Vec(event->pos().x(), event->pos().y(), c[2]) - c;
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
	if (!allowSelect)
	{
		QGLViewer::mouseReleaseEvent(event);
		return;
	}
	mousePressed = false;
	Qt::KeyboardModifiers kms = event->modifiers();
	if ((kms & Qt::ControlModifier) != Qt::ControlModifier &&
		selectedAxis >= AXIS_X && selectedAxis <= AXIS_SCALE)
	{
		if (poCmd != NULL)
		{
			poCmd->setNewData();
			undoStack->push(poCmd);
		}
	}
	QGLViewer::mouseReleaseEvent(event);
}

void Scene::wheelEvent( QWheelEvent *event )
{
	if (sceneMode == SCENE_3D)
	{
		QGLViewer::wheelEvent(event);
	}
	else
	{
		Qt::KeyboardModifiers kms = event->modifiers();
		if ((kms & Qt::ControlModifier) == Qt::ControlModifier)
		{
			Vec trans(0.0, 0.0, event->delta() * 8e-4);
			camera()->setPosition(camera()->position() + trans);
			updateGL();
			event->accept();
		}
	}
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
		camera()->frame()->stopSpinning();
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
		drawSubScaleBox(minlen, -len[0] / 2, -len[1] / 2, -len[2] / 2);
		drawSubScaleBox(minlen, -len[0] / 2, len[1] / 2, -len[2] / 2);
		drawSubScaleBox(minlen, len[0] / 2, -len[1] / 2, -len[2] / 2);
		drawSubScaleBox(minlen, len[0] / 2, len[1] / 2, -len[2] / 2);
		drawSubScaleBox(minlen, -len[0] / 2, -len[1] / 2, len[2] / 2);
		drawSubScaleBox(minlen, -len[0] / 2, len[1] / 2, len[2] / 2);
		drawSubScaleBox(minlen, len[0] / 2, -len[1] / 2, len[2] / 2);
		drawSubScaleBox(minlen, len[0] / 2, len[1] / 2, len[2] / 2);
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

void Scene::drawEuler()
{
	//camera()->setPosition(qglviewer::Vec(0.0, 0.0, 2.0));
	int N = spEG.size;
	glDisable(GL_LIGHTING);
	glDisable(GL_COLOR_MATERIAL);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0);

	glPushMatrix();
	glBegin(GL_QUADS);
	if (sceneMode == SCENE_2D)
	{
#define IX(i, j) ((i) + (N + 2) * (j))
		float h = 1.0f / N;
		for (int i = 0; i <= N; i++)
		{
			float x = (i - 0.5f) * h - 0.5f;
			for (int j = 0; j <= N; j++)
			{
				float y = (j - 0.5f) * h - 0.5f;

				float d00 = spEG.density[IX(i, j)];
				float d01 = spEG.density[IX(i, j + 1)];
				float d10 = spEG.density[IX(i + 1, j)];
				float d11 = spEG.density[IX(i + 1, j + 1)];

				glColor3f(d00, d00, d00); glVertex3f (x, y, 0.0f);
				glColor3f(d10, d10, d10); glVertex3f (x + h, y, 0.0f);
				glColor3f(d11, d11, d11); glVertex3f (x + h, y + h, 0.0f);
				glColor3f(d01, d01, d01); glVertex3f (x, y + h, 0.0f);
			}
		}
	}
	else
	{
#define IX3D(i, j, k) ((i) + (N + 2) * (j) + (N + 2) * (N + 2) * k)
		float h= 1.0f / N;
		float alpha = 0.05f;
		for (int i = 0; i < N; i++)
		{
			float x = i * h - 0.5f;
			for (int j = 0; j < N; j++)
			{
				float y = j * h - 0.5f;
				for (int k = 0; k < N; k++)
				{
					float z = k * h - 0.5f;

					float density000 = spEG.density[IX3D(i, j, k)];
					float density010 = spEG.density[IX3D(i, j + 1, k)];
					float density100 = spEG.density[IX3D(i + 1, j, k)];
					float density110 = spEG.density[IX3D(i + 1, j + 1, k)];

					float density001 = spEG.density[IX3D(i, j, k + 1)];
					float density011 = spEG.density[IX3D(i, j + 1, k + 1)];
					float density101 = spEG.density[IX3D(i + 1, j, k + 1)];
					float density111 = spEG.density[IX3D(i + 1, j + 1, k + 1)];

					glColor4f(density111, density111, density111, alpha);
					glVertex3f(x + h, y + h, z + h);

					glColor4f(density011, density011, density011, alpha);
					glVertex3f(x, y + h, z + h);

					glColor4f(density001, density001, density001, alpha);
					glVertex3f(x, y, z + h);

					glColor4f(density101, density101, density101, alpha);
					glVertex3f(x + h, y, z + h);

					glColor4f(density110, density110, density110, alpha);
					glVertex3f(x + h, y + h, z);

					glColor4f(density111, density111, density111, alpha);
					glVertex3f(x + h, y + h, z + h);

					glColor4f(density101, density101, density101, alpha);
					glVertex3f(x + h, y, z + h);

					glColor4f(density100, density100, density100, alpha);
					glVertex3f(x + h, y, z);

					glColor4f(density010, density010, density010, alpha);
					glVertex3f(x, y + h, z);

					glColor4f(density110, density110, density110, alpha);
					glVertex3f(x + h, y + h, z);

					glColor4f(density100, density100, density100, alpha);
					glVertex3f(x + h, y, z);

					glColor4f(density000, density000, density000, alpha);
					glVertex3f(x, y, z);

					glColor4f(density011, density011, density011, alpha);
					glVertex3f(x, y + h, z + h);

					glColor4f(density010, density010, density010, alpha);
					glVertex3f(x, y + h, z);

					glColor4f(density000, density000, density000, alpha);
					glVertex3f(x, y, z);

					glColor4f(density001, density001, density001, alpha);
					glVertex3f(x, y, z + h);

					glColor4f(density100, density100, density100, alpha);
					glVertex3f(x + h, y, z);

					glColor4f(density000, density000, density000, alpha);
					glVertex3f(x, y, z);

					glColor4f(density001, density001, density001, alpha);
					glVertex3f(x, y, z + h);

					glColor4f(density101, density101, density101, alpha);
					glVertex3f(x+h, y, z + h);

					glColor4f(density110, density110, density110, alpha);
					glVertex3f(x + h, y + h, z);

					glColor4f(density010, density010, density010, alpha);
					glVertex3f(x, y + h, z);

					glColor4f(density011, density011, density011, alpha);
					glVertex3f(x, y + h, z + h);

					glColor4f(density111, density111, density111, alpha);
					glVertex3f(x + h, y + h, z + h);
				}
			}
		}
	}
	glEnd();
	glPopMatrix();

	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);

	glEnable(GL_COLOR_MATERIAL);
	glEnable(GL_LIGHTING);
}
