#ifndef CODINGWIDGET_H
#define CODINGWIDGET_H

#include <QMap>
#include <QMainWindow>
#include <QMenuBar>
#include <QProcess>
#include "ui_codingwidget.h"

class CodingWidget : public QMainWindow
{
	Q_OBJECT

public:
    CodingWidget(QMenuBar *menubar, QWidget *parent = 0);
	~CodingWidget();

	QString filePath(){ return curFilePath; }

signals:
	void filePathChanged(QString);
	void running(int);

protected:

private:
	Ui::CodingWidget ui;

    QMap<QString, QAction *> actions;

	int codingTabNum; // record how many tabs have been added
	QIcon savedIcon;
	QIcon unsavedIcon;

	QString curFilePath;

	void loadFile(const QString &fileName);
	int saveOrNot(int index);
	void saveFile(const QString &fileName);
    void parseMenuActions(QMenuBar *menubar);

public slots:
/************************************************************************/
/*                        menu slots                                    */
/************************************************************************/
	void newFile();
	void openFile();
	void saveFile();
	void saveAs();
	void closeFile();
	bool closeAll();

    void undo();
    void redo();
    void cut();
    void copy();
    void paste();
    void deleteSelection();
    void seletAll();

	void runModule();

/************************************************************************/
/*                        tab slots                                     */
/************************************************************************/
    void checkState(int);
	bool closeTab(int index);
	void textChanged(bool changed);

/************************************************************************/
/*                        tool bar slots                                */
/************************************************************************/
	void copyAvailable(bool yes);

	void showRunError();
};

#endif // CODINGWIDGET_H
