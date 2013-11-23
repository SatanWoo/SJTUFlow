#include "primitive.h"
#include <math.h>

using namespace SceneUnit;

Primitive::Primitive(void)
{
	center[0] = 0.0; 
	center[1] = 0.0;
	center[2] = 0.0;
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	fill = true;
}

Primitive::~Primitive(void)
{
}

void Primitive::getCenter( GLdouble center[3] )
{
	center[0] = this->center[0];
	center[1] = this->center[1];
	center[2] = this->center[2];
}

QColor Primitive::getColor()
{
	return QColor(this->color[0], 
		this->color[1], this->color[2]);
}

void Primitive::setColor( QColor color )
{
	this->color[0] = color.red();
	this->color[1] = color.green();
	this->color[2] = color.blue();

	emit propertyChanged();
}

Primitive2D::Primitive2D( GLdouble center[2], QColor color, bool fill )
{
	setCenter(center);
	setColor(color);
	setFill(fill);
}

void Primitive2D::setCenter( GLdouble center[2] )
{
	this->center[0] = center[0];
	this->center[1] = center[1];

	emit propertyChanged();
}

Primitive3D::Primitive3D( GLdouble center[3], QColor color )
{
	setCenter(center);
	setColor(color);
}

void Primitive3D::setCenter( GLdouble center[3] )
{
	this->center[0] = center[0];
	this->center[1] = center[1];
	this->center[2] = center[2];

	emit propertyChanged();
}

Circle::Circle( GLdouble center[2], QColor color, 
	GLdouble radius, bool fill )
	: Primitive2D(center, color, fill)
{
	setRadius(radius);
	type = T_Circle;
}

void Circle::draw()
{
	glLoadIdentity();
	glTranslated(center[0], center[1], -1.0);
	glColor3ubv(color);
	if (fill)
	{
		glBegin(GL_TRIANGLE_FAN);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
	}

	double pi = acos(-1.0);
	double d = pi / 180;
	for (double i = 0.0; i < 2 * pi; i += d)
	{
		double x = radius * cos(i);
		double y = radius * sin(i);
		glVertex3d(x, y, 0.0);
	}

	glEnd();
}

Rectangle::Rectangle( GLdouble center[2], QColor color, 
	GLdouble width, GLdouble height, bool fill ) 
	: Primitive2D(center, color, fill)
{
	setWidth(width);
	setHeight(height);
	type = T_Rect;
}

Rectangle::Rectangle( GLdouble center[2], QColor color, 
	GLdouble width, bool fill )
	: Primitive2D(center, color, fill)
{
	setWidth(width);
	setHeight(width);
	type = T_Rect;
}

void Rectangle::draw()
{
	glLoadIdentity();
	glTranslated(center[0] - width / 2, center[1] - height / 2, -1.0);
	glColor3ubv(color);
	if (fill)
	{
		glBegin(GL_QUADS);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
	}

	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(width, 0.0, 0.0);
	glVertex3d(width, height, 0.0);
	glVertex3d(0.0, height, 0.0);

	glEnd();
}

Sphere::Sphere( GLdouble center[3], QColor color, 
	GLdouble radius, GLUquadric *quadric )
	: Primitive3D(center, color)
{
	setRadius(radius);
	this->quadric = quadric;
}

void Sphere::draw()
{
	glLoadIdentity();
	glTranslated(center[0], center[1], center[2]);
	glColor3ubv(color);

	gluSphere(quadric, radius, 32, 32);
}

Box::Box( GLdouble center[3], QColor color, 
	GLdouble lenx, GLdouble leny, GLdouble lenz )
	: Primitive3D(center, color)
{
	setLenX(lenx);
	setLenY(leny);
	setLenZ(lenz);
}

Box::Box( GLdouble center[3], QColor color, 
	GLdouble len )
	: Primitive3D(center, color)
{
	setLenX(len);
	setLenY(len);
	setLenZ(len);
}

void Box::draw()
{
	glLoadIdentity();
	glTranslated(center[0] - lenx / 2, 
		center[1] - leny / 2, 
		center[2] - lenz / 2);
	glColor3ubv(color);

	glBegin(GL_QUADS);

	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, 0.0, lenz);
	glVertex3d(0.0, leny, lenz);
	glVertex3d(0.0, leny, 0.0);

	glVertex3d(0.0, 0.0, lenz);
	glVertex3d(lenx, 0.0, lenz);
	glVertex3d(lenx, leny, lenz);
	glVertex3d(0.0, leny, lenz);

	glVertex3d(lenx, 0.0, lenz);
	glVertex3d(lenx, 0.0, 0.0);
	glVertex3d(lenx, leny, 0.0);
	glVertex3d(lenx, leny, lenz);

	glVertex3d(lenx, 0.0, 0.0);
	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(0.0, leny, 0.0);
	glVertex3d(lenx, leny, 0.0);

	glVertex3d(0.0, leny, 0.0);
	glVertex3d(0.0, leny, lenz);
	glVertex3d(lenx, leny, lenz);
	glVertex3d(lenx, leny, 0.0);

	glVertex3d(0.0, 0.0, 0.0);
	glVertex3d(lenx, 0.0, 0.0);
	glVertex3d(lenx, 0.0, lenz);
	glVertex3d(0.0, 0.0, lenz);

	glEnd();
}
