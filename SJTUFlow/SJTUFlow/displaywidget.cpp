#include "displaywidget.h"

DisplayWidget::DisplayWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	glWidget = new GLWidget;
	setCentralWidget(glWidget);
}

DisplayWidget::~DisplayWidget()
{

}
