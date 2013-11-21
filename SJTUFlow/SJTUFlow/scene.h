#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>

#include "primitive.h"

#define PROPORTION_TO_SCENE	0.01

class Scene : public QGLWidget
{
	Q_OBJECT

public:
	Scene(QWidget *parent = 0);
	~Scene();

protected:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);
	void mousePressEvent(QMouseEvent *event);
	void mouseMoveEvent(QMouseEvent *event);

	void timerEvent(QTimerEvent *);

public slots:
	void newCircle();
	void newRectangle();
	void newBox();
	void newSphere();

	void clearPrimitives(){ primitives.clear(); }

private:
	QList<SceneUnit::Primitive *> primitives;
	GLUquadric *quadric;

	int circleNum;
	int rectangleNum;
	int boxNum;
	int sphereNum;

	GLfloat rtri;
	GLfloat rquad;
};

#endif // GLWIDGET_H
