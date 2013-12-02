#ifndef SCENEDESIGNWIDGET_H
#define SCENEDESIGNWIDGET_H

#include <QMainWindow>
#include "ui_scenedesignwidget.h"

#include <QColorDialog>
#include <QMap>
#include <QMenuBar>

#include "scene.h"

class SceneDesignWidget : public QMainWindow
{
	Q_OBJECT

public:
    SceneDesignWidget(QMenuBar *menuBar, QWidget *parent = 0);
	~SceneDesignWidget();

    // check if the actions' state is right
    void checkState();

public slots:
/************************************************************************/
/*                                menu                                  */
/************************************************************************/
	void new2DScene();
	void new3DScene();
	void deleteObject();

    void move();
    void rotate();
    void scale();

	void showProperty();

	void selectedObjChanged(int id);
	void colorChanged(QColor color);

private:
	Ui::SceneDesignWidget ui;

    QMap<QString, QAction *> actions;

	QColorDialog *colorDialog;
	Scene *scene;
	SceneUnit::Primitive *selectedObj;

	void changePropertyWidget();
    void parseMenuActions(QMenuBar *menubar);
};

#endif // SCENEDESIGNWIDGET_H
