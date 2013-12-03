#include "scenedesignwidget.h"

#include "primitive.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

SceneDesignWidget::SceneDesignWidget(QMenuBar *menubar, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    parseMenuActions(menubar);

	selectedObj = NULL;

	scene = new Scene;
	setCentralWidget(scene);

	connect(scene, SIGNAL(selectedObjChanged(int)), 
		this, SLOT(selectedObjChanged(int)));
	new3DScene();

/************************************************************************/
/*                              menu                                    */
/************************************************************************/
    actions["delete"]->setEnabled(false);

    connect(actions["2DScene"], SIGNAL(triggered()), this, SLOT(new2DScene()));
    connect(actions["3DScene"], SIGNAL(triggered()), this, SLOT(new3DScene()));

    connect(actions["circle"], SIGNAL(triggered()), scene, SLOT(newCircle()));
    connect(actions["rectangle"], SIGNAL(triggered()), scene, SLOT(newRectangle()));
    connect(actions["sphere"], SIGNAL(triggered()), scene, SLOT(newSphere()));
    connect(actions["box"], SIGNAL(triggered()), scene, SLOT(newBox()));

    connect(actions["move"], SIGNAL(triggered()), this, SLOT(move()));
    connect(actions["rotate"], SIGNAL(triggered()), this, SLOT(rotate()));
    connect(actions["scale"], SIGNAL(triggered()), this, SLOT(scale()));

	connect(actions["import"], SIGNAL(triggered()), this, SLOT(import()));

    connect(actions["property"], SIGNAL(triggered()), this, SLOT(showProperty()));

/************************************************************************/
/*                             toolbar                                  */
/************************************************************************/
    ui.mainToolBar->addAction(actions["move"]);
    ui.mainToolBar->addAction(actions["rotate"]);
    ui.mainToolBar->addAction(actions["scale"]);

    ui.toolBar2D->addAction(actions["circle"]);
    ui.toolBar2D->addAction(actions["rectangle"]);

    ui.toolBar3D->addAction(actions["sphere"]);
    ui.toolBar3D->addAction(actions["box"]);

	actions["move"]->setChecked(true);

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

void SceneDesignWidget::checkState()
{
    if (selectedObj == NULL)
    {
        actions["delete"]->setEnabled(false);
    }
    else
    {
        actions["delete"]->setEnabled(true);
    }
}

void SceneDesignWidget::new2DScene()
{
	scene->clear(Scene::SCENE_2D);
	ui.dockWidgetProperty->close();
	ui.toolBar2D->show();
	ui.toolBar3D->close();

    actions["circle"]->setVisible(true);
    actions["rectangle"]->setVisible(true);
    actions["sphere"]->setVisible(false);
    actions["box"]->setVisible(false);
	actions["import"]->setEnabled(false);
}

void SceneDesignWidget::new3DScene()
{
	scene->clear(Scene::SCENE_3D);
	ui.dockWidgetProperty->close();
	ui.toolBar2D->close();
	ui.toolBar3D->show();

    actions["circle"]->setVisible(false);
    actions["rectangle"]->setVisible(false);
    actions["sphere"]->setVisible(true);
    actions["box"]->setVisible(true);
	actions["import"]->setEnabled(true);
}

void SceneDesignWidget::deleteObject()
{
	if (selectedObj != NULL)
	{
		scene->deleteObject(selectedObj->getId());
		selectedObj = NULL;
        actions["delete"]->setEnabled(false);
		changePropertyWidget();
    }
}

void SceneDesignWidget::move()
{
    actions["move"]->setChecked(true);
    actions["rotate"]->setChecked(false);
    actions["scale"]->setChecked(false);
}

void SceneDesignWidget::rotate()
{
    actions["move"]->setChecked(false);
    actions["rotate"]->setChecked(true);
    actions["scale"]->setChecked(false);
}

void SceneDesignWidget::scale()
{
    actions["move"]->setChecked(false);
    actions["rotate"]->setChecked(false);
    actions["scale"]->setChecked(true);
}

void SceneDesignWidget::import()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		QString(), tr("Object File(*.obj)"));
	if(!fileName.isEmpty())
	{
		if (!scene->importObject(fileName))
		{
			QMessageBox::warning(this, tr("Warning"), 
				tr("Can't open file %1").arg(fileName), QMessageBox::Ok);
		}
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
        actions["delete"]->setEnabled(false);
	}
	else
	{
        actions["delete"]->setEnabled(true);
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

		QVector3D center = selectedObj->getCenter();

		ui.lineEditPosX->setText(QString::number(center.x()));
		ui.lineEditPosY->setText(QString::number(center.y()));
		ui.lineEditPosZ->setText(QString::number(center.z()));

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

void SceneDesignWidget::parseMenuActions(QMenuBar *menubar)
{
    QMenu *menu = menubar->findChild<QMenu *>(tr("menuFile"));
    menu = menu->findChild<QMenu *>(tr("menuNewScene"));
    QList<QAction *> actionsList = menu->actions();
    for (int i = 0; i < actionsList.count(); i++)
    {
        QAction *action = actionsList.at(i);
        if (tr("action2DScene") == action->objectName())
        {
            actions["2DScene"] = action;
        }
        else if (tr("action3DScene") == action->objectName())
        {
            actions["3DScene"] = action;
        }
        else if (tr("actionOpen") == action->objectName())
        {
            actions["open"] = action;
        }
        else if (tr("actionSave") == action->objectName())
        {
            actions["save"] = action;
        }
        else if (tr("actionSaveAs") == action->objectName())
        {
            actions["saveAs"] = action;
        }
    }
    menu = menubar->findChild<QMenu *>(tr("menuEdit"));
    actionsList = menu->actions();
    for (int i = 0; i < actionsList.count(); i++)
    {
        QAction *action = actionsList.at(i);
        if (tr("actionUndo") == action->objectName())
        {
            actions["undo"] = action;
        }
        else if (tr("actionRedo") == action->objectName())
        {
            actions["redo"] = action;
        }
        else if (tr("actionDelete") == action->objectName())
        {
            actions["delete"] = action;
        }
    }
    menu = menubar->findChild<QMenu *>(tr("menuPrimitive"));
    actionsList = menu->actions();
    for (int i = 0; i < actionsList.count(); i++)
    {
        QAction *action = actionsList.at(i);
        if (tr("actionCircle") == action->objectName())
        {
            actions["circle"] = action;
        }
        else if (tr("actionRectangle") == action->objectName())
        {
            actions["rectangle"] = action;
        }
        else if (tr("actionSphere") == action->objectName())
        {
            actions["sphere"] = action;
        }
        else if (tr("actionBox") == action->objectName())
        {
            actions["box"] = action;
        }
        else if (tr("actionMove") == action->objectName())
        {
            actions["move"] = action;
        }
        else if (tr("actionRotate") == action->objectName())
        {
            actions["rotate"] = action;
        }
        else if (tr("actionScale") == action->objectName())
        {
            actions["scale"] = action;
        }
        else if (tr("actionImport") == action->objectName())
        {
            actions["import"] = action;
        }
        else if (tr("actionProperty") == action->objectName())
        {
            actions["property"] = action;
        }
    }
}
