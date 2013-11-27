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
	enum Mode{SCENE_2D = 0, SCENE_3D};

	Scene(QWidget *parent = 0);

	// get the id-specific primitive
	SceneUnit::Primitive *getPrimitive(int id);
	void setAnimate(bool animate = true) { ifAnimate = animate; }

signals:
	void selectedObjChanged(int);

public slots:
	void newCircle();
	void newRectangle();
	void newBox();
	void newSphere();
	void deleteObject(int id);

	// clear the scene and set to the specific mode
	void clear(Mode m);

protected:
	void init();
	void draw();
	void drawWithNames();
	void postDraw();
	void postSelection(const QPoint& point);
	void animate();

	void mousePressEvent(QMouseEvent *event);
	void keyPressEvent(QKeyEvent *event){};
	void timerEvent(QTimerEvent *);

private:
	QList<SceneUnit::Primitive *> primitives;
	static GLUquadric *quadric;

	qglviewer::Vec orig, dir, selectedPoint;
	qglviewer::Camera *camera_;

	bool ifAnimate;

	int circleNum;
	int rectangleNum;
	int boxNum;
	int sphereNum;
	int id;

	//example
	GLdouble dx;

	int getPrimitiveIndex(int id);

	void drawCornerAxis();
	void setSceneMode(Mode m);
};

#endif // GLWIDGET_H
