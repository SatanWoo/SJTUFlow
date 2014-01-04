#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	actionReplay = ui.toolBar->addAction(
		QIcon(":/Display/Resources/Icons/DisplayReplay.png"),
		tr("Replay"), this, SLOT(replay()));
	actionReplay->setEnabled(false);

	scene = new Scene;
	setCentralWidget(scene);
	scene->setAllowSelect(false);
	scene->setFPSIsDisplayed();
}

DisplayWidget::~DisplayWidget()
{
}

void DisplayWidget::cloneScene( Scene *scene_ )
{
	scene->clone(scene_);
}

void DisplayWidget::startAnimation()
{
	actionReplay->setEnabled(false);
	scene->startAnimation();
}

void DisplayWidget::stopAnimation()
{
	actionReplay->setEnabled(false);
	scene->stopAnimation();
}

void DisplayWidget::replayEnabled( bool enabled )
{
	actionReplay->setEnabled(enabled);
}

void DisplayWidget::replay()
{
	actionReplay->setEnabled(false);
	emit replayClicked();
}
