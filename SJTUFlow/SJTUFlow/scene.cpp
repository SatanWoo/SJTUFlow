#include "scene.h"

#include <QMouseEvent>
#include <GL/glut.h>

#ifndef GL_MULTISAMPLE
#define GL_MULTISAMPLE  0x809D
#endif

Scene::Scene(QWidget *parent)
	: QGLWidget(parent)
{
	rtri = 0;
	rquad = 0;

	circleNum = 0;
	rectangleNum = 0;
	boxNum = 0;
	sphereNum = 0;
}

Scene::~Scene()
{

}

void Scene::initializeGL()
{
	glShadeModel(GL_SMOOTH);							// Enable Smooth Shading
	glClearColor(0.1f, 0.1f, 0.1f, 0.8f);				// Black Background
	glClearDepth(1.0f);									// Depth Buffer Setup
	glEnable(GL_DEPTH_TEST);							// Enables Depth Testing
	glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);	// Really Nice Perspective Calculations

	quadric = gluNewQuadric();
}

void Scene::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear Screen And Depth Buffer
 	
	for (int i = 0; i < primitives.count(); i++)
	{
		primitives.at(i)->draw();
	}
// 	glLoadIdentity();									// Reset The Current Modelview Matrix
// 	glTranslatef(-1.5f,0.0f,-6.0f);						// Move Left 1.5 Units And Into The Screen 6.0
// 	glRotatef(rtri,0.0f,1.0f,0.0f);						// Rotate The Triangle On The Y axis ( NEW )
// 	glBegin(GL_TRIANGLES);								// Start Drawing A Triangle
// 		glColor3f(1.0f,0.0f,0.0f);						// Red
// 		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Front)
// 		glColor3f(0.0f,1.0f,0.0f);						// Green
// 		glVertex3f(-1.0f,-1.0f, 1.0f);					// Left Of Triangle (Front)
// 		glColor3f(0.0f,0.0f,1.0f);						// Blue
// 		glVertex3f( 1.0f,-1.0f, 1.0f);					// Right Of Triangle (Front)
// 
// 		glColor3f(1.0f,0.0f,0.0f);						// Red
// 		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Right)
// 		glColor3f(0.0f,0.0f,1.0f);						// Blue
// 		glVertex3f( 1.0f,-1.0f, 1.0f);					// Left Of Triangle (Right)
// 		glColor3f(0.0f,1.0f,0.0f);						// Green
// 		glVertex3f( 1.0f,-1.0f, -1.0f);					// Right Of Triangle (Right)
// 
// 		glColor3f(1.0f,0.0f,0.0f);						// Red
// 		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Back)
// 		glColor3f(0.0f,1.0f,0.0f);						// Green
// 		glVertex3f( 1.0f,-1.0f, -1.0f);					// Left Of Triangle (Back)
// 		glColor3f(0.0f,0.0f,1.0f);						// Blue
// 		glVertex3f(-1.0f,-1.0f, -1.0f);					// Right Of Triangle (Back)
// 		glColor3f(1.0f,0.0f,0.0f);						// Red
// 
// 		glVertex3f( 0.0f, 1.0f, 0.0f);					// Top Of Triangle (Left)
// 		glColor3f(0.0f,0.0f,1.0f);						// Blue
// 		glVertex3f(-1.0f,-1.0f,-1.0f);					// Left Of Triangle (Left)
// 		glColor3f(0.0f,1.0f,0.0f);						// Green
// 		glVertex3f(-1.0f,-1.0f, 1.0f);					// Right Of Triangle (Left)
// 	glEnd();											// Done Drawing The Pyramid
// 
// 	glLoadIdentity();									// Reset The Current Modelview Matrix
// 	glTranslatef(1.5f,0.0f,-7.0f);						// Move Right 1.5 Units And Into The Screen 7.0
// 	glRotatef(rquad,1.0f,1.0f,1.0f);					// Rotate The Quad On The X axis ( NEW )
// 	glBegin(GL_QUADS);									// Draw A Quad
// 		glColor3f(0.0f,1.0f,0.0f);						// Set The Color To Green
// 		glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right Of The Quad (Top)
// 		glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left Of The Quad (Top)
// 		glVertex3f(-1.0f, 1.0f, 1.0f);					// Bottom Left Of The Quad (Top)
// 		glVertex3f( 1.0f, 1.0f, 1.0f);					// Bottom Right Of The Quad (Top)
// 		glColor3f(1.0f,0.5f,0.0f);						// Set The Color To Orange
// 		glVertex3f( 1.0f,-1.0f, 1.0f);					// Top Right Of The Quad (Bottom)
// 		glVertex3f(-1.0f,-1.0f, 1.0f);					// Top Left Of The Quad (Bottom)
// 		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Bottom)
// 		glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom Right Of The Quad (Bottom)
// 		glColor3f(1.0f,0.0f,0.0f);						// Set The Color To Red
// 		glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Front)
// 		glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Front)
// 		glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom Left Of The Quad (Front)
// 		glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom Right Of The Quad (Front)
// 		glColor3f(1.0f,1.0f,0.0f);						// Set The Color To Yellow
// 		glVertex3f( 1.0f,-1.0f,-1.0f);					// Top Right Of The Quad (Back)
// 		glVertex3f(-1.0f,-1.0f,-1.0f);					// Top Left Of The Quad (Back)
// 		glVertex3f(-1.0f, 1.0f,-1.0f);					// Bottom Left Of The Quad (Back)
// 		glVertex3f( 1.0f, 1.0f,-1.0f);					// Bottom Right Of The Quad (Back)
// 		glColor3f(0.0f,0.0f,1.0f);						// Set The Color To Blue
// 		glVertex3f(-1.0f, 1.0f, 1.0f);					// Top Right Of The Quad (Left)
// 		glVertex3f(-1.0f, 1.0f,-1.0f);					// Top Left Of The Quad (Left)
// 		glVertex3f(-1.0f,-1.0f,-1.0f);					// Bottom Left Of The Quad (Left)
// 		glVertex3f(-1.0f,-1.0f, 1.0f);					// Bottom Right Of The Quad (Left)
// 		glColor3f(1.0f,0.0f,1.0f);						// Set The Color To Violet
// 		glVertex3f( 1.0f, 1.0f,-1.0f);					// Top Right Of The Quad (Right)
// 		glVertex3f( 1.0f, 1.0f, 1.0f);					// Top Left Of The Quad (Right)
// 		glVertex3f( 1.0f,-1.0f, 1.0f);					// Bottom Left Of The Quad (Right)
// 		glVertex3f( 1.0f,-1.0f,-1.0f);					// Bottom Right Of The Quad (Right)
// 	glEnd();											// Done Drawing The Quad
}

void Scene::resizeGL(int width, int height)
{
	if (height == 0)									// Prevent A Divide By Zero By
	{
		height = 1;										// Making Height Equal One
	}

	glViewport(0, 0, width, height);					// Reset The Current Viewport

	glMatrixMode(GL_PROJECTION);						// Select The Projection Matrix
	glLoadIdentity();									// Reset The Projection Matrix

	// Calculate The Aspect Ratio Of The Window
	gluPerspective(45.0f, (GLfloat)width / (GLfloat)height, 1.0f, 1000.0f);

	glMatrixMode(GL_MODELVIEW);							// Select The Modelview Matrix
	glLoadIdentity();									// Reset The Modelview Matrix
}

void Scene::mousePressEvent(QMouseEvent *event)
{
	
}

void Scene::mouseMoveEvent(QMouseEvent *event)
{
	
}

void Scene::timerEvent(QTimerEvent *)
{
	rtri += 0.2f;										// Increase The Rotation Variable For The Triangle ( NEW )
	rquad -= 0.15f;										// Decrease The Rotation Variable For The Quad ( NEW )

	updateGL();
}

void Scene::newCircle()
{
	GLdouble center[2] = {0.2, 0.0};
	GLdouble radius = 0.1;
	QColor color(0, 255, 0);

	SceneUnit::Primitive *p = new SceneUnit::Circle(center, color, radius);
	p->setName(QString("circle_%1").arg(++circleNum));
	p->setId(primitives.count());
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}

void Scene::newRectangle()
{
	GLdouble center[2] = {-0.2, 0.0};
	GLdouble width = 0.1;
	QColor color(255, 0, 0);

	SceneUnit::Primitive *p = new SceneUnit::Rectangle(center, color, width);
	p->setName(QString("rect_%1").arg(++rectangleNum));
	p->setId(primitives.count());
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}

void Scene::newBox()
{
	GLdouble center[3] = {0.0, 0.2, -1.0};
	GLdouble len = 0.1;
	QColor color(0, 255, 255);

	SceneUnit::Primitive *p = new SceneUnit::Box(center, color, len);
	p->setName(QString("box_%1").arg(++boxNum));
	p->setId(primitives.count());
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}

void Scene::newSphere()
{
	GLdouble center[3] = {0.0, -0.2, -1.0};
	GLdouble radius = 0.1;
	QColor color(255, 0, 255);

	SceneUnit::Primitive *p = new SceneUnit::Sphere(center, color, radius, quadric);
	p->setName(QString("sphere_%1").arg(++sphereNum));
	p->setId(primitives.count());
	primitives.append(p);

	connect(p, SIGNAL(propertyChanged()), this, SLOT(updateGL()));

	updateGL();
}
