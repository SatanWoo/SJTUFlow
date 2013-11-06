#include "codingwidget.h"

#include <QtWidgets/QMessageBox>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QFileDialog>
#include <QFile>
#include <QTextStream>

CodingWidget::CodingWidget(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	setCentralWidget(ui.tabWidget);
	codingTabNum = 0;
	newFile();

/************************************************************************/
/*                             toolBar                                  */
/************************************************************************/
	ui.toolBar->addAction(ui.actionNew);

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
}

CodingWidget::~CodingWidget()
{

}

int CodingWidget::saveOrNotCoding( int index )
{
	QTextEdit *textEdit = (QTextEdit *)ui.tabWidget->widget(index);
	if (textEdit->document()->isModified())
	{
		QMessageBox box;
		box.setWindowTitle(tr("Save"));
		box.setIcon(QMessageBox::Question);
		box.setText(tr("Save file ") + ui.tabWidget->tabText(index));
		box.setStandardButtons(QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);

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
			tr("Can not save file %1:\n %2").arg(fileName).arg(file.errorString()));
		return;
	}

	QTextStream out(&file);
	QTextEdit *textEdit = (QTextEdit *)ui.tabWidget->currentWidget();
	out << textEdit->toPlainText();
}

void CodingWidget::newFile()
{
	QTextEdit *textEdit = new QTextEdit;
	ui.tabWidget->addTab(textEdit, QString("New %1").arg(++codingTabNum));
	ui.tabWidget->setCurrentIndex(ui.tabWidget->count() - 1);
	textEdit->setFocus();
}

void CodingWidget::openFile()
{

}

void CodingWidget::saveFile()
{

}

void CodingWidget::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Áí´æÎª"));
	if(!fileName.isEmpty())
	{
		saveFile(fileName);
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

bool CodingWidget::closeTab( int index )
{
	int ret = saveOrNotCoding(index);

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
