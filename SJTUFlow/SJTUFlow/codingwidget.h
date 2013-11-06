#ifndef CODINGWIDGET_H
#define CODINGWIDGET_H

#include <QMainWindow>
#include "ui_codingwidget.h"

class CodingWidget : public QMainWindow
{
	Q_OBJECT

public:
	CodingWidget(QWidget *parent = 0);
	~CodingWidget();

private:
	Ui::CodingWidget ui;

	int codingTabNum; // record how many tabs have been added

	int saveOrNotCoding(int index);
	void saveFile(const QString &filename);

private slots:
/************************************************************************/
/*                        menu slots                                    */
/************************************************************************/
	void newFile();
	void openFile();
	void saveFile();
	void saveAs();
	void closeFile();
	void closeAll();

/************************************************************************/
/*                        tab slots                                     */
/************************************************************************/
	bool closeTab(int index);
};

#endif // CODINGWIDGET_H
