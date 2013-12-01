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

namespace SceneUnit
{
	class Primitive : public QObject
	{
		Q_OBJECT

	public:
		Primitive(void);
		~Primitive(void);

		enum Type{T_Rect, T_Circle, T_Box, T_Sphere, T_Object};

		virtual void draw(GLuint id) = 0;

		Type getType(){ return type; }
		GLuint getId(){ return id; }
		void setId(int id){ this->id = id; }
		QString getName(){ return name; }

		void getCenter(GLdouble center[3]);
		virtual void setCenter(GLdouble center[3]);
		QColor getColor();
		bool isFilled(){ return fill; }

	signals:
		void propertyChanged();

	public slots:
		void setName(QString name){ this->name = name; }
		void setFill(bool fill){ this->fill = fill; emit propertyChanged(); }
		void setColor(QColor color);
		void setCenterX(QString str){ center[0] = str.toDouble(); emit propertyChanged(); }
		void setCenterY(QString str){ center[1] = str.toDouble(); emit propertyChanged(); }
		void setCenterZ(QString str){ center[2] = str.toDouble(); emit propertyChanged(); }
        virtual void setRadius(QString){};
        virtual void setLenX(QString){};
        virtual void setLenY(QString){};
        virtual void setLenZ(QString){};

	protected:
		Type type;
		GLuint id;
		QString name;

		GLdouble center[3];
		GLubyte color[3];
		bool fill;
	};

	class Circle : public Primitive
	{
		Q_OBJECT

	public:
		Circle(){}
		Circle(GLdouble center[2], QColor color, 
			GLdouble radius, bool fill = true);

		virtual void draw(GLuint id);
		virtual void setCenter(GLdouble center[2]);
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
		Sphere(GLdouble center[3], QColor color, 
			GLdouble radius, GLUquadric *quadric);

		void draw(GLuint id);
		void setCenter(GLdouble center[3]){ Primitive::setCenter(center); }

	private:
		GLUquadric *quadric;
	};

	class Rectangle : public Primitive
	{
		Q_OBJECT

	public:
		Rectangle(){}
		Rectangle(GLdouble center[2], QColor color, 
			GLdouble lenx, GLdouble leny, bool fill = true);
		Rectangle(GLdouble center[2], QColor color, 
			GLdouble lenx, bool fill = true);

		virtual void draw(GLuint id);
		virtual void setCenter(GLdouble center[2]);
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
		Box(GLdouble center[3], QColor color, 
			GLdouble lenx, GLdouble leny, GLdouble lenz);
		Box(GLdouble center[3], QColor color, GLdouble len);

		void draw(GLuint id);
		void setCenter(GLdouble center[3]){ Primitive::setCenter(center); }
		GLdouble getLenZ(){ return lenz; }
		void setLenZ(GLdouble lenz){ this->lenz = lenz; emit propertyChanged(); }

	public slots:
		void setLenZ(QString str){ setLenZ(str.toDouble()); }

	private:
		GLdouble lenz;
	};
};

#endif