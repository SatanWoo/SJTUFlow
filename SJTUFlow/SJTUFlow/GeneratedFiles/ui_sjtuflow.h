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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qhorizontaltabwidget.h"

QT_BEGIN_NAMESPACE

class Ui_SJTUFlowClass
{
public:
    QWidget *centralWidget;
    QHorizontalTabWidget *tabWidget;
    QWidget *tabSceneDesign;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayoutSceneDesign;
    QGraphicsView *graphicsViewSceneDesign;
    QWidget *tabCoding;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayoutCoding;
    QWidget *tabDisplay;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayoutDisplay;

    void setupUi(QMainWindow *SJTUFlowClass)
    {
        if (SJTUFlowClass->objectName().isEmpty())
            SJTUFlowClass->setObjectName(QStringLiteral("SJTUFlowClass"));
        SJTUFlowClass->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SJTUFlowClass->sizePolicy().hasHeightForWidth());
        SJTUFlowClass->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(SJTUFlowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        centralWidget->setAutoFillBackground(false);
        centralWidget->setStyleSheet(QStringLiteral(""));
        tabWidget = new QHorizontalTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 800, 600));
        tabWidget->setLayoutDirection(Qt::LeftToRight);
        tabWidget->setTabPosition(QTabWidget::West);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setIconSize(QSize(128, 128));
        tabWidget->setElideMode(Qt::ElideNone);
        tabSceneDesign = new QWidget();
        tabSceneDesign->setObjectName(QStringLiteral("tabSceneDesign"));
        verticalLayoutWidget = new QWidget(tabSceneDesign);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 160, 80));
        verticalLayoutSceneDesign = new QVBoxLayout(verticalLayoutWidget);
        verticalLayoutSceneDesign->setSpacing(6);
        verticalLayoutSceneDesign->setContentsMargins(11, 11, 11, 11);
        verticalLayoutSceneDesign->setObjectName(QStringLiteral("verticalLayoutSceneDesign"));
        verticalLayoutSceneDesign->setContentsMargins(0, 0, 0, 0);
        graphicsViewSceneDesign = new QGraphicsView(verticalLayoutWidget);
        graphicsViewSceneDesign->setObjectName(QStringLiteral("graphicsViewSceneDesign"));

        verticalLayoutSceneDesign->addWidget(graphicsViewSceneDesign);

        QIcon icon;
        icon.addFile(QStringLiteral(":/Icons/Resources/Icons/SceneDesign.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabSceneDesign, icon, QString());
        tabCoding = new QWidget();
        tabCoding->setObjectName(QStringLiteral("tabCoding"));
        verticalLayoutWidget_2 = new QWidget(tabCoding);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(0, 0, 160, 80));
        verticalLayoutCoding = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayoutCoding->setSpacing(6);
        verticalLayoutCoding->setContentsMargins(11, 11, 11, 11);
        verticalLayoutCoding->setObjectName(QStringLiteral("verticalLayoutCoding"));
        verticalLayoutCoding->setContentsMargins(0, 0, 0, 0);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/Resources/Icons/Coding.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabCoding, icon1, QString());
        tabDisplay = new QWidget();
        tabDisplay->setObjectName(QStringLiteral("tabDisplay"));
        verticalLayoutWidget_3 = new QWidget(tabDisplay);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(0, 0, 160, 80));
        verticalLayoutDisplay = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayoutDisplay->setSpacing(6);
        verticalLayoutDisplay->setContentsMargins(11, 11, 11, 11);
        verticalLayoutDisplay->setObjectName(QStringLiteral("verticalLayoutDisplay"));
        verticalLayoutDisplay->setContentsMargins(0, 0, 0, 0);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/Resources/Icons/Display.png"), QSize(), QIcon::Normal, QIcon::Off);
        tabWidget->addTab(tabDisplay, icon2, QString());
        SJTUFlowClass->setCentralWidget(centralWidget);

        retranslateUi(SJTUFlowClass);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(SJTUFlowClass);
    } // setupUi

    void retranslateUi(QMainWindow *SJTUFlowClass)
    {
        SJTUFlowClass->setWindowTitle(QApplication::translate("SJTUFlowClass", "SJTUFlow", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabSceneDesign), QApplication::translate("SJTUFlowClass", "Scene Design", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabCoding), QApplication::translate("SJTUFlowClass", "Coding", 0));
        tabWidget->setTabText(tabWidget->indexOf(tabDisplay), QApplication::translate("SJTUFlowClass", "Display", 0));
    } // retranslateUi

};

namespace Ui {
    class SJTUFlowClass: public Ui_SJTUFlowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SJTUFLOW_H
