/********************************************************************************
** Form generated from reading UI file 'aboutdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ABOUTDIALOG_H
#define UI_ABOUTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_AboutDialog
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelIcon;
    QLabel *labelName;
    QTextBrowser *textBrowserAuthor;
    QTextBrowser *textBrowserDALAB;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QPlainTextEdit *plainTextEdit;

    void setupUi(QDialog *AboutDialog)
    {
        if (AboutDialog->objectName().isEmpty())
            AboutDialog->setObjectName(QStringLiteral("AboutDialog"));
        AboutDialog->resize(400, 345);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(AboutDialog->sizePolicy().hasHeightForWidth());
        AboutDialog->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SJTUFlow/Resources/SJTU-Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        AboutDialog->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(AboutDialog);
        verticalLayout->setSpacing(0);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(6, 6, 6, 6);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(6, -1, 6, -1);
        labelIcon = new QLabel(AboutDialog);
        labelIcon->setObjectName(QStringLiteral("labelIcon"));
        labelIcon->setMaximumSize(QSize(64, 64));
        labelIcon->setPixmap(QPixmap(QString::fromUtf8(":/SJTUFlow/Resources/SJTU-Icon.png")));
        labelIcon->setScaledContents(true);

        horizontalLayout->addWidget(labelIcon);

        labelName = new QLabel(AboutDialog);
        labelName->setObjectName(QStringLiteral("labelName"));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(16);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        labelName->setFont(font);

        horizontalLayout->addWidget(labelName);


        verticalLayout->addLayout(horizontalLayout);

        textBrowserAuthor = new QTextBrowser(AboutDialog);
        textBrowserAuthor->setObjectName(QStringLiteral("textBrowserAuthor"));
        textBrowserAuthor->setMaximumSize(QSize(16777215, 30));
        QFont font1;
        font1.setFamily(QStringLiteral("Arial"));
        font1.setBold(true);
        font1.setWeight(75);
        textBrowserAuthor->setFont(font1);
        textBrowserAuthor->setStyleSheet(QStringLiteral("background-color:transparent;"));
        textBrowserAuthor->setFrameShape(QFrame::NoFrame);
        textBrowserAuthor->setFrameShadow(QFrame::Plain);

        verticalLayout->addWidget(textBrowserAuthor);

        textBrowserDALAB = new QTextBrowser(AboutDialog);
        textBrowserDALAB->setObjectName(QStringLiteral("textBrowserDALAB"));
        textBrowserDALAB->setMaximumSize(QSize(16777215, 30));
        textBrowserDALAB->setContextMenuPolicy(Qt::NoContextMenu);
        textBrowserDALAB->setStyleSheet(QStringLiteral("background-color:transparent;"));
        textBrowserDALAB->setFrameShape(QFrame::NoFrame);
        textBrowserDALAB->setFrameShadow(QFrame::Plain);
        textBrowserDALAB->setOpenExternalLinks(true);
        textBrowserDALAB->setOpenLinks(true);

        verticalLayout->addWidget(textBrowserDALAB);

        groupBox = new QGroupBox(AboutDialog);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font2;
        font2.setFamily(QStringLiteral("Arial"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setWeight(50);
        groupBox->setFont(font2);
        groupBox->setContextMenuPolicy(Qt::NoContextMenu);
        groupBox->setStyleSheet(QStringLiteral(""));
        groupBox->setAlignment(Qt::AlignCenter);
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        plainTextEdit = new QPlainTextEdit(groupBox);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setContextMenuPolicy(Qt::NoContextMenu);
        plainTextEdit->setReadOnly(true);

        verticalLayout_2->addWidget(plainTextEdit);


        verticalLayout->addWidget(groupBox);


        retranslateUi(AboutDialog);

        QMetaObject::connectSlotsByName(AboutDialog);
    } // setupUi

    void retranslateUi(QDialog *AboutDialog)
    {
        AboutDialog->setWindowTitle(QApplication::translate("AboutDialog", "About SJTU Flow", 0));
        labelIcon->setText(QString());
        labelName->setText(QApplication::translate("AboutDialog", "SJTU Flow v0.6", 0));
        textBrowserAuthor->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Arial'; font-size:9pt; font-weight:600; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:12pt; font-weight:400; font-style:italic;\">  Author:                          SJTU DALAB Team</span></p></body></html>", 0));
        textBrowserDALAB->setHtml(QApplication::translate("AboutDialog", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'Arial'; font-size:12pt; font-style:italic;\">  DALAB Home Page: </span><a href=\"http://dalab.se.sjtu.edu.cn/\"><span style=\" font-family:'Arial'; font-size:12pt; font-style:italic; text-decoration: underline; color:#0000ff;\">http://dalab.se.sjtu.edu.cn/</span></a></p></body></html>", 0));
        groupBox->setTitle(QApplication::translate("AboutDialog", "GNU General Public Licence", 0));
        plainTextEdit->setPlainText(QApplication::translate("AboutDialog", "This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation; either version 2 of the License, or (at your option) any later version.\n"
"\n"
"This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details. \n"
"\n"
"You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.", 0));
    } // retranslateUi

};

namespace Ui {
    class AboutDialog: public Ui_AboutDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ABOUTDIALOG_H
