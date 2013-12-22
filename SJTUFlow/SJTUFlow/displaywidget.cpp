#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	scene = new Scene;
	setCentralWidget(scene);
	scene->setAllowSelect(false);
}

DisplayWidget::~DisplayWidget()
{
}

void DisplayWidget::cloneScene( Scene *scene_ )
{
	scene->clone(scene_);
}

void DisplayWidget::startAnimate()
{
	scene->startAnimation();
}

void DisplayWidget::stopAnimate()
{
	scene->stopAnimation();
}