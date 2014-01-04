#include "primitive.h"
#include <math.h>

using namespace SceneUnit;

Primitive::Primitive()
{
	name = "";
	id = -1;
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

QDomElement Primitive::domElement(QDomDocument &doc)
{
	QDomElement node = doc.createElement(tr("Primitive"));
	node.setAttribute(tr("name"), name);
	node.setAttribute(tr("id"), id);
	node.setAttribute(tr("color"), 
		QColor(color[0], color[1], color[2]).name());
	node.setAttribute(tr("fill"), fill ? tr("true") : tr("false"));
	node.setAttribute(tr("scalar"), scalar);
	node.appendChild(bmin.domElement(tr("bmin"), doc));
	node.appendChild(bmax.domElement(tr("bmax"), doc));
	node.appendChild(frame->domElement(tr("frame"), doc));

	return node;
}

void Primitive::initFromDomElement(const QDomElement &node)
{
	name = node.attribute(tr("name"));
	id = DomUtils::intFromDom(node, tr("id"), -1);
	QColor c = QColor(node.attribute(tr("color"), tr("#ffffff")));
	color[0] = c.red();
	color[1] = c.green();
	color[2] = c.blue();
	fill = DomUtils::boolFromDom(node, tr("fill"), true);
	scalar = DomUtils::doubleFromDom(node, tr("scalar"), 1.0);
	bmin.initFromDOMElement(node.firstChildElement(tr("bmin")));
	bmax.initFromDOMElement(node.firstChildElement(tr("bmax")));
	frame->initFromDOMElement(node.firstChildElement(tr("frame")));
	center = frame->position();
	type = Type(DomUtils::intFromDom(node, tr("type"), -1));
}

void Primitive::setId(int id_)
{
	id = id_;
}

void Primitive::setCenter(qglviewer::Vec center_)
{
	center = center_;
	frame->setPosition(center);

	emit propertyChanged();
}

void Primitive::getBoundingBox(qglviewer::Vec &bmin_, qglviewer::Vec &bmax_)
{
	qglviewer::Vec b[8] = {
		qglviewer::Vec(bmin),
		qglviewer::Vec(bmin[0], bmin[1], bmax[2]),
		qglviewer::Vec(bmin[0], bmax[1], bmin[2]),
		qglviewer::Vec(bmin[0], bmax[1], bmax[2]),
		qglviewer::Vec(bmax[0], bmin[1], bmin[2]),
		qglviewer::Vec(bmax[0], bmin[1], bmax[2]),
		qglviewer::Vec(bmax[0], bmax[1], bmin[2]),
		qglviewer::Vec(bmax)
	};
	bmin_ = b[0];
	bmax_ = b[0];
	for (int i = 1; i < 8; i++)
	{
		b[i] = frame->rotation().rotate(b[i]);
		bmin_[0] = bmin_[0] < b[i][0] ? bmin_[0] : b[i][0];
		bmin_[1] = bmin_[1] < b[i][1] ? bmin_[1] : b[i][1];
		bmin_[2] = bmin_[2] < b[i][2] ? bmin_[2] : b[i][2];
		bmax_[0] = bmax_[0] > b[i][0] ? bmax_[0] : b[i][0];
		bmax_[1] = bmax_[1] > b[i][1] ? bmax_[1] : b[i][1];
		bmax_[2] = bmax_[2] > b[i][2] ? bmax_[2] : b[i][2];
	}
	bmin_ = scalar * bmin_; 
	bmax_ = scalar * bmax_;
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

void Primitive::setName(QString name_)
{
	name = name_;
}

void Primitive::setFill(bool fill_)
{
	fill = fill_; 
	emit propertyChanged();
}

void Primitive::setColor(QColor color_)
{
	color[0] = color_.red();
	color[1] = color_.green();
	color[2] = color_.blue();

	emit propertyChanged();
}

void Primitive::setCenterX(double val)
{ 
	center[0] = val; 
	frame->setPosition(center); 

	emit propertyChanged(); 
}

void Primitive::setCenterY(double val)
{ 
	center[1] = val; 
	frame->setPosition(center); 

	emit propertyChanged(); 
}

void Primitive::setCenterZ(double val)
{ 
	center[2] = val; 
	frame->setPosition(center);

	emit propertyChanged(); 
}

void Primitive::setScalar(double val)
{ 
	scalar = val; 
	emit propertyChanged(); 
	emit operated(); 
}

Circle::Circle() : Primitive()
{
	setRadius(0.1);
    type = T_Circle;
}

Circle::Circle(qglviewer::Vec center, QColor color, 
	GLdouble radius, bool fill) : Primitive()
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

QDomElement Circle::domElement(QDomDocument &doc)
{
	QDomElement node = Primitive::domElement(doc);
	node.setAttribute(tr("type"), type);
	node.setAttribute(tr("radius"), radius);
	return node;
}

void Circle::initFromDomElement(const QDomElement &node)
{
	Primitive::initFromDomElement(node);
	radius = DomUtils::doubleFromDom(node, tr("radius"), 0.1);
}

void Circle::setRadius(GLdouble radius_)
{
	radius = radius_; 
	bmax = radius * qglviewer::Vec(1.0, 1.0, 0.0);
	bmin = -bmax;

	emit propertyChanged();
}

Sphere::Sphere(GLUquadric *quadric_, int slice_, int stack_) : Circle()
{
	setRadius(radius);
    type = T_Sphere;
    quadric = quadric_;
	slices = slice_;
	stacks = stack_;
}

Sphere::Sphere(qglviewer::Vec center, QColor color,
	GLdouble radius, GLUquadric *quadric_, int slice_, int stack_, bool fill) : Circle()
{
	setCenter(center);
	setColor(color);
	setRadius(radius);
	setFill(fill);
	quadric = quadric_;
	slices = slice_;
	stacks = stack_;
	type = T_Sphere;
}

void Sphere::draw(bool selected)
{
	double radius = scalar * this->radius;

	Primitive::draw(selected);

	gluSphere(quadric, radius, slices, stacks);

	if (!fill)
	{
		glEnable(GL_LIGHTING);
	}
}

QDomElement Sphere::domElement(QDomDocument &doc)
{
	QDomElement node = Circle::domElement(doc);
	node.setAttribute(tr("type"), type);
	return node;
}

void Sphere::setRadius(GLdouble radius_)
{
	radius = radius_; 
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

Rectangle::Rectangle(qglviewer::Vec center, QColor color, 
	GLdouble lenx, GLdouble leny, bool fill ) : Primitive()
{
	center[2] = 0.0;
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setFill(fill);
	type = T_Rect;
}

Rectangle::Rectangle(qglviewer::Vec center, QColor color, 
	GLdouble lenx, bool fill ) : Primitive()
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

QDomElement Rectangle::domElement(QDomDocument &doc)
{
	QDomElement node = Primitive::domElement(doc);
	node.setAttribute(tr("type"), type);
	QDomElement subNode = doc.createElement(tr("size"));
	subNode.setAttribute(tr("x"), lenx);
	subNode.setAttribute(tr("y"), leny);
	node.appendChild(subNode);
	return node;
}

void Rectangle::initFromDomElement(const QDomElement &node)
{
	Primitive::initFromDomElement(node);
	QDomElement s = node.firstChildElement(tr("size"));
	lenx = DomUtils::doubleFromDom(s, tr("x"), 0.2);
	leny = DomUtils::doubleFromDom(s, tr("y"), 0.2);
}

void Rectangle::setLenX(GLdouble lenx_)
{ 
	lenx = lenx_; 
	bmin[0] = -lenx / 2; 
	bmax[0] = -bmin[0]; 

	emit propertyChanged(); 
}

void Rectangle::setLenY(GLdouble leny_)
{ 
	leny = leny_; 
	bmin[1] = -leny / 2; 
	bmax[1] = -bmin[1];
	
	emit propertyChanged(); 
}

Box::Box() : Rectangle()
{
    setLenZ(0.2);
    type = T_Box;
}

Box::Box(qglviewer::Vec center, QColor color, GLdouble lenx, 
	GLdouble leny, GLdouble lenz, bool fill) : Rectangle()
{
	setCenter(center);
	setColor(color);
	setLenX(lenx);
	setLenY(leny);
	setLenZ(lenz);
	setFill(fill);
	type = T_Box;
}

Box::Box(qglviewer::Vec center, QColor color, 
	GLdouble len, bool fill ) : Rectangle()
{
	setCenter(center);
	setColor(color);
	setLenX(len);
	setLenY(len);
	setLenZ(len);
	setFill(fill);
	type = T_Box;
}

void Box::setLenZ(GLdouble lenz_)
{
	lenz = lenz_; 
	bmin[2] = -lenz / 2; 
	bmax[2] = -bmin[2]; 

	emit propertyChanged();
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

QDomElement Box::domElement(QDomDocument &doc)
{
	QDomElement node = Rectangle::domElement(doc);
	node.setAttribute(tr("type"), type);
	QDomElement sizeNode = node.firstChildElement(tr("size"));
	sizeNode.setAttribute(tr("z"), lenz);
	node.replaceChild(sizeNode, node.firstChildElement(tr("size")));
	return node;
}

void Box::initFromDomElement(const QDomElement &node)
{
	Primitive::initFromDomElement(node);
	QDomElement s = node.firstChildElement(tr("size"));
	lenx = DomUtils::doubleFromDom(s, tr("x"), 0.2);
	leny = DomUtils::doubleFromDom(s, tr("y"), 0.2);
	lenz = DomUtils::doubleFromDom(s, tr("z"), 0.2);
}

Object::Object() : Primitive()
{
	type = T_Object;
}

void Object::draw(bool selected)
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

QDomElement Object::domElement(QDomDocument &doc)
{
	QDomElement node = Primitive::domElement(doc);
	node.setAttribute(tr("type"), type);
	node.setAttribute(tr("path"), pathname);
	return node;
}

void Object::initFromDomElement(const QDomElement &node)
{
	Primitive::initFromDomElement(node);
}

void Object::adjust()
{
	for (int i = 0; i < vertexs.count(); i++)
	{
		vertexs[i] = vertexs[i] -  center;
	}
	center = qglviewer::Vec(0, 0, 0);
}

void Object::addVertex(qglviewer::Vec v)
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

Object::Group *Object::addGroup(Object::Group g)
{
	groups.append(g);
	return &groups[groups.count() - 1];
}
