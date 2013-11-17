#include "qhorizontaltabwidget.h"

#include "qhorizontaltabbar.h"
#include <QPainter>

QHorizontalTabWidget::QHorizontalTabWidget(QWidget *parent)
	: QTabWidget(parent)
{
	setTabBar(new QHorizontalTabBar());
}

QHorizontalTabWidget::~QHorizontalTabWidget()
{

}

void QHorizontalTabWidget::paintEvent( QPaintEvent * )
{
	QPainter painter(this);
	painter.fillRect(rect(), Qt::transparent);
}
