#include "qhorizontaltabbar.h"

#include <QtWidgets/QStylePainter>
#include <QtWidgets/QStyleOptionTabV3>

QHorizontalTabBar::QHorizontalTabBar(QWidget *parent)
	: QTabBar(parent)
{
	setIconSize(QSize(160, 240));
}

QHorizontalTabBar::~QHorizontalTabBar()
{

}

QSize QHorizontalTabBar::tabSizeHint(int) const
{
	return QSize(160, 240);
}

void QHorizontalTabBar::paintEvent(QPaintEvent *)
{
	QStylePainter p(this);
	QFont font = QFont("Courier", 16);
	font.setFixedPitch(true);
	for (int index = 0; index < count(); index++)
	{
		QStyleOptionTabV3 tab;
		initStyleOption(&tab, index);

		QIcon tempIcon = tab.icon;
		QString tempText = tab.text;
		tab.icon = QIcon();
		tab.text = QString();

		p.drawControl(QStyle::CE_TabBarTab, tab);

		QPainter painter;
		painter.begin(this);
		painter.setFont(font);
		QRect tabrect = tabRect(index);
		tabrect.adjust(0, 40, 0, -40);
		painter.drawText(tabrect, Qt::AlignBottom | Qt::AlignHCenter, tempText);
		tempIcon.paint(&painter, 16, tabrect.top(), tab.iconSize.width(), tab.iconSize.height(), Qt::AlignTop | Qt::AlignHCenter);    
		painter.end();
	}
}
