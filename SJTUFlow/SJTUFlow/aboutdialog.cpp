#include "aboutdialog.h"

AboutDialog::AboutDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(windowFlags() &
		~Qt::WindowMinMaxButtonsHint &
		~Qt::WindowContextHelpButtonHint);
}

AboutDialog::~AboutDialog()
{

}
