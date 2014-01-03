/********************************************************************************
** Form generated from reading UI file 'setting.ui'
**
** Created by: Qt User Interface Compiler version 5.1.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTING_H
#define UI_SETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Setting
{
public:
    QGridLayout *gridLayout;
    QStackedWidget *stackedWidget;
    QWidget *pageRun;
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer_4;
    QGroupBox *groupBoxPy;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelPyPath;
    QLineEdit *lineEditPyPath;
    QPushButton *pushButtonPyPath;
    QGroupBox *groupBoxRunOutput;
    QGridLayout *gridLayout_2;
    QLineEdit *lineEditRunOutputName;
    QLabel *labelRunPath;
    QLineEdit *lineEditRunOutputPath;
    QLabel *labelRunName;
    QPushButton *pushButtonOutputPath;
    QLabel *labelPromote;
    QSpacerItem *verticalSpacer;
    QWidget *pageRender;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_3;
    QCheckBox *checkBoxRender;
    QGroupBox *groupBoxRenderOutput;
    QGridLayout *gridLayout_3;
    QLabel *labelRenderSize;
    QComboBox *comboBoxSize;
    QLabel *labelRenderName;
    QLabel *labelRenderPath;
    QSpacerItem *horizontalSpacer_2;
    QLineEdit *lineEditRenderName;
    QLineEdit *lineEditRenderPath;
    QSpacerItem *verticalSpacer_2;
    QWidget *pageDllManager;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButtonNew;
    QPushButton *pushButtonDelete;
    QListWidget *listWidgetDll;
    QLabel *labelSysLib;
    QPlainTextEdit *plainTextEditSysLib;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonOK;
    QPushButton *pushButtonCancel;
    QPushButton *pushButtonApply;
    QListWidget *listWidget;

    void setupUi(QDialog *Setting)
    {
        if (Setting->objectName().isEmpty())
            Setting->setObjectName(QStringLiteral("Setting"));
        Setting->resize(420, 320);
        Setting->setMinimumSize(QSize(420, 320));
        Setting->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon;
        icon.addFile(QStringLiteral(":/SJTUFlow/Resources/SJTU-Icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        Setting->setWindowIcon(icon);
        gridLayout = new QGridLayout(Setting);
        gridLayout->setSpacing(0);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        stackedWidget = new QStackedWidget(Setting);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        pageRun = new QWidget();
        pageRun->setObjectName(QStringLiteral("pageRun"));
        verticalLayout = new QVBoxLayout(pageRun);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_4);

        groupBoxPy = new QGroupBox(pageRun);
        groupBoxPy->setObjectName(QStringLiteral("groupBoxPy"));
        horizontalLayout_2 = new QHBoxLayout(groupBoxPy);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        labelPyPath = new QLabel(groupBoxPy);
        labelPyPath->setObjectName(QStringLiteral("labelPyPath"));

        horizontalLayout_2->addWidget(labelPyPath);

        lineEditPyPath = new QLineEdit(groupBoxPy);
        lineEditPyPath->setObjectName(QStringLiteral("lineEditPyPath"));
        lineEditPyPath->setReadOnly(true);

        horizontalLayout_2->addWidget(lineEditPyPath);

        pushButtonPyPath = new QPushButton(groupBoxPy);
        pushButtonPyPath->setObjectName(QStringLiteral("pushButtonPyPath"));
        pushButtonPyPath->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(pushButtonPyPath);


        verticalLayout->addWidget(groupBoxPy);

        groupBoxRunOutput = new QGroupBox(pageRun);
        groupBoxRunOutput->setObjectName(QStringLiteral("groupBoxRunOutput"));
        gridLayout_2 = new QGridLayout(groupBoxRunOutput);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        lineEditRunOutputName = new QLineEdit(groupBoxRunOutput);
        lineEditRunOutputName->setObjectName(QStringLiteral("lineEditRunOutputName"));

        gridLayout_2->addWidget(lineEditRunOutputName, 1, 1, 1, 1);

        labelRunPath = new QLabel(groupBoxRunOutput);
        labelRunPath->setObjectName(QStringLiteral("labelRunPath"));

        gridLayout_2->addWidget(labelRunPath, 0, 0, 1, 1);

        lineEditRunOutputPath = new QLineEdit(groupBoxRunOutput);
        lineEditRunOutputPath->setObjectName(QStringLiteral("lineEditRunOutputPath"));
        lineEditRunOutputPath->setReadOnly(true);

        gridLayout_2->addWidget(lineEditRunOutputPath, 0, 1, 1, 1);

        labelRunName = new QLabel(groupBoxRunOutput);
        labelRunName->setObjectName(QStringLiteral("labelRunName"));

        gridLayout_2->addWidget(labelRunName, 1, 0, 1, 1);

        pushButtonOutputPath = new QPushButton(groupBoxRunOutput);
        pushButtonOutputPath->setObjectName(QStringLiteral("pushButtonOutputPath"));
        pushButtonOutputPath->setMaximumSize(QSize(50, 16777215));

        gridLayout_2->addWidget(pushButtonOutputPath, 0, 2, 1, 1);

        labelPromote = new QLabel(groupBoxRunOutput);
        labelPromote->setObjectName(QStringLiteral("labelPromote"));

        gridLayout_2->addWidget(labelPromote, 2, 1, 1, 2);


        verticalLayout->addWidget(groupBoxRunOutput);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        stackedWidget->addWidget(pageRun);
        pageRender = new QWidget();
        pageRender->setObjectName(QStringLiteral("pageRender"));
        verticalLayout_2 = new QVBoxLayout(pageRender);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        checkBoxRender = new QCheckBox(pageRender);
        checkBoxRender->setObjectName(QStringLiteral("checkBoxRender"));

        verticalLayout_2->addWidget(checkBoxRender);

        groupBoxRenderOutput = new QGroupBox(pageRender);
        groupBoxRenderOutput->setObjectName(QStringLiteral("groupBoxRenderOutput"));
        groupBoxRenderOutput->setEnabled(false);
        gridLayout_3 = new QGridLayout(groupBoxRenderOutput);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        labelRenderSize = new QLabel(groupBoxRenderOutput);
        labelRenderSize->setObjectName(QStringLiteral("labelRenderSize"));

        gridLayout_3->addWidget(labelRenderSize, 2, 0, 1, 1);

        comboBoxSize = new QComboBox(groupBoxRenderOutput);
        comboBoxSize->setObjectName(QStringLiteral("comboBoxSize"));

        gridLayout_3->addWidget(comboBoxSize, 2, 1, 1, 1);

        labelRenderName = new QLabel(groupBoxRenderOutput);
        labelRenderName->setObjectName(QStringLiteral("labelRenderName"));

        gridLayout_3->addWidget(labelRenderName, 1, 0, 1, 1);

        labelRenderPath = new QLabel(groupBoxRenderOutput);
        labelRenderPath->setObjectName(QStringLiteral("labelRenderPath"));

        gridLayout_3->addWidget(labelRenderPath, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 2, 2, 1, 1);

        lineEditRenderName = new QLineEdit(groupBoxRenderOutput);
        lineEditRenderName->setObjectName(QStringLiteral("lineEditRenderName"));

        gridLayout_3->addWidget(lineEditRenderName, 1, 1, 1, 2);

        lineEditRenderPath = new QLineEdit(groupBoxRenderOutput);
        lineEditRenderPath->setObjectName(QStringLiteral("lineEditRenderPath"));

        gridLayout_3->addWidget(lineEditRenderPath, 0, 1, 1, 2);


        verticalLayout_2->addWidget(groupBoxRenderOutput);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        stackedWidget->addWidget(pageRender);
        pageDllManager = new QWidget();
        pageDllManager->setObjectName(QStringLiteral("pageDllManager"));
        verticalLayout_3 = new QVBoxLayout(pageDllManager);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(3);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);

        pushButtonNew = new QPushButton(pageDllManager);
        pushButtonNew->setObjectName(QStringLiteral("pushButtonNew"));
        pushButtonNew->setMaximumSize(QSize(50, 16777215));
        pushButtonNew->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/Icons/Resources/Icons/DllNew.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonNew->setIcon(icon1);
        pushButtonNew->setAutoDefault(false);

        horizontalLayout_3->addWidget(pushButtonNew);

        pushButtonDelete = new QPushButton(pageDllManager);
        pushButtonDelete->setObjectName(QStringLiteral("pushButtonDelete"));
        pushButtonDelete->setMaximumSize(QSize(50, 16777215));
        pushButtonDelete->setContextMenuPolicy(Qt::NoContextMenu);
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/Icons/Resources/Icons/DllDelete.bmp"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonDelete->setIcon(icon2);
        pushButtonDelete->setAutoDefault(false);

        horizontalLayout_3->addWidget(pushButtonDelete);


        verticalLayout_3->addLayout(horizontalLayout_3);

        listWidgetDll = new QListWidget(pageDllManager);
        listWidgetDll->setObjectName(QStringLiteral("listWidgetDll"));
        listWidgetDll->setContextMenuPolicy(Qt::NoContextMenu);
        listWidgetDll->setStyleSheet(QLatin1String("QListWidget::item\n"
"{\n"
"	height: 40px;\n"
"}"));
        listWidgetDll->setEditTriggers(QAbstractItemView::DoubleClicked|QAbstractItemView::EditKeyPressed);
        listWidgetDll->setSelectionBehavior(QAbstractItemView::SelectRows);
        listWidgetDll->setResizeMode(QListView::Adjust);

        verticalLayout_3->addWidget(listWidgetDll);

        labelSysLib = new QLabel(pageDllManager);
        labelSysLib->setObjectName(QStringLiteral("labelSysLib"));

        verticalLayout_3->addWidget(labelSysLib);

        plainTextEditSysLib = new QPlainTextEdit(pageDllManager);
        plainTextEditSysLib->setObjectName(QStringLiteral("plainTextEditSysLib"));
        plainTextEditSysLib->setContextMenuPolicy(Qt::NoContextMenu);
        plainTextEditSysLib->setReadOnly(true);

        verticalLayout_3->addWidget(plainTextEditSysLib);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_6);

        stackedWidget->addWidget(pageDllManager);

        gridLayout->addWidget(stackedWidget, 0, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButtonOK = new QPushButton(Setting);
        pushButtonOK->setObjectName(QStringLiteral("pushButtonOK"));
        pushButtonOK->setMaximumSize(QSize(70, 16777215));
        pushButtonOK->setAutoDefault(true);

        horizontalLayout->addWidget(pushButtonOK);

        pushButtonCancel = new QPushButton(Setting);
        pushButtonCancel->setObjectName(QStringLiteral("pushButtonCancel"));
        pushButtonCancel->setMaximumSize(QSize(70, 16777215));
        pushButtonCancel->setAutoDefault(false);

        horizontalLayout->addWidget(pushButtonCancel);

        pushButtonApply = new QPushButton(Setting);
        pushButtonApply->setObjectName(QStringLiteral("pushButtonApply"));
        pushButtonApply->setEnabled(false);
        pushButtonApply->setMaximumSize(QSize(70, 16777215));
        pushButtonApply->setAutoDefault(false);

        horizontalLayout->addWidget(pushButtonApply);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 2);

        listWidget = new QListWidget(Setting);
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/Icons/Resources/Icons/Run.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(listWidget);
        __qlistwidgetitem->setIcon(icon3);
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/Icons/Resources/Icons/Render.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem1 = new QListWidgetItem(listWidget);
        __qlistwidgetitem1->setIcon(icon4);
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/Icons/Resources/Icons/Libraries.png"), QSize(), QIcon::Normal, QIcon::Off);
        QListWidgetItem *__qlistwidgetitem2 = new QListWidgetItem(listWidget);
        __qlistwidgetitem2->setIcon(icon5);
        listWidget->setObjectName(QStringLiteral("listWidget"));
        listWidget->setMaximumSize(QSize(76, 16777215));
        listWidget->setSelectionBehavior(QAbstractItemView::SelectItems);
        listWidget->setIconSize(QSize(64, 64));
        listWidget->setTextElideMode(Qt::ElideMiddle);
        listWidget->setMovement(QListView::Static);
        listWidget->setFlow(QListView::LeftToRight);
        listWidget->setSpacing(0);
        listWidget->setViewMode(QListView::IconMode);

        gridLayout->addWidget(listWidget, 0, 0, 1, 1);

        gridLayout->setColumnStretch(1, 1);
        QWidget::setTabOrder(lineEditPyPath, lineEditRunOutputPath);
        QWidget::setTabOrder(lineEditRunOutputPath, lineEditRunOutputName);
        QWidget::setTabOrder(lineEditRunOutputName, lineEditRenderPath);
        QWidget::setTabOrder(lineEditRenderPath, lineEditRenderName);
        QWidget::setTabOrder(lineEditRenderName, comboBoxSize);
        QWidget::setTabOrder(comboBoxSize, pushButtonNew);
        QWidget::setTabOrder(pushButtonNew, pushButtonDelete);
        QWidget::setTabOrder(pushButtonDelete, plainTextEditSysLib);
        QWidget::setTabOrder(plainTextEditSysLib, pushButtonOK);
        QWidget::setTabOrder(pushButtonOK, pushButtonCancel);
        QWidget::setTabOrder(pushButtonCancel, pushButtonApply);

        retranslateUi(Setting);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(Setting);
    } // setupUi

    void retranslateUi(QDialog *Setting)
    {
        Setting->setWindowTitle(QApplication::translate("Setting", "Setting", 0));
        groupBoxPy->setTitle(QApplication::translate("Setting", "Python", 0));
        labelPyPath->setText(QApplication::translate("Setting", "Path", 0));
        pushButtonPyPath->setText(QApplication::translate("Setting", "Browse", 0));
        groupBoxRunOutput->setTitle(QApplication::translate("Setting", "Output", 0));
        labelRunPath->setText(QApplication::translate("Setting", "Path", 0));
        labelRunName->setText(QApplication::translate("Setting", "Name", 0));
        pushButtonOutputPath->setText(QApplication::translate("Setting", "Browse", 0));
        labelPromote->setText(QApplication::translate("Setting", "TextLabel", 0));
        checkBoxRender->setText(QApplication::translate("Setting", "Render the results using renderer", 0));
        groupBoxRenderOutput->setTitle(QApplication::translate("Setting", "Output", 0));
        labelRenderSize->setText(QApplication::translate("Setting", "Size", 0));
        comboBoxSize->clear();
        comboBoxSize->insertItems(0, QStringList()
         << QApplication::translate("Setting", "640x480", 0)
         << QApplication::translate("Setting", "800x600", 0)
        );
        labelRenderName->setText(QApplication::translate("Setting", "Name", 0));
        labelRenderPath->setText(QApplication::translate("Setting", "Path", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonNew->setToolTip(QApplication::translate("Setting", "New Dll", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonNew->setStatusTip(QApplication::translate("Setting", "New Dll", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonNew->setWhatsThis(QApplication::translate("Setting", "New Dll", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonNew->setText(QString());
#ifndef QT_NO_TOOLTIP
        pushButtonDelete->setToolTip(QApplication::translate("Setting", "Delete selected row", 0));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        pushButtonDelete->setStatusTip(QApplication::translate("Setting", "Delete selected row", 0));
#endif // QT_NO_STATUSTIP
#ifndef QT_NO_WHATSTHIS
        pushButtonDelete->setWhatsThis(QApplication::translate("Setting", "Delete selected row", 0));
#endif // QT_NO_WHATSTHIS
        pushButtonDelete->setText(QString());
        labelSysLib->setText(QApplication::translate("Setting", "System Libraries", 0));
        plainTextEditSysLib->setPlainText(QApplication::translate("Setting", "SJTUFlow_SPH.pyd", 0));
        pushButtonOK->setText(QApplication::translate("Setting", "OK", 0));
        pushButtonCancel->setText(QApplication::translate("Setting", "Cancel", 0));
        pushButtonApply->setText(QApplication::translate("Setting", "Apply", 0));

        const bool __sortingEnabled = listWidget->isSortingEnabled();
        listWidget->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = listWidget->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("Setting", "Run", 0));
        QListWidgetItem *___qlistwidgetitem1 = listWidget->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("Setting", "Render", 0));
        QListWidgetItem *___qlistwidgetitem2 = listWidget->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("Setting", "Libraries", 0));
        listWidget->setSortingEnabled(__sortingEnabled);

    } // retranslateUi

};

namespace Ui {
    class Setting: public Ui_Setting {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTING_H
