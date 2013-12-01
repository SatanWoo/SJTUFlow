#include "sjtuflow.h"

SJTUFlow::SJTUFlow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	bgImage.load(":/SJTUFlow/Resources/background.jpg");

	setWindowFlags(Qt::FramelessWindowHint);
	setGeometry(50, 30, width(), height());
	setFixedSize(width(), height());

    QMenuBar *menubar = new QMenuBar;

/************************************************************************/
/*                             tab widget                               */
/************************************************************************/
	sceneDesignWidget = new SceneDesignWidget;
	ui.tabWidget->addTab(sceneDesignWidget, 
		QIcon(":/Icons/Resources/Icons/SceneDesign.png"), tr("Scene Design"));

	codingWidget = new CodingWidget;
	ui.tabWidget->addTab(codingWidget,
		QIcon(":/Icons/Resources/Icons/Coding.png"), tr("Coding"));

	displayWidget = new DisplayWidget;
	ui.tabWidget->addTab(displayWidget,
		QIcon(":/Icons/Resources/Icons/Display.png"), tr("Display"));

	ui.tabWidget->setCurrentIndex(0);
}

SJTUFlow::~SJTUFlow()
{

}

void SJTUFlow::paintEvent( QPaintEvent *)
{
	QPainter painter(this);
	painter.drawPixmap(rect(), bgImage);
}
