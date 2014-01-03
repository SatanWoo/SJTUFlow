#include "setting.h"
#include "ui_setting.h"

#include "dllrow.h"
//#include "AlgorithmManager.h"

#include <QSettings>
#include <QFileDialog>
#include <QMessageBox>

Setting::Setting(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);

	isEdit = false;

    setWindowFlags(windowFlags() &
        ~Qt::WindowMinMaxButtonsHint &
        ~Qt::WindowContextHelpButtonHint);
    setModal(true);

    ui.listWidget->setCurrentRow(0);
    ui.stackedWidget->setCurrentIndex(0);

	connect(ui.pushButtonOK, SIGNAL(clicked()), this, SLOT(saveSetting()));
    connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));
	connect(ui.pushButtonApply, SIGNAL(clicked()), this, SLOT(saveSetting()));

    connect(ui.listWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));

	connect(ui.lineEditPyPath, SIGNAL(textChanged(QString)), this, SLOT(canApply(QString)));
	connect(ui.pushButtonPyPath, SIGNAL(clicked()), this, SLOT(selectPyPath()));
	connect(ui.lineEditRunOutputPath, SIGNAL(textChanged(QString)), this, SLOT(canApply(QString)));
	connect(ui.pushButtonOutputPath, SIGNAL(clicked()), this, SLOT(selectOutputDir()));
	connect(ui.lineEditRunOutputName, SIGNAL(textChanged(QString)), this, SLOT(outputNameChanged(QString)));
   
	connect(ui.checkBoxRender, SIGNAL(toggled(bool)), 
		ui.groupBoxRenderOutput, SLOT(setEnabled(bool)));
	
	connect(ui.pushButtonNew, SIGNAL(clicked()), this, SLOT(insertRow()));
	connect(ui.pushButtonDelete, SIGNAL(clicked()), this, SLOT(removeRow()));
	connect(ui.listWidgetDll, SIGNAL(itemActivated(QListWidgetItem *)), 
		this, SLOT(enterEdit(QListWidgetItem *)));

    ui.pushButtonCancel->setShortcut(tr("ctrl+w"));

	QStringList sysLibs;
	sysLibs << "SJTUFlow_Global.pyd" << "SJTUFlow_SPH.pyd" << "SJTUFlow_EG.pyd";
	QSettings settings;
	settings.setValue(tr("SysLibs"), sysLibs);

	loadSetting();
}

Setting::~Setting()
{
}

void Setting::changePage(QListWidgetItem *current, QListWidgetItem *previous)
{
    if (!current)
    {
        current = previous;
    }
    ui.stackedWidget->setCurrentIndex(ui.listWidget->row(current));
}

void Setting::selectPyPath()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Set Python Path"),
		QDir::homePath(), tr("Executable File(*.exe)"));
	if (fileName.endsWith(tr("python.exe")))
	{
		ui.lineEditPyPath->setText(fileName);
	}
	else if (!fileName.isEmpty())
	{
		QMessageBox::warning(this, tr("Warning"), 
			tr("Please select the python executable file"), QMessageBox::Ok);
	}
}

void Setting::selectOutputDir()
{
	QString dirName = QFileDialog::getExistingDirectory(
		this, tr("Set Output Directory"), QDir::homePath());
	if (!dirName.isEmpty())
	{
		ui.lineEditRunOutputPath->setText(dirName);
	}
}

void Setting::outputNameChanged( QString name )
{
	ui.labelPromote->setText(
		tr("The output files will be like %1_[0...n].txt").arg(name));
	canApply();
}

void Setting::insertRow()
{
	int row = ui.listWidgetDll->currentRow() + 1;

	QListWidgetItem *newItem = new QListWidgetItem;
	newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
	ui.listWidgetDll->insertItem(row, newItem);
	DllRow *dllrow = new DllRow;
#ifdef Q_OS_MAC
    newItem->setSizeHint(dllrow->sizeHint());
#endif
	ui.listWidgetDll->setItemWidget(newItem, dllrow);
	ui.listWidgetDll->setCurrentRow(row);
	dllrow->enterEditState();

	canApply();
}

void Setting::removeRow()
{
	int row = ui.listWidgetDll->currentRow();

	ui.listWidgetDll->takeItem(row);

	canApply();
}

void Setting::enterEdit(QListWidgetItem *item)
{
	DllRow *dllrow = qobject_cast<DllRow *>(
		ui.listWidgetDll->itemWidget(item));
	dllrow->enterEditState();
}

void Setting::saveSetting()
{
	//TODO save setting
	QSettings settings;

	QString pyPath = ui.lineEditPyPath->text();
	settings.setValue(tr("PyPath"), pyPath);

	QString outputDir = ui.lineEditRunOutputPath->text();
	if (outputDir != QDir::homePath())
	{
		settings.setValue(tr("OutputDir"), outputDir);
	}
	QString outputName = ui.lineEditRunOutputName->text();
	settings.setValue(tr("OutputName"), outputName);

	QStringList dllList;
	for (int i = 0; i < ui.listWidgetDll->count(); i++)
	{
		QListWidgetItem *item = ui.listWidgetDll->item(i);
		DllRow *dllrow = qobject_cast<DllRow *>(
			ui.listWidgetDll->itemWidget(item));
		QString text = dllrow->text();
		if (!text.isEmpty())
		{
			dllList.append(text);
		}
	}
	settings.setValue(tr("DllList"), dllList);

	ui.pushButtonApply->setEnabled(false);

	QPushButton *pushbutton = qobject_cast<QPushButton *>(sender());
	if (tr("pushButtonOK") == pushbutton->objectName())
	{
		// open dll
		for (int i = 0; i < ui.listWidgetDll->count(); i++)
		{
			QListWidgetItem *item = ui.listWidgetDll->item(i);
			DllRow *dllrow = qobject_cast<DllRow *>(
				ui.listWidgetDll->itemWidget(item));

			std::string str = dllrow->text().toStdString();
			if (str == "")
				continue;
			
//			if (AlgorithmManager::GetInstance().hModule != NULL)
//				FreeLibrary(AlgorithmManager::GetInstance().hModule);

//			wchar_t *buf = new wchar_t[str.size()+1];
//			MultiByteToWideChar(CP_ACP, NULL, str.c_str(), str.size(), buf, str.size() * sizeof(wchar_t));
//			buf[str.size()] = 0;
//			AlgorithmManager::GetInstance().hModule = LoadLibraryEx(buf, NULL, LOAD_WITH_ALTERED_SEARCH_PATH);
//			delete buf;

			break; // no dll list; just single dll
		}

		close();
	}
}

void Setting::canApply()
{
	ui.pushButtonApply->setEnabled(true);
}

void Setting::canApply(QString)
{
	canApply();
}

void Setting::loadSetting()
{
	//TODO load setting
	QSettings settings;

	QString pyPath = settings.value(tr("PyPath")).toString();
	ui.lineEditPyPath->setText(pyPath);
	QString outputDir = settings.value(tr("OutputDir")).toString();
	if (outputDir.isEmpty() || QDir(outputDir).exists())
	{
		outputDir = QDir::homePath();
		settings.setValue(tr("OutputDir"), outputDir);
	}
	ui.lineEditRunOutputPath->setText(outputDir);
	QString outputName = settings.value(tr("OutputName")).toString();
	ui.lineEditRunOutputName->setText(outputName);
	ui.labelPromote->setText(
		tr("The output files will be like %1_[0...n].txt").arg(outputName));

	QStringList dllList = settings.value(tr("DllList")).toStringList();
	foreach (QString s, dllList)
	{
		QListWidgetItem *newItem = new QListWidgetItem;
		newItem->setFlags(newItem->flags() | Qt::ItemIsEditable);
		ui.listWidgetDll->addItem(newItem);
		DllRow *dllrow = new DllRow;
		dllrow->setText(s);
		ui.listWidgetDll->setItemWidget(newItem, dllrow);
	}

	QStringList sysLibs = settings.value(tr("SysLibs")).toStringList();
	QString sysLibStr;
	foreach (QString s, sysLibs)
	{
		sysLibStr += tr("%1\n").arg(s);
	}
	ui.plainTextEditSysLib->setPlainText(sysLibStr);

	ui.pushButtonApply->setEnabled(false);
}
