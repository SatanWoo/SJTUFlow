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

void Primitive::setCenter( GLdouble center[3] )
{
	this->center[0] = center[0];
	this->center[1] = center[1];
	this->center[2] = center[2];

	emit propertyChanged();
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

Circle::Circle( GLdouble center[2], QColor color, 
	GLdouble radius, bool fill )
{
	setCenter(center);
	setColor(color);
	setRadius(radius);
	setFill(fill);
	type = T_Circle;
}

void Circle::draw(GLuint id)
{
	glTranslated(center[0], center[1], 0.0);
	if (this->id == id)
	{
		glColor4ub(color[0], color[1], color[2], 128);
	}
	else
	{
		glColor3ubv(color);
	}
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

void Circle::setCenter( GLdouble center[2] )
{
	this->center[0] = center[0];
	this->center[1] = center[1];

	emit propertyChanged();
}

Sphere::Sphere( GLdouble center[3], QColor color, 
	GLdouble radius, GLUquadric *quadric )
{
	setCenter(center);
	setColor(color);
	setRadius(radius);
	this->quadric = quadric;
	type = T_Sphere;
}

void Sphere::draw(GLuint id)
{
	glTranslated(center[0], center[1], center[2]);
	if (this->id == id)
	{
		glColor4ub(color[0], color[1], color[2], 128);
	}
	else
	{
		glColor3ubv(color);
	}

	gluSphere(quadric, radius, 32, 32);
}

Rectangle::Rectangle( GLdouble center[2], QColor color, 
	GLdouble lenx, GLdouble leny, bool fill )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setFill(fill);
	type = T_Rect;
}

Rectangle::Rectangle( GLdouble center[2], QColor color, 
	GLdouble lenx, bool fill )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(lenx);
	setFill(fill);
	type = T_Rect;
}

void Rectangle::draw(GLuint id)
{
	glTranslated(center[0], center[1], 0.0);
	if (this->id == id)
	{
		glColor4ub(color[0], color[1], color[2], 128);
	}
	else
	{
		glColor3ubv(color);
	}
	if (fill)
	{
		glBegin(GL_QUADS);
	}
	else
	{
		glBegin(GL_LINE_LOOP);
	}

	glVertex3d(-lenx / 2, -leny / 2, 0.0);
	glVertex3d(lenx / 2, -leny / 2, 0.0);
	glVertex3d(lenx / 2, leny / 2, 0.0);
	glVertex3d(-lenx / 2, leny / 2, 0.0);

	glEnd();
}

void Rectangle::setCenter( GLdouble center[2] )
{
	this->center[0] = center[0];
	this->center[1] = center[1];

	emit propertyChanged();
}

Box::Box( GLdouble center[3], QColor color, 
	GLdouble lenx, GLdouble leny, GLdouble lenz )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setLenZ(lenz);
	type = T_Box;
}

Box::Box( GLdouble center[3], QColor color, 
	GLdouble len )
{
	setCenter(center);
	setColor(color);
	setLenX(len);
	setLenY(len);
	setLenZ(len);
	type = T_Box;
}

void Box::draw(GLuint id)
{
	glTranslated(center[0], center[1], center[2]);
	if (this->id == id)
	{
		glColor4ub(color[0], color[1], color[2], 128);
	}
	else
	{
		glColor3ubv(color);
	}

	glBegin(GL_QUADS);

	glVertex3d(-lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, -lenz / 2);

	glVertex3d(-lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(lenx / 2, leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, lenz / 2);

	glVertex3d(lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, leny / 2, lenz / 2);

	glVertex3d(lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, leny / 2, -lenz / 2);

	glVertex3d(-lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, lenz / 2);
	glVertex3d(lenx / 2, leny / 2, lenz / 2);
	glVertex3d(lenx / 2, leny / 2, -lenz / 2);

	glVertex3d(-lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, lenz / 2);

	glEnd();
}