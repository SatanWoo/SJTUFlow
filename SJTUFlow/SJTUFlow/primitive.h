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

namespace SceneUnit
{
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

		QVector3D getCenter(){ return center; }
		virtual void setCenter(QVector3D center);
		QColor getColor();
		bool isFilled(){ return fill; }

	signals:
		void propertyChanged();

	public slots:
		void setName(QString name){ this->name = name; }
		void setFill(bool fill){ this->fill = fill; emit propertyChanged(); }
		void setColor(QColor color);
		void setCenterX(QString str){ center.setX(str.toFloat()); emit propertyChanged(); }
		void setCenterY(QString str){ center.setY(str.toFloat()); emit propertyChanged(); }
		void setCenterZ(QString str){ center.setZ(str.toFloat()); emit propertyChanged(); }
		virtual void setRadius(QString){};
		virtual void setLenX(QString){};
		virtual void setLenY(QString){};
		virtual void setLenZ(QString){};

	protected:
		Type type;
		GLuint id;
		QString name;

		QVector3D center;
		GLubyte color[3];
		bool fill;
	};

	class Circle : public Primitive
	{
		Q_OBJECT

	public:
        Circle();
		Circle(QVector2D center, QColor color, 
			GLdouble radius, bool fill = true);

		virtual void draw(bool selected);
		virtual void setCenter(QVector2D center);
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
		Sphere(QVector3D center, QColor color, 
			GLdouble radius, GLUquadric *quadric);

		void draw(bool selected);
		void setCenter(QVector3D center){ Primitive::setCenter(center); }

	private:
		GLUquadric *quadric;
	};

	class Rectangle : public Primitive
	{
		Q_OBJECT

	public:
        Rectangle();
		Rectangle(QVector2D center, QColor color, 
			GLdouble lenx, GLdouble leny, bool fill = true);
		Rectangle(QVector2D center, QColor color, 
			GLdouble lenx, bool fill = true);

		virtual void draw(bool selected);
		virtual void setCenter(QVector2D center);
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
		Box(QVector3D center, QColor color, 
			GLdouble lenx, GLdouble leny, GLdouble lenz);
		Box(QVector3D center, QColor color, GLdouble len);

		void draw(bool selected);
		void setCenter(QVector3D center){ Primitive::setCenter(center); }
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
		void addVertex(QVector3D v);
		void addNormal(QVector3D n){ normals.append(n); }
		void addTexture(QVector2D t){ textures.append(t); }
		void addFace(TriangleFace f){ faces.append(f); }
		int facesNum(){ return faces.count(); }
		Group *addGroup(Group g);

	private:
		QString pathname;
		QString mtllibname;
		QVector<QVector3D> vertexs;
		QVector<QVector3D> normals;
		QVector<QVector2D> textures;
		QVector<TriangleFace> faces;
		QVector<Group> groups;
	};
};

#endif
