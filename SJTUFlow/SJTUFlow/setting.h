#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QListWidgetItem>

#include "ui_setting.h"

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

public slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

private:
    Ui::Setting ui;
};

#endif // SETTING_H
