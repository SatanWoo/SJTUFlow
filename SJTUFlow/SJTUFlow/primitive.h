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
#include <QDomDocument>

#include <qglviewer.h>
#include <domUtils.h>

namespace SceneUnit
{
	class Primitive : public QObject
	{
		Q_OBJECT

	public:
		Primitive();
		~Primitive(){}

		enum Type{T_Rect = 0, T_Circle, T_Box, T_Sphere, T_Object};

		virtual void draw(bool selected);
		
		virtual QDomElement domElement(QDomDocument &doc);
		virtual void initFromDomElement(const QDomElement &node);

		Type getType(){ return type; }
		GLuint getId(){ return id; }
		void setId(int id_);
		QString getName(){ return name; }

		qglviewer::Vec getCenter(){ return center; }
		void setCenter(qglviewer::Vec center_);
		void getBoundingBox(qglviewer::Vec &bmin_, qglviewer::Vec &bmax_);
		QColor getColor();
		bool isFilled(){ return fill; }
		double getScalar(){ return scalar; }

		void translate(qglviewer::Vec t, int axis);
		void rotate(double angle, qglviewer::Vec axis);

	signals:
		void propertyChanged();
		void operated();

	public slots:
		void setName(QString name_);
		void setFill(bool fill_);
		void setColor(QColor color_);
        void setCenterX(double val);
        void setCenterY(double val);
        void setCenterZ(double val);
        void setScalar(double val);
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
		virtual QDomElement domElement(QDomDocument &doc);
		virtual void initFromDomElement(const QDomElement &node);
		GLdouble getRadius(){ return radius; }

	public slots:
        virtual void setRadius(GLdouble radius_);

	protected:
		GLdouble radius;
	};

	class Sphere : public Circle
	{
		Q_OBJECT

	public:
        Sphere(GLUquadric *quadric_);
		Sphere(qglviewer::Vec center, QColor color, 
			GLdouble radius, GLUquadric *quadric_, bool fill = true);

		void draw(bool selected);
		QDomElement domElement(QDomDocument &doc);

    public slots:
		void setRadius(GLdouble radius_);

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
		virtual QDomElement domElement(QDomDocument &doc);
		virtual void initFromDomElement(const QDomElement &node);
		GLdouble getLenX(){ return lenx; }
		GLdouble getLenY(){ return leny; }

	public slots:
        void setLenX(GLdouble lenx_);
        void setLenY(GLdouble leny_);

	protected:
		GLdouble lenx;
		GLdouble leny;
	};

	class Box : public Rectangle
	{
		Q_OBJECT

	public:
        Box();
		Box(qglviewer::Vec center, QColor color, GLdouble lenx, 
			GLdouble leny, GLdouble lenz, bool fill = true);
		Box(qglviewer::Vec center, QColor color, 
			GLdouble len, bool fill = true);

		void draw(bool selected);
		QDomElement domElement(QDomDocument &doc);
		void initFromDomElement(const QDomElement &node);
		GLdouble getLenZ(){ return lenz; }

	public slots:
        void setLenZ(GLdouble lenz_);

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

		Object();

		void draw(bool selected);
		QDomElement domElement(QDomDocument &doc);
		void initFromDomElement(const QDomElement &node);
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
