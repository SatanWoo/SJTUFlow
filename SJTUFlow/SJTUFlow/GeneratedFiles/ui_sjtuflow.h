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
    QAction *actionImport_Object;
    QAction *actionProperty;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionCut;
    QAction *actionCopy;
    QAction *actionPaste;
    QAction *actionDelete;
    QAction *actionSelectAll;
    QAction *actionOption;
    QAction *actionRun;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    TitleBar *titleBar;
    QHorizontalTabWidget *tabWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuPrimitive;
    QMenu *menuEdit;
    QMenu *menuTools;
    QMenu *menuHelp;

    void setupUi(QMainWindow *SJTUFlowClass)
    {
        if (SJTUFlowClass->objectName().isEmpty())
            SJTUFlowClass->setObjectName(QStringLiteral("SJTUFlowClass"));
        SJTUFlowClass->resize(1024, 773);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SJTUFlowClass->sizePolicy().hasHeightForWidth());
        SJTUFlowClass->setSizePolicy(sizePolicy);
        SJTUFlowClass->setContextMenuPolicy(Qt::NoContextMenu);
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
"QMenuBar::item:pressed\n"
"{\n"
"	background-color: rgba(20, 59, 255, 100);\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/Design/Resources/Icons/Circle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCircle->setIcon(icon);
        actionRectangle = new QAction(SJTUFlowClass);
        actionRectangle->setObjectName(QStringLiteral("actionRectangle"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Design/Resources/Icons/Rectangle.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRectangle->setIcon(icon1);
        actionSphere = new QAction(SJTUFlowClass);
        actionSphere->setObjectName(QStringLiteral("actionSphere"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Design/Resources/Icons/Sphere.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSphere->setIcon(icon2);
        actionBox = new QAction(SJTUFlowClass);
        actionBox->setObjectName(QStringLiteral("actionBox"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Design/Resources/Icons/Box.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionBox->setIcon(icon3);
        actionMove = new QAction(SJTUFlowClass);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionMove->setCheckable(true);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Design/Resources/Icons/Move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon4);
        actionRotate = new QAction(SJTUFlowClass);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionRotate->setCheckable(true);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Design/Resources/Icons/Rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon5);
        actionScale = new QAction(SJTUFlowClass);
        actionScale->setObjectName(QStringLiteral("actionScale"));
        actionScale->setCheckable(true);
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/Design/Resources/Icons/Scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale->setIcon(icon6);
        actionImport_Object = new QAction(SJTUFlowClass);
        actionImport_Object->setObjectName(QStringLiteral("actionImport_Object"));
        actionProperty = new QAction(SJTUFlowClass);
        actionProperty->setObjectName(QStringLiteral("actionProperty"));
        actionUndo = new QAction(SJTUFlowClass);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingUndo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUndo->setIcon(icon7);
        actionRedo = new QAction(SJTUFlowClass);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingRedo.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRedo->setIcon(icon8);
        actionCut = new QAction(SJTUFlowClass);
        actionCut->setObjectName(QStringLiteral("actionCut"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCut.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCut->setIcon(icon9);
        actionCopy = new QAction(SJTUFlowClass);
        actionCopy->setObjectName(QStringLiteral("actionCopy"));
        QIcon icon10;
        icon10.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingCopy.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionCopy->setIcon(icon10);
        actionPaste = new QAction(SJTUFlowClass);
        actionPaste->setObjectName(QStringLiteral("actionPaste"));
        QIcon icon11;
        icon11.addFile(QStringLiteral(":/Coding/Resources/Icons/CodingPaste.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionPaste->setIcon(icon11);
        actionDelete = new QAction(SJTUFlowClass);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionSelectAll = new QAction(SJTUFlowClass);
        actionSelectAll->setObjectName(QStringLiteral("actionSelectAll"));
        actionOption = new QAction(SJTUFlowClass);
        actionOption->setObjectName(QStringLiteral("actionOption"));
        actionRun = new QAction(SJTUFlowClass);
        actionRun->setObjectName(QStringLiteral("actionRun"));
        centralWidget = new QWidget(SJTUFlowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
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
        menuBar->setGeometry(QRect(0, 0, 1024, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuPrimitive = new QMenu(menuBar);
        menuPrimitive->setObjectName(QStringLiteral("menuPrimitive"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuTools = new QMenu(menuBar);
        menuTools->setObjectName(QStringLiteral("menuTools"));
        menuHelp = new QMenu(menuBar);
        menuHelp->setObjectName(QStringLiteral("menuHelp"));
        SJTUFlowClass->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuPrimitive->menuAction());
        menuBar->addAction(menuTools->menuAction());
        menuBar->addAction(menuHelp->menuAction());
        menuPrimitive->addAction(actionCircle);
        menuPrimitive->addAction(actionRectangle);
        menuPrimitive->addAction(actionSphere);
        menuPrimitive->addAction(actionBox);
        menuPrimitive->addSeparator();
        menuPrimitive->addAction(actionMove);
        menuPrimitive->addAction(actionRotate);
        menuPrimitive->addAction(actionScale);
        menuPrimitive->addSeparator();
        menuPrimitive->addAction(actionImport_Object);
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
        menuTools->addAction(actionRun);
        menuTools->addSeparator();
        menuTools->addAction(actionOption);

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
        actionRectangle->setText(QApplication::translate("SJTUFlowClass", "Rectangle", 0));
#ifndef QT_NO_TOOLTIP
        actionRectangle->setToolTip(QApplication::translate("SJTUFlowClass", "New rectangle", 0));
#endif // QT_NO_TOOLTIP
        actionSphere->setText(QApplication::translate("SJTUFlowClass", "Sphere", 0));
#ifndef QT_NO_TOOLTIP
        actionSphere->setToolTip(QApplication::translate("SJTUFlowClass", "New sphere", 0));
#endif // QT_NO_TOOLTIP
        actionBox->setText(QApplication::translate("SJTUFlowClass", "Box", 0));
#ifndef QT_NO_TOOLTIP
        actionBox->setToolTip(QApplication::translate("SJTUFlowClass", "New box", 0));
#endif // QT_NO_TOOLTIP
        actionMove->setText(QApplication::translate("SJTUFlowClass", "Move", 0));
#ifndef QT_NO_TOOLTIP
        actionMove->setToolTip(QApplication::translate("SJTUFlowClass", "Move the object", 0));
#endif // QT_NO_TOOLTIP
        actionMove->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+W", 0));
        actionRotate->setText(QApplication::translate("SJTUFlowClass", "Rotate", 0));
#ifndef QT_NO_TOOLTIP
        actionRotate->setToolTip(QApplication::translate("SJTUFlowClass", "Rotate the object", 0));
#endif // QT_NO_TOOLTIP
        actionRotate->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+E", 0));
        actionScale->setText(QApplication::translate("SJTUFlowClass", "Scale", 0));
        actionScale->setShortcut(QApplication::translate("SJTUFlowClass", "Ctrl+R", 0));
        actionImport_Object->setText(QApplication::translate("SJTUFlowClass", "Import Object", 0));
        actionProperty->setText(QApplication::translate("SJTUFlowClass", "Property", 0));
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
        actionOption->setText(QApplication::translate("SJTUFlowClass", "Option", 0));
        actionRun->setText(QApplication::translate("SJTUFlowClass", "Run", 0));
        actionRun->setShortcut(QApplication::translate("SJTUFlowClass", "F5", 0));
        menuFile->setTitle(QApplication::translate("SJTUFlowClass", "&File", 0));
        menuPrimitive->setTitle(QApplication::translate("SJTUFlowClass", "&Primitive", 0));
        menuEdit->setTitle(QApplication::translate("SJTUFlowClass", "&Edit", 0));
        menuTools->setTitle(QApplication::translate("SJTUFlowClass", "&Tools", 0));
        menuHelp->setTitle(QApplication::translate("SJTUFlowClass", "&Help", 0));
    } // retranslateUi

};

namespace Ui {
    class SJTUFlowClass: public Ui_SJTUFlowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SJTUFLOW_H
