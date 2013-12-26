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
	void startAnimation();
	void stopAnimation();

public slots:
	void replayEnabled(bool enabled);

signals:
	void replayClicked();

private:
	Ui::DisplayWidget ui;
	QAction *actionReplay;

	Scene *scene;

private slots:
	void replay();
};

#endif // DISPLAYWIDGET_H
