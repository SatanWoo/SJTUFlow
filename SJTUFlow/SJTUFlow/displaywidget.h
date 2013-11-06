#ifndef DISPLAYWIDGET_H
#define DISPLAYWIDGET_H

#include <QMainWindow>
#include "ui_displaywidget.h"

class DisplayWidget : public QMainWindow
{
	Q_OBJECT

public:
	DisplayWidget(QWidget *parent = 0);
	~DisplayWidget();

private:
	Ui::DisplayWidget ui;
};

#endif // DISPLAYWIDGET_H
