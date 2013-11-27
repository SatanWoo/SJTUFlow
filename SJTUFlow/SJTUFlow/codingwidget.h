#ifndef CODINGWIDGET_H
#define CODINGWIDGET_H

#include <QMainWindow>
#include "ui_codingwidget.h"

#include "dllmanager.h"
#include "runsetting.h"
#include "rendersetting.h"

#define TEMP_FILE_NAME ".tmp"

class CodingWidget : public QMainWindow
{
	Q_OBJECT

public:
	CodingWidget(QWidget *parent = 0);
	~CodingWidget();

protected:

private:
	Ui::CodingWidget ui;

	DLLManager *dllManager;
	RunSetting *settingRun;
	RenderSetting *settingRender;

	int codingTabNum; // record how many tabs have been added
	QIcon savedIcon;
	QIcon unsavedIcon;

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
	void textChanged(bool changed);

/************************************************************************/
/*                        tool bar slots                                */
/************************************************************************/
	void copyAvailable(bool yes);
};

#endif // CODINGWIDGET_H
