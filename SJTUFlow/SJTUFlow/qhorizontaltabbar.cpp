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

void QHorizontalTabBar::paintEvent(QPaintEvent *e)
{
	QList<QIcon> icons;
	QList<QSize> iconSizes;
	QList<QString> texts;
	for (int index = 0; index < count(); index++)
	{
		QStyleOptionTabV3 tab;
		initStyleOption(&tab, index);

		icons.append(tab.icon);
		iconSizes.append(tab.iconSize);
		texts.append(tab.text);

		// don't paint the icon and text
		setTabIcon(index, QIcon());
		setTabText(index, QString());
	}
	QTabBar::paintEvent(e);

	QFont font = QFont("Courier", 16);
	font.setFixedPitch(true);
	for (int index = 0; index < count(); index++)
	{
		QIcon icon = icons.at(index);
		QSize iconSize = iconSizes.at(index);
		QString text = texts.at(index);

		QRect tabrect = tabRect(index);
		tabrect.adjust(0, 40, 0, -40);

		// restore the icon and text
		setTabIcon(index, icon);
		setTabText(index, text);

		QPainter painter;
		painter.begin(this);
		painter.setFont(font);
		painter.setPen(Qt::white);
		painter.drawText(tabrect, Qt::AlignBottom | Qt::AlignHCenter, text);
		icon.paint(&painter, 16, tabrect.top(), iconSize.width(), iconSize.height(), Qt::AlignTop | Qt::AlignHCenter);    
		painter.end();
	}
}
