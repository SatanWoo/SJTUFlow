#include "primitive.h"
#include <math.h>

using namespace SceneUnit;

Primitive::Primitive(void)
{
	center = QVector3D(0, 0, 0);
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	fill = true;
}

Primitive::~Primitive(void)
{
}

void Primitive::draw(bool selected)
{
	glTranslatef(center.x(), center.y(), center.z());
	if (selected)
	{
		glColor3ub(200, 200, 200);
	}
	else
	{
		glColor3ubv(color);
	}
}

void Primitive::setCenter( QVector3D center )
{
	this->center = center;

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

Circle::Circle() : Primitive()
{
    radius = 0.1;
    type = T_Circle;
}

Circle::Circle( QVector2D center, QColor color,
	GLdouble radius, bool fill )
{
	setCenter(center);
	setColor(color);
	setRadius(radius);
	setFill(fill);
	type = T_Circle;
}

void Circle::draw(bool selected)
{
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
		glVertex3d(x, y, center.z());
	}

	glEnd();
}

void Circle::setCenter( QVector2D center )
{
	this->center = center.toVector3D();

	emit propertyChanged();
}

Sphere::Sphere(GLUquadric *quadric) : Circle()
{
    type = T_Sphere;
    this->quadric = quadric;
}

Sphere::Sphere( QVector3D center, QColor color,
	GLdouble radius, GLUquadric *quadric )
{
	setCenter(center);
	setColor(color);
	setRadius(radius);
	this->quadric = quadric;
	type = T_Sphere;
}

void Sphere::draw(bool selected)
{
	Primitive::draw(selected);

	gluSphere(quadric, radius, 32, 32);
}

Rectangle::Rectangle() : Primitive()
{
    lenx = 0.2;
    leny = 0.2;
    type = T_Rect;
}

Rectangle::Rectangle( QVector2D center, QColor color,
	GLdouble lenx, GLdouble leny, bool fill )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setFill(fill);
	type = T_Rect;
}

Rectangle::Rectangle( QVector2D center, QColor color, 
	GLdouble lenx, bool fill )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(lenx);
	setFill(fill);
	type = T_Rect;
}

void Rectangle::draw(bool selected)
{
	Primitive::draw(selected);

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

void Rectangle::setCenter( QVector2D center )
{
	this->center = center.toVector3D();

	emit propertyChanged();
}

Box::Box() : Rectangle()
{
    lenz = 0.2;
    type = T_Box;
}

Box::Box( QVector3D center, QColor color,
	GLdouble lenx, GLdouble leny, GLdouble lenz )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setLenZ(lenz);
	type = T_Box;
}

Box::Box( QVector3D center, QColor color, GLdouble len )
{
	setCenter(center);
	setColor(color);
	setLenX(len);
	setLenY(len);
	setLenZ(len);
	type = T_Box;
}

void Box::draw(bool selected)
{
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
}

void SceneUnit::Object::draw( bool selected )
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
					QVector3D normal = normals[face.n[i]];
					glNormal3f(normal.x(), normal.y(), normal.z());
				}
				QVector3D vertex = vertexs[face.v[i]];
				glVertex3f(vertex.x(), vertex.y(), vertex.z());
			}
		}
		glEnd();
    }
}

void Object::adjust()
{
	for (int i = 0; i < vertexs.count(); i++)
	{
		vertexs[i] -= center;
	}
	center = QVector3D(0, 0, 0);
}

void Object::addVertex( QVector3D v )
{
	center *= vertexs.count();

	vertexs.append(v);

	center += v;
	center /= vertexs.count();
}

Object::Group *Object::addGroup( Object::Group g )
{
	groups.append(g);
	return &groups[groups.count() - 1];
}
