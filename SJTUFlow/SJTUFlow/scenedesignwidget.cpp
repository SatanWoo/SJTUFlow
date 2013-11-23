#include "scenedesignwidget.h"

#include "primitive.h"

SceneDesignWidget::SceneDesignWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	selectedObjectId = 0;

	scene = new Scene;
	setCentralWidget(scene);
	scene->newRectangle();

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
	ui.lineEditPosX->setValidator(new QDoubleValidator());
	ui.lineEditPosY->setValidator(new QDoubleValidator());
	ui.lineEditPosZ->setValidator(new QDoubleValidator());

	QPixmap pix(ui.pushButtonColor->iconSize());
	pix.fill(Qt::white);
	ui.pushButtonColor->setIcon(QIcon(pix));

	colorDialog = new QColorDialog(this);
	colorDialog->setModal(true);
	colorDialog->setCurrentColor(Qt::white);
	connect(ui.pushButtonColor, SIGNAL(clicked()), colorDialog, SLOT(show()));

	showProperty();
}

SceneDesignWidget::~SceneDesignWidget()
{

}

void SceneDesignWidget::showProperty()
{
	if (selectedObjectId >= 0)
	{
		ui.lineEditObjName->setEnabled(true);
		ui.lineEditPosX->setEnabled(true);
		ui.lineEditPosY->setEnabled(true);
		ui.lineEditPosZ->setEnabled(true);
		ui.checkBoxFill->setEnabled(true);
		ui.pushButtonColor->setEnabled(true);

		SceneUnit::Primitive *p = scene->getPrimitive(selectedObjectId);

		connect(ui.lineEditObjName, SIGNAL(textChanged(QString)), p, SLOT(setName(QString)));
		connect(ui.checkBoxFill, SIGNAL(toggled(bool)), p, SLOT(setFill(bool)));
		connect(colorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(colorChanged(QColor)));

		GLdouble center[3];
		p->getCenter(center);

		ui.lineEditPosX->setText(QString::number(center[0]));
		ui.lineEditPosY->setText(QString::number(center[1]));
		ui.lineEditPosZ->setText(QString::number(center[2]));

		ui.lineEditObjName->setText(p->getName());
		ui.checkBoxFill->setChecked(p->isFilled());

		QPixmap pix(ui.pushButtonColor->iconSize());
		pix.fill(p->getColor());
		ui.pushButtonColor->setIcon(QIcon(pix));
		colorDialog->setCurrentColor(p->getColor());

		if (p->getType() == SceneUnit::Primitive::T_Circle ||
			p->getType() == SceneUnit::Primitive::T_Rect)
		{
			ui.labelPosZ->setVisible(false);
			ui.lineEditPosZ->setVisible(false);
		}
		else if (p->getType() == SceneUnit::Primitive::T_Sphere ||
			p->getType() == SceneUnit::Primitive::T_Box)
		{
			ui.labelPosZ->setVisible(true);
			ui.lineEditPosZ->setVisible(true);
		}
	}
	else
	{
		ui.lineEditObjName->setEnabled(false);
		ui.lineEditPosX->setEnabled(false);
		ui.lineEditPosY->setEnabled(false);
		ui.lineEditPosZ->setEnabled(false);
		ui.checkBoxFill->setEnabled(false);
		ui.pushButtonColor->setEnabled(false);
	}

	ui.dockWidgetProperty->show();
}

void SceneDesignWidget::colorChanged( QColor color )
{
	QPixmap pix(ui.pushButtonColor->iconSize());
	pix.fill(color);
	ui.pushButtonColor->setIcon(QIcon(pix));

	SceneUnit::Primitive *p = scene->getPrimitive(selectedObjectId);
	p->setColor(color);
}