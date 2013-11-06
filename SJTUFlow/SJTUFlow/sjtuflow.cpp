#include "sjtuflow.h"

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QFileDialog>
#include <QFile>
#include <QTextStream>

SJTUFlow::SJTUFlow(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setCentralWidget(ui.tabWidget);
	setWindowFlags(windowFlags() & ~Qt::WindowMaximizeButtonHint);
	setFixedSize(width(), height());
	ui.tabWidget->setCurrentIndex(0);

/************************************************************************/
/*                             Menu                                     */
/************************************************************************/
	menuBarSceneDesign = new QMenuBar;
	menuBarSceneDesign->addAction("File");
	ui.verticalLayoutSceneDesign->setMenuBar(menuBarSceneDesign);

	menuBarCoding = new QMenuBar;
	QMenu *menuCodingFile = new QMenu(tr("&File"));
	
	QAction * actionNewFileCoding = 
		menuCodingFile->addAction(QIcon(":/ToolBar/Resources/Icons/NewFileCoding.png"),
			tr("&New"), this, SLOT(newFileCoding()), QKeySequence::New);
	menuCodingFile->addAction(tr("&Open"), this, SLOT(openFileCoding()), QKeySequence::Open);
	menuCodingFile->addSeparator();
	menuCodingFile->addAction(tr("&Save"), this, SLOT(saveFileCoding()), QKeySequence::Save);
	menuCodingFile->addAction(tr("&Save As"), this, SLOT(saveAsCoding()), QKeySequence::SaveAs);
	menuCodingFile->addSeparator();
	menuCodingFile->addAction(tr("&Close"), this, SLOT(closeFileCoding()), tr("Ctrl+W"));
	menuCodingFile->addAction(tr("&Close All"), this, SLOT(closeAllCoding()));

	menuBarCoding->addMenu(menuCodingFile);
	ui.verticalLayoutCoding->setMenuBar(menuBarCoding);

	menuBarDisplay = new QMenuBar;
	menuBarDisplay->addAction("File");
	ui.verticalLayoutDisplay->setMenuBar(menuBarDisplay);

	codingTabNum = 0;

/************************************************************************/
/*                            Toolbar						            */
/************************************************************************/
	toolBarSceneDesign = new QToolBar;

	toolBarCoding = new QToolBar;
	toolBarCoding->setMovable(true);
	toolBarCoding->setFloatable(true);
	toolBarCoding->addAction(actionNewFileCoding);

	toolBarDisplay = new QToolBar;

/************************************************************************/
/*                           coding tabWidget                           */
/************************************************************************/
	tabWidgetCoding = new QTabWidget;
	tabWidgetCoding->setTabsClosable(true);
	connect(tabWidgetCoding, 
		SIGNAL(tabCloseRequested(int)),
		this, SLOT(closeCodingTab(int)));
	newFileCoding();

/************************************************************************/
/*                             Layout                                   */
/************************************************************************/
	ui.verticalLayoutSceneDesign->addWidget(toolBarSceneDesign);
	ui.verticalLayoutSceneDesign->addWidget(ui.graphicsViewSceneDesign);
	ui.tabSceneDesign->setLayout(ui.verticalLayoutSceneDesign);
	
	ui.verticalLayoutCoding->addWidget(toolBarCoding);
	ui.verticalLayoutCoding->addWidget(tabWidgetCoding);
	ui.tabCoding->setLayout(ui.verticalLayoutCoding);

	ui.verticalLayoutDisplay->addWidget(toolBarDisplay);
	ui.tabDisplay->setLayout(ui.verticalLayoutDisplay);
}

SJTUFlow::~SJTUFlow()
{

}

int SJTUFlow::saveOrNotCoding( int index )
{
	QTextEdit *textEdit = (QTextEdit *)tabWidgetCoding->widget(index);
	if (textEdit->document()->isModified())
	{
		QMessageBox box;
		box.setWindowTitle(tr("Save"));
		box.setIcon(QMessageBox::Question);
		box.setText(tr("Save file ") + tabWidgetCoding->tabText(index));
		box.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

		int ret = box.exec();
		if(ret == QMessageBox::Yes)
		{
			saveFileCoding();
		}
		return ret;
	}

	return 0;
}

void SJTUFlow::saveFileCoding(const QString &fileName)
{
	QFile file(fileName);

	if (!file.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, tr("Save file"), 
			tr("Can not save file %1:\n %2").arg(fileName).arg(file.errorString()));
		return;
	}

	QTextStream out(&file);
	QTextEdit *textEdit = (QTextEdit *)tabWidgetCoding->currentWidget();
	out << textEdit->toPlainText();
}

void SJTUFlow::newFileCoding()
{
	QTextEdit *textEdit = new QTextEdit;
	tabWidgetCoding->addTab(textEdit, QString("New %1").arg(++codingTabNum));
	tabWidgetCoding->setCurrentIndex(tabWidgetCoding->count() - 1);
	textEdit->setFocus();
}

void SJTUFlow::openFileCoding()
{

}

void SJTUFlow::saveFileCoding()
{

}

void SJTUFlow::saveAsCoding()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Áí´æÎª"));
	if(!fileName.isEmpty())
	{
		saveFileCoding(fileName);
	}
}

void SJTUFlow::closeFileCoding()
{
	int currentIndex = tabWidgetCoding->currentIndex();
	closeCodingTab(currentIndex);
	tabWidgetCoding->currentWidget()->setFocus();
}

void SJTUFlow::closeAllCoding()
{
	int count = tabWidgetCoding->count();
	while (count > 0)
	{
		tabWidgetCoding->setCurrentIndex(0);
		if (!closeCodingTab(0))
		{
			break;
		}
		count--;
	}
	tabWidgetCoding->currentWidget()->setFocus();
}

bool SJTUFlow::closeCodingTab( int index )
{
	int ret = saveOrNotCoding(index);

	if (ret == QMessageBox::Cancel)
	{
		return false;
	}
	if (tabWidgetCoding->count() == 1 && ret != 0)
	{
		newFileCoding();
	}
	if (tabWidgetCoding->count() > 1)
	{
		tabWidgetCoding->removeTab(index);
	}
	return true;
}
