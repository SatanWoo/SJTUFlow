#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <GL/glut.h>
#include <QString>

namespace SceneUnit
{
	class Primitive
	{
	public:
		Primitive(void);
		~Primitive(void);

		enum Type{T_Rect, T_Circle, T_Box, T_Sphere};

		virtual void draw() = 0;

		Type getType(){ return type; }
		int getId(){ return id; }
		void setId(int id){ this->id = id; }
		QString getName(){ return name; }
		void setName(QString name){ this->name = name; }

		virtual void getCenter(GLdouble center[]) = 0;
		virtual void setCenter(GLdouble center[]) = 0;
		void getColor(GLubyte color[3]);
		void setColor(GLubyte color[3]);
		bool isFilled(){ return fill; }
		void setFill(bool fill){ this->fill = fill; }

	protected:
		Type type;
		int id;
		QString name;

		GLdouble center[3];
		GLubyte color[3];
		bool fill;
	};

	class Primitive2D : public Primitive
	{
	public:
		Primitive2D(GLdouble center[2], GLubyte color[3], bool fill = true);

		virtual void draw() = 0;
		void getCenter(GLdouble center[2]);
		void setCenter(GLdouble center[2]);
	};

	class Primitive3D : public Primitive
	{
	public:
		Primitive3D(GLdouble center[3], GLubyte color[3]);

		virtual void draw() = 0;
		void getCenter(GLdouble center[3]);
		void setCenter(GLdouble center[3]);
	};

	class Circle : public Primitive2D
	{
	public:
		Circle(GLdouble center[2], GLubyte color[3], 
			GLdouble radius, bool fill = true);

		void draw();
		GLdouble getRadius(){ return radius; }
		void setRadius(GLdouble radius){ this->radius = radius; }

	private:
		GLdouble radius;
	};

	class Rectangle : public Primitive2D
	{
	public:
		Rectangle(GLdouble center[2], GLubyte color[3], 
			GLdouble width, GLdouble height, bool fill = true);
		Rectangle(GLdouble center[2], GLubyte color[3], 
			GLdouble width, bool fill = true);

		void draw();
		GLdouble getWidth(){ return width; }
		void setWidth(GLdouble width){ this->width = width; }
		GLdouble getHeight(){ return height; }
		void setHeight(GLdouble height){ this->height = height; }

	private:
		GLdouble width;
		GLdouble height;
	};

	class Sphere : public Primitive3D
	{
	public:
		Sphere(GLdouble center[3], GLubyte color[3], 
			GLdouble radius, GLUquadric *quadric);

		void draw();
		GLdouble getRadius(){ return radius; }
		void setRadius(GLdouble radius){ this->radius = radius; }

	private:
		GLdouble radius;
		GLUquadric *quadric;
	};

	class Box : public Primitive3D
	{
	public:
		Box(GLdouble center[3], GLubyte color[3], 
			GLdouble lenx, GLdouble leny, GLdouble lenz);
		Box(GLdouble center[3], GLubyte color[3], GLdouble len);

		void draw();
		GLdouble getLenX(){ return lenx; }
		void setLenX(GLdouble lenx){ this->lenx = lenx; }
		GLdouble getLenY(){ return leny; }
		void setLenY(GLdouble leny){ this->leny = leny; }
		GLdouble getLenZ(){ return lenz; }
		void setLenZ(GLdouble lenz){ this->lenz = lenz; }

	private:
		GLdouble lenx, leny, lenz;
	};
};

#endif