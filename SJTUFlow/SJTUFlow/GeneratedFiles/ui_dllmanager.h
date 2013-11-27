/********************************************************************************
** Form generated from reading UI file 'dllmanager.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLLMANAGER_H
#define UI_DLLMANAGER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DLLManager
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonDelete;
    QListView *listView;
    QLabel *label;
    QPlainTextEdit *plainTextEditSystemAlgorithm;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QSpacerItem *horizontalSpacer_3;

    void setupUi(QDialog *DLLManager)
    {
        if (DLLManager->objectName().isEmpty())
            DLLManager->setObjectName(QStringLiteral("DLLManager"));
        DLLManager->resize(400, 293);
        gridLayout = new QGridLayout(DLLManager);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonNew = new QPushButton(DLLManager);
        pushButtonNew->setObjectName(QStringLiteral("pushButtonNew"));
        pushButtonNew->setMinimumSize(QSize(23, 23));
        pushButtonNew->setMaximumSize(QSize(50, 23));

        horizontalLayout->addWidget(pushButtonNew);

        pushButtonDelete = new QPushButton(DLLManager);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setMaximumSize(QSize(50, 23));

        horizontalLayout->addWidget(pushButtonDelete);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        listView = new QListView(DLLManager);
        listView->setObjectName(QStringLiteral("listView"));

        gridLayout->addWidget(listView, 1, 0, 1, 1);

        label = new QLabel(DLLManager);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 2, 0, 1, 1);

        plainTextEditSystemAlgorithm = new QPlainTextEdit(DLLManager);
        plainTextEditSystemAlgorithm->setObjectName(QStringLiteral("plainTextEditSystemAlgorithm"));
        plainTextEditSystemAlgorithm->setReadOnly(true);

        gridLayout->addWidget(plainTextEditSystemAlgorithm, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        pushButtonOK = new QPushButton(DLLManager);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));

        horizontalLayout_2->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(DLLManager);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));

        horizontalLayout_2->addWidget(pushButtonCancel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);


        retranslateUi(DLLManager);

        QMetaObject::connectSlotsByName(DLLManager);
    } // setupUi

    void retranslateUi(QDialog *DLLManager)
    {
        DLLManager->setWindowTitle(QApplication::translate("DLLManager", "Algorithm DLL", 0));
        pushButtonNew->setText(QApplication::translate("DLLManager", "New", 0));
        pushButtonDelete->setText(QApplication::translate("DLLManager", "Delete", 0));
        label->setText(QApplication::translate("DLLManager", "System Algorithms", 0));
        plainTextEditSystemAlgorithm->setPlainText(QApplication::translate("DLLManager", "*.dll", 0));
        pushButtonOK->setText(QApplication::translate("DLLManager", "OK", 0));
        pushButtonCancel->setText(QApplication::translate("DLLManager", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class DLLManager: public Ui_DLLManager {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLMANAGER_H
