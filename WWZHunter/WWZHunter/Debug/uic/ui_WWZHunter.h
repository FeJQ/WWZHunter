/********************************************************************************
** Form generated from reading UI file 'WWZHunter.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WWZHUNTER_H
#define UI_WWZHUNTER_H

#include "CQCheckBox.h"
#include "CQLineEdit.h"
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WWZHunterClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_3;
    QTabWidget *tabCard;
    QWidget *tabCardOffLine;
    QFormLayout *formLayout;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labOfflineUnlimitedHealth;
    QSpacerItem *horizontalSpacer_3;
    CQCheckBox *ckbOfflineUnlimitedHealth;
    QSpacerItem *horizontalSpacer_4;
    CQLineEdit *txtOfflineUnlimitedHealth;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labOfflineUnlimitedAmmo;
    QSpacerItem *horizontalSpacer_5;
    CQCheckBox *ckbOfflineUnlimitedAmmo;
    QSpacerItem *horizontalSpacer_6;
    CQLineEdit *txtOfflineUnlimitedAmmo;
    QSpacerItem *verticalSpacer;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *labTitle;
    QLabel *labState;

    void setupUi(QWidget *WWZHunterClass)
    {
        if (WWZHunterClass->objectName().isEmpty())
            WWZHunterClass->setObjectName(QString::fromUtf8("WWZHunterClass"));
        WWZHunterClass->resize(513, 314);
        gridLayout = new QGridLayout(WWZHunterClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        tabCard = new QTabWidget(WWZHunterClass);
        tabCard->setObjectName(QString::fromUtf8("tabCard"));
        tabCard->setLayoutDirection(Qt::LeftToRight);
        tabCard->setMovable(false);
        tabCardOffLine = new QWidget();
        tabCardOffLine->setObjectName(QString::fromUtf8("tabCardOffLine"));
        formLayout = new QFormLayout(tabCardOffLine);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labOfflineUnlimitedHealth = new QLabel(tabCardOffLine);
        labOfflineUnlimitedHealth->setObjectName(QString::fromUtf8("labOfflineUnlimitedHealth"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labOfflineUnlimitedHealth->sizePolicy().hasHeightForWidth());
        labOfflineUnlimitedHealth->setSizePolicy(sizePolicy);
        labOfflineUnlimitedHealth->setMinimumSize(QSize(0, 0));
        labOfflineUnlimitedHealth->setLayoutDirection(Qt::LeftToRight);
        labOfflineUnlimitedHealth->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labOfflineUnlimitedHealth);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        ckbOfflineUnlimitedHealth = new CQCheckBox(tabCardOffLine);
        ckbOfflineUnlimitedHealth->setObjectName(QString::fromUtf8("ckbOfflineUnlimitedHealth"));

        horizontalLayout_5->addWidget(ckbOfflineUnlimitedHealth);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        txtOfflineUnlimitedHealth = new CQLineEdit(tabCardOffLine);
        txtOfflineUnlimitedHealth->setObjectName(QString::fromUtf8("txtOfflineUnlimitedHealth"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtOfflineUnlimitedHealth->sizePolicy().hasHeightForWidth());
        txtOfflineUnlimitedHealth->setSizePolicy(sizePolicy1);
        txtOfflineUnlimitedHealth->setMinimumSize(QSize(60, 0));
        txtOfflineUnlimitedHealth->setMaximumSize(QSize(300, 16777215));
        txtOfflineUnlimitedHealth->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(txtOfflineUnlimitedHealth);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_2);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labOfflineUnlimitedAmmo = new QLabel(tabCardOffLine);
        labOfflineUnlimitedAmmo->setObjectName(QString::fromUtf8("labOfflineUnlimitedAmmo"));
        sizePolicy.setHeightForWidth(labOfflineUnlimitedAmmo->sizePolicy().hasHeightForWidth());
        labOfflineUnlimitedAmmo->setSizePolicy(sizePolicy);
        labOfflineUnlimitedAmmo->setMinimumSize(QSize(0, 0));

        horizontalLayout_6->addWidget(labOfflineUnlimitedAmmo);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        ckbOfflineUnlimitedAmmo = new CQCheckBox(tabCardOffLine);
        ckbOfflineUnlimitedAmmo->setObjectName(QString::fromUtf8("ckbOfflineUnlimitedAmmo"));

        horizontalLayout_6->addWidget(ckbOfflineUnlimitedAmmo);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        txtOfflineUnlimitedAmmo = new CQLineEdit(tabCardOffLine);
        txtOfflineUnlimitedAmmo->setObjectName(QString::fromUtf8("txtOfflineUnlimitedAmmo"));
        sizePolicy1.setHeightForWidth(txtOfflineUnlimitedAmmo->sizePolicy().hasHeightForWidth());
        txtOfflineUnlimitedAmmo->setSizePolicy(sizePolicy1);
        txtOfflineUnlimitedAmmo->setMinimumSize(QSize(60, 0));
        txtOfflineUnlimitedAmmo->setMaximumSize(QSize(300, 16777215));

        horizontalLayout_6->addWidget(txtOfflineUnlimitedAmmo);


        verticalLayout_7->addLayout(horizontalLayout_6);


        formLayout->setLayout(1, QFormLayout::SpanningRole, verticalLayout_7);

        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

        tabCard->addTab(tabCardOffLine, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabCard->addTab(tab_2, QString());

        horizontalLayout_3->addWidget(tabCard);


        gridLayout->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labTitle = new QLabel(WWZHunterClass);
        labTitle->setObjectName(QString::fromUtf8("labTitle"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labTitle->sizePolicy().hasHeightForWidth());
        labTitle->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(labTitle);

        labState = new QLabel(WWZHunterClass);
        labState->setObjectName(QString::fromUtf8("labState"));
        QSizePolicy sizePolicy3(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(labState->sizePolicy().hasHeightForWidth());
        labState->setSizePolicy(sizePolicy3);
        labState->setMinimumSize(QSize(16, 16));
        labState->setMaximumSize(QSize(16, 16));

        horizontalLayout->addWidget(labState);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);


        retranslateUi(WWZHunterClass);

        tabCard->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(WWZHunterClass);
    } // setupUi

    void retranslateUi(QWidget *WWZHunterClass)
    {
        WWZHunterClass->setWindowTitle(QCoreApplication::translate("WWZHunterClass", "WWZHunter", nullptr));
        labOfflineUnlimitedHealth->setText(QCoreApplication::translate("WWZHunterClass", "TextLabel", nullptr));
        ckbOfflineUnlimitedHealth->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labOfflineUnlimitedAmmo->setText(QCoreApplication::translate("WWZHunterClass", "TextLabel", nullptr));
        ckbOfflineUnlimitedAmmo->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        tabCard->setTabText(tabCard->indexOf(tabCardOffLine), QCoreApplication::translate("WWZHunterClass", "Tab 1", nullptr));
        tabCard->setTabText(tabCard->indexOf(tab_2), QCoreApplication::translate("WWZHunterClass", "Tab 2", nullptr));
        labTitle->setText(QCoreApplication::translate("WWZHunterClass", "WORLD WAR Zgtgtg ", nullptr));
        labState->setText(QCoreApplication::translate("WWZHunterClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WWZHunterClass: public Ui_WWZHunterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WWZHUNTER_H
