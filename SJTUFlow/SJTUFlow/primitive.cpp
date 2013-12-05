#include "primitive.h"
#include <math.h>

using namespace SceneUnit;

Primitive::Primitive(void)
{
	center = qglviewer::Vec(0, 0, 0);
	color[0] = 255;
	color[1] = 255;
	color[2] = 255;
	fill = true;

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
	glEnable(GL_LIGHTING);

	glEnd();
}

Sphere::Sphere(GLUquadric *quadric) : Circle()
{
    type = T_Sphere;
    this->quadric = quadric;
}

Sphere::Sphere( qglviewer::Vec center, QColor color,
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
	glDisable(GL_LIGHTING);

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

	glEnable(GL_LIGHTING);
}

Box::Box() : Rectangle()
{
    lenz = 0.2;
    type = T_Box;
}

Box::Box( qglviewer::Vec center, QColor color,
	GLdouble lenx, GLdouble leny, GLdouble lenz )
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setLenZ(lenz);
	type = T_Box;
}

Box::Box( qglviewer::Vec center, QColor color, GLdouble len )
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
					qglviewer::Vec normal = normals[face.n[i]];
					glNormal3dv(normal);
				}
				qglviewer::Vec vertex = vertexs[face.v[i]];
				glVertex3dv(vertex);
			}
		}
		glEnd();
    }
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
}

Object::Group *Object::addGroup( Object::Group g )
{
	groups.append(g);
	return &groups[groups.count() - 1];
}
