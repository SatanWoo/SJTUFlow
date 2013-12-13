#include "setting.h"
#include "ui_setting.h"

#include "dllrow.h"

#include <QSettings>

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
   
	connect(ui.checkBoxRender, SIGNAL(toggled(bool)), 
		ui.groupBoxRenderOutput, SLOT(setEnabled(bool)));
	
	connect(ui.pushButtonNew, SIGNAL(clicked()), this, SLOT(insertRow()));
	connect(ui.pushButtonDelete, SIGNAL(clicked()), this, SLOT(removeRow()));
	connect(ui.listWidgetDll, SIGNAL(itemActivated(QListWidgetItem *)), 
		this, SLOT(enterEdit(QListWidgetItem *)));

    ui.pushButtonCancel->setShortcut(tr("ctrl+w"));

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
}

void Setting::removeRow()
{
	int row = ui.listWidgetDll->currentRow();

	ui.listWidgetDll->takeItem(row);
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

	QPushButton *pushbutton = qobject_cast<QPushButton *>(sender());
	if (tr("pushButtonOK") == pushbutton->objectName())
	{
		close();
	}
}

void Setting::loadSetting()
{
	//TODO load setting

	QSettings settings;
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
}
