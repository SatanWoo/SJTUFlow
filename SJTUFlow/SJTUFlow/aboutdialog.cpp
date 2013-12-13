#include "aboutdialog.h"

#include <QDesktopServices>
#include <QShortcut>

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

    QShortcut *shortcut = new QShortcut(QKeySequence("ctrl+w"), this);
    connect(shortcut, SIGNAL(activated()), this, SLOT(close()));
}

AboutDialog::~AboutDialog()
{

}
