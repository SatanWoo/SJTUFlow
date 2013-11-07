#ifndef PYSYNTAXHIGHLIGHTER_H
#define PYSYNTAXHIGHLIGHTER_H

#include <QSyntaxHighlighter>
#include <QTextCharFormat>

QT_BEGIN_NAMESPACE
class QTextDocument;
QT_END_NAMESPACE

class PySyntaxHighlighter : public QSyntaxHighlighter
{
	Q_OBJECT

public:
	PySyntaxHighlighter(QTextDocument *parent = 0);
	~PySyntaxHighlighter();

protected:
	void highlightBlock(const QString &text);

private:
	struct PyHighlightingRule
	{
		QRegExp pattern;
		QTextCharFormat format;
	};

	QVector<PyHighlightingRule> highlightingRules;

	QRegExp commentStartExpression;
	QRegExp commentEndExpression;

	QTextCharFormat keywordFormat;
	QTextCharFormat builtinFormat;
	QTextCharFormat commentFormat;
	QTextCharFormat quotationFormat;
};

#endif // PYSYNTAXHIGHLIGHTER_H
