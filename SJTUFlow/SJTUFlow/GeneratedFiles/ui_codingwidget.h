/********************************************************************************
** Form generated from reading UI file 'codingwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CODINGWIDGET_H
#define UI_CODINGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodingWidget
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionClose;
    QAction *actionCloseAll;
    QAction *actionRunModule;
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CodingWidget)
    {
        if (CodingWidget->objectName().isEmpty())
            CodingWidget->setObjectName(QStringLiteral("CodingWidget"));
        CodingWidget->resize(400, 300);
        actionNew = new QAction(CodingWidget);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/ToolBar/Resources/Icons/NewFileCoding.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(CodingWidget);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(CodingWidget);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSaveAs = new QAction(CodingWidget);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionClose = new QAction(CodingWidget);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        actionCloseAll = new QAction(CodingWidget);
        actionCloseAll->setObjectName(QStringLiteral("actionCloseAll"));
        actionRunModule = new QAction(CodingWidget);
        actionRunModule->setObjectName(QStringLiteral("actionRunModule"));
        centralWidget = new QWidget(CodingWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 361, 191));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabsClosable(true);
        CodingWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CodingWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        CodingWidget->setMenuBar(menuBar);
        toolBar = new QToolBar(CodingWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        CodingWidget->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionCloseAll);
        menuRun->addAction(actionRunModule);

        retranslateUi(CodingWidget);

        QMetaObject::connectSlotsByName(CodingWidget);
    } // setupUi

    void retranslateUi(QMainWindow *CodingWidget)
    {
        CodingWidget->setWindowTitle(QApplication::translate("CodingWidget", "CodingWidget", 0));
        actionNew->setText(QApplication::translate("CodingWidget", "New", 0));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("CodingWidget", "New File", 0));
#endif // QT_NO_TOOLTIP
        actionNew->setShortcut(QApplication::translate("CodingWidget", "Ctrl+N", 0));
        actionOpen->setText(QApplication::translate("CodingWidget", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("CodingWidget", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("CodingWidget", "Save", 0));
        actionSave->setShortcut(QApplication::translate("CodingWidget", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("CodingWidget", "Save As", 0));
        actionSaveAs->setShortcut(QApplication::translate("CodingWidget", "Ctrl+Shift+S", 0));
        actionClose->setText(QApplication::translate("CodingWidget", "Close", 0));
        actionClose->setShortcut(QApplication::translate("CodingWidget", "Ctrl+W", 0));
        actionCloseAll->setText(QApplication::translate("CodingWidget", "Close All", 0));
        actionRunModule->setText(QApplication::translate("CodingWidget", "Run Module", 0));
        actionRunModule->setShortcut(QApplication::translate("CodingWidget", "F5", 0));
        menuFile->setTitle(QApplication::translate("CodingWidget", "&File", 0));
        menuRun->setTitle(QApplication::translate("CodingWidget", "Run", 0));
    } // retranslateUi

};

namespace Ui {
    class CodingWidget: public Ui_CodingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODINGWIDGET_H
