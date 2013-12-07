#include "titlebar.h"

#include <QStyle>
#include <QMouseEvent>
#include <QPainter>

#include <iostream>

TitleBar::TitleBar(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	pressed = false;

	title = tr("SJTU Flow");
	ui.labelTitle->setText(title);
	parent->setWindowTitle(title);

	connect(ui.toolButtonClose, SIGNAL(clicked()), parent->parent(), SLOT(close()));
	connect(ui.toolButtonMin, SIGNAL(clicked()), parent->parent(), SLOT(showMinimized()));
}

TitleBar::~TitleBar()
{

}

void TitleBar::setFilePath(QString path)
{
	if (path.isEmpty())
	{
		ui.labelTitle->setText(title);
	}
	else
	{
		QString text = tr("%1 - %2").arg(title).arg(path);
		ui.labelTitle->setText(text);
	}
}

void TitleBar::mousePressEvent( QMouseEvent *me )
{
	clickPos = mapToParent(me->pos());
	pressed = true;
}

void TitleBar::mouseMoveEvent( QMouseEvent *me )
{
	if (pressed)
	{
		parentWidget()->parentWidget()->move(me->globalPos() - clickPos);
	}
}

void TitleBar::mouseReleaseEvent( QMouseEvent * )
{
	pressed = false;
}
