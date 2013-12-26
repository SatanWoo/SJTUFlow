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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DisplayWidget
{
public:
    QWidget *centralWidget;
    QToolBar *toolBar;

    void setupUi(QMainWindow *DisplayWidget)
    {
        if (DisplayWidget->objectName().isEmpty())
            DisplayWidget->setObjectName(QStringLiteral("DisplayWidget"));
        DisplayWidget->resize(400, 300);
        DisplayWidget->setContextMenuPolicy(Qt::NoContextMenu);
        DisplayWidget->setStyleSheet(QLatin1String("QToolBar\n"
"{\n"
"	background-color: rgba(255, 255, 255, 50);\n"
"	border-color: rgba(255, 255, 255, 50);\n"
"}"));
        centralWidget = new QWidget(DisplayWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        DisplayWidget->setCentralWidget(centralWidget);
        toolBar = new QToolBar(DisplayWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setFloatable(false);
        DisplayWidget->addToolBar(Qt::LeftToolBarArea, toolBar);

        retranslateUi(DisplayWidget);

        QMetaObject::connectSlotsByName(DisplayWidget);
    } // setupUi

    void retranslateUi(QMainWindow *DisplayWidget)
    {
        DisplayWidget->setWindowTitle(QApplication::translate("DisplayWidget", "DisplayWidget", 0));
        toolBar->setWindowTitle(QApplication::translate("DisplayWidget", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class DisplayWidget: public Ui_DisplayWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYWIDGET_H
