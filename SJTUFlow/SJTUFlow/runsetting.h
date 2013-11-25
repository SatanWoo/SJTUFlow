#ifndef RUNSETTING_H
#define RUNSETTING_H

#include <QDialog>
#include "ui_runsetting.h"

class RunSetting : public QDialog
{
	Q_OBJECT

public:
	RunSetting(QWidget *parent = 0);
	~RunSetting();

private:
	Ui::RunSetting ui;
};

#endif // RUNSETTING_H
