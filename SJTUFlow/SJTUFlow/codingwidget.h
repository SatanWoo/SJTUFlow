#ifndef CODINGWIDGET_H
#define CODINGWIDGET_H

#include <QMainWindow>
#include "ui_codingwidget.h"

#define TEMP_FILE_NAME ".tmp"

class CodingWidget : public QMainWindow
{
	Q_OBJECT

public:
	CodingWidget(QWidget *parent = 0);
	~CodingWidget();

private:
	Ui::CodingWidget ui;

	int codingTabNum; // record how many tabs have been added

	void loadFile(const QString &fileName);
	int saveOrNot(int index);
	void saveFile(const QString &fileName);

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

	void runModule();

/************************************************************************/
/*                        tab slots                                     */
/************************************************************************/
	bool closeTab(int index);
};

#endif // CODINGWIDGET_H
