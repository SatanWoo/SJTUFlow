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
    void setSaved(){ stateSaved = true; }
    bool saved(){ return stateSaved; }
    bool canUndo(){ return stateCanUndo; }
    bool canRedo(){ return stateCanRedo; }

protected:
	void resizeEvent(QResizeEvent *event);

private slots:
 	void updateLineNumberAreaWidth(int newBlockCount);
	void updateLineNumberArea(const QRect &, int);
    void changeUndoState(bool canUndo);
    void changeRedoState(bool canRedo);

private:
	PySyntaxHighlighter *highlighter;
	LineNumberArea *lineNumberArea;
	QString fileName;
    bool stateSaved;
    bool stateCanUndo;
    bool stateCanRedo;
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
