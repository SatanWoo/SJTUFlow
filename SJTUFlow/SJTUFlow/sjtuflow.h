#ifndef SJTUFLOW_H
#define SJTUFLOW_H

#include <QtWidgets/QMainWindow>
#include "ui_sjtuflow.h"

#include <QtWidgets/QMenuBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTabWidget>

class SJTUFlow : public QMainWindow
{
	Q_OBJECT

public:
	SJTUFlow(QWidget *parent = 0);
	~SJTUFlow();

private:
	Ui::SJTUFlowClass ui;

	QMenuBar *menuBarSceneDesign;
	QMenuBar *menuBarCoding;
	QMenuBar *menuBarDisplay;
	QToolBar *toolBarSceneDesign;
	QToolBar *toolBarCoding;
	QToolBar *toolBarDisplay;

	int codingTabNum; // record how many tabs have been added
	QTabWidget *tabWidgetCoding;
	
	int saveOrNotCoding(int index);
	void saveFileCoding(const QString &filename);

private slots:
/************************************************************************/
/*                        menu slots                                    */
/************************************************************************/
	void newFileCoding();
	void openFileCoding();
	void saveFileCoding();
	void saveAsCoding();
	void closeFileCoding();
	void closeAllCoding();
	
/************************************************************************/
/*                        tab slots                                     */
/************************************************************************/
	bool closeCodingTab(int index);
};

#endif // SJTUFLOW_H
