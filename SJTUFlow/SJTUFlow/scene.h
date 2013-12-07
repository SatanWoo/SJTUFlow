#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QDomDocument>

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
	enum Axis{AXIS_X = 0xfffff0, AXIS_Y, AXIS_Z, AXIS_SCALE};

	Scene(QWidget *parent = 0);

	// get the id-specific primitive
	SceneUnit::Primitive *getPrimitive(int id);
	void setAnimate(bool animate = true) { ifAnimate = animate; }
	bool importObject(QString filename);
	void setOperator(Operator op){ curOp = op; updateGL(); }

	QDomElement domElement(QDomDocument &doc);
	bool initFromDomElement(const QDomElement &node);

signals:
	void selectedObjChanged(int);
	void sceneChanged();

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
	void mouseReleaseEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *){}
	void timerEvent(QTimerEvent *);

private:
	QList<SceneUnit::Primitive *> primitives;
	static GLUquadric *quadric;
	static qglviewer::Vec axisDirs[3];
	static double axisRot[3][4];

	bool mousePressed;
	qglviewer::Vec mousePos;
	QPoint mousePosInWin;

    Mode sceneMode;
	Operator curOp;

	bool ifAnimate;

	int circleNum;
	int rectangleNum;
	int boxNum;
	int sphereNum;
	int objectNum;
	int id;

	int selectedId;
	int selectedAxis;

	//example
	GLdouble dx;

	int getPrimitiveIndex(int id);

	void drawCornerAxis();
    void setSceneMode();
	void drawOperator(qglviewer::Vec center, qglviewer::Vec bmin, 
		qglviewer::Vec vmax, bool withName = false);	// withName for select()
	void drawMoveAxis(double length, Axis axis, bool withName = false);
	void drawRotateRing(double radius, Axis axis, bool withName = false);
	void drawScaleBox(qglviewer::Vec bmin, qglviewer::Vec bmax, bool withName = false);
	void drawSubScaleBox(double len, double x, double y, double z = 0.0, bool s3d = true);
};

#endif // GLWIDGET_H
