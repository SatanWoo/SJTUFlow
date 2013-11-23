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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDockWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
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
    QToolBar *toolBar2D;
    QToolBar *toolBar3D;
    QDockWidget *dockWidgetProperty;
    QWidget *dockWidgetContents;
    QGridLayout *gridLayout;
    QLabel *labelPosX;
    QLineEdit *lineEditObjName;
    QLabel *labelPos;
    QLabel *labelObjName;
    QSpacerItem *verticalSpacer;
    QLabel *labelColor;
    QLineEdit *lineEditPosX;
    QLineEdit *lineEditPosZ;
    QLabel *labelPosY;
    QLineEdit *lineEditPosY;
    QLabel *labelPosZ;
    QCheckBox *checkBoxFill;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonColor;
    QSpacerItem *horizontalSpacer;

    void setupUi(QMainWindow *SceneDesignWidget)
    {
        if (SceneDesignWidget->objectName().isEmpty())
            SceneDesignWidget->setObjectName(QStringLiteral("SceneDesignWidget"));
        SceneDesignWidget->resize(400, 300);
        SceneDesignWidget->setContextMenuPolicy(Qt::NoContextMenu);
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
"	border-color: rgb(209, 209, 209);\n"
"	background-color: rgb(209, 209, 209);\n"
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
        QIcon icon;
        icon.addFile(QStringLiteral(":/Design/Resources/Icons/Move.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionMove->setIcon(icon);
        actionRotate = new QAction(SceneDesignWidget);
        actionRotate->setObjectName(QStringLiteral("actionRotate"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Design/Resources/Icons/Rotate.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRotate->setIcon(icon1);
        actionScale = new QAction(SceneDesignWidget);
        actionScale->setObjectName(QStringLiteral("actionScale"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Design/Resources/Icons/Scale.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionScale->setIcon(icon2);
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
        menuBar->setContextMenuPolicy(Qt::NoContextMenu);
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
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        mainToolBar->setFloatable(false);
        SceneDesignWidget->addToolBar(Qt::TopToolBarArea, mainToolBar);
        toolBar2D = new QToolBar(SceneDesignWidget);
        toolBar2D->setObjectName(QStringLiteral("toolBar2D"));
        toolBar2D->setContextMenuPolicy(Qt::NoContextMenu);
        SceneDesignWidget->addToolBar(Qt::TopToolBarArea, toolBar2D);
        toolBar3D = new QToolBar(SceneDesignWidget);
        toolBar3D->setObjectName(QStringLiteral("toolBar3D"));
        toolBar3D->setContextMenuPolicy(Qt::NoContextMenu);
        SceneDesignWidget->addToolBar(Qt::TopToolBarArea, toolBar3D);
        dockWidgetProperty = new QDockWidget(SceneDesignWidget);
        dockWidgetProperty->setObjectName(QStringLiteral("dockWidgetProperty"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetProperty->sizePolicy().hasHeightForWidth());
        dockWidgetProperty->setSizePolicy(sizePolicy);
        dockWidgetProperty->setMinimumSize(QSize(200, 205));
        dockWidgetProperty->setMaximumSize(QSize(200, 10000));
        dockWidgetProperty->setStyleSheet(QLatin1String("*\n"
"{\n"
"	border-color: rgb(100, 100, 100);\n"
"	background-color: rgb(100, 100, 100);\n"
"}\n"
"QLineEdit\n"
"{\n"
"	border-color: transparent;\n"
"	background-color: white;\n"
"}\n"
"QLineEdit:!enabled\n"
"{\n"
"	background-color: rgb(200, 200, 200);\n"
"}\n"
"QPushButton\n"
"{\n"
"    border-style: outset;\n"
"    border-width: 1px;\n"
"    border-color: beige;\n"
"}"));
        dockWidgetProperty->setFloating(false);
        dockWidgetProperty->setFeatures(QDockWidget::DockWidgetClosable);
        dockWidgetProperty->setAllowedAreas(Qt::RightDockWidgetArea);
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QStringLiteral("dockWidgetContents"));
        gridLayout = new QGridLayout(dockWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelPosX = new QLabel(dockWidgetContents);
        labelPosX->setObjectName(QStringLiteral("labelPosX"));
        labelPosX->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPosX, 1, 1, 1, 1);

        lineEditObjName = new QLineEdit(dockWidgetContents);
        lineEditObjName->setObjectName(QStringLiteral("lineEditObjName"));
        lineEditObjName->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditObjName, 0, 2, 1, 1);

        labelPos = new QLabel(dockWidgetContents);
        labelPos->setObjectName(QStringLiteral("labelPos"));
        labelPos->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelPos, 1, 0, 3, 1);

        labelObjName = new QLabel(dockWidgetContents);
        labelObjName->setObjectName(QStringLiteral("labelObjName"));
        labelObjName->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelObjName, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 7, 0, 1, 3);

        labelColor = new QLabel(dockWidgetContents);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        labelColor->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelColor, 5, 0, 1, 1);

        lineEditPosX = new QLineEdit(dockWidgetContents);
        lineEditPosX->setObjectName(QStringLiteral("lineEditPosX"));
        lineEditPosX->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditPosX, 1, 2, 1, 1);

        lineEditPosZ = new QLineEdit(dockWidgetContents);
        lineEditPosZ->setObjectName(QStringLiteral("lineEditPosZ"));
        lineEditPosZ->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditPosZ, 3, 2, 1, 1);

        labelPosY = new QLabel(dockWidgetContents);
        labelPosY->setObjectName(QStringLiteral("labelPosY"));
        labelPosY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPosY, 2, 1, 1, 1);

        lineEditPosY = new QLineEdit(dockWidgetContents);
        lineEditPosY->setObjectName(QStringLiteral("lineEditPosY"));
        lineEditPosY->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditPosY, 2, 2, 1, 1);

        labelPosZ = new QLabel(dockWidgetContents);
        labelPosZ->setObjectName(QStringLiteral("labelPosZ"));
        labelPosZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPosZ, 3, 1, 1, 1);

        checkBoxFill = new QCheckBox(dockWidgetContents);
        checkBoxFill->setObjectName(QStringLiteral("checkBoxFill"));

        gridLayout->addWidget(checkBoxFill, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        pushButtonColor = new QPushButton(dockWidgetContents);
        pushButtonColor->setObjectName(QStringLiteral("pushButtonColor"));
        pushButtonColor->setMinimumSize(QSize(28, 20));
        pushButtonColor->setMaximumSize(QSize(28, 20));
        pushButtonColor->setIconSize(QSize(26, 18));
        pushButtonColor->setFlat(false);

        horizontalLayout->addWidget(pushButtonColor);

        horizontalSpacer = new QSpacerItem(100, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout, 5, 2, 1, 1);

        dockWidgetProperty->setWidget(dockWidgetContents);
        SceneDesignWidget->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetProperty);
        QWidget::setTabOrder(lineEditObjName, lineEditPosX);
        QWidget::setTabOrder(lineEditPosX, lineEditPosY);
        QWidget::setTabOrder(lineEditPosY, lineEditPosZ);

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
        mainToolBar->setWindowTitle(QApplication::translate("SceneDesignWidget", "Main ToolBar", 0));
        toolBar2D->setWindowTitle(QApplication::translate("SceneDesignWidget", "2D toolBar", 0));
        toolBar3D->setWindowTitle(QApplication::translate("SceneDesignWidget", "3D toolBar", 0));
        dockWidgetProperty->setWindowTitle(QApplication::translate("SceneDesignWidget", "Property", 0));
        labelPosX->setText(QApplication::translate("SceneDesignWidget", "x", 0));
        labelPos->setText(QApplication::translate("SceneDesignWidget", "position", 0));
        labelObjName->setText(QApplication::translate("SceneDesignWidget", "objectName", 0));
        labelColor->setText(QApplication::translate("SceneDesignWidget", "color", 0));
        labelPosY->setText(QApplication::translate("SceneDesignWidget", "y", 0));
        labelPosZ->setText(QApplication::translate("SceneDesignWidget", "z", 0));
        checkBoxFill->setText(QApplication::translate("SceneDesignWidget", "fill", 0));
        pushButtonColor->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class SceneDesignWidget: public Ui_SceneDesignWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEDESIGNWIDGET_H
