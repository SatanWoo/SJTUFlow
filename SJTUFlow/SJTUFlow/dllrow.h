#ifndef DLLROW_H
#define DLLROW_H

#include <QWidget>
#include <QStyledItemDelegate>
#include "ui_dllrow.h"

class DllRow : public QWidget
{
	Q_OBJECT

public:
	DllRow(QWidget *parent = 0);
	~DllRow();

	void setText(QString text){ ui.lineEdit->setText(text); }
	QString text(){ return ui.lineEdit->text(); }

public slots:
	void enterEditState();
	void leaveEditState();

private slots:
	void openDll();

private:
	Ui::DllRow ui;
};

#endif // DLLROW_H
