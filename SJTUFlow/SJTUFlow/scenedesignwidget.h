#ifndef SCENEDESIGNWIDGET_H
#define SCENEDESIGNWIDGET_H

#include <QMainWindow>
#include "ui_scenedesignwidget.h"

class SceneDesignWidget : public QMainWindow
{
	Q_OBJECT

public:
	SceneDesignWidget(QWidget *parent = 0);
	~SceneDesignWidget();

private:
	Ui::SceneDesignWidget ui;
};

#endif // SCENEDESIGNWIDGET_H
