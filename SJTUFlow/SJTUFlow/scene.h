#ifndef SCENE_H
#define SCENE_H

#include <QGLWidget>
#include <QDomDocument>
#include <QUndoStack>
#include <QLocalServer>

#include "primitive.h"

#include <qglviewer.h>

#include "SJTUFlow/global.h"
//#include "StableFluidsApplication.h"

#define RAND_255 rand() % 255
#define RAND_COLOR QColor(RAND_255, RAND_255, RAND_255)

class PrimitiveOperateCommand;

class Scene : public QGLViewer
{
	Q_OBJECT

public:
	enum Mode{SCENE_2D = 0, SCENE_3D};
	enum Operator{OP_MOVE = 0, OP_ROTATE, OP_SCALE};
	enum Axis{AXIS_X = 0xfffff0, AXIS_Y, AXIS_Z, AXIS_SCALE};
	enum Error{OK = 0, NOTMATCH, PATHERR};

	Scene(QWidget *parent = 0);
	~Scene(){ stopAnimation(); }

	// get the id-specific primitive
	SceneUnit::Primitive *getPrimitive(int id);
	void setAllowSelect(bool allow = false){ allowSelect = allow; }
	void setOperator(Operator op){ curOp = op; updateGL(); }
	void setUndoStack(QUndoStack *undoStack_){ undoStack = undoStack_;}

	QDomElement domElement(QDomDocument &doc, bool withCamera = false);
	Error initFromDomElement(const QDomElement &node, bool withCamera = false);

	void clone(Scene *scene);

	void startAnimation();
	void stopAnimation();

signals:
	void selectedObjChanged(int);
	void sceneChanged();

public:
	bool importObject(QString filename);
	void newPrimitive(SceneUnit::Primitive::Type type);
	QString defaultName(SceneUnit::Primitive::Type type);
	static GLUquadric *getQuadric(){ return quadric; }

	void deletePrimitive(int id);
	void appendPrimitive(SceneUnit::Primitive *p);

	// clear the scene and set to the specific mode
	void clear(Mode m);

	int getAnID(){ return id; }
	void increaseID(){ id++; }
	void decreaseID(){ id--; }
	void increaseNum(SceneUnit::Primitive::Type t);
	void decreaseNum(SceneUnit::Primitive::Type t);

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
	void wheelEvent(QWheelEvent *event);
    void keyPressEvent(QKeyEvent *){}
	void timerEvent(QTimerEvent *);

private:
	QList<SceneUnit::Primitive *> primitives;
	static GLUquadric *quadric;
	static qglviewer::Vec axisDirs[3];
	static double axisRot[3][4];

	QLocalServer *localServer;
	SocketPackageSPH spSPH;
	SocketPackageEuler spEG;
	bool allowSelect;

	bool mousePressed;
	qglviewer::Vec mousePos;
	QPoint mousePosInWin;

	QUndoStack *undoStack;
	PrimitiveOperateCommand *poCmd;

    Mode sceneMode;
	Operator curOp;

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

	void drawEuler();
};

#endif // GLWIDGET_H
