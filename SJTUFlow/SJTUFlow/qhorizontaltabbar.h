#ifndef QHORIZONTALTABBAR_H
#define QHORIZONTALTABBAR_H

#include <QTabBar>

class QHorizontalTabBar : public QTabBar
{
public:
	QHorizontalTabBar(QWidget *parent = 0);
	~QHorizontalTabBar();

protected:
	QSize tabSizeHint(int) const;
	void paintEvent(QPaintEvent *);

private:
	
};

#endif // QHORIZONTALTABBAR_H
