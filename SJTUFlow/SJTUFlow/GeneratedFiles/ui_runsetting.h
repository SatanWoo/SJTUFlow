/********************************************************************************
** Form generated from reading UI file 'runsetting.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RUNSETTING_H
#define UI_RUNSETTING_H

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

class Ui_RunSetting
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBoxPython;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPyPath;
    QLineEdit *lineEditPyPath;
    QGroupBox *groupBoxResults;
    QGridLayout *gridLayout_2;
    QLabel *labelPath;
    QLineEdit *lineEditRetPath;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelPrompt;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *RunSetting)
    {
        if (RunSetting->objectName().isEmpty())
            RunSetting->setObjectName(QStringLiteral("RunSetting"));
        RunSetting->resize(326, 203);
        RunSetting->setContextMenuPolicy(Qt::NoContextMenu);
        verticalLayout = new QVBoxLayout(RunSetting);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBoxPython = new QGroupBox(RunSetting);
        groupBoxPython->setObjectName(QStringLiteral("groupBoxPython"));
        horizontalLayout = new QHBoxLayout(groupBoxPython);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelPyPath = new QLabel(groupBoxPython);
        labelPyPath->setObjectName(QStringLiteral("labelPyPath"));

        horizontalLayout->addWidget(labelPyPath);

        lineEditPyPath = new QLineEdit(groupBoxPython);
        lineEditPyPath->setObjectName(QStringLiteral("lineEditPyPath"));

        horizontalLayout->addWidget(lineEditPyPath);


        verticalLayout->addWidget(groupBoxPython);

        groupBoxResults = new QGroupBox(RunSetting);
        groupBoxResults->setObjectName(QStringLiteral("groupBoxResults"));
        gridLayout_2 = new QGridLayout(groupBoxResults);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        labelPath = new QLabel(groupBoxResults);
        labelPath->setObjectName(QStringLiteral("labelPath"));

        gridLayout_2->addWidget(labelPath, 0, 0, 1, 1);

        lineEditRetPath = new QLineEdit(groupBoxResults);
        lineEditRetPath->setObjectName(QStringLiteral("lineEditRetPath"));

        gridLayout_2->addWidget(lineEditRetPath, 0, 1, 1, 1);

        labelName = new QLabel(groupBoxResults);
        labelName->setObjectName(QStringLiteral("labelName"));

        gridLayout_2->addWidget(labelName, 1, 0, 1, 1);

        lineEditName = new QLineEdit(groupBoxResults);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));

        gridLayout_2->addWidget(lineEditName, 1, 1, 1, 1);

        labelPrompt = new QLabel(groupBoxResults);
        labelPrompt->setObjectName(QStringLiteral("labelPrompt"));

        gridLayout_2->addWidget(labelPrompt, 2, 1, 1, 1);


        verticalLayout->addWidget(groupBoxResults);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(RunSetting);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout_2->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(RunSetting);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(RunSetting);

        QMetaObject::connectSlotsByName(RunSetting);
    } // setupUi

    void retranslateUi(QDialog *RunSetting)
    {
        RunSetting->setWindowTitle(QApplication::translate("RunSetting", "Setting", 0));
        groupBoxPython->setTitle(QApplication::translate("RunSetting", "Python", 0));
        labelPyPath->setText(QApplication::translate("RunSetting", "Path", 0));
        groupBoxResults->setTitle(QApplication::translate("RunSetting", "Output", 0));
        labelPath->setText(QApplication::translate("RunSetting", "Path", 0));
        labelName->setText(QApplication::translate("RunSetting", "Name", 0));
        labelPrompt->setText(QApplication::translate("RunSetting", "Files' names will be [name]_[0-9].file", 0));
        pushButtonOK->setText(QApplication::translate("RunSetting", "OK", 0));
        pushButtonCancel->setText(QApplication::translate("RunSetting", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class RunSetting: public Ui_RunSetting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RUNSETTING_H
