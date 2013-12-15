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
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CodingWidget
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
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
"QTabWidget::tab-bar\n"
"{\n"
"	alignment: left;\n"
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
"	background-color: rgba(255"
                        ", 255, 255, 200);\n"
"}"));
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
        toolBar = new QToolBar(CodingWidget);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        toolBar->setMovable(false);
        toolBar->setIconSize(QSize(24, 24));
        toolBar->setFloatable(false);
        CodingWidget->addToolBar(Qt::LeftToolBarArea, toolBar);

        retranslateUi(CodingWidget);

        QMetaObject::connectSlotsByName(CodingWidget);
    } // setupUi

    void retranslateUi(QMainWindow *CodingWidget)
    {
        CodingWidget->setWindowTitle(QApplication::translate("CodingWidget", "CodingWidget", 0));
    } // retranslateUi

};

namespace Ui {
    class CodingWidget: public Ui_CodingWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CODINGWIDGET_H
