#include "sjtuflow.h"

#include <QMessageBox>

SJTUFlow::SJTUFlow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	bgImage.load(":/SJTUFlow/Resources/background.jpg");

	setWindowFlags(Qt::FramelessWindowHint);
    setGeometry(100, 25, width(), height());

    ui.verticalLayout->insertWidget(1, ui.menuBar);

    setting = new Setting;
	aboutDialog = new AboutDialog;

/************************************************************************/
/*                             tab widget                               */
/************************************************************************/
    sceneDesignWidget = new SceneDesignWidget(ui.menuBar);
	ui.tabWidget->addTab(sceneDesignWidget, 
		QIcon(":/Icons/Resources/Icons/SceneDesign.png"), tr("Scene Design"));

    codingWidget = new CodingWidget(ui.menuBar);
	ui.tabWidget->addTab(codingWidget,
		QIcon(":/Icons/Resources/Icons/Coding.png"), tr("Coding"));
	connect(codingWidget, SIGNAL(running()), this, SLOT(display()));

	displayWidget = new DisplayWidget;
	ui.tabWidget->addTab(displayWidget,
		QIcon(":/Icons/Resources/Icons/Display.png"), tr("Display"));

    connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(tabChanged(int)));

    ui.tabWidget->setCurrentIndex(0);
	tabChanged(0);

/************************************************************************/
/*                           connect                                    */
/************************************************************************/
    connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(sharedOpen()));
    connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(sharedSave()));
    connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(sharedSaveAs()));
    connect(ui.actionUndo, SIGNAL(triggered()), this, SLOT(sharedUndo()));
    connect(ui.actionRedo, SIGNAL(triggered()), this, SLOT(sharedRedo()));
    connect(ui.actionDelete, SIGNAL(triggered()), this, SLOT(sharedDelete()));

    connect(ui.actionQuit, SIGNAL(triggered()), this, SLOT(close()));

    connect(ui.actionSetting, SIGNAL(triggered()), setting, SLOT(show()));

	connect(ui.actionAbout, SIGNAL(triggered()), aboutDialog, SLOT(show()));

	connect(ui.action2DScene, SIGNAL(triggered()), sceneDesignWidget, SLOT(new2DScene()));
	connect(ui.action3DScene, SIGNAL(triggered()), sceneDesignWidget, SLOT(new3DScene()));

	connect(ui.actionProperty, SIGNAL(triggered()), sceneDesignWidget, SLOT(showProperty()));

	connect(sceneDesignWidget, SIGNAL(filePathChanged(QString)), ui.titleBar, SLOT(setFilePath(QString)));
	connect(codingWidget, SIGNAL(filePathChanged(QString)), ui.titleBar, SLOT(setFilePath(QString)));
}

SJTUFlow::~SJTUFlow()
{

}

void SJTUFlow::paintEvent( QPaintEvent *)
{
	QPainter painter(this);
    painter.drawPixmap(rect(), bgImage);
}

void SJTUFlow::closeEvent(QCloseEvent *e)
{
	ui.tabWidget->setCurrentIndex(0);
	if (!sceneDesignWidget->saved())
	{
		QMessageBox box;
		box.setWindowTitle(tr("Save"));
		box.setIcon(QMessageBox::Question);
		box.setText(tr("Save scene file "));
		box.setStandardButtons(QMessageBox::Yes | 
			QMessageBox::No | QMessageBox::Cancel);

		int ret = box.exec();
		if(ret == QMessageBox::Yes)
		{
			sceneDesignWidget->saveScene();
		}
		else if (ret == QMessageBox::Cancel)
		{
			e->ignore();
			return;
		}
	}
	ui.tabWidget->setCurrentIndex(1);
	if (!codingWidget->closeAll())
	{
		e->ignore();
	}
}

void SJTUFlow::tabChanged(int index)
{
    switch (index)
    {
    case 0:
        ui.menuFile->setEnabled(true);
        ui.menuEdit->setEnabled(true);
        ui.menuPrimitive->setEnabled(true);
        ui.actionNewFile->setVisible(false);
        ui.menuNewScene->menuAction()->setVisible(true);
		ui.action2DScene->setVisible(true);
		ui.action3DScene->setVisible(true);
        ui.actionClose->setVisible(false);
        ui.actionCloseAll->setVisible(false);
        ui.actionRun->setEnabled(false);
        ui.actionCut->setVisible(false);
        ui.actionCopy->setVisible(false);
        ui.actionPaste->setVisible(false);
        ui.actionSelectAll->setVisible(false);
        sceneDesignWidget->checkState();
		ui.titleBar->setFilePath(sceneDesignWidget->filePath());
		displayWidget->stopAnimate();
        break;
    case 1:
        ui.menuFile->setEnabled(true);
        ui.menuEdit->setEnabled(true);
        ui.menuPrimitive->setEnabled(false);
        ui.actionNewFile->setVisible(true);
        ui.menuNewScene->menuAction()->setVisible(false);
		ui.action2DScene->setVisible(false);
		ui.action3DScene->setVisible(false);
        ui.actionClose->setVisible(true);
        ui.actionCloseAll->setVisible(true);
        ui.actionRun->setEnabled(true);
        ui.actionCut->setVisible(true);
        ui.actionCopy->setVisible(true);
        ui.actionPaste->setVisible(true);
        ui.actionSelectAll->setVisible(true);
        codingWidget->checkState(0);
		ui.titleBar->setFilePath(codingWidget->filePath());
		displayWidget->stopAnimate();
        break;
    case 2:
        ui.menuFile->setEnabled(false);
        ui.menuEdit->setEnabled(false);
        ui.menuPrimitive->setEnabled(false);
        ui.actionRun->setEnabled(false);
		ui.titleBar->setFilePath(QString());
		//displayWidget->cloneScene(sceneDesignWidget->getScene());
		displayWidget->startAnimate();
    default:
        break;
    }
}

void SJTUFlow::sharedOpen()
{
    if (ui.tabWidget->currentIndex() == 0)
    {
		sceneDesignWidget->openScene();
    }
    else if (ui.tabWidget->currentIndex() == 1)
    {
        codingWidget->openFile();
    }
}

void SJTUFlow::sharedSave()
{
    if (ui.tabWidget->currentIndex() == 0)
    {
		sceneDesignWidget->saveScene();
    }
    else if (ui.tabWidget->currentIndex() == 1)
    {
        codingWidget->saveFile();
    }
}

void SJTUFlow::sharedSaveAs()
{
    if (ui.tabWidget->currentIndex() == 0)
    {
		sceneDesignWidget->saveAs();
    }
    else if (ui.tabWidget->currentIndex() == 1)
    {
        codingWidget->saveAs();
    }
}

void SJTUFlow::sharedUndo()
{
    if (ui.tabWidget->currentIndex() == 0)
    {
		sceneDesignWidget->undo();
    }
    else if (ui.tabWidget->currentIndex() == 1)
    {
        codingWidget->undo();
    }
}

void SJTUFlow::sharedRedo()
{
    if (ui.tabWidget->currentIndex() == 0)
    {
		sceneDesignWidget->redo();
    }
    else if (ui.tabWidget->currentIndex() == 1)
    {
        codingWidget->redo();
    }
}

void SJTUFlow::sharedDelete()
{
    if (ui.tabWidget->currentIndex() == 0)
    {
        sceneDesignWidget->deleteObject();
    }
    else if (ui.tabWidget->currentIndex() == 1)
    {
        codingWidget->deleteSelection();
    }
}

void SJTUFlow::display()
{
	ui.tabWidget->setCurrentIndex(2);
}
