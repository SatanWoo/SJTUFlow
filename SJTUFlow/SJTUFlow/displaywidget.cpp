#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new Scene;
	scene->startTimer(1);
	setCentralWidget(scene);
}

DisplayWidget::~DisplayWidget()
{

}
