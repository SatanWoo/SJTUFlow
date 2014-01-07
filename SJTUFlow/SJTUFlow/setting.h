#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QListWidgetItem>

#include "ui_setting.h"

const int sizes[2][2] = {{640, 480}, {800, 600}};

class Setting : public QDialog
{
    Q_OBJECT

public:
    explicit Setting(QWidget *parent = 0);
    ~Setting();

protected:
	void showEvent(QShowEvent *);

private slots:
    void changePage(QListWidgetItem *current, QListWidgetItem *previous);

	void selectPyPath();
	void selectOutputDir();
	void selectRenderOutputDir();
	void outputNameChanged(QString name);

	void insertRow();
	void removeRow();

	void enterEdit(QListWidgetItem *item);

	void canApply();
	void canApply(QString);
	void canApply(int);
	void saveSetting();

private:
    Ui::Setting ui;
	
	bool isEdit;

	void loadSetting();
};

#endif // SETTING_H
