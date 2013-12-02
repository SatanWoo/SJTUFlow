#include "setting.h"
#include "ui_setting.h"

Setting::Setting(QWidget *parent) :
    QDialog(parent)
{
    ui.setupUi(this);

    setWindowFlags(windowFlags() &
        ~Qt::WindowMinMaxButtonsHint &
        ~Qt::WindowContextHelpButtonHint);
    setModal(true);

    ui.listWidget->setCurrentRow(0);
    ui.stackedWidget->setCurrentIndex(0);

    connect(ui.pushButtonCancel, SIGNAL(clicked()), this, SLOT(close()));

    connect(ui.listWidget, SIGNAL(currentItemChanged(QListWidgetItem*,QListWidgetItem*)),
            this, SLOT(changePage(QListWidgetItem*,QListWidgetItem*)));
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
