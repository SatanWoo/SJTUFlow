#ifndef SJTUFLOW_H
#define SJTUFLOW_H

#include <QtWidgets/QMainWindow>
#include "ui_sjtuflow.h"

#include "titlebar.h"
#include "scenedesignwidget.h"
#include "codingwidget.h"
#include "displaywidget.h"

class SJTUFlow : public QMainWindow
{
	Q_OBJECT

public:
	SJTUFlow(QWidget *parent = 0);
	~SJTUFlow();

protected:
	void paintEvent(QPaintEvent *);

private:
	Ui::SJTUFlowClass ui;

	QPixmap bgImage;

	TitleBar *titleBar;
	SceneDesignWidget *sceneDesignWidget;
	CodingWidget *codingWidget;
	DisplayWidget *displayWidget;

private slots:
    void tabChanged(int index);

    void sharedOpen();
    void sharedSave();
    void sharedSaveAs();
    void sharedUndo();
    void sharedRedo();
    void sharedDelete();
};

#endif // SJTUFLOW_H
