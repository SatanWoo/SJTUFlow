#include "pysyntaxhighlighter.h"

PySyntaxHighlighter::PySyntaxHighlighter(QTextDocument *parent)
	: QSyntaxHighlighter(parent)
{
	PyHighlightingRule rule;

	// keywords
	keywordFormat.setForeground(QBrush(QColor("#8cc4ff")));
	QStringList keywordPatterns;
	keywordPatterns << "\\bbreak\\b" << "\\bcontinue\\b" << "\\bdel\\b"
		<< "\\bexec\\b" << "\\breturn\\b" << "\\bpass\\b" << "\\braise\\b"
		<< "\\bglobal\\b" << "\\bassert\\b" << "\\blambda\\b" << "\\byield\\b"
		<< "\\bwith\\b" << "\\bdef\\b" << "\\bclass\\b" << "\\bfor\\b"
		<< "\\bwhile\\b" << "\\bif\\b" << "\\belif\\b" << "\\belse\\b"
		<< "\\bimport\\b" << "\\bfrom\\b" << "\\bas\\b" << "\\btry\\b"
		<< "\\bexcept\\b" << "\\bfinally\\b" << "\\band\\b" << "\\bin\\b"
		<< "\\bis\\b" << "\\bnot\\b" << "\\bor\\b" << "\\bprint\\b";
	foreach (const QString &pattern, keywordPatterns)
	{
		rule.pattern = QRegExp(pattern);
		rule.format = keywordFormat;
		highlightingRules.append(rule);
	}

	// built-in objects and functions
	builtinFormat.setForeground(QBrush(QColor("#ad7fa8")));
	QStringList builtinPatterns;
	builtinPatterns << "\\bTrue\\b" << "\\bFalse\\b" << "\\bNone\\b" 
		<< "\\b__debug__\\b" << "\\b__doc__\\b" << "\\b__file__\\b"
		<< "\\b__name__\\b" << "\\b__package__\\b" << "\\babs\\b" 
		<< "\\ball\\b" << "\\bany\\b" << "\\bbasestring\\b" << "\\bbin\\b" 
		<< "\\bbool\\b" << "\\bbytearray\\b" << "\\bcallable\\b" << "\\bchr\\b"
		<< "\\bclassmethod\\b" << "\\bcmp\\b" << "\\bcompile\\b" 
		<< "\\bcomplex\\b" << "\\bdelattr\\b" << "\\bdict\\b" << "\\bdir\\b"
		<< "\\bdivmod\\b" << "\\benumerate\\b" << "\\beval\\b" 
		<< "\\bexecfile\\b" << "\\bfile\\b" << "\\bfilter\\b" << "\\bfloat\\b" 
		<< "\\bformat\\b" << "\\bfrozenset\\b" << "\\bgetattr\\b" 
		<< "\\bglobals\\b" << "\\bhasattr\\b" << "\\bhash\\b" << "\\bhelp\\b" 
		<< "\\bhex\\b" << "\\bid\\b" << "\\binput\\b" << "\\bint\\b" 
		<< "\\bisinstance\\b" << "\\bissubclass\\b" << "\\biter\\b" 
		<< "\\blen\\b" << "\\blist\\b" << "\\blocals\\b" << "\\blong\\b" 
		<< "\\bmap\\b" << "\\bmax\\b" << "\\bmemoryview\\b" << "\\bmin\\b" 
		<< "\\bnext\\b" << "\\bobject\\b" << "\\boct\\b" << "\\bopend\\b" 
		<< "\\bord\\b" << "\\bpow\\b" << "\\bproperty\\b" << "\\brange\\b" 
		<< "\\braw_input\\b" << "\\breduce\\b" << "\\breload\\b" 
		<< "\\brepr\\b" << "\\breversed\\b" << "\\bround\\b" << "\\bset\\b" 
		<< "\\bsetattr\\b" << "\\bslice\\b" << "\\bsorted\\b" 
		<< "\\bstaticmethod\\b" << "\\bstr\\b" << "\\bsum\\b" << "\\bsuper\\b"
		<< "\\btuple\\b" << "\\btype\\b" << "\\bunichr\\b" << "\\bunicode\\b"
		<< "\\bvars\\b" << "\\bxrange\\b" << "\\bzip\\b" << "\\b__import__\\b"
		<< "\\bapply\\b" << "\\bbuffer\\b" << "\\bcoerce\\b" << "\\bintern\\b";
	foreach (const QString &pattern, builtinPatterns)
	{
		rule.pattern = QRegExp(pattern);
		rule.format = builtinFormat;
		highlightingRules.append(rule);
	}

	// quotation
	quotationFormat.setForeground(QBrush(QColor("#e9b96e")));
	rule.pattern = QRegExp("'.*'|\".*\"");
	rule.pattern.setMinimal(true);
	rule.format = quotationFormat;
	highlightingRules.append(rule);

	// comments
	commentFormat.setForeground(QBrush(QColor("#73d216")));
	rule.pattern = QRegExp("#[^\n]*");
	rule.format = commentFormat;
	highlightingRules.append(rule);
}

PySyntaxHighlighter::~PySyntaxHighlighter()
{

}

void PySyntaxHighlighter::highlightBlock( const QString &text )
{
	foreach (const PyHighlightingRule &rule, highlightingRules)
	{
		QRegExp expression(rule.pattern);
		int index = expression.indexIn(text);
		while (index >= 0)
		{
			int length = expression.matchedLength();
			setFormat(index, length, rule.format);
			index = expression.indexIn(text, index + length);
		}
	}

	setCurrentBlockState(0);

// 	int startIndex = 0;
// 	if (previousBlockState() != 1)
// 	{
// 		startIndex = commentStartExpression.indexIn(text);
// 	}
// 
// 	while (startIndex >= 0) {
// 		//! [10] //! [11]
// 		int endIndex = commentEndExpression.indexIn(text, startIndex);
// 		int commentLength;
// 		if (endIndex == -1) {
// 			setCurrentBlockState(1);
// 			commentLength = text.length() - startIndex;
// 		} else {
// 			commentLength = endIndex - startIndex
// 				+ commentEndExpression.matchedLength();
// 		}
// 		setFormat(startIndex, commentLength, multiLineCommentFormat);
// 		startIndex = commentStartExpression.indexIn(text, startIndex + commentLength);
// 	}
}
