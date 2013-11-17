#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	glWidget = new GLWidget;
	glWidget->startTimer(1);
	setCentralWidget(glWidget);
}

DisplayWidget::~DisplayWidget()
{

}
