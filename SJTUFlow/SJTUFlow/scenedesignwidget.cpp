#include "scenedesignwidget.h"

#include "primitive.h"

SceneDesignWidget::SceneDesignWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	currentObjectId = -1;

	scene = new Scene;
	setCentralWidget(scene);

/************************************************************************/
/*                              menu                                    */
/************************************************************************/
	connect(ui.actionProperty, SIGNAL(triggered()), this, SLOT(showProperty()));

/************************************************************************/
/*                             toolbar                                  */
/************************************************************************/
//	ui.toolBar2D->setVisible(false);
//	ui.toolBar3D->setVisible(false);

	ui.mainToolBar->addAction(ui.actionMove);
	ui.mainToolBar->addAction(ui.actionRotate);
	ui.mainToolBar->addAction(ui.actionScale);

	ui.toolBar2D->addAction(QIcon(":/Design/Resources/Icons/Rectangle.png"), 
		tr("New Rectangle"), scene, SLOT(newRectangle()));
	ui.toolBar2D->addAction(QIcon(":/Design/Resources/Icons/Circle.png"),
		tr("New Circle"), scene, SLOT(newCircle()));

	ui.toolBar3D->addAction(QIcon(":/Design/Resources/Icons/Box.png"), 
		tr("New Box"), scene, SLOT(newBox()));
	ui.toolBar3D->addAction(QIcon(":/Design/Resources/Icons/Sphere.png"),
		tr("New Sphere"), scene, SLOT(newSphere()));

/************************************************************************/
/*                            property                                  */
/************************************************************************/
	//ui.dockWidgetProperty->setVisible(false);
	QPixmap pix(QSize(20, 16));
	pix.fill(Qt::white);
	ui.pushButtonColor->setIcon(QIcon(pix));

	colorDialog = new QColorDialog(this);
	colorDialog->setCurrentColor(Qt::white);
	connect(ui.pushButtonColor, SIGNAL(clicked()), colorDialog, SLOT(show()));
}

SceneDesignWidget::~SceneDesignWidget()
{

}

void SceneDesignWidget::showProperty()
{
	if (currentObjectId >= 0)
	{
		ui.lineEditObjName->setEnabled(true);
		ui.lineEditPosX->setEnabled(true);
		ui.lineEditPosY->setEnabled(true);
		ui.lineEditPosZ->setEnabled(true);
		ui.checkBoxFill->setEnabled(true);
		ui.pushButtonColor->setEnabled(true);
	}
	else
	{
		ui.lineEditObjName->setEnabled(false);
		ui.lineEditPosX->setEnabled(false);
		ui.lineEditPosY->setEnabled(false);
		ui.lineEditPosZ->setEnabled(false);
		ui.checkBoxFill->setEnabled(false);
		ui.pushButtonColor->setEnabled(false);

		ui.dockWidgetProperty->show();
	}
}
