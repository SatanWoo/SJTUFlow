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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SceneDesignWidget
{
public:
    QWidget *centralWidget;
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
    QLineEdit *lineEditRadius;
    QLabel *labelRadius;
    QLabel *labelSizeX;
    QLabel *labelSizeY;
    QLabel *labelSizeZ;
    QLabel *labelSize;
    QLineEdit *lineEditSizeX;
    QLineEdit *lineEditSizeY;
    QLineEdit *lineEditSizeZ;

    void setupUi(QMainWindow *SceneDesignWidget)
    {
        if (SceneDesignWidget->objectName().isEmpty())
            SceneDesignWidget->setObjectName(QStringLiteral("SceneDesignWidget"));
        SceneDesignWidget->resize(400, 504);
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
        centralWidget = new QWidget(SceneDesignWidget);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SceneDesignWidget->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(SceneDesignWidget);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setContextMenuPolicy(Qt::NoContextMenu);
        mainToolBar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
        mainToolBar->setFloatable(false);
        SceneDesignWidget->addToolBar(Qt::LeftToolBarArea, mainToolBar);
        toolBar2D = new QToolBar(SceneDesignWidget);
        toolBar2D->setObjectName(QStringLiteral("toolBar2D"));
        toolBar2D->setContextMenuPolicy(Qt::NoContextMenu);
        toolBar2D->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
        SceneDesignWidget->addToolBar(Qt::LeftToolBarArea, toolBar2D);
        toolBar3D = new QToolBar(SceneDesignWidget);
        toolBar3D->setObjectName(QStringLiteral("toolBar3D"));
        toolBar3D->setContextMenuPolicy(Qt::NoContextMenu);
        toolBar3D->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
        SceneDesignWidget->addToolBar(Qt::LeftToolBarArea, toolBar3D);
        dockWidgetProperty = new QDockWidget(SceneDesignWidget);
        dockWidgetProperty->setObjectName(QStringLiteral("dockWidgetProperty"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(dockWidgetProperty->sizePolicy().hasHeightForWidth());
        dockWidgetProperty->setSizePolicy(sizePolicy);
        dockWidgetProperty->setMinimumSize(QSize(200, 295));
        dockWidgetProperty->setMaximumSize(QSize(200, 10000));
        dockWidgetProperty->setStyleSheet(QLatin1String("*\n"
"{\n"
"	color: white;\n"
"	border-color: rgb(100, 100, 100);\n"
"	background-color: rgb(100, 100, 100);\n"
"}\n"
"QLineEdit\n"
"{\n"
"	border-color: transparent;\n"
"	background-color: white;\n"
"	color: black;\n"
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

        gridLayout->addItem(verticalSpacer, 10, 0, 1, 3);

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

        lineEditRadius = new QLineEdit(dockWidgetContents);
        lineEditRadius->setObjectName(QStringLiteral("lineEditRadius"));
        lineEditRadius->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditRadius, 6, 2, 1, 1);

        labelRadius = new QLabel(dockWidgetContents);
        labelRadius->setObjectName(QStringLiteral("labelRadius"));
        labelRadius->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelRadius, 6, 0, 1, 1);

        labelSizeX = new QLabel(dockWidgetContents);
        labelSizeX->setObjectName(QStringLiteral("labelSizeX"));

        gridLayout->addWidget(labelSizeX, 7, 1, 1, 1);

        labelSizeY = new QLabel(dockWidgetContents);
        labelSizeY->setObjectName(QStringLiteral("labelSizeY"));

        gridLayout->addWidget(labelSizeY, 8, 1, 1, 1);

        labelSizeZ = new QLabel(dockWidgetContents);
        labelSizeZ->setObjectName(QStringLiteral("labelSizeZ"));

        gridLayout->addWidget(labelSizeZ, 9, 1, 1, 1);

        labelSize = new QLabel(dockWidgetContents);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelSize, 7, 0, 3, 1);

        lineEditSizeX = new QLineEdit(dockWidgetContents);
        lineEditSizeX->setObjectName(QStringLiteral("lineEditSizeX"));
        lineEditSizeX->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditSizeX, 7, 2, 1, 1);

        lineEditSizeY = new QLineEdit(dockWidgetContents);
        lineEditSizeY->setObjectName(QStringLiteral("lineEditSizeY"));
        lineEditSizeY->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditSizeY, 8, 2, 1, 1);

        lineEditSizeZ = new QLineEdit(dockWidgetContents);
        lineEditSizeZ->setObjectName(QStringLiteral("lineEditSizeZ"));
        lineEditSizeZ->setContextMenuPolicy(Qt::NoContextMenu);

        gridLayout->addWidget(lineEditSizeZ, 9, 2, 1, 1);

        dockWidgetProperty->setWidget(dockWidgetContents);
        SceneDesignWidget->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetProperty);
        QWidget::setTabOrder(lineEditObjName, lineEditPosX);
        QWidget::setTabOrder(lineEditPosX, lineEditPosY);
        QWidget::setTabOrder(lineEditPosY, lineEditPosZ);

        retranslateUi(SceneDesignWidget);

        QMetaObject::connectSlotsByName(SceneDesignWidget);
    } // setupUi

    void retranslateUi(QMainWindow *SceneDesignWidget)
    {
        SceneDesignWidget->setWindowTitle(QApplication::translate("SceneDesignWidget", "SceneDesignWidget", 0));
        mainToolBar->setWindowTitle(QApplication::translate("SceneDesignWidget", "Main ToolBar", 0));
        toolBar2D->setWindowTitle(QApplication::translate("SceneDesignWidget", "2D toolBar", 0));
        toolBar3D->setWindowTitle(QApplication::translate("SceneDesignWidget", "3D toolBar", 0));
        dockWidgetProperty->setWindowTitle(QApplication::translate("SceneDesignWidget", "Property", 0));
        labelPosX->setText(QApplication::translate("SceneDesignWidget", "x", 0));
        lineEditObjName->setText(QString());
        labelPos->setText(QApplication::translate("SceneDesignWidget", "position", 0));
        labelObjName->setText(QApplication::translate("SceneDesignWidget", "objectName", 0));
        labelColor->setText(QApplication::translate("SceneDesignWidget", "color", 0));
        labelPosY->setText(QApplication::translate("SceneDesignWidget", "y", 0));
        labelPosZ->setText(QApplication::translate("SceneDesignWidget", "z", 0));
        checkBoxFill->setText(QApplication::translate("SceneDesignWidget", "fill", 0));
        pushButtonColor->setText(QString());
        labelRadius->setText(QApplication::translate("SceneDesignWidget", "radius", 0));
        labelSizeX->setText(QApplication::translate("SceneDesignWidget", "x", 0));
        labelSizeY->setText(QApplication::translate("SceneDesignWidget", "y", 0));
        labelSizeZ->setText(QApplication::translate("SceneDesignWidget", "z", 0));
        labelSize->setText(QApplication::translate("SceneDesignWidget", "size", 0));
    } // retranslateUi

};

namespace Ui {
    class SceneDesignWidget: public Ui_SceneDesignWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEDESIGNWIDGET_H
