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
	QString filePath(){ return sceneFilePath; }

signals:
	void filePathChanged(QString);

public slots:
/************************************************************************/
/*                                menu                                  */
/************************************************************************/
	void new2DScene();
	void new3DScene();

	void openScene();
	void saveScene();
	void saveAs();

	void deleteObject();

    void move();
    void rotate();
    void scale();

	void import();

	void showProperty();

/************************************************************************/
/*                                other                                 */
/************************************************************************/
	void selectedObjChanged(int id);
	void colorChanged(QColor color);
	void propertyOperated();
	void sceneChanged();

private:
	Ui::SceneDesignWidget ui;

    QMap<QString, QAction *> actions;

	QColorDialog *colorDialog;
	Scene *scene;
	SceneUnit::Primitive *selectedObj;

 	bool isSaved;
 	QString sceneFilePath;

	void changePropertyWidget();
    void parseMenuActions(QMenuBar *menubar);
	void openScene(QString fileName);
	void saveScene(QString fileName);
};

#endif // SCENEDESIGNWIDGET_H
