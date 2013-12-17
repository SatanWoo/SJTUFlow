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

private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

	void selectPyPath();

	void insertRow();
	void removeRow();

	void enterEdit(QListWidgetItem *item);

	void canApply();
	void canApply(QString);
	void saveSetting();

private:
    Ui::Setting ui;
	
	bool isEdit;

	void loadSetting();
};

#endif // SETTING_H
