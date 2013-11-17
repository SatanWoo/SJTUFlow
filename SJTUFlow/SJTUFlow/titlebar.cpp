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

	QPixmap pix = style()->standardPixmap(QStyle::SP_TitleBarCloseButton);
	QImage img = pix.toImage();
	img.invertPixels(QImage::InvertRgb);
	ui.toolButtonClose->setIcon(QPixmap::fromImage(img));
	
	pix = style()->standardPixmap(QStyle::SP_TitleBarMinButton);
	img = pix.toImage();
	img.invertPixels(QImage::InvertRgb);
	ui.toolButtonMin->setIcon(QPixmap::fromImage(img));

	ui.labelTitle->setText("SJTU Flow");
	parent->setWindowTitle("SJTU Flow");

	connect(ui.toolButtonClose, SIGNAL(clicked()), parent->parent(), SLOT(close()));
	connect(ui.toolButtonMin, SIGNAL(clicked()), parent->parent(), SLOT(showMinimized()));
}

TitleBar::~TitleBar()
{

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
