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
#include <QtWidgets/QVBoxLayout>
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
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelectAll;
    QAction *actionSettingRun;
    QAction *actionSettingRender;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuRun;
    QMenu *menuEdit;
    QMenu *menuRender;
    QToolBar *toolBar;

    void setupUi(QMainWindow *CodingWidget)
    {
        if (CodingWidget->objectName().isEmpty())
            CodingWidget->setObjectName(QStringLiteral("CodingWidget"));
        CodingWidget->resize(400, 300);
        CodingWidget->setContextMenuPolicy(Qt::NoContextMenu);
        CodingWidget->setStyleSheet(QLatin1String("CodingWidget{background-color: rgba(255, 255, 255, 50);}\n"
"QMenuBar\n"
"{\n"
"	border-color: transparent;\n"
"	background-color: transparent;\n"
"	color: white;\n"
"}\n"
"QMenuBar::item\n"
"{\n"
"	background-color: transparent;\n"
"	\n"
"}\n"
"QToolBar, QTabWidget, QTabBar\n"
"{\n"
"	background-color: transparent;\n"
"	border-color: transparent;\n"
"}\n"
"QMenuBar::item:pressed\n"
"{\n"
"	background-color: rgba(20, 59, 255, 100);\n"
"}\n"
"QTabWidget::pane\n"
"{\n"
"	border-color: transparent;\n"
"	background-color: transparent;\n"
"	border-radius: 5px;\n"
"}\n"
"QTabBar::tab\n"
"{\n"
"	background-color: rgba(255, 255, 255, 100);\n"
"	border-color: rgba(255, 255, 255, 200);\n"
"    border-top-right-radius: 4px;\n"
"	padding: 2px;\n"
"}\n"
"QTabBar::tab:!selected\n"
"{\n"
"	margin-top: 2px;\n"
"	border-top-right-radius: 4px;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	margin-right: -4px;\n"
"	border-top-right-radius: 4px;\n"
"	background-color: rgba(255, 255, 255, 200);\n"
"}"));
        actionNew = new QAction(CodingWidget);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingNewFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(CodingWidget);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingOpenFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionSave = new QAction(CodingWidget);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingSaveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon2);
        actionSaveAs = new QAction(CodingWidget);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionClose = new QAction(CodingWidget);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCloseFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon3);
        actionCloseAll = new QAction(CodingWidget);
        actionCloseAll->setObjectName(QStringLiteral("actionCloseAll"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCloseAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCloseAll->setIcon(icon4);
        actionRunModule = new QAction(CodingWidget);
        actionRunModule->setObjectName(QStringLiteral("actionRunModule"));
        actionUndo = new QAction(CodingWidget);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo->setEnabled(false);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingUndo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon5);
        actionRedo = new QAction(CodingWidget);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionRedo->setEnabled(false);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingRedo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon6);
        actionCut = new QAction(CodingWidget);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCut->setEnabled(false);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon7);
        actionCopy = new QAction(CodingWidget);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCopy->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon8);
        actionPaste = new QAction(CodingWidget);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingPaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon9);
        actionDelete = new QAction(CodingWidget);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionDelete->setEnabled(false);
        actionSelectAll = new QAction(CodingWidget);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionSettingRun = new QAction(CodingWidget);
        actionSettingRun->setObjectName(QStringLiteral("actionSettingRun"));
        actionSettingRender = new QAction(CodingWidget);
        actionSettingRender->setObjectName(QStringLiteral("actionSettingRender"));
        centralWidget = new QWidget(CodingWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabsClosable(true);

        verticalLayout->addWidget(tabWidget);

        CodingWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CodingWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuRun = new QMenu(menuBar);
        menuRun->setObjectName(QStringLiteral("menuRun"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuRender = new QMenu(menuBar);
        menuRender->setObjectName(QStringLiteral("menuRender"));
        CodingWidget->setMenuBar(menuBar);
        toolBar = new QToolBar(CodingWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(16, 16));
        toolBar->setFloatable(false);
        CodingWidget->addToolBar(Qt::TopToolBarArea, toolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuRun->menuAction());
        menuBar->addAction(menuRender->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionCloseAll);
        menuRun->addAction(actionRunModule);
        menuRun->addSeparator();
        menuRun->addAction(actionSettingRun);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionSelectAll);
        menuRender->addAction(actionSettingRender);

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
        actionUndo->setText(QApplication::translate("CodingWidget", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("CodingWidget", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("CodingWidget", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("CodingWidget", "Ctrl+Y", 0));
        actionCut->setText(QApplication::translate("CodingWidget", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("CodingWidget", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("CodingWidget", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("CodingWidget", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("CodingWidget", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("CodingWidget", "Ctrl+V", 0));
        actionDelete->setText(QApplication::translate("CodingWidget", "Delete", 0));
        actionDelete->setShortcut(QApplication::translate("CodingWidget", "Del", 0));
        actionSelectAll->setText(QApplication::translate("CodingWidget", "Select All", 0));
        actionSelectAll->setShortcut(QApplication::translate("CodingWidget", "Ctrl+A", 0));
        actionSettingRun->setText(QApplication::translate("CodingWidget", "Setting", 0));
        actionSettingRender->setText(QApplication::translate("CodingWidget", "Setting", 0));
        menuFile->setTitle(QApplication::translate("CodingWidget", "&File", 0));
        menuRun->setTitle(QApplication::translate("CodingWidget", "Run", 0));
        menuEdit->setTitle(QApplication::translate("CodingWidget", "&Edit", 0));
        menuRender->setTitle(QApplication::translate("CodingWidget", "Render", 0));
    } // retranslateUi

};

namespace Ui {
    class CodingWidget: public Ui_CodingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODINGWIDGET_H
