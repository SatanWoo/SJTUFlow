/********************************************************************************
** Form generated from reading UI file 'rendersetting.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENDERSETTING_H
#define UI_RENDERSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_RenderSetting
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *labelPath;
    QLineEdit *lineEditPath;
    QLabel *labelSize;
    QPushButton *pushButtonSize;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RenderSetting)
    {
        if (RenderSetting->objectName().isEmpty())
            RenderSetting->setObjectName(QStringLiteral("RenderSetting"));
        RenderSetting->resize(291, 156);
        verticalLayout = new QVBoxLayout(RenderSetting);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(RenderSetting);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        labelPath = new QLabel(groupBox);
        labelPath->setObjectName(QStringLiteral("labelPath"));

        gridLayout->addWidget(labelPath, 0, 0, 1, 1);

        lineEditPath = new QLineEdit(groupBox);
        lineEditPath->setObjectName(QStringLiteral("lineEditPath"));

        gridLayout->addWidget(lineEditPath, 0, 1, 1, 1);

        labelSize = new QLabel(groupBox);
        labelSize->setObjectName(QStringLiteral("labelSize"));

        gridLayout->addWidget(labelSize, 2, 0, 1, 1);

        pushButtonSize = new QPushButton(groupBox);
        pushButtonSize->setObjectName(QStringLiteral("pushButtonSize"));

        gridLayout->addWidget(pushButtonSize, 2, 1, 1, 1);

        labelName = new QLabel(groupBox);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout->addWidget(labelName, 1, 0, 1, 1);

        lineEditName = new QLineEdit(groupBox);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        gridLayout->addWidget(lineEditName, 1, 1, 1, 1);


        verticalLayout->addWidget(groupBox);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(RenderSetting);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(RenderSetting);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout->addWidget(pushButtonCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        QWidget::setTabOrder(lineEditPath, lineEditName);
        QWidget::setTabOrder(lineEditName, pushButtonSize);
        QWidget::setTabOrder(pushButtonSize, pushButtonOK);
        QWidget::setTabOrder(pushButtonOK, pushButtonCancel);

        retranslateUi(RenderSetting);

        QMetaObject::connectSlotsByName(RenderSetting);
    } // setupUi

    void retranslateUi(QDialog *RenderSetting)
    {
        RenderSetting->setWindowTitle(QApplication::translate("RenderSetting", "Render Setting", 0));
        groupBox->setTitle(QApplication::translate("RenderSetting", "Output", 0));
        labelPath->setText(QApplication::translate("RenderSetting", "Path", 0));
        labelSize->setText(QApplication::translate("RenderSetting", "Size", 0));
        pushButtonSize->setText(QApplication::translate("RenderSetting", "640x480", 0));
        labelName->setText(QApplication::translate("RenderSetting", "Name", 0));
        pushButtonOK->setText(QApplication::translate("RenderSetting", "OK", 0));
        pushButtonCancel->setText(QApplication::translate("RenderSetting", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class RenderSetting: public Ui_RenderSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENDERSETTING_H
