#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QMainWindow>
#include "ui_displaywidget.h"

#include <QLocalServer>

#include "scene.h"

class DisplayWidget : public QMainWindow
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = 0);
	~DisplayWidget();

	void cloneScene(Scene *scene_);
	void startAnimate()
	{
		scene->startAnimation();
	}
	void stopAnimate()
	{
		scene->stopAnimation();
	}

private:
	Ui::DisplayWidget ui;

	Scene *scene;
	QLocalServer *localServer;

private slots:
	void dealConnection();
	void readData();
};

#endif // DISPLAYWIDGET_H
