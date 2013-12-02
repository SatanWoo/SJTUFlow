#include "runsetting.h"

RunSetting::RunSetting(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(windowFlags() & 
		~Qt::WindowMinMaxButtonsHint & 
		~Qt::WindowContextHelpButtonHint);
	setModal(true);

    connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));
}

RunSetting::~RunSetting()
{

}
