#ifndef TITLEBAR_H
#define TITLEBAR_H

#include <QWidget>
#include "ui_titlebar.h"

class TitleBar : public QWidget
{
	Q_OBJECT

public:
	TitleBar(QWidget *parent = 0);
	~TitleBar();

protected:
	void mousePressEvent(QMouseEvent *);
	void mouseMoveEvent(QMouseEvent *);
	void mouseReleaseEvent(QMouseEvent *);

private:
	Ui::TitleBar ui;

	bool pressed;
	QPoint clickPos;
};

#endif // TITLEBAR_H
