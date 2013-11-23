#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>

#include "primitive.h"

#include <qglviewer.h>

#define PROPORTION_TO_SCENE	0.01

#define RAND_255 rand() % 255
#define RAND_COLOR QColor(RAND_255, RAND_255, RAND_255)

class Scene : public QGLViewer
{
	Q_OBJECT

public:
	SceneUnit::Primitive *getPrimitive(int id);

signals:
	void selectedObjChanged(int);

public slots:
	void newCircle();
	void newRectangle();
	void newBox();
	void newSphere();

	void clearPrimitives(){ primitives.clear(); }

protected:
	void mousePressEvent(QMouseEvent *event);
	void draw();
	void drawWithNames();
	void postDraw();
	void postSelection(const QPoint& point);
	void init();

	void timerEvent(QTimerEvent *);

private:
	QList<SceneUnit::Primitive *> primitives;
	GLUquadric *quadric;

	qglviewer::Vec orig, dir, selectedPoint;

	int circleNum;
	int rectangleNum;
	int boxNum;
	int sphereNum;
	int id;

	GLfloat rtri;
	GLfloat rquad;

	void drawCornerAxis();
};

#endif // GLWIDGET_H
