#include "codeedit.h"

#include <QPainter>

CodeEdit::CodeEdit(QWidget *parent)
	: QPlainTextEdit(parent)
{
	highlighter = new PySyntaxHighlighter(document());
	lineNumberArea = new LineNumberArea(this);
	saved = false;

	QFont font = QFont("Courier", 10);
	font.setFixedPitch(true);
	setFont(font);

	setStyleSheet("background-color:#2e3436;color:#ffffff");

	connect(this, SIGNAL(blockCountChanged(int)), this, SLOT(updateLineNumberAreaWidth(int)));
	connect(this, SIGNAL(updateRequest(QRect, int)), this, SLOT(updateLineNumberArea(QRect, int)));

	updateLineNumberAreaWidth(0);
}

CodeEdit::~CodeEdit()
{

}

void CodeEdit::lineNumberAreaPaintEvent( QPaintEvent *event )
{
	QPainter painter(lineNumberArea);
	painter.fillRect(event->rect(), Qt::lightGray);

	QTextBlock block = firstVisibleBlock();
	int blockNumber = block.blockNumber();
	int top = (int) blockBoundingGeometry(block).translated(contentOffset()).top();
	int bottom = top + (int) blockBoundingRect(block).height();

	while (block.isValid() && top <= event->rect().bottom()) 
	{
		if (block.isVisible() && bottom >= event->rect().top()) 
		{
			QString number = QString::number(blockNumber + 1);
			painter.setPen(Qt::black);
			painter.drawText(0, top, lineNumberArea->width(), fontMetrics().height(),
				Qt::AlignRight, number);
		}

		block = block.next();
		top = bottom;
		bottom = top + (int) blockBoundingRect(block).height();
		++blockNumber;
	}
}

int CodeEdit::lineNumberAreaWidth()
{
	int digits = 1;
	int max = qMax(1, blockCount());
	while (max >= 10) 
	{
		max /= 10;
		++digits;
	}

	int space = 3 + fontMetrics().width(QLatin1Char('9')) * digits;

	return space;
}

void CodeEdit::resizeEvent( QResizeEvent *event )
{
	QPlainTextEdit::resizeEvent(event);

	QRect cr = contentsRect();
	lineNumberArea->setGeometry(QRect(cr.left(), cr.top(), lineNumberAreaWidth(), cr.height()));
}

void CodeEdit::updateLineNumberAreaWidth( int newBlockCount )
{
	setViewportMargins(lineNumberAreaWidth(), 0, 0, 0);
}

void CodeEdit::updateLineNumberArea( const QRect &rect, int dy )
{
	if (dy)
	{
		lineNumberArea->scroll(0, dy);
	}
	else
	{
		lineNumberArea->update(0, rect.y(), lineNumberArea->width(), rect.height());
	}

	if (rect.contains(viewport()->rect()))
	{
		updateLineNumberAreaWidth(0);
	}
}
