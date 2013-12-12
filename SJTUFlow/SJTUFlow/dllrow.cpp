#include "dllrow.h"

#include <QFileDialog>

DllRow::DllRow(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	connect(ui.lineEdit, SIGNAL(textChanged(QString)), 
		ui.label, SLOT(setText(QString)));
	connect(ui.lineEdit, SIGNAL(editingFinished()), 
		this, SLOT(leaveEditState()));
	connect(ui.pushButton, SIGNAL(clicked()), this, SLOT(openDll()));

	leaveEditState();
}

DllRow::~DllRow()
{

}

void DllRow::enterEditState()
{
	ui.label->setVisible(false);
	ui.lineEdit->setVisible(true);
	ui.pushButton->setVisible(true);
	ui.lineEdit->setFocus();
}

void DllRow::leaveEditState()
{
	// TODO binding dll

	if (!ui.pushButton->hasFocus())
	{
		ui.label->setVisible(true);
		ui.lineEdit->setVisible(false);
		ui.pushButton->setVisible(false);
	}
}

void DllRow::openDll()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Load Dll"),
		QDir::homePath(), tr("Dynamic Link Libraries(*.dll)"));
	if(!fileName.isEmpty())
	{
		ui.lineEdit->setText(fileName);
		// TODO binding dll
	}
	ui.lineEdit->setFocus();
}
