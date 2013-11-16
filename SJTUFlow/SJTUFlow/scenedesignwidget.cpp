#include "scenedesignwidget.h"

SceneDesignWidget::SceneDesignWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	glWidget = new GLWidget;
	setCentralWidget(glWidget);
}

SceneDesignWidget::~SceneDesignWidget()
{

}
