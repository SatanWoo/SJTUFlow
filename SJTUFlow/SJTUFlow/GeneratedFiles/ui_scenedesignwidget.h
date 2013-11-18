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
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneDesignWidget
{
public:
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSave_as;
    QAction *actionSetting;
    QAction *actionUndo;
    QAction *actionRedo;
    QAction *actionDelete;
    QAction *actionMove;
    QAction *actionRotate;
    QAction *actionScale;
    QAction *actionProperty;
    QAction *actionImport;
    QAction *actionScene2D;
    QAction *actionScene3D;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuNew;
    QMenu *menuRender;
    QMenu *menuEdit;
    QToolBar *mainToolBar;

    void setupUi(QMainWindow *SceneDesignWidget)
    {
        if (SceneDesignWidget->objectName().isEmpty())
            SceneDesignWidget->setObjectName(QStringLiteral("SceneDesignWidget"));
        SceneDesignWidget->resize(400, 300);
        SceneDesignWidget->setStyleSheet(QLatin1String("QMenuBar\n"
"{\n"
"	border-color: rgba(255, 255, 255, 50);\n"
"	background-color: rgba(255, 255, 255, 50);\n"
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
"QToolBar\n"
"{\n"
"	border-color: rgba(255, 255, 255, 50);\n"
"	background-color: rgba(255, 255, 255, 50);\n"
"}"));
        actionOpen = new QAction(SceneDesignWidget);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionSave = new QAction(SceneDesignWidget);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        actionSave_as = new QAction(SceneDesignWidget);
        actionSave_as->setObjectName(QStringLiteral("actionSave_as"));
        actionSetting = new QAction(SceneDesignWidget);
        actionSetting->setObjectName(QStringLiteral("actionSetting"));
        actionUndo = new QAction(SceneDesignWidget);
        actionUndo->setObjectName(QStringLiteral("actionUndo"));
        actionRedo = new QAction(SceneDesignWidget);
        actionRedo->setObjectName(QStringLiteral("actionRedo"));
        actionDelete = new QAction(SceneDesignWidget);
        actionDelete->setObjectName(QStringLiteral("actionDelete"));
        actionMove = new QAction(SceneDesignWidget);
        actionMove->setObjectName(QStringLiteral("actionMove"));
        actionRotate = new QAction(SceneDesignWidget);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        actionScale = new QAction(SceneDesignWidget);
        actionScale->setObjectName(QStringLiteral("actionScale"));
        actionProperty = new QAction(SceneDesignWidget);
        actionProperty->setObjectName(QStringLiteral("actionProperty"));
        actionImport = new QAction(SceneDesignWidget);
        actionImport->setObjectName(QStringLiteral("actionImport"));
        actionScene2D = new QAction(SceneDesignWidget);
        actionScene2D->setObjectName(QStringLiteral("actionScene2D"));
        actionScene3D = new QAction(SceneDesignWidget);
        actionScene3D->setObjectName(QStringLiteral("actionScene3D"));
        centralWidget = new QWidget(SceneDesignWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SceneDesignWidget->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(SceneDesignWidget);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 23));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuNew = new QMenu(menuFile);
        menuNew->setObjectName(QStringLiteral("menuNew"));
        menuRender = new QMenu(menuBar);
        menuRender->setObjectName(QStringLiteral("menuRender"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        SceneDesignWidget->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SceneDesignWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SceneDesignWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuRender->menuAction());
        menuFile->addAction(menuNew->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addSeparator();
        menuFile->addAction(actionSave);
        menuFile->addAction(actionSave_as);
        menuFile->addSeparator();
        menuFile->addAction(actionImport);
        menuNew->addAction(actionScene2D);
        menuNew->addAction(actionScene3D);
        menuRender->addAction(actionSetting);
        menuEdit->addAction(actionUndo);
        menuEdit->addAction(actionRedo);
        menuEdit->addSeparator();
        menuEdit->addAction(actionDelete);
        menuEdit->addSeparator();
        menuEdit->addAction(actionMove);
        menuEdit->addAction(actionRotate);
        menuEdit->addAction(actionScale);
        menuEdit->addSeparator();
        menuEdit->addAction(actionProperty);

        retranslateUi(SceneDesignWidget);

        QMetaObject::connectSlotsByName(SceneDesignWidget);
    } // setupUi

    void retranslateUi(QMainWindow *SceneDesignWidget)
    {
        SceneDesignWidget->setWindowTitle(QApplication::translate("SceneDesignWidget", "SceneDesignWidget", 0));
        actionOpen->setText(QApplication::translate("SceneDesignWidget", "Open", 0));
        actionOpen->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+O", 0));
        actionSave->setText(QApplication::translate("SceneDesignWidget", "Save", 0));
        actionSave->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+S", 0));
        actionSave_as->setText(QApplication::translate("SceneDesignWidget", "Save as", 0));
        actionSave_as->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+Shift+S", 0));
        actionSetting->setText(QApplication::translate("SceneDesignWidget", "Setting", 0));
        actionUndo->setText(QApplication::translate("SceneDesignWidget", "Undo", 0));
        actionUndo->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+Z", 0));
        actionRedo->setText(QApplication::translate("SceneDesignWidget", "Redo", 0));
        actionRedo->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+Y", 0));
        actionDelete->setText(QApplication::translate("SceneDesignWidget", "Delete", 0));
        actionDelete->setShortcut(QApplication::translate("SceneDesignWidget", "Del", 0));
        actionMove->setText(QApplication::translate("SceneDesignWidget", "Move", 0));
        actionMove->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+W", 0));
        actionRotate->setText(QApplication::translate("SceneDesignWidget", "Rotate", 0));
        actionRotate->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+E", 0));
        actionScale->setText(QApplication::translate("SceneDesignWidget", "Scale", 0));
        actionScale->setShortcut(QApplication::translate("SceneDesignWidget", "Ctrl+R", 0));
        actionProperty->setText(QApplication::translate("SceneDesignWidget", "Property", 0));
        actionImport->setText(QApplication::translate("SceneDesignWidget", "Import", 0));
        actionScene2D->setText(QApplication::translate("SceneDesignWidget", "2D Scene", 0));
        actionScene3D->setText(QApplication::translate("SceneDesignWidget", "3D Scene", 0));
        menuFile->setTitle(QApplication::translate("SceneDesignWidget", "&File", 0));
        menuNew->setTitle(QApplication::translate("SceneDesignWidget", "New", 0));
        menuRender->setTitle(QApplication::translate("SceneDesignWidget", "&Render", 0));
        menuEdit->setTitle(QApplication::translate("SceneDesignWidget", "&Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class SceneDesignWidget: public Ui_SceneDesignWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEDESIGNWIDGET_H
