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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qhorizontaltabwidget.h"
#include "titlebar.h"

QT_BEGIN_NAMESPACE

class Ui_SJTUFlowClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    TitleBar *titleBar;
    QHorizontalTabWidget *tabWidget;

    void setupUi(QMainWindow *SJTUFlowClass)
    {
        if (SJTUFlowClass->objectName().isEmpty())
            SJTUFlowClass->setObjectName(QStringLiteral("SJTUFlowClass"));
        SJTUFlowClass->resize(1024, 750);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SJTUFlowClass->sizePolicy().hasHeightForWidth());
        SJTUFlowClass->setSizePolicy(sizePolicy);
        SJTUFlowClass->setStyleSheet(QStringLiteral("font: \"Comic Sans MS\";"));
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

        retranslateUi(SJTUFlowClass);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(SJTUFlowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SJTUFlowClass)
    {
        SJTUFlowClass->setWindowTitle(QApplication::translate("SJTUFlowClass", "SJTUFlow", 0));
    } // retranslateUi

};

namespace Ui {
    class SJTUFlowClass: public Ui_SJTUFlowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SJTUFLOW_H
