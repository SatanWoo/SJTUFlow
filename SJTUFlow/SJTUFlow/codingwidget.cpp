#include "codingwidget.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QSettings>

#include <QDebug>

#include "codeedit.h"

#include "SJTUFlow/global.h"

CodingWidget::CodingWidget(QMenuBar *menubar, QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

    scriptProcess = new QProcess(this);
    connect(scriptProcess, SIGNAL(readyReadStandardError()),
        this, SLOT(showRunError()));

    parseMenuActions(menubar);

	codingTabNum = 0;
	savedIcon = QIcon(":/Coding/Resources/Icons/CodingSaved.png");
	unsavedIcon = QIcon(":/Coding/Resources/Icons/CodingUnsaved.png");

	setCentralWidget(ui.tabWidget);
	newFile();

/************************************************************************/
/*                             toolBar                                  */
/************************************************************************/
    ui.toolBar->addAction(actions["newFile"]);
    ui.toolBar->addAction(actions["open"]);
    ui.toolBar->addAction(actions["save"]);
    ui.toolBar->addAction(actions["close"]);
    ui.toolBar->addAction(actions["closeAll"]);
	ui.toolBar->addSeparator();
    ui.toolBar->addAction(actions["cut"]);
    ui.toolBar->addAction(actions["copy"]);
    ui.toolBar->addAction(actions["paste"]);
	ui.toolBar->addSeparator();
    ui.toolBar->addAction(actions["undo"]);
    ui.toolBar->addAction(actions["redo"]);

/************************************************************************/
/*                          signals and slots                           */
/************************************************************************/
	connect(ui.tabWidget, SIGNAL(tabCloseRequested(int)), this, SLOT(closeTab(int)));
    connect(ui.tabWidget, SIGNAL(currentChanged(int)), this, SLOT(checkState(int)));

    connect(actions["newFile"], SIGNAL(triggered()), this, SLOT(newFile()));
    connect(actions["close"], SIGNAL(triggered()), this, SLOT(closeFile()));
    connect(actions["closeAll"], SIGNAL(triggered()), this, SLOT(closeAll()));

    connect(actions["cut"], SIGNAL(triggered()), this, SLOT(cut()));
    connect(actions["copy"], SIGNAL(triggered()), this, SLOT(copy()));
    connect(actions["paste"], SIGNAL(triggered()), this, SLOT(paste()));
    connect(actions["selectAll"], SIGNAL(triggered()), this, SLOT(seletAll()));

    connect(actions["run"], SIGNAL(triggered()), this, SLOT(runModule()));
}

CodingWidget::~CodingWidget()
{

}

void CodingWidget::terminateScriptProcess()
{
    if (scriptProcess->state() == QProcess::Running)
    {
        scriptProcess->kill();
    }
}

void CodingWidget::loadFile(const QString &fileName)
{
	QFile file(fileName);
	if (!file.open(QFile::ReadOnly | QFile::Text))
	{
		QMessageBox::warning(this, tr("Open File Error"),
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

	curFilePath = fileName;
	emit filePathChanged(curFilePath);
}

int CodingWidget::saveOrNot(int index)
{
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->widget(index);
	if (codeEdit->document()->isModified())
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
		QMessageBox::warning(this, tr("Save File Error"), 
			tr("Can not save file %1:\n %2")
			.arg(fileName).arg(file.errorString()));
		return;
	}

	QTextStream out(&file);
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    out << codeEdit->toPlainText();

	curFilePath = fileName;
	emit filePathChanged(curFilePath);
}

void CodingWidget::parseMenuActions(QMenuBar *menubar)
{
    QMenu *menu = menubar->findChild<QMenu *>(tr("menuFile"));
    QList<QAction *> actionsList = menu->actions();
    for (int i = 0; i < actionsList.count(); i++)
    {
        QAction *action = actionsList.at(i);
        if (tr("actionNewFile") == action->objectName())
        {
            actions["newFile"] = action;
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
        else if (tr("actionClose") == action->objectName())
        {
            actions["close"] = action;
        }
        else if (tr("actionCloseAll") == action->objectName())
        {
            actions["closeAll"] = action;
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
        else if (tr("actionCut") == action->objectName())
        {
            actions["cut"] = action;
        }
        else if (tr("actionCopy") == action->objectName())
        {
            actions["copy"] = action;
        }
        else if (tr("actionPaste") == action->objectName())
        {
            actions["paste"] = action;
        }
        else if (tr("actionDelete") == action->objectName())
        {
            actions["delete"] = action;
        }
        else if (tr("actionSelectAll") == action->objectName())
        {
            actions["selectAll"] = action;
        }
    }
    menu = menubar->findChild<QMenu *>(tr("menuTool"));
    actionsList = menu->actions();
    for (int i = 0; i < actionsList.count(); i++)
    {
        QAction *action = actionsList.at(i);
        if (tr("actionRun") == action->objectName())
        {
            actions["run"] = action;
        }
		else if(tr("actionSetting") == action->objectName())
		{
			actions["setting"] = action;
		}
    }
}

void CodingWidget::newFile()
{
	CodeEdit *textEdit = new CodeEdit;
	
	connect(textEdit, SIGNAL(modificationChanged(bool)), this, SLOT(textChanged(bool)));
	connect(textEdit, SIGNAL(copyAvailable(bool)), this, SLOT(copyAvailable(bool)));
    connect(textEdit, SIGNAL(redoAvailable(bool)), actions["redo"], SLOT(setEnabled(bool)));
    connect(textEdit, SIGNAL(undoAvailable(bool)), actions["undo"], SLOT(setEnabled(bool)));

	ui.tabWidget->addTab(textEdit, savedIcon, QString("New %1").arg(++codingTabNum));
	ui.tabWidget->setCurrentIndex(ui.tabWidget->count() - 1);
	textEdit->setFocus();

	curFilePath = QString();
	emit filePathChanged(curFilePath);
}

void CodingWidget::openFile()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open"),
		QDir::homePath(), tr("Python File(*.py)"));
	if(!fileName.isEmpty())
	{
		loadFile(fileName);
	}
}

void CodingWidget::saveFile()
{
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    if (!codeEdit->document()->isModified())
	{
		return;
	}
    if (codeEdit->saved())
	{
		saveFile(codeEdit->getFileName());
	}
	else
	{
		saveAs();
	}
	codeEdit->document()->setModified(false);
	ui.tabWidget->setTabIcon(ui.tabWidget->currentIndex(), savedIcon);
}

void CodingWidget::saveAs()
{
	QString fileName = QFileDialog::getSaveFileName(this, tr("Save as "), 
		QDir::homePath(), tr("Python Files(*.py)"));
	if(!fileName.isEmpty())
	{
		CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
		codeEdit->setFileName(fileName);
		QFileInfo fileInfo(fileName);
		ui.tabWidget->setTabText(ui.tabWidget->currentIndex(), fileInfo.fileName());
		saveFile(fileName);
		codeEdit->setSaved();
		ui.tabWidget->setTabIcon(ui.tabWidget->currentIndex(), savedIcon);
	}
}

void CodingWidget::closeFile()
{
	int currentIndex = ui.tabWidget->currentIndex();
	closeTab(currentIndex);
	ui.tabWidget->currentWidget()->setFocus();
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
	curFilePath = codeEdit->getFileName();
	emit filePathChanged(curFilePath);
}

bool CodingWidget::closeAll()
{
	int count = ui.tabWidget->count();
	bool flag = true;
	while (count > 0)
	{
		ui.tabWidget->setCurrentIndex(0);
		if (!closeTab(0))
		{
			flag = false;
			break;
		}
		count--;
	}
    ui.tabWidget->currentWidget()->setFocus();
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
	curFilePath = codeEdit->getFileName();
	emit filePathChanged(curFilePath);
	return flag;
}

void CodingWidget::undo()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->undo();
}

void CodingWidget::redo()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->redo();
}

void CodingWidget::cut()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->cut();
}

void CodingWidget::copy()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->copy();
}

void CodingWidget::paste()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->paste();
}

void CodingWidget::deleteSelection()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->clear();
}

void CodingWidget::seletAll()
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    codeEdit->selectAll();
}

void CodingWidget::runModule()
{
	CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
	saveFile();
	if (!codeEdit->getFileName().isEmpty())
	{
		QSettings settings;
		QString pyPath = settings.value(tr("PyPath")).toString();
		if (pyPath.isEmpty())
		{
			actions["setting"]->trigger();
		}
		else
		{
			QString execStr = tr("import sys\nsys.path.append('%1')\n")
				.arg(QDir::currentPath()) + codeEdit->toPlainText();

            scriptProcess->start(pyPath);
            scriptProcess->waitForStarted();
            scriptProcess->write(execStr.toStdString().c_str());
            scriptProcess->closeWriteChannel();

			emit running(2);
		}
//D:/Projects/SJTUFlow/SJTUFlow/Win32/Debug
	}	
}

void CodingWidget::checkState(int)
{
    CodeEdit *codeEdit = (CodeEdit *)ui.tabWidget->currentWidget();
    if (codeEdit)
    {
        bool flag = (codeEdit->textCursor().selectedText() != "");
        actions["copy"]->setEnabled(flag);
        actions["cut"]->setEnabled(flag);
        actions["delete"]->setEnabled(flag);
        actions["paste"]->setEnabled(codeEdit->canPaste());
        actions["save"]->setEnabled(codeEdit->document()->isModified());
        actions["undo"]->setEnabled(codeEdit->canUndo());
        actions["redo"]->setEnabled(codeEdit->canRedo());

		curFilePath = codeEdit->getFileName();
		emit filePathChanged(curFilePath);
    }
}

bool CodingWidget::closeTab(int index)
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
    actions["save"]->setEnabled(changed);

}

void CodingWidget::copyAvailable( bool yes )
{
    actions["copy"]->setEnabled(yes);
    actions["cut"]->setEnabled(yes);
    actions["delete"]->setEnabled(yes);
}

void CodingWidget::showRunError()
{
    QString errStr = QString::fromLocal8Bit(scriptProcess->readAllStandardError());
	if (errStr.contains(UnconnectedException().msg.c_str()) ||
		errStr.contains(tr("QWindowsPipeReader")))
	{
		return;
	}
	errStr = errStr.replace(tr("<stdin>"), curFilePath);
	int pos = errStr.indexOf(tr("line")) + 5;
	QString num = errStr.mid(pos);
	QStringList tokens = num.split(' ', QString::SkipEmptyParts);
	int lineNum = tokens[0].toInt();
	lineNum -= 2;
	QString lineStr = tr("line %1").arg(lineNum);
	errStr = errStr.replace(QRegExp("line [0-9]+"), lineStr);
	QMessageBox::warning(this, tr("Runtime Error"), errStr, QMessageBox::Ok);
	emit running(1);
}
