#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QMainWindow>
#include "ui_displaywidget.h"

#include "scene.h"

class DisplayWidget : public QMainWindow
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = 0);
	~DisplayWidget();

	void cloneScene(Scene *scene_);

private:
	Ui::DisplayWidget ui;

	Scene *scene;
};

#endif // DISPLAYWIDGET_H
