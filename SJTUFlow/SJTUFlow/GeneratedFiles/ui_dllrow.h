/********************************************************************************
** Form generated from reading UI file 'dllrow.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DLLROW_H
#define UI_DLLROW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DllRow
{
public:
    QHBoxLayout *horizontalLayout;
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QWidget *DllRow)
    {
        if (DllRow->objectName().isEmpty())
            DllRow->setObjectName(QStringLiteral("DllRow"));
        DllRow->resize(250, 23);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(DllRow->sizePolicy().hasHeightForWidth());
        DllRow->setSizePolicy(sizePolicy);
        DllRow->setContextMenuPolicy(Qt::NoContextMenu);
        horizontalLayout = new QHBoxLayout(DllRow);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit = new QLineEdit(DllRow);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout->addWidget(lineEdit);

        label = new QLabel(DllRow);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        pushButton = new QPushButton(DllRow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(35, 0));
        pushButton->setMaximumSize(QSize(35, 16777215));
        pushButton->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout->addWidget(pushButton);

        horizontalLayout->setStretch(0, 1);

        retranslateUi(DllRow);

        QMetaObject::connectSlotsByName(DllRow);
    } // setupUi

    void retranslateUi(QWidget *DllRow)
    {
        DllRow->setWindowTitle(QApplication::translate("DllRow", "DllRow", 0));
        label->setText(QString());
        pushButton->setText(QApplication::translate("DllRow", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class DllRow: public Ui_DllRow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DLLROW_H
