/********************************************************************************
** Form generated from reading UI file 'displaywidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYWIDGET_H
#define UI_DISPLAYWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWidget
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DisplayWidget)
    {
        if (DisplayWidget->objectName().isEmpty())
            DisplayWidget->setObjectName(QStringLiteral("DisplayWidget"));
        DisplayWidget->resize(400, 300);
        centralWidget = new QWidget(DisplayWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DisplayWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(DisplayWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        DisplayWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DisplayWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        DisplayWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(DisplayWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        DisplayWidget->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());

        retranslateUi(DisplayWidget);

        QMetaObject::connectSlotsByName(DisplayWidget);
    } // setupUi

    void retranslateUi(QMainWindow *DisplayWidget)
    {
        DisplayWidget->setWindowTitle(QApplication::translate("DisplayWidget", "DisplayWidget", 0));
        menuFile->setTitle(QApplication::translate("DisplayWidget", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayWidget: public Ui_DisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWIDGET_H
