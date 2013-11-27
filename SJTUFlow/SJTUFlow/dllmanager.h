#ifndef DLLMANAGER_H
#define DLLMANAGER_H

#include <QDialog>
#include "ui_dllmanager.h"

class DLLManager : public QDialog
{
	Q_OBJECT

public:
	DLLManager(QWidget *parent = 0);
	~DLLManager();

private:
	Ui::DLLManager ui;
};

#endif // DLLMANAGER_H
