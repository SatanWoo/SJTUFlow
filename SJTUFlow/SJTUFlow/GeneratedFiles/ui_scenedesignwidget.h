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
#include <QtWidgets/QDoubleSpinBox>
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
    QDoubleSpinBox *doubleSpinBoxRadius;
    QLabel *labelPosX;
    QLineEdit *lineEditObjName;
    QLabel *labelPos;
    QLabel *labelObjName;
    QSpacerItem *verticalSpacer;
    QLabel *labelColor;
    QLabel *labelPosY;
    QLabel *labelPosZ;
    QCheckBox *checkBoxFill;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButtonColor;
    QSpacerItem *horizontalSpacer;
    QLabel *labelRadius;
    QLabel *labelSizeX;
    QLabel *labelSizeY;
    QLabel *labelSizeZ;
    QLabel *labelSize;
    QLabel *labelScalar;
    QDoubleSpinBox *doubleSpinBoxScalar;
    QDoubleSpinBox *doubleSpinBoxSizeY;
    QDoubleSpinBox *doubleSpinBoxSizeX;
    QDoubleSpinBox *doubleSpinBoxSizeZ;
    QDoubleSpinBox *doubleSpinBoxPosX;
    QDoubleSpinBox *doubleSpinBoxPosY;
    QDoubleSpinBox *doubleSpinBoxPosZ;

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
        dockWidgetProperty->setMinimumSize(QSize(200, 321));
        dockWidgetProperty->setMaximumSize(QSize(200, 10000));
        dockWidgetProperty->setStyleSheet(QLatin1String("*\n"
"{\n"
"	color: white;\n"
"	border-color: rgb(100, 100, 100);\n"
"	background-color: rgb(100, 100, 100);\n"
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
        doubleSpinBoxRadius = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxRadius->setObjectName(QStringLiteral("doubleSpinBoxRadius"));
        doubleSpinBoxRadius->setDecimals(3);
        doubleSpinBoxRadius->setMinimum(0.001);
        doubleSpinBoxRadius->setMaximum(10);
        doubleSpinBoxRadius->setSingleStep(0.001);
        doubleSpinBoxRadius->setValue(0.01);

        gridLayout->addWidget(doubleSpinBoxRadius, 7, 2, 1, 1);

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

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 3);

        labelColor = new QLabel(dockWidgetContents);
        labelColor->setObjectName(QStringLiteral("labelColor"));
        labelColor->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelColor, 6, 0, 1, 1);

        labelPosY = new QLabel(dockWidgetContents);
        labelPosY->setObjectName(QStringLiteral("labelPosY"));
        labelPosY->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPosY, 2, 1, 1, 1);

        labelPosZ = new QLabel(dockWidgetContents);
        labelPosZ->setObjectName(QStringLiteral("labelPosZ"));
        labelPosZ->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(labelPosZ, 3, 1, 1, 1);

        checkBoxFill = new QCheckBox(dockWidgetContents);
        checkBoxFill->setObjectName(QStringLiteral("checkBoxFill"));

        gridLayout->addWidget(checkBoxFill, 5, 0, 1, 1);

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


        gridLayout->addLayout(horizontalLayout, 6, 2, 1, 1);

        labelRadius = new QLabel(dockWidgetContents);
        labelRadius->setObjectName(QStringLiteral("labelRadius"));
        labelRadius->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelRadius, 7, 0, 1, 1);

        labelSizeX = new QLabel(dockWidgetContents);
        labelSizeX->setObjectName(QStringLiteral("labelSizeX"));

        gridLayout->addWidget(labelSizeX, 8, 1, 1, 1);

        labelSizeY = new QLabel(dockWidgetContents);
        labelSizeY->setObjectName(QStringLiteral("labelSizeY"));

        gridLayout->addWidget(labelSizeY, 9, 1, 1, 1);

        labelSizeZ = new QLabel(dockWidgetContents);
        labelSizeZ->setObjectName(QStringLiteral("labelSizeZ"));

        gridLayout->addWidget(labelSizeZ, 10, 1, 1, 1);

        labelSize = new QLabel(dockWidgetContents);
        labelSize->setObjectName(QStringLiteral("labelSize"));
        labelSize->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelSize, 8, 0, 3, 1);

        labelScalar = new QLabel(dockWidgetContents);
        labelScalar->setObjectName(QStringLiteral("labelScalar"));
        labelScalar->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(labelScalar, 4, 0, 1, 1);

        doubleSpinBoxScalar = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxScalar->setObjectName(QStringLiteral("doubleSpinBoxScalar"));
        doubleSpinBoxScalar->setDecimals(3);
        doubleSpinBoxScalar->setMinimum(0.01);
        doubleSpinBoxScalar->setMaximum(5);
        doubleSpinBoxScalar->setSingleStep(0.001);
        doubleSpinBoxScalar->setValue(1);

        gridLayout->addWidget(doubleSpinBoxScalar, 4, 2, 1, 1);

        doubleSpinBoxSizeY = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxSizeY->setObjectName(QStringLiteral("doubleSpinBoxSizeY"));
        doubleSpinBoxSizeY->setDecimals(3);
        doubleSpinBoxSizeY->setMinimum(0.001);
        doubleSpinBoxSizeY->setMaximum(10);
        doubleSpinBoxSizeY->setSingleStep(0.001);
        doubleSpinBoxSizeY->setValue(0.2);

        gridLayout->addWidget(doubleSpinBoxSizeY, 9, 2, 1, 1);

        doubleSpinBoxSizeX = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxSizeX->setObjectName(QStringLiteral("doubleSpinBoxSizeX"));
        doubleSpinBoxSizeX->setDecimals(3);
        doubleSpinBoxSizeX->setMinimum(0.001);
        doubleSpinBoxSizeX->setMaximum(10);
        doubleSpinBoxSizeX->setSingleStep(0.001);
        doubleSpinBoxSizeX->setValue(0.2);

        gridLayout->addWidget(doubleSpinBoxSizeX, 8, 2, 1, 1);

        doubleSpinBoxSizeZ = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxSizeZ->setObjectName(QStringLiteral("doubleSpinBoxSizeZ"));
        doubleSpinBoxSizeZ->setDecimals(3);
        doubleSpinBoxSizeZ->setMinimum(0.001);
        doubleSpinBoxSizeZ->setMaximum(10);
        doubleSpinBoxSizeZ->setSingleStep(0.001);
        doubleSpinBoxSizeZ->setValue(0.2);

        gridLayout->addWidget(doubleSpinBoxSizeZ, 10, 2, 1, 1);

        doubleSpinBoxPosX = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxPosX->setObjectName(QStringLiteral("doubleSpinBoxPosX"));
        doubleSpinBoxPosX->setDecimals(6);
        doubleSpinBoxPosX->setMinimum(-10);
        doubleSpinBoxPosX->setMaximum(10);
        doubleSpinBoxPosX->setSingleStep(0.001);
        doubleSpinBoxPosX->setValue(0);

        gridLayout->addWidget(doubleSpinBoxPosX, 1, 2, 1, 1);

        doubleSpinBoxPosY = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxPosY->setObjectName(QStringLiteral("doubleSpinBoxPosY"));
        doubleSpinBoxPosY->setDecimals(6);
        doubleSpinBoxPosY->setMinimum(-10);
        doubleSpinBoxPosY->setMaximum(10);
        doubleSpinBoxPosY->setSingleStep(0.001);

        gridLayout->addWidget(doubleSpinBoxPosY, 2, 2, 1, 1);

        doubleSpinBoxPosZ = new QDoubleSpinBox(dockWidgetContents);
        doubleSpinBoxPosZ->setObjectName(QStringLiteral("doubleSpinBoxPosZ"));
        doubleSpinBoxPosZ->setDecimals(6);
        doubleSpinBoxPosZ->setMinimum(-10);
        doubleSpinBoxPosZ->setMaximum(10);
        doubleSpinBoxPosZ->setSingleStep(0.001);

        gridLayout->addWidget(doubleSpinBoxPosZ, 3, 2, 1, 1);

        dockWidgetProperty->setWidget(dockWidgetContents);
        SceneDesignWidget->addDockWidget(static_cast<Qt::DockWidgetArea>(2), dockWidgetProperty);
        QWidget::setTabOrder(lineEditObjName, doubleSpinBoxPosX);
        QWidget::setTabOrder(doubleSpinBoxPosX, doubleSpinBoxPosY);
        QWidget::setTabOrder(doubleSpinBoxPosY, doubleSpinBoxPosZ);
        QWidget::setTabOrder(doubleSpinBoxPosZ, doubleSpinBoxScalar);
        QWidget::setTabOrder(doubleSpinBoxScalar, checkBoxFill);
        QWidget::setTabOrder(checkBoxFill, pushButtonColor);
        QWidget::setTabOrder(pushButtonColor, doubleSpinBoxRadius);
        QWidget::setTabOrder(doubleSpinBoxRadius, doubleSpinBoxSizeX);
        QWidget::setTabOrder(doubleSpinBoxSizeX, doubleSpinBoxSizeY);
        QWidget::setTabOrder(doubleSpinBoxSizeY, doubleSpinBoxSizeZ);

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
        labelScalar->setText(QApplication::translate("SceneDesignWidget", "Scalar", 0));
    } // retranslateUi

};

namespace Ui {
    class SceneDesignWidget: public Ui_SceneDesignWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCENEDESIGNWIDGET_H
