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
		void getBoundingBox(qglviewer::Vec &bmin_, qglviewer::Vec &bmax_){ bmin_ = scalar * bmin; bmax_ = scalar * bmax; }
		QColor getColor();
		bool isFilled(){ return fill; }
		double getScalar(){ return scalar; }

		void translate(qglviewer::Vec t, int axis);
		void rotate(double angle, qglviewer::Vec axis);

	signals:
		void propertyChanged();
		void operated();

	public slots:
		void setName(QString name){ this->name = name; }
		void setFill(bool fill){ this->fill = fill; emit propertyChanged(); }
		void setColor(QColor color);
        void setCenterX(double val){ center[0] = val; frame->setPosition(center); emit propertyChanged(); }
        void setCenterY(double val){ center[1] = val; frame->setPosition(center); emit propertyChanged(); }
        void setCenterZ(double val){ center[2] = val; frame->setPosition(center); emit propertyChanged(); }
        void setScalar(double val){ scalar = val; emit propertyChanged(); emit operated(); }
        virtual void setRadius(double){}
        virtual void setLenX(double){}
        virtual void setLenY(double){}
        virtual void setLenZ(double){}

	protected:
		Type type;
		GLuint id;
		QString name;

		qglviewer::Vec center;			// barycenter
		qglviewer::Vec bmin, bmax;		// bounding box for scale
		GLubyte color[3];				// color
		bool fill;						// wire or face
		double scalar;

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

	public slots:
        virtual void setRadius(GLdouble radius);

	protected:
		GLdouble radius;
	};

	class Sphere : public Circle
	{
		Q_OBJECT

	public:
        Sphere(GLUquadric *quadric);
		Sphere(qglviewer::Vec center, QColor color, 
			GLdouble radius, GLUquadric *quadric, bool fill = true);

		void draw(bool selected);

    public slots:
		void setRadius(GLdouble radius);

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
		GLdouble getLenY(){ return leny; }

	public slots:
        void setLenX(GLdouble lenx){ this->lenx = lenx; bmin[0] = -lenx / 2; bmax[0] = -bmin[0]; emit propertyChanged(); }
        void setLenY(GLdouble leny){ this->leny = leny; bmin[1] = -leny / 2; bmax[1] = -bmin[0]; emit propertyChanged(); }

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
			GLdouble lenx, GLdouble leny, GLdouble lenz, bool fill = true);
		Box(qglviewer::Vec center, QColor color, GLdouble len, bool fill = true);

		void draw(bool selected);
		GLdouble getLenZ(){ return lenz; }

	public slots:
        void setLenZ(GLdouble lenz){ this->lenz = lenz; bmin[2] = -lenz / 2; bmax[2] = -bmin[2]; emit propertyChanged(); }

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
