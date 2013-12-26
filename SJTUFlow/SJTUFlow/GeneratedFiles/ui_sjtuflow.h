/********************************************************************************
** Form generated from reading UI file 'sjtuflow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SJTUFLOW_H
#define UI_SJTUFLOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qhorizontaltabwidget.h"
#include "titlebar.h"

QT_BEGIN_NAMESPACE

class Ui_SJTUFlowClass
{
public:
    QAction *actionCircle;
    QAction *actionRectangle;
    QAction *actionSphere;
    QAction *actionBox;
    QAction *actionMove;
    QAction *actionRotate;
    QAction *actionScale;
    QAction *actionImport;
    QAction *actionProperty;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelectAll;
    QAction *actionSetting;
    QAction *actionRun;
    QAction *actionAbout;
    QAction *actionNewFile;
    QAction *action2DScene;
    QAction *action3DScene;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionClose;
    QAction *actionCloseAll;
    QAction *actionQuit;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    TitleBar *titleBar;
    QHorizontalTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNewScene;
    QMenu *menuPrimitive;
    QMenu *menuEdit;
    QMenu *menuTool;
    QMenu *menuHelp;

    void setupUi(QMainWindow *SJTUFlowClass)
    {
        if (SJTUFlowClass->objectName().isEmpty())
            SJTUFlowClass->setObjectName(QStringLiteral("SJTUFlowClass"));
        SJTUFlowClass->resize(1024, 773);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SJTUFlowClass->sizePolicy().hasHeightForWidth());
        SJTUFlowClass->setSizePolicy(sizePolicy);
        SJTUFlowClass->setMinimumSize(QSize(1024, 773));
        QFont font;
        font.setBold(false);
        font.setItalic(false);
        font.setWeight(50);
        SJTUFlowClass->setFont(font);
        SJTUFlowClass->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SJTUFlow/Resources/SJTU-Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        SJTUFlowClass->setWindowIcon(icon);
        SJTUFlowClass->setStyleSheet(QLatin1String("*\n"
"{\n"
"	font: \"Comic Sans MS\";\n"
"	border-color: transparent;\n"
"}\n"
"QMenuBar\n"
"{\n"
"	border-color: transparent;\n"
"	background-color: transparent;\n"
"	color: white;\n"
"}\n"
"QMenuBar::item\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"QMenuBar::item:pressed:enabled\n"
"{\n"
"	background-color: rgba(20, 59, 255, 100);\n"
"}\n"
"QMenuBar::item:!enabled\n"
"{\n"
"	color: gray;\n"
"}\n"
"QTabWidget, QTabWidget::pane\n"
"{\n"
"	border-color: transparent;\n"
"}\n"
"QHorizontalTabWidget::tab-bar\n"
"{\n"
"	alignment: center;\n"
"	border-color: transparent;\n"
"}\n"
"QTabBar::tab\n"
"{\n"
"	background-color: transparent;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"	background-color: qradialgradient(spread:pad, cx:1, cy:0.5, radius:0.2, fx:1, fy:0.5, stop:0 rgba(255, 255, 255, 255), stop:1 rgba(255, 255, 255, 50));\n"
"}"));
        actionCircle = new QAction(SJTUFlowClass);
        actionCircle->setObjectName(QStringLiteral("actionCircle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Design/Resources/Icons/Circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon1);
        actionRectangle = new QAction(SJTUFlowClass);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Design/Resources/Icons/Rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon2);
        actionSphere = new QAction(SJTUFlowClass);
        actionSphere->setObjectName(QStringLiteral("actionSphere"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Design/Resources/Icons/Sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSphere->setIcon(icon3);
        actionBox = new QAction(SJTUFlowClass);
        actionBox->setObjectName(QStringLiteral("actionBox"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Design/Resources/Icons/Box.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBox->setIcon(icon4);
        actionMove = new QAction(SJTUFlowClass);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Design/Resources/Icons/Move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon5);
        actionRotate = new QAction(SJTUFlowClass);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionRotate->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Design/Resources/Icons/Rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon6);
        actionScale = new QAction(SJTUFlowClass);
        actionScale->setObjectName(QStringLiteral("actionScale"));
        actionScale->setCheckable(true);
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Design/Resources/Icons/Scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale->setIcon(icon7);
        actionImport = new QAction(SJTUFlowClass);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionProperty = new QAction(SJTUFlowClass);
        actionProperty->setObjectName(QStringLiteral("actionProperty"));
        actionUndo = new QAction(SJTUFlowClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionUndo->setEnabled(false);
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingUndo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon8);
        actionRedo = new QAction(SJTUFlowClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionRedo->setEnabled(false);
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingRedo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon9);
        actionCut = new QAction(SJTUFlowClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        actionCut->setEnabled(false);
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon10);
        actionCopy = new QAction(SJTUFlowClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        actionCopy->setEnabled(false);
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon11);
        actionPaste = new QAction(SJTUFlowClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        actionPaste->setEnabled(false);
        QIcon icon12;
        icon12.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingPaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon12);
        actionDelete = new QAction(SJTUFlowClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionDelete->setEnabled(false);
        actionSelectAll = new QAction(SJTUFlowClass);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionSetting = new QAction(SJTUFlowClass);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        actionRun = new QAction(SJTUFlowClass);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        actionAbout = new QAction(SJTUFlowClass);
        actionAbout->setObjectName(QStringLiteral("actionAbout"));
        actionNewFile = new QAction(SJTUFlowClass);
        actionNewFile->setObjectName(QStringLiteral("actionNewFile"));
        QIcon icon13;
        icon13.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingNewFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNewFile->setIcon(icon13);
        action2DScene = new QAction(SJTUFlowClass);
        action2DScene->setObjectName(QStringLiteral("action2DScene"));
        action3DScene = new QAction(SJTUFlowClass);
        action3DScene->setObjectName(QStringLiteral("action3DScene"));
        actionOpen = new QAction(SJTUFlowClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon14;
        icon14.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingOpenFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon14);
        actionSave = new QAction(SJTUFlowClass);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave->setEnabled(false);
        QIcon icon15;
        icon15.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingSaveFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon15);
        actionSaveAs = new QAction(SJTUFlowClass);
        actionSaveAs->setObjectName(QStringLiteral("actionSaveAs"));
        actionClose = new QAction(SJTUFlowClass);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon16;
        icon16.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCloseFile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon16);
        actionCloseAll = new QAction(SJTUFlowClass);
        actionCloseAll->setObjectName(QStringLiteral("actionCloseAll"));
        QIcon icon17;
        icon17.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCloseAll.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCloseAll->setIcon(icon17);
        actionQuit = new QAction(SJTUFlowClass);
        actionQuit->setObjectName(QStringLiteral("actionQuit"));
        centralWidget = new QWidget(SJTUFlowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy1);
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        titleBar = new TitleBar(centralWidget);
        titleBar->setObjectName(QStringLiteral("titleBar"));

        verticalLayout->addWidget(titleBar);

        tabWidget = new QHorizontalTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setStyleSheet(QStringLiteral(""));
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(128, 128));
        tabWidget->setElideMode(Qt::ElideNone);

        verticalLayout->addWidget(tabWidget);

        SJTUFlowClass->setCentralWidget(centralWidget);
        tabWidget->raise();
        titleBar->raise();
        menuBar = new QMenuBar(SJTUFlowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        QFont font1;
        font1.setPointSize(10);
        menuBar->setFont(font1);
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNewScene = new QMenu(menuFile);
        menuNewScene->setObjectName(QStringLiteral("menuNewScene"));
        menuPrimitive = new QMenu(menuBar);
        menuPrimitive->setObjectName(QStringLiteral("menuPrimitive"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTool = new QMenu(menuBar);
        menuTool->setObjectName(QStringLiteral("menuTool"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SJTUFlowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuPrimitive->menuAction());
        menuBar->addAction(menuTool->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuFile->addAction(actionNewFile);
        menuFile->addAction(menuNewScene->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSaveAs);
        menuFile->addSeparator();
        menuFile->addAction(actionClose);
        menuFile->addAction(actionCloseAll);
        menuFile->addSeparator();
        menuFile->addAction(actionQuit);
        menuNewScene->addAction(action2DScene);
        menuNewScene->addAction(action3DScene);
        menuPrimitive->addAction(actionCircle);
        menuPrimitive->addAction(actionRectangle);
        menuPrimitive->addAction(actionSphere);
        menuPrimitive->addAction(actionBox);
        menuPrimitive->addSeparator();
        menuPrimitive->addAction(actionMove);
        menuPrimitive->addAction(actionRotate);
        menuPrimitive->addAction(actionScale);
        menuPrimitive->addSeparator();
        menuPrimitive->addAction(actionImport);
        menuPrimitive->addSeparator();
        menuPrimitive->addAction(actionProperty);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionCut);
        menuEdit->addAction(actionCopy);
        menuEdit->addAction(actionPaste);
        menuEdit->addAction(actionDelete);
        menuEdit->addAction(actionSelectAll);
        menuTool->addAction(actionRun);
        menuTool->addSeparator();
        menuTool->addAction(actionSetting);
        menuHelp->addAction(actionAbout);

        retranslateUi(SJTUFlowClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SJTUFlowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SJTUFlowClass)
    {
        SJTUFlowClass->setWindowTitle(QApplication::translate("SJTUFlowClass", "SJTUFlow", 0));
        actionCircle->setText(QApplication::translate("SJTUFlowClass", "Circle", 0));
#ifndef QT_NO_TOOLTIP
        actionCircle->setToolTip(QApplication::translate("SJTUFlowClass", "New circle", 0));
#endif // QT_NO_TOOLTIP
        actionCircle->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Shift+C", 0));
        actionRectangle->setText(QApplication::translate("SJTUFlowClass", "Rectangle", 0));
#ifndef QT_NO_TOOLTIP
        actionRectangle->setToolTip(QApplication::translate("SJTUFlowClass", "New rectangle", 0));
#endif // QT_NO_TOOLTIP
        actionRectangle->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Shift+R", 0));
        actionSphere->setText(QApplication::translate("SJTUFlowClass", "Sphere", 0));
#ifndef QT_NO_TOOLTIP
        actionSphere->setToolTip(QApplication::translate("SJTUFlowClass", "New sphere", 0));
#endif // QT_NO_TOOLTIP
        actionSphere->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Shift+S", 0));
        actionBox->setText(QApplication::translate("SJTUFlowClass", "Box", 0));
#ifndef QT_NO_TOOLTIP
        actionBox->setToolTip(QApplication::translate("SJTUFlowClass", "New box", 0));
#endif // QT_NO_TOOLTIP
        actionBox->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Shift+B", 0));
        actionMove->setText(QApplication::translate("SJTUFlowClass", "Move", 0));
#ifndef QT_NO_TOOLTIP
        actionMove->setToolTip(QApplication::translate("SJTUFlowClass", "Move the object", 0));
#endif // QT_NO_TOOLTIP
        actionMove->setShortcut(QApplication::translate("SJTUFlowClass", "W", 0));
        actionRotate->setText(QApplication::translate("SJTUFlowClass", "Rotate", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate->setToolTip(QApplication::translate("SJTUFlowClass", "Rotate the object", 0));
#endif // QT_NO_TOOLTIP
        actionRotate->setShortcut(QApplication::translate("SJTUFlowClass", "E", 0));
        actionScale->setText(QApplication::translate("SJTUFlowClass", "Scale", 0));
#ifndef QT_NO_TOOLTIP
        actionScale->setToolTip(QApplication::translate("SJTUFlowClass", "Scale the object", 0));
#endif // QT_NO_TOOLTIP
        actionScale->setShortcut(QApplication::translate("SJTUFlowClass", "R", 0));
        actionImport->setText(QApplication::translate("SJTUFlowClass", "Import...", 0));
#ifndef QT_NO_TOOLTIP
        actionImport->setToolTip(QApplication::translate("SJTUFlowClass", "Import object", 0));
#endif // QT_NO_TOOLTIP
        actionImport->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+I", 0));
        actionProperty->setText(QApplication::translate("SJTUFlowClass", "Property", 0));
#ifndef QT_NO_TOOLTIP
        actionProperty->setToolTip(QApplication::translate("SJTUFlowClass", "The property of a object", 0));
#endif // QT_NO_TOOLTIP
        actionProperty->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+P", 0));
        actionUndo->setText(QApplication::translate("SJTUFlowClass", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("SJTUFlowClass", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Y", 0));
        actionCut->setText(QApplication::translate("SJTUFlowClass", "Cut", 0));
        actionCut->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+X", 0));
        actionCopy->setText(QApplication::translate("SJTUFlowClass", "Copy", 0));
        actionCopy->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+C", 0));
        actionPaste->setText(QApplication::translate("SJTUFlowClass", "Paste", 0));
        actionPaste->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+V", 0));
        actionDelete->setText(QApplication::translate("SJTUFlowClass", "Delete", 0));
        actionDelete->setShortcut(QApplication::translate("SJTUFlowClass", "Del", 0));
        actionSelectAll->setText(QApplication::translate("SJTUFlowClass", "Select All", 0));
        actionSelectAll->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+A", 0));
        actionSetting->setText(QApplication::translate("SJTUFlowClass", "Setting", 0));
        actionRun->setText(QApplication::translate("SJTUFlowClass", "Run", 0));
#ifndef QT_NO_TOOLTIP
        actionRun->setToolTip(QApplication::translate("SJTUFlowClass", "Run module", 0));
#endif // QT_NO_TOOLTIP
        actionRun->setShortcut(QApplication::translate("SJTUFlowClass", "F5", 0));
        actionAbout->setText(QApplication::translate("SJTUFlowClass", "&About SJTU Flow", 0));
        actionNewFile->setText(QApplication::translate("SJTUFlowClass", "New File", 0));
        actionNewFile->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+N", 0));
        action2DScene->setText(QApplication::translate("SJTUFlowClass", "2D Scene", 0));
        action2DScene->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+2", 0));
        action3DScene->setText(QApplication::translate("SJTUFlowClass", "3D Scene", 0));
        action3DScene->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+3", 0));
        actionOpen->setText(QApplication::translate("SJTUFlowClass", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("SJTUFlowClass", "Save", 0));
        actionSave->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+S", 0));
        actionSaveAs->setText(QApplication::translate("SJTUFlowClass", "Save As", 0));
        actionSaveAs->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Shift+S", 0));
        actionClose->setText(QApplication::translate("SJTUFlowClass", "Close", 0));
        actionClose->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+W", 0));
        actionCloseAll->setText(QApplication::translate("SJTUFlowClass", "Close All", 0));
#ifndef QT_NO_TOOLTIP
        actionCloseAll->setToolTip(QApplication::translate("SJTUFlowClass", "Close all", 0));
#endif // QT_NO_TOOLTIP
        actionCloseAll->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Shift+W", 0));
        actionQuit->setText(QApplication::translate("SJTUFlowClass", "Quit", 0));
        actionQuit->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+Q", 0));
        menuFile->setTitle(QApplication::translate("SJTUFlowClass", "&File", 0));
        menuNewScene->setTitle(QApplication::translate("SJTUFlowClass", "New Scene", 0));
        menuPrimitive->setTitle(QApplication::translate("SJTUFlowClass", "&Primitive", 0));
        menuEdit->setTitle(QApplication::translate("SJTUFlowClass", "&Edit", 0));
        menuTool->setTitle(QApplication::translate("SJTUFlowClass", "&Tool", 0));
        menuHelp->setTitle(QApplication::translate("SJTUFlowClass", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SJTUFlowClass: public Ui_SJTUFlowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SJTUFLOW_H
