/********************************************************************************
** Form generated from reading UI file 'titlebar.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TITLEBAR_H
#define UI_TITLEBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TitleBar
{
public:
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *labelTitle;
    QToolButton *toolButtonMin;
    QToolButton *toolButtonClose;

    void setupUi(QWidget *TitleBar)
    {
        if (TitleBar->objectName().isEmpty())
            TitleBar->setObjectName(QStringLiteral("TitleBar"));
        TitleBar->resize(720, 29);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TitleBar->sizePolicy().hasHeightForWidth());
        TitleBar->setSizePolicy(sizePolicy);
        TitleBar->setStyleSheet(QLatin1String("*\n"
"{\n"
"	border-image: transparent;\n"
"}\n"
"QLabel\n"
"{\n"
"	color: white;\n"
"}\n"
"QToolButton\n"
"{\n"
"	background-color: transparent;\n"
"	border-style: flat;\n"
"	border-width: 1px;\n"
"	border-radius: 3px;\n"
"	border-color: rgb(51, 153, 255);\n"
"}\n"
"QToolButton:hover\n"
"{\n"
"	background-color: rgba(115, 209, 255, 200);\n"
"}\n"
"QToolButton:pressed\n"
"{\n"
"	background-color: rgba(20, 59, 255, 100);\n"
"}\n"
""));
        horizontalLayout = new QHBoxLayout(TitleBar);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(TitleBar);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(29, 29));
        label->setPixmap(QPixmap(QString::fromUtf8(":/SJTUFlow/Resources/SJTU-Icon.png")));
        label->setScaledContents(true);

        horizontalLayout->addWidget(label);

        labelTitle = new QLabel(TitleBar);
        labelTitle->setObjectName(QStringLiteral("labelTitle"));
        QFont font;
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(14);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(labelTitle);

        toolButtonMin = new QToolButton(TitleBar);
        toolButtonMin->setObjectName(QStringLiteral("toolButtonMin"));
        toolButtonMin->setStyleSheet(QStringLiteral(""));
        QIcon icon;
        icon.addFile(QStringLiteral(":/SJTUFlow/Resources/TitleMin.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonMin->setIcon(icon);
        toolButtonMin->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(toolButtonMin);

        toolButtonClose = new QToolButton(TitleBar);
        toolButtonClose->setObjectName(QStringLiteral("toolButtonClose"));
        toolButtonClose->setStyleSheet(QStringLiteral(""));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/SJTUFlow/Resources/TitleClose.png"), QSize(), QIcon::Normal, QIcon::Off);
        toolButtonClose->setIcon(icon1);
        toolButtonClose->setIconSize(QSize(24, 24));

        horizontalLayout->addWidget(toolButtonClose);

        horizontalLayout->setStretch(1, 500);

        retranslateUi(TitleBar);

        QMetaObject::connectSlotsByName(TitleBar);
    } // setupUi

    void retranslateUi(QWidget *TitleBar)
    {
        TitleBar->setWindowTitle(QApplication::translate("TitleBar", "TitleBar", 0));
        label->setText(QString());
        labelTitle->setText(QApplication::translate("TitleBar", "SJTU Flow", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonMin->setToolTip(QApplication::translate("TitleBar", "Minimize", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toolButtonMin->setWhatsThis(QApplication::translate("TitleBar", "Minimize", 0));
#endif // QT_NO_WHATSTHIS
        toolButtonMin->setText(QApplication::translate("TitleBar", "...", 0));
#ifndef QT_NO_TOOLTIP
        toolButtonClose->setToolTip(QApplication::translate("TitleBar", "Close", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_WHATSTHIS
        toolButtonClose->setWhatsThis(QApplication::translate("TitleBar", "Close", 0));
#endif // QT_NO_WHATSTHIS
        toolButtonClose->setText(QApplication::translate("TitleBar", "...", 0));
    } // retranslateUi

};

namespace Ui {
    class TitleBar: public Ui_TitleBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TITLEBAR_H
