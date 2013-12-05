#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <QtGlobal>

#ifdef Q_OS_MAC
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <QString>
#include <QObject>
#include <QColor>
#include <QVector>
#include <QVector2D>
#include <QVector3D>

#include <qglviewer.h>

namespace SceneUnit
{
#define QVec3DToVec(v) qglviewer::Vec(v.x(), v.y(), v.z())

	class Primitive : public QObject
	{
		Q_OBJECT

	public:
		Primitive(void);
		~Primitive(void);

		enum Type{T_Rect, T_Circle, T_Box, T_Sphere, T_Object};

		virtual void draw(bool selected);

		Type getType(){ return type; }
		GLuint getId(){ return id; }
		void setId(int id){ this->id = id; }
		QString getName(){ return name; }

		qglviewer::Vec getCenter(){ return center; }
		void setCenter(qglviewer::Vec center);
		QColor getColor();
		bool isFilled(){ return fill; }

		void translate(qglviewer::Vec t, int axis);

	signals:
		void propertyChanged();
		void operated();

	public slots:
		void setName(QString name){ this->name = name; }
		void setFill(bool fill){ this->fill = fill; emit propertyChanged(); }
		void setColor(QColor color);
		void setCenterX(QString str){ center[0] = str.toDouble(); frame->setPosition(center); emit propertyChanged(); }
		void setCenterY(QString str){ center[1] = str.toDouble(); frame->setPosition(center); emit propertyChanged(); }
		void setCenterZ(QString str){ center[2] = str.toDouble(); frame->setPosition(center); emit propertyChanged(); }
		virtual void setRadius(QString){};
		virtual void setLenX(QString){};
		virtual void setLenY(QString){};
		virtual void setLenZ(QString){};

	protected:
		Type type;
		GLuint id;
		QString name;

		qglviewer::Vec center;
		GLubyte color[3];
		bool fill;

		qglviewer::Frame *frame;
	};

	class Circle : public Primitive
	{
		Q_OBJECT

	public:
        Circle();
		Circle(qglviewer::Vec center, QColor color, 
			GLdouble radius, bool fill = true);

		virtual void draw(bool selected);
		GLdouble getRadius(){ return radius; }
		void setRadius(GLdouble radius){ this->radius = radius; emit propertyChanged(); }

	public slots:
		void setRadius(QString str){ setRadius(str.toDouble()); }

	protected:
		GLdouble radius;
	};

	class Sphere : public Circle
	{
		Q_OBJECT

	public:
        Sphere(GLUquadric *quadric);
		Sphere(qglviewer::Vec center, QColor color, 
			GLdouble radius, GLUquadric *quadric);

		void draw(bool selected);

	private:
		GLUquadric *quadric;
	};

	class Rectangle : public Primitive
	{
		Q_OBJECT

	public:
        Rectangle();
		Rectangle(qglviewer::Vec center, QColor color, 
			GLdouble lenx, GLdouble leny, bool fill = true);
		Rectangle(qglviewer::Vec center, QColor color, 
			GLdouble lenx, bool fill = true);

		virtual void draw(bool selected);
		GLdouble getLenX(){ return lenx; }
		void setLenX(GLdouble lenx){ this->lenx = lenx; emit propertyChanged(); }
		GLdouble getLenY(){ return leny; }
		void setLenY(GLdouble leny){ this->leny = leny; emit propertyChanged(); }

	public slots:
		void setLenX(QString str){ setLenX(str.toDouble()); }
		void setLenY(QString str){ setLenY(str.toDouble()); }

	protected:
		GLdouble lenx;
		GLdouble leny;
	};

	class Box : public Rectangle
	{
		Q_OBJECT

	public:
        Box();
		Box(qglviewer::Vec center, QColor color, 
			GLdouble lenx, GLdouble leny, GLdouble lenz);
		Box(qglviewer::Vec center, QColor color, GLdouble len);

		void draw(bool selected);
		GLdouble getLenZ(){ return lenz; }
		void setLenZ(GLdouble lenz){ this->lenz = lenz; emit propertyChanged(); }

	public slots:
		void setLenZ(QString str){ setLenZ(str.toDouble()); }

	private:
		GLdouble lenz;
	};

	class Object : public Primitive
	{
		Q_OBJECT

	public:
		struct TriangleFace
		{
			GLuint v[3]; // vertex indices
			GLuint t[3]; // texture indices
			GLuint n[3]; // normal indices
			bool hasT;
			bool hasN;
		};
		struct Group
		{
			QString name;
			QVector<GLuint> tIndices;
		};

		Object() : Primitive(){ type = T_Object; }

		void draw(bool selected);
		void adjust();	// adjust the coordinate to the relative coordinate to center

		QString pathName(){ return pathname; }
		void setPathName(QString path){ pathname = path; }
		QString mtlLibName(){ return mtllibname; }
		void setMtlLibName(QString name){ mtllibname = name; }
		void addVertex(qglviewer::Vec v);
		void addNormal(qglviewer::Vec n){ normals.append(n); }
		void addTexture(QVector2D t){ textures.append(t); }
		void addFace(TriangleFace f){ faces.append(f); }
		int facesNum(){ return faces.count(); }
		Group *addGroup(Group g);

	private:
		QString pathname;
		QString mtllibname;
		QVector<qglviewer::Vec> vertexs;
		QVector<qglviewer::Vec> normals;
		QVector<QVector2D> textures;
		QVector<TriangleFace> faces;
		QVector<Group> groups;
	};
};

#endif
