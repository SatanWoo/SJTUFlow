#include "qhorizontaltabwidget.h"

#include "qhorizontaltabbar.h"

QHorizontalTabWidget::QHorizontalTabWidget(QWidget *parent)
	: QTabWidget(parent)
{
	setTabBar(new QHorizontalTabBar());
}

QHorizontalTabWidget::~QHorizontalTabWidget()
{

}
