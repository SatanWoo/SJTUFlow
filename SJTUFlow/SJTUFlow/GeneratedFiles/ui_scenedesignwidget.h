/********************************************************************************
** Form generated from reading UI file 'scenedesignwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCENEDESIGNWIDGET_H
#define UI_SCENEDESIGNWIDGET_H

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

class Ui_SceneDesignWidget
{
public:
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SceneDesignWidget)
    {
        if (SceneDesignWidget->objectName().isEmpty())
            SceneDesignWidget->setObjectName(QStringLiteral("SceneDesignWidget"));
        SceneDesignWidget->resize(400, 300);
        centralWidget = new QWidget(SceneDesignWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SceneDesignWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SceneDesignWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        SceneDesignWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SceneDesignWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SceneDesignWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(SceneDesignWidget);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SceneDesignWidget->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());

        retranslateUi(SceneDesignWidget);

        QMetaObject::connectSlotsByName(SceneDesignWidget);
    } // setupUi

    void retranslateUi(QMainWindow *SceneDesignWidget)
    {
        SceneDesignWidget->setWindowTitle(QApplication::translate("SceneDesignWidget", "SceneDesignWidget", 0));
        menuFile->setTitle(QApplication::translate("SceneDesignWidget", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class SceneDesignWidget: public Ui_SceneDesignWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEDESIGNWIDGET_H
