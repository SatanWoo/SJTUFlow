#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>

#include "primitive.h"

#include <qglviewer.h>

#define RAND_255 rand() % 255
#define RAND_COLOR QColor(RAND_255, RAND_255, RAND_255)

class Scene : public QGLViewer
{
	Q_OBJECT

public:
	enum Mode{SCENE_2D = 0, SCENE_3D};
	enum Operator{OP_MOVE = 0, OP_ROTATE, OP_SCALE};
	enum Axis{AXIS_X = 1000, AXIS_Y, AXIS_Z};

	Scene(QWidget *parent = 0);

	// get the id-specific primitive
	SceneUnit::Primitive *getPrimitive(int id);
	void setAnimate(bool animate = true) { ifAnimate = animate; }
	bool importObject(QString filename);

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
    void mouseMoveEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *){}
	void timerEvent(QTimerEvent *);

private:
	QList<SceneUnit::Primitive *> primitives;
	static GLUquadric *quadric;
	static qglviewer::Vec axisDirs[3];

	qglviewer::Vec mousePos;

    Mode sceneMode;

	bool ifAnimate;

	int circleNum;
	int rectangleNum;
	int boxNum;
	int sphereNum;
	int objectNum;
	int id;

	int selectedId;

	//example
	GLdouble dx;

	int getPrimitiveIndex(int id);

	void drawCornerAxis();
    void setSceneMode();
	void drawAxis(double length, Axis axis);
};

#endif // GLWIDGET_H
