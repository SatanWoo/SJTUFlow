#include "aboutdialog.h"

#include <QDesktopServices>

AboutDialog::AboutDialog(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);

	setWindowFlags(windowFlags() &
		~Qt::WindowMinMaxButtonsHint &
		~Qt::WindowContextHelpButtonHint);

	QString name = QCoreApplication::applicationName();
	QString version = QCoreApplication::applicationVersion();
	ui.labelName->setText(tr("%1 v%2").arg(name).arg(version));
}

AboutDialog::~AboutDialog()
{

}
