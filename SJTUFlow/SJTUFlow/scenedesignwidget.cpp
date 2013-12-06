#include "scenedesignwidget.h"

#include "primitive.h"
#include <QFileDialog>
#include <QMessageBox>

SceneDesignWidget::SceneDesignWidget(QMenuBar *menubar, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    parseMenuActions(menubar);

	selectedObj = NULL;

	scene = new Scene;
	scene->setMouseTracking(true);
	setCentralWidget(scene);

	connect(scene, SIGNAL(selectedObjChanged(int)), 
		this, SLOT(selectedObjChanged(int)));

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

/************************************************************************/
/*                            property                                  */
/************************************************************************/
	ui.dockWidgetProperty->setVisible(false);

	QPixmap pix(ui.pushButtonColor->iconSize());
	pix.fill(Qt::white);
	ui.pushButtonColor->setIcon(QIcon(pix));

	colorDialog = new QColorDialog(this);
	colorDialog->setModal(true);
	colorDialog->setCurrentColor(Qt::white);
	connect(ui.pushButtonColor, SIGNAL(clicked()), colorDialog, SLOT(show()));
	connect(colorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(colorChanged(QColor)));

	new3DScene();
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
	actions["move"]->trigger();
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
	actions["move"]->trigger();
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

	scene->setOperator(Scene::OP_MOVE);
}

void SceneDesignWidget::rotate()
{
    actions["move"]->setChecked(false);
    actions["rotate"]->setChecked(true);
    actions["scale"]->setChecked(false);

	scene->setOperator(Scene::OP_ROTATE);
}

void SceneDesignWidget::scale()
{
    actions["move"]->setChecked(false);
    actions["rotate"]->setChecked(false);
    actions["scale"]->setChecked(true);

	scene->setOperator(Scene::OP_SCALE);
}

void SceneDesignWidget::import()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		QDir::homePath(), tr("Object File(*.obj)"));
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
        disconnect(ui.doubleSpinBoxPosX, SIGNAL(valueChanged(double)),
            selectedObj, SLOT(setCenterX(double)));
        disconnect(ui.doubleSpinBoxPosY, SIGNAL(valueChanged(double)),
            selectedObj, SLOT(setCenterY(double)));
        disconnect(ui.doubleSpinBoxPosZ, SIGNAL(valueChanged(double)),
            selectedObj, SLOT(setCenterZ(double)));
		disconnect(ui.doubleSpinBoxScalar, SIGNAL(valueChanged(double)),
			selectedObj, SLOT(setScalar(double)));
		disconnect(ui.checkBoxFill, SIGNAL(toggled(bool)), 
			selectedObj, SLOT(setFill(bool)));
        disconnect(ui.doubleSpinBoxRadius, SIGNAL(valueChanged(double)), 
			selectedObj, SLOT(setRadius(double)));
        disconnect(ui.doubleSpinBoxSizeX, SIGNAL(valueChanged(double)), 
			selectedObj, SLOT(setLenX(double)));
        disconnect(ui.doubleSpinBoxSizeY, SIGNAL(valueChanged(double)), 
			selectedObj, SLOT(setLenY(double)));
        disconnect(ui.doubleSpinBoxSizeZ, SIGNAL(valueChanged(double)), 
			selectedObj, SLOT(setLenZ(double)));
	}

	selectedObj = scene->getPrimitive(id);
	if (selectedObj == NULL)
	{
        actions["delete"]->setEnabled(false);
	}
	else
	{
        actions["delete"]->setEnabled(true);

		connect(selectedObj, SIGNAL(operated()), this, SLOT(propertyOperated()));
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

void SceneDesignWidget::propertyOperated()
{
    if (selectedObj != NULL)
	{
		qglviewer::Vec center = selectedObj->getCenter();
        ui.doubleSpinBoxPosX->setValue(center[0]);
        ui.doubleSpinBoxPosY->setValue(center[1]);
        ui.doubleSpinBoxPosZ->setValue(center[2]);
		ui.doubleSpinBoxScalar->setValue(selectedObj->getScalar());
	}
}

void SceneDesignWidget::changePropertyWidget()
{
	if (selectedObj != NULL)
	{
		ui.lineEditObjName->setEnabled(true);
        ui.doubleSpinBoxPosX->setEnabled(true);
        ui.doubleSpinBoxPosY->setEnabled(true);
        ui.doubleSpinBoxPosZ->setEnabled(true);
		ui.doubleSpinBoxScalar->setEnabled(true);
		ui.checkBoxFill->setEnabled(true);
		ui.pushButtonColor->setEnabled(true);

		connect(ui.lineEditObjName, SIGNAL(textChanged(QString)), selectedObj, SLOT(setName(QString)));
        connect(ui.doubleSpinBoxPosX, SIGNAL(valueChanged(double)), selectedObj, SLOT(setCenterX(double)));
        connect(ui.doubleSpinBoxPosY, SIGNAL(valueChanged(double)), selectedObj, SLOT(setCenterY(double)));
        connect(ui.doubleSpinBoxPosZ, SIGNAL(valueChanged(double)), selectedObj, SLOT(setCenterZ(double)));
		connect(ui.doubleSpinBoxScalar, SIGNAL(valueChanged(double)), selectedObj, SLOT(setScalar(double)));
		connect(ui.checkBoxFill, SIGNAL(toggled(bool)), selectedObj, SLOT(setFill(bool)));
        connect(ui.doubleSpinBoxRadius, SIGNAL(valueChanged(double)), selectedObj, SLOT(setRadius(double)));
        connect(ui.doubleSpinBoxSizeX, SIGNAL(valueChanged(double)), selectedObj, SLOT(setLenX(double)));
        connect(ui.doubleSpinBoxSizeY, SIGNAL(valueChanged(double)), selectedObj, SLOT(setLenY(double)));
        connect(ui.doubleSpinBoxSizeZ, SIGNAL(valueChanged(double)), selectedObj, SLOT(setLenZ(double)));

		qglviewer::Vec center = selectedObj->getCenter();

        ui.doubleSpinBoxPosX->setValue(center[0]);
        ui.doubleSpinBoxPosY->setValue(center[1]);
        ui.doubleSpinBoxPosZ->setValue(center[2]);
		ui.doubleSpinBoxScalar->setValue(selectedObj->getScalar());

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
            ui.doubleSpinBoxPosZ->setVisible(false);
		}
		else
		{
			ui.labelPosZ->setVisible(true);
            ui.doubleSpinBoxPosZ->setVisible(true);
		}
		
		if (selectedObj->getType() == SceneUnit::Primitive::T_Object)
		{
			ui.labelRadius->setVisible(false);
            ui.doubleSpinBoxRadius->setVisible(false);
			ui.labelSize->setVisible(false);
			ui.labelSizeX->setVisible(false);
            ui.doubleSpinBoxSizeX->setVisible(false);
			ui.labelSizeY->setVisible(false);
            ui.doubleSpinBoxSizeY->setVisible(false);
			ui.labelSizeZ->setVisible(false);
            ui.doubleSpinBoxSizeZ->setVisible(false);
		}
		else if (selectedObj->getType() == SceneUnit::Primitive::T_Circle ||
			selectedObj->getType() == SceneUnit::Primitive::T_Sphere)
		{
			SceneUnit::Circle *c = (SceneUnit::Circle *)selectedObj;
			ui.labelRadius->setVisible(true);
            ui.doubleSpinBoxRadius->setVisible(true);
            ui.doubleSpinBoxRadius->setValue(c->getRadius());

			ui.labelSize->setVisible(false);
			ui.labelSizeX->setVisible(false);
            ui.doubleSpinBoxSizeX->setVisible(false);
			ui.labelSizeY->setVisible(false);
            ui.doubleSpinBoxSizeY->setVisible(false);
			ui.labelSizeZ->setVisible(false);
            ui.doubleSpinBoxSizeZ->setVisible(false);
		}
		else
		{
			ui.labelRadius->setVisible(false);
            ui.doubleSpinBoxRadius->setVisible(false);

			ui.labelSize->setVisible(true);
			ui.labelSizeX->setVisible(true);
            ui.doubleSpinBoxSizeX->setVisible(true);
			ui.labelSizeY->setVisible(true);
            ui.doubleSpinBoxSizeY->setVisible(true);

			SceneUnit::Rectangle *r = (SceneUnit::Rectangle *)selectedObj;
            ui.doubleSpinBoxSizeX->setValue(r->getLenX());
            ui.doubleSpinBoxSizeY->setValue(r->getLenY());

			if (selectedObj->getType() == SceneUnit::Primitive::T_Rect)
			{
				ui.labelSizeZ->setVisible(false);
                ui.doubleSpinBoxSizeZ->setVisible(false);
			}
			else
			{
				ui.labelSizeZ->setVisible(true);
                ui.doubleSpinBoxSizeZ->setVisible(true);

				SceneUnit::Box *b = (SceneUnit::Box *)selectedObj;
                ui.doubleSpinBoxSizeZ->setValue(b->getLenX());
			}
		}
	}
	else
	{
		ui.lineEditObjName->setEnabled(false);
        ui.doubleSpinBoxPosX->setEnabled(false);
        ui.doubleSpinBoxPosY->setEnabled(false);
        ui.doubleSpinBoxPosZ->setEnabled(false);
		ui.doubleSpinBoxScalar->setEnabled(false);
		ui.checkBoxFill->setEnabled(false);
		ui.pushButtonColor->setEnabled(false);

		ui.labelSize->setVisible(false);
		ui.labelRadius->setVisible(false);
        ui.doubleSpinBoxRadius->setVisible(false);
		ui.labelSizeX->setVisible(false);
        ui.doubleSpinBoxSizeX->setVisible(false);
		ui.labelSizeY->setVisible(false);
        ui.doubleSpinBoxSizeY->setVisible(false);
		ui.labelSizeZ->setVisible(false);
        ui.doubleSpinBoxSizeZ->setVisible(false);

		ui.lineEditObjName->setText("");
        ui.doubleSpinBoxPosX->setValue(0.0);
        ui.doubleSpinBoxPosY->setValue(0.0);
        ui.doubleSpinBoxPosZ->setValue(0.0);
		ui.doubleSpinBoxScalar->setValue(1.0);
        ui.doubleSpinBoxRadius->setValue(0.1);
        ui.doubleSpinBoxSizeX->setValue(0.2);
        ui.doubleSpinBoxSizeY->setValue(0.2);
        ui.doubleSpinBoxSizeZ->setValue(0.2);
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
