#include "scenedesignwidget.h"

#include "primitive.h"

SceneDesignWidget::SceneDesignWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	selectedObj = NULL;

	scene = new Scene;
	setCentralWidget(scene);

	connect(scene, SIGNAL(selectedObjChanged(int)), 
		this, SLOT(selectedObjChanged(int)));
	new2DScene();

/************************************************************************/
/*                              menu                                    */
/************************************************************************/
	ui.actionDelete->setEnabled(false);

	connect(ui.actionScene2D, SIGNAL(triggered()), this, SLOT(new2DScene()));
	connect(ui.actionScene3D, SIGNAL(triggered()), this, SLOT(new3DScene()));
	connect(ui.actionDelete, SIGNAL(triggered()), this, SLOT(deleteObject()));

	connect(ui.actionProperty, SIGNAL(triggered()), this, SLOT(showProperty()));

/************************************************************************/
/*                             toolbar                                  */
/************************************************************************/
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
	ui.dockWidgetProperty->setVisible(false);
	ui.lineEditPosX->setValidator(new QDoubleValidator());
	ui.lineEditPosY->setValidator(new QDoubleValidator());
	ui.lineEditPosZ->setValidator(new QDoubleValidator());
	ui.lineEditSizeX->setValidator(new QDoubleValidator());
	ui.lineEditSizeY->setValidator(new QDoubleValidator());
	ui.lineEditSizeZ->setValidator(new QDoubleValidator());

	QPixmap pix(ui.pushButtonColor->iconSize());
	pix.fill(Qt::white);
	ui.pushButtonColor->setIcon(QIcon(pix));

	colorDialog = new QColorDialog(this);
	colorDialog->setModal(true);
	colorDialog->setCurrentColor(Qt::white);
	connect(ui.pushButtonColor, SIGNAL(clicked()), colorDialog, SLOT(show()));
	connect(colorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(colorChanged(QColor)));
}

SceneDesignWidget::~SceneDesignWidget()
{

}

void SceneDesignWidget::new2DScene()
{
	scene->clear(Scene::SCENE_2D);
	ui.dockWidgetProperty->close();
	ui.toolBar2D->show();
	ui.toolBar3D->close();
}

void SceneDesignWidget::new3DScene()
{
	scene->clear(Scene::SCENE_3D);
	ui.dockWidgetProperty->close();
	ui.toolBar2D->close();
	ui.toolBar3D->show();
}

void SceneDesignWidget::deleteObject()
{
	if (selectedObj != NULL)
	{
		scene->deleteObject(selectedObj->getId());
		selectedObj = NULL;
		ui.actionDelete->setEnabled(false);
		changePropertyWidget();
	}
}

void SceneDesignWidget::showProperty()
{
	changePropertyWidget();
	ui.dockWidgetProperty->show();
}


void SceneDesignWidget::selectedObjChanged( int id )
{
	if (selectedObj != NULL)
	{
		disconnect(ui.lineEditObjName, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setName(QString)));
		disconnect(ui.lineEditPosX, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setCenterX(QString)));
		disconnect(ui.lineEditPosY, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setCenterY(QString)));
		disconnect(ui.lineEditPosZ, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setCenterZ(QString)));
		disconnect(ui.checkBoxFill, SIGNAL(toggled(bool)), 
			selectedObj, SLOT(setFill(bool)));
		disconnect(ui.lineEditRadius, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setRadius(QString)));
		disconnect(ui.lineEditSizeX, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setLenX(QString)));
		disconnect(ui.lineEditSizeY, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setLenY(QString)));
		disconnect(ui.lineEditSizeZ, SIGNAL(textChanged(QString)), 
			selectedObj, SLOT(setLenZ(QString)));
	}

	selectedObj = scene->getPrimitive(id);
	if (selectedObj == NULL)
	{
		ui.actionDelete->setEnabled(false);
	}
	else
	{
		ui.actionDelete->setEnabled(true);
	}
	changePropertyWidget();
}

void SceneDesignWidget::colorChanged( QColor color )
{
	if (selectedObj != NULL)
	{
		QPixmap pix(ui.pushButtonColor->iconSize());
		pix.fill(color);
		ui.pushButtonColor->setIcon(QIcon(pix));

		selectedObj->setColor(color);
	}
}

void SceneDesignWidget::changePropertyWidget()
{
	if (selectedObj != NULL)
	{
		ui.lineEditObjName->setEnabled(true);
		ui.lineEditPosX->setEnabled(true);
		ui.lineEditPosY->setEnabled(true);
		ui.lineEditPosZ->setEnabled(true);
		ui.checkBoxFill->setEnabled(true);
		ui.pushButtonColor->setEnabled(true);

		connect(ui.lineEditObjName, SIGNAL(textChanged(QString)), selectedObj, SLOT(setName(QString)));
		connect(ui.lineEditPosX, SIGNAL(textChanged(QString)), selectedObj, SLOT(setCenterX(QString)));
		connect(ui.lineEditPosY, SIGNAL(textChanged(QString)), selectedObj, SLOT(setCenterY(QString)));
		connect(ui.lineEditPosZ, SIGNAL(textChanged(QString)), selectedObj, SLOT(setCenterZ(QString)));
		connect(ui.checkBoxFill, SIGNAL(toggled(bool)), selectedObj, SLOT(setFill(bool)));
		connect(ui.lineEditRadius, SIGNAL(textChanged(QString)), selectedObj, SLOT(setRadius(QString)));
		connect(ui.lineEditSizeX, SIGNAL(textChanged(QString)), selectedObj, SLOT(setLenX(QString)));
		connect(ui.lineEditSizeY, SIGNAL(textChanged(QString)), selectedObj, SLOT(setLenY(QString)));
		connect(ui.lineEditSizeZ, SIGNAL(textChanged(QString)), selectedObj, SLOT(setLenZ(QString)));

		GLdouble center[3];
		selectedObj->getCenter(center);

		ui.lineEditPosX->setText(QString::number(center[0]));
		ui.lineEditPosY->setText(QString::number(center[1]));
		ui.lineEditPosZ->setText(QString::number(center[2]));

		ui.lineEditObjName->setText(selectedObj->getName());
		ui.checkBoxFill->setChecked(selectedObj->isFilled());

		QPixmap pix(ui.pushButtonColor->iconSize());
		pix.fill(selectedObj->getColor());
		ui.pushButtonColor->setIcon(QIcon(pix));
		colorDialog->setCurrentColor(selectedObj->getColor());

		if (selectedObj->getType() == SceneUnit::Primitive::T_Circle ||
			selectedObj->getType() == SceneUnit::Primitive::T_Rect)
		{
			ui.labelPosZ->setVisible(false);
			ui.lineEditPosZ->setVisible(false);
		}
		else
		{
			ui.labelPosZ->setVisible(true);
			ui.lineEditPosZ->setVisible(true);
		}
		
		if (selectedObj->getType() == SceneUnit::Primitive::T_Object)
		{
			ui.labelRadius->setVisible(false);
			ui.lineEditRadius->setVisible(false);
			ui.labelSize->setVisible(false);
			ui.labelSizeX->setVisible(false);
			ui.lineEditSizeX->setVisible(false);
			ui.labelSizeY->setVisible(false);
			ui.lineEditSizeY->setVisible(false);
			ui.labelSizeZ->setVisible(false);
			ui.lineEditSizeZ->setVisible(false);
		}
		else if (selectedObj->getType() == SceneUnit::Primitive::T_Circle ||
			selectedObj->getType() == SceneUnit::Primitive::T_Sphere)
		{
			SceneUnit::Circle *c = (SceneUnit::Circle *)selectedObj;
			ui.labelRadius->setVisible(true);
			ui.lineEditRadius->setVisible(true);
			ui.lineEditRadius->setText(QString::number(c->getRadius()));

			ui.labelSize->setVisible(false);
			ui.labelSizeX->setVisible(false);
			ui.lineEditSizeX->setVisible(false);
			ui.labelSizeY->setVisible(false);
			ui.lineEditSizeY->setVisible(false);
			ui.labelSizeZ->setVisible(false);
			ui.lineEditSizeZ->setVisible(false);
		}
		else
		{
			ui.labelRadius->setVisible(false);
			ui.lineEditRadius->setVisible(false);

			ui.labelSize->setVisible(true);
			ui.labelSizeX->setVisible(true);
			ui.lineEditSizeX->setVisible(true);
			ui.labelSizeY->setVisible(true);
			ui.lineEditSizeY->setVisible(true);

			SceneUnit::Rectangle *r = (SceneUnit::Rectangle *)selectedObj;
			ui.lineEditSizeX->setText(QString::number(r->getLenX()));
			ui.lineEditSizeY->setText(QString::number(r->getLenY()));

			if (selectedObj->getType() == SceneUnit::Primitive::T_Rect)
			{
				ui.labelSizeZ->setVisible(false);
				ui.lineEditSizeZ->setVisible(false);
			}
			else
			{
				ui.labelSizeZ->setVisible(true);
				ui.lineEditSizeZ->setVisible(true);

				SceneUnit::Box *b = (SceneUnit::Box *)selectedObj;
				ui.lineEditSizeZ->setText(QString::number(b->getLenX()));
			}
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

		ui.labelSize->setVisible(false);
		ui.labelRadius->setVisible(false);
		ui.lineEditRadius->setVisible(false);
		ui.labelSizeX->setVisible(false);
		ui.lineEditSizeX->setVisible(false);
		ui.labelSizeY->setVisible(false);
		ui.lineEditSizeY->setVisible(false);
		ui.labelSizeZ->setVisible(false);
		ui.lineEditSizeZ->setVisible(false);
	}
}
