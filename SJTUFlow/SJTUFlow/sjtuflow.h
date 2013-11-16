#ifndef SJTUFLOW_H
#define SJTUFLOW_H

#include <QtWidgets/QMainWindow>
#include "ui_sjtuflow.h"

#include "titlebar.h"
#include "scenedesignwidget.h"
#include "codingwidget.h"
#include "displaywidget.h"

class SJTUFlow : public QMainWindow
{
	Q_OBJECT

public:
	SJTUFlow(QWidget *parent = 0);
	~SJTUFlow();

private:
	Ui::SJTUFlowClass ui;

	TitleBar *titleBar;
	SceneDesignWidget *sceneDesignWidget;
	CodingWidget *codingWidget;
	DisplayWidget *displayWidget;

private slots:

};

#endif // SJTUFLOW_H
