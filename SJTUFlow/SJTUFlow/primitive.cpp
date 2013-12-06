#include "primitive.h"
#include <math.h>

using namespace SceneUnit;

Primitive::Primitive(void)
{
	center = qglviewer::Vec(0, 0, 0);
	bmin = qglviewer::Vec(0, 0, 0);
	bmax = qglviewer::Vec(0, 0, 0);
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	fill = true;
	scalar = 1.0;

	frame = new qglviewer::Frame(center, qglviewer::Quaternion());
}

Primitive::~Primitive(void)
{
}

void Primitive::draw(bool selected)
{
	glMultMatrixd(frame->matrix());
	if (selected)
	{
		glColor3ub(200, 200, 200);
	}
	else
	{
		glColor3ubv(color);
	}

	if (fill)
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else
	{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glDisable(GL_LIGHTING);
	}
}

void Primitive::setCenter( qglviewer::Vec center )
{
	this->center = center;

	emit propertyChanged();
}

QColor Primitive::getColor()
{
	return QColor(this->color[0], 
            this->color[1], this->color[2]);
}

void Primitive::translate(qglviewer::Vec t, int axis)
{
	qglviewer::Vec tmp;
	tmp[axis] = t[axis];
    frame->translate(tmp);
    center = frame->position();

	emit operated();
}

void Primitive::rotate(double angle, qglviewer::Vec axis)
{
	frame->rotate(qglviewer::Quaternion(axis, angle));

	emit operated();
}

void Primitive::setColor( QColor color )
{
	this->color[0] = color.red();
	this->color[1] = color.green();
	this->color[2] = color.blue();

	emit propertyChanged();
}

Circle::Circle() : Primitive()
{
	setRadius(0.1);
    type = T_Circle;
}

Circle::Circle( qglviewer::Vec center, QColor color,
	GLdouble radius, bool fill )
{
	center[2] = 0.0;
	setCenter(center);
	setColor(color);
	setRadius(radius);
	setFill(fill);
	type = T_Circle;
}

void Circle::draw(bool selected)
{
	double radius = scalar * this->radius;

	glDisable(GL_LIGHTING);
	Primitive::draw(selected);

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
		glVertex3d(x, y, center[2]);
	}

	glEnd();

	glEnable(GL_LIGHTING);
}

void Circle::setRadius( GLdouble radius )
{
	this->radius = radius; 
	bmax = radius * qglviewer::Vec(1.0, 1.0, 0.0);
	bmin = -bmax;
	emit propertyChanged();
}

Sphere::Sphere(GLUquadric *quadric) : Circle()
{
	setRadius(radius);
    type = T_Sphere;
    this->quadric = quadric;
}

Sphere::Sphere( qglviewer::Vec center, QColor color,
	GLdouble radius, GLUquadric *quadric, bool fill )
{
	setCenter(center);
	setColor(color);
	setRadius(radius);
	setFill(fill);
	this->quadric = quadric;
	type = T_Sphere;
}

void Sphere::draw(bool selected)
{
	double radius = scalar * this->radius;

	Primitive::draw(selected);

	gluSphere(quadric, radius, 32, 32);

	if (!fill)
	{
		glEnable(GL_LIGHTING);
	}
}

void Sphere::setRadius( GLdouble radius )
{
	this->radius = radius; 
	bmax = radius * qglviewer::Vec(1.0, 1.0, 1.0);
	bmin = -bmax;
	emit propertyChanged();
}

Rectangle::Rectangle() : Primitive()
{
	setLenX(0.2);
	setLenY(0.2);
    type = T_Rect;
}

Rectangle::Rectangle( qglviewer::Vec center, QColor color,
	GLdouble lenx, GLdouble leny, bool fill )
{
	center[2] = 0.0;
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setFill(fill);
	type = T_Rect;
}

Rectangle::Rectangle( qglviewer::Vec center, QColor color, 
	GLdouble lenx, bool fill )
{
	center[2] = 0.0;
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(lenx);
	setFill(fill);
	type = T_Rect;
}

void Rectangle::draw(bool selected)
{
	double lenx = scalar * this->lenx;
	double leny = scalar * this->leny;

	glDisable(GL_LIGHTING);

	Primitive::draw(selected);

	glBegin(GL_QUADS);

	glVertex3d(-lenx / 2, -leny / 2, 0.0);
	glVertex3d(lenx / 2, -leny / 2, 0.0);
	glVertex3d(lenx / 2, leny / 2, 0.0);
	glVertex3d(-lenx / 2, leny / 2, 0.0);

	glEnd();

	glEnable(GL_LIGHTING);
}

Box::Box() : Rectangle()
{
    setLenZ(0.2);
    type = T_Box;
}

Box::Box( qglviewer::Vec center, QColor color,
	GLdouble lenx, GLdouble leny, GLdouble lenz, bool fill )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setLenZ(lenz);
	setFill(fill);
	type = T_Box;
}

Box::Box( qglviewer::Vec center, QColor color, GLdouble len, bool fill )
{
	setCenter(center);
	setColor(color);
	setLenX(len);
	setLenY(len);
	setLenZ(len);
	setFill(fill);
	type = T_Box;
}

void Box::draw(bool selected)
{
	double lenx = scalar * this->lenx;
	double leny = scalar * this->leny;
	double lenz = scalar * this->lenz;

	Primitive::draw(selected);

	glBegin(GL_QUADS);

	glVertex3d(lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, lenz / 2);
	glVertex3d(lenx / 2, leny / 2, lenz / 2);

	glVertex3d(lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, -lenz / 2);

	glVertex3d(lenx / 2, leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, lenz / 2);

	glVertex3d(lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, leny / 2, -lenz / 2);

	glVertex3d(-lenx / 2, leny / 2, lenz / 2);
	glVertex3d(-lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, -lenz / 2);
	glVertex3d(-lenx / 2, -leny / 2, lenz / 2);

	glVertex3d(lenx / 2, leny / 2, -lenz / 2);
	glVertex3d(lenx / 2, leny / 2, lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, lenz / 2);
	glVertex3d(lenx / 2, -leny / 2, -lenz / 2);

	glEnd();

	if (!fill)
	{
		glEnable(GL_LIGHTING);
	}
}

void Object::draw( bool selected )
{
	Primitive::draw(selected);

	for (int gn = 0; gn < groups.count(); gn++)
	{
		glBegin(GL_TRIANGLES);
		for (int tn = 0; tn < groups[gn].tIndices.count(); tn++)
		{
			TriangleFace face = faces[groups[gn].tIndices[tn]];

			for (int i = 0; i < 3; i++)
			{
				if (face.hasN)
				{
					qglviewer::Vec normal = normals[face.n[i]];
					glNormal3dv(normal);
				}
				qglviewer::Vec vertex = scalar * vertexs[face.v[i]];
				glVertex3dv(vertex);
			}
		}
		glEnd();
    }

	glEnable(GL_LIGHTING);
}

void Object::adjust()
{
	for (int i = 0; i < vertexs.count(); i++)
	{
		vertexs[i] = vertexs[i] -  center;
	}
	center = qglviewer::Vec(0, 0, 0);
}

void Object::addVertex( qglviewer::Vec v )
{
	center *= vertexs.count();

	vertexs.append(v);

	center += v;
	center /= vertexs.count();

	bmin[0] = bmin[0] > v[0] ? v[0] : bmin[0];
	bmin[1] = bmin[1] > v[1] ? v[1] : bmin[1];
	bmin[2] = bmin[2] > v[2] ? v[2] : bmin[2];
	bmax[0] = bmax[0] < v[0] ? v[0] : bmax[0];
	bmax[1] = bmax[1] < v[1] ? v[1] : bmax[1];
	bmax[2] = bmax[2] < v[2] ? v[2] : bmax[2];
}

Object::Group *Object::addGroup( Object::Group g )
{
	groups.append(g);
	return &groups[groups.count() - 1];
}
