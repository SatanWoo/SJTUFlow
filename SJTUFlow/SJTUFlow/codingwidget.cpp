#include "codingwidget.h"

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QFileDialog>
#include <QFile>
#include <QTextStream>

#include "codeedit.h"

CodingWidget::CodingWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	codingTabNum = 0;
	savedIcon = QIcon(":/Coding/Resources/Icons/CodingSaved.png");
	unsavedIcon = QIcon(":/Coding/Resources/Icons/CodingUnsaved.png");

	setCentralWidget(ui.tabWidget);
	newFile();

/************************************************************************/
/*                             toolBar                                  */
/************************************************************************/
	ui.toolBar->addAction(ui.actionNew);
	ui.toolBar->addAction(ui.actionOpen);
	ui.toolBar->addAction(ui.actionSave);
	ui.toolBar->addAction(ui.actionClose);
	ui.toolBar->addAction(ui.actionCloseAll);
	ui.toolBar->addSeparator();
	ui.toolBar->addAction(ui.actionCut);
	ui.toolBar->addAction(ui.actionCopy);
	ui.toolBar->addAction(ui.actionPaste);
	ui.toolBar->addSeparator();
	ui.toolBar->addAction(ui.actionUndo);
	ui.toolBar->addAction(ui.actionRedo);

/************************************************************************/
/*                          signals and slots                           */
/************************************************************************/
	connect(ui.tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));

	connect(ui.actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(ui.actionOpen, SIGNAL(triggered()), this, SLOT(openFile()));
	connect(ui.actionSave, SIGNAL(triggered()), this, SLOT(saveFile()));
	connect(ui.actionSaveAs, SIGNAL(triggered()), this, SLOT(saveAs()));
	connect(ui.actionClose, SIGNAL(triggered()), this, SLOT(closeFile()));
	connect(ui.actionCloseAll, SIGNAL(triggered()), this, SLOT(closeAll()));

	connect(ui.actionRunModule, SIGNAL(triggered()), this, SLOT(runModule()));
}

CodingWidget::~CodingWidget()
{

}

void CodingWidget::loadFile( const QString &fileName )
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, tr("Open file"),
			tr("Can not open file %1:\n %2.")
			.arg(fileName).arg(file.errorString()));
		return;
	}

	QTextStream in(&file);
	newFile();
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
	codeEdit->setPlainText(in.readAll());
	codeEdit->setFileName(fileName);
	codeEdit->setSaved();
	ui.tabWidget->setTabText(ui.tabWidget->currentIndex(), 
		QFileInfo(fileName).fileName());
}

int CodingWidget::saveOrNot( int index )
{
	QTextEdit *textEdit = (QTextEdit *)ui.tabWidget->widget(index);
	if (textEdit->document()->isModified())
	{
		QMessageBox box;
		box.setWindowTitle(tr("Save"));
		box.setIcon(QMessageBox::Question);
		box.setText(tr("Save file ") + ui.tabWidget->tabText(index));
		box.setStandardButtons(QMessageBox::Yes | 
			QMessageBox::No | QMessageBox::Cancel);

		int ret = box.exec();
		if(ret == QMessageBox::Yes)
		{
			saveFile();
		}
		return ret;
	}

	return 0;
}

void CodingWidget::saveFile(const QString &fileName)
{
	QFile file(fileName);

	if (!file.open(QFile::WriteOnly | QFile::Text))
	{
		QMessageBox::warning(this, tr("Save file"), 
			tr("Can not save file %1:\n %2")
			.arg(fileName).arg(file.errorString()));
		return;
	}

	QTextStream out(&file);
	QTextEdit *textEdit = (QTextEdit *)ui.tabWidget->currentWidget();
	out << textEdit->toPlainText();
}

void CodingWidget::newFile()
{
	CodeEdit *textEdit = new CodeEdit;
	
	connect(textEdit, SIGNAL(modificationChanged(bool)), this, SLOT(textChanged(bool)));
	connect(textEdit, SIGNAL(copyAvailable(bool)), this, SLOT(copyAvailable(bool)));
	connect(textEdit, SIGNAL(redoAvailable(bool)), ui.actionRedo, SLOT(setEnabled(bool)));
	connect(textEdit, SIGNAL(undoAvailable(bool)), ui.actionUndo, SLOT(setEnabled(bool)));

	connect(ui.actionUndo, SIGNAL(triggered()), textEdit, SLOT(undo()));
	connect(ui.actionRedo, SIGNAL(triggered()), textEdit, SLOT(redo()));
	connect(ui.actionCut, SIGNAL(triggered()), textEdit, SLOT(cut()));
	connect(ui.actionCopy, SIGNAL(triggered()), textEdit, SLOT(copy()));
	connect(ui.actionPaste, SIGNAL(triggered()), textEdit, SLOT(paste()));
	connect(ui.actionDelete, SIGNAL(triggered()), textEdit, SLOT(clear()));
	connect(ui.actionSelectAll, SIGNAL(triggered()), textEdit, SLOT(selectAll()));

	ui.tabWidget->addTab(textEdit, savedIcon, QString("New %1").arg(++codingTabNum));
	ui.tabWidget->setCurrentIndex(ui.tabWidget->count() - 1);
	textEdit->setFocus();
}

void CodingWidget::openFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		QString(), tr("Python File(*.py)"));
	if(!fileName.isEmpty())
	{
		loadFile(fileName);
	}
}

void CodingWidget::saveFile()
{
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
	if (!codeEdit->isChanged())
	{
		return;
	}
	if (codeEdit->isSaved())
	{
		saveFile(codeEdit->getFileName());
	}
	else
	{
		saveAs();
	}
}

void CodingWidget::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save as "), 
		QString(), tr("Python Files(*.py)"));
	if(!fileName.isEmpty())
	{
		CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
		codeEdit->setFileName(fileName);
		QFileInfo fileInfo(fileName);
		ui.tabWidget->setTabText(ui.tabWidget->currentIndex(), fileInfo.fileName());
		saveFile(fileName);
		codeEdit->setSaved();
	}
}

void CodingWidget::closeFile()
{
	int currentIndex = ui.tabWidget->currentIndex();
	closeTab(currentIndex);
	ui.tabWidget->currentWidget()->setFocus();
}

void CodingWidget::closeAll()
{
	int count = ui.tabWidget->count();
	while (count > 0)
	{
		ui.tabWidget->setCurrentIndex(0);
		if (!closeTab(0))
		{
			break;
		}
		count--;
	}
	ui.tabWidget->currentWidget()->setFocus();
}

void CodingWidget::runModule()
{
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
	saveFile();
	if (!codeEdit->getFileName().isEmpty())
	{
		system(QString("E:\\Python27\\python %1 > %2")
			.arg(codeEdit->getFileName()).arg(TEMP_FILE_NAME)
			.toStdString().c_str());

		QFile file(tr(TEMP_FILE_NAME));
		file.open(QFile::ReadOnly | QFile::Text);
		QTextStream in(&file);
		QString output = in.readAll();
		file.close();
		QFile::remove(tr(TEMP_FILE_NAME));
		QMessageBox::information(this, tr("Output"), output, QMessageBox::Ok);
	}	
}

bool CodingWidget::closeTab( int index )
{
	int ret = saveOrNot(index);

	if (ret == QMessageBox::Cancel)
	{
		return false;
	}
	if (ui.tabWidget->count() == 1 && ret != 0)
	{
		newFile();
	}
	if (ui.tabWidget->count() > 1)
	{
		ui.tabWidget->removeTab(index);
	}
	return true;
}

void CodingWidget::textChanged(bool changed)
{
	if (changed)
	{
		ui.tabWidget->setTabIcon(ui.tabWidget->currentIndex(), unsavedIcon);
	}
	else
	{
		ui.tabWidget->setTabIcon(ui.tabWidget->currentIndex(), savedIcon);
	}
	ui.actionSave->setEnabled(changed);
}

void CodingWidget::copyAvailable( bool yes )
{
	ui.actionCopy->setEnabled(yes);
	ui.actionCut->setEnabled(yes);
	ui.actionDelete->setEnabled(yes);
}
