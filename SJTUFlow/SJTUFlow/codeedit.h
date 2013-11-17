#ifndef CODEEDIT_H
#define CODEEDIT_H

#include <QPlainTextEdit>

#include "pysyntaxhighlighter.h"

class LineNumberArea;

class CodeEdit : public QPlainTextEdit
{
	Q_OBJECT

public:
	CodeEdit(QWidget *parent = 0);
	~CodeEdit();

	void lineNumberAreaPaintEvent(QPaintEvent *event);
	int lineNumberAreaWidth();

	void setFileName(QString name){ fileName = name; }
	QString getFileName(){ return fileName; }
	void setSaved(){ saved = true; }
	bool isSaved(){ return saved; }
	bool isChanged(){ return changed; }

protected:
	void resizeEvent(QResizeEvent *event);
	void contextMenuEvent(QContextMenuEvent *e){}

private slots:
 	void updateLineNumberAreaWidth(int newBlockCount);
	void updateLineNumberArea(const QRect &, int);
	void contentChanged(bool changed);

private:
	PySyntaxHighlighter *highlighter;
	LineNumberArea *lineNumberArea;
	QString fileName;
	bool saved;
	bool changed;
	int tabWidth;
};

class LineNumberArea : public QWidget
{
public:
	LineNumberArea(CodeEdit *edit) : QWidget(edit)
	{
		codeEdit = edit;
	}

	QSize sizeHint() const
	{
		return QSize(codeEdit->lineNumberAreaWidth(), 0);
	}

protected:
	void paintEvent(QPaintEvent *event)
	{
		codeEdit->lineNumberAreaPaintEvent(event);
	}

private:
	CodeEdit *codeEdit;
};

#endif // CODEEDIT_H
