#ifndef QHORIZONTALTABWIDGET_H
#define QHORIZONTALTABWIDGET_H

#include <QTabWidget>

class QHorizontalTabWidget : public QTabWidget
{
public:
	QHorizontalTabWidget(QWidget *parent);
	~QHorizontalTabWidget();

protected:
	void paintEvent(QPaintEvent *);

private:
	
};

#endif // QHORIZONTALTABWIDGET_H
