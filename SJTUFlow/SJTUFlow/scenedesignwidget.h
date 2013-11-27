#ifndef SCENEDESIGNWIDGET_H
#define SCENEDESIGNWIDGET_H

#include <QMainWindow>
#include "ui_scenedesignwidget.h"

#include <QColorDialog>

#include "scene.h"

class SceneDesignWidget : public QMainWindow
{
	Q_OBJECT

public:
	SceneDesignWidget(QWidget *parent = 0);
	~SceneDesignWidget();

private slots:
/************************************************************************/
/*                                menu                                  */
/************************************************************************/
	void new2DScene();
	void new3DScene();
	void deleteObject();

	void showProperty();

	void selectedObjChanged(int id);
	void colorChanged(QColor color);

private:
	Ui::SceneDesignWidget ui;

	QColorDialog *colorDialog;
	Scene *scene;
	SceneUnit::Primitive *selectedObj;

	void changePropertyWidget();
};

#endif // SCENEDESIGNWIDGET_H
