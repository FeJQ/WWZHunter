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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextEdit>
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
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labOfflineUnlimitedHealth;
    QSpacerItem *horizontalSpacer_3;
    CQCheckBox *ckbOfflineUnlimitedHealth;
    QSpacerItem *horizontalSpacer_4;
    CQLineEdit *txtOfflineUnlimitedHealth;
    QSpacerItem *verticalSpacer_2;
    QHBoxLayout *horizontalLayout_10;
    QLabel *labLockSight;
    QSpacerItem *horizontalSpacer_10;
    CQCheckBox *ckbLockSight;
    QSpacerItem *horizontalSpacer_12;
    CQLineEdit *txtLockSight;
    QSpacerItem *verticalSpacer_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labOfflineUnlimitedAmmo;
    QSpacerItem *horizontalSpacer_5;
    CQCheckBox *ckbOfflineUnlimitedAmmo;
    QSpacerItem *horizontalSpacer_6;
    CQLineEdit *txtOfflineUnlimitedAmmo;
    QSpacerItem *verticalSpacer_3;
    QHBoxLayout *horizontalLayout_12;
    QLabel *labUnlimitedMelee;
    QSpacerItem *horizontalSpacer_15;
    CQCheckBox *ckbUnlimitedMelee;
    QSpacerItem *horizontalSpacer_16;
    CQLineEdit *txtUnlimitedMelee;
    QSpacerItem *verticalSpacer_6;
    QHBoxLayout *horizontalLayout_13;
    QLabel *labAdjustPos;
    QSpacerItem *horizontalSpacer_17;
    CQCheckBox *ckbAdjustPos;
    QSpacerItem *horizontalSpacer_18;
    CQLineEdit *txtAdjustPos;
    QSpacerItem *verticalSpacer_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *labAdjustMainWeaponFireRate;
    QSpacerItem *horizontalSpacer_9;
    QPushButton *btnAdjustMainWeaponFireRateDown;
    QLineEdit *txtAdjustMainWeaponFireRateValue;
    QPushButton *btnAdjustMainWeaponFireRateUp;
    QSpacerItem *horizontalSpacer;
    CQLineEdit *txtAdjustMainWeaponFireRate;
    QSpacerItem *verticalSpacer_4;
    QHBoxLayout *horizontalLayout_9;
    QLabel *labAdjustSencondWeaponFireRate;
    QSpacerItem *horizontalSpacer_11;
    QPushButton *btnAdjustSencondWeaponFireRateDown;
    QLineEdit *txtAdjustSencondWeaponFireRateValue;
    QPushButton *btnAdjustSencondWeaponFireRateUp;
    QSpacerItem *horizontalSpacer_2;
    CQLineEdit *txtAdjustSencondWeaponFireRate;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labMusic;
    QSpacerItem *horizontalSpacer_7;
    CQCheckBox *ckbMusic;
    QSpacerItem *horizontalSpacer_8;
    CQLineEdit *txtMusic;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labHotKey;
    QSpacerItem *horizontalSpacer_14;
    CQCheckBox *ckbHotKey;
    QSpacerItem *horizontalSpacer_13;
    CQLineEdit *txtHotKey;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QTextEdit *txtAbout;
    QHBoxLayout *horizontalLayout;
    QLabel *labTitle;
    QLabel *labState;

    void setupUi(QWidget *WWZHunterClass)
    {
        if (WWZHunterClass->objectName().isEmpty())
            WWZHunterClass->setObjectName(QString::fromUtf8("WWZHunterClass"));
        WWZHunterClass->resize(390, 490);
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
        verticalSpacer = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        formLayout->setItem(0, QFormLayout::FieldRole, verticalSpacer);

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
        labOfflineUnlimitedHealth->setMinimumSize(QSize(100, 0));
        labOfflineUnlimitedHealth->setLayoutDirection(Qt::LeftToRight);
        labOfflineUnlimitedHealth->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labOfflineUnlimitedHealth);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_3);

        ckbOfflineUnlimitedHealth = new CQCheckBox(tabCardOffLine);
        ckbOfflineUnlimitedHealth->setObjectName(QString::fromUtf8("ckbOfflineUnlimitedHealth"));

        horizontalLayout_5->addWidget(ckbOfflineUnlimitedHealth);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_4);

        txtOfflineUnlimitedHealth = new CQLineEdit(tabCardOffLine);
        txtOfflineUnlimitedHealth->setObjectName(QString::fromUtf8("txtOfflineUnlimitedHealth"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(txtOfflineUnlimitedHealth->sizePolicy().hasHeightForWidth());
        txtOfflineUnlimitedHealth->setSizePolicy(sizePolicy1);
        txtOfflineUnlimitedHealth->setMinimumSize(QSize(100, 0));
        txtOfflineUnlimitedHealth->setMaximumSize(QSize(100, 16777215));
        txtOfflineUnlimitedHealth->setAlignment(Qt::AlignCenter);

        horizontalLayout_5->addWidget(txtOfflineUnlimitedHealth);


        verticalLayout_7->addLayout(horizontalLayout_5);

        verticalSpacer_2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_2);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        labLockSight = new QLabel(tabCardOffLine);
        labLockSight->setObjectName(QString::fromUtf8("labLockSight"));
        sizePolicy.setHeightForWidth(labLockSight->sizePolicy().hasHeightForWidth());
        labLockSight->setSizePolicy(sizePolicy);
        labLockSight->setMinimumSize(QSize(100, 0));
        labLockSight->setLayoutDirection(Qt::LeftToRight);
        labLockSight->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_10->addWidget(labLockSight);

        horizontalSpacer_10 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_10);

        ckbLockSight = new CQCheckBox(tabCardOffLine);
        ckbLockSight->setObjectName(QString::fromUtf8("ckbLockSight"));

        horizontalLayout_10->addWidget(ckbLockSight);

        horizontalSpacer_12 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_12);

        txtLockSight = new CQLineEdit(tabCardOffLine);
        txtLockSight->setObjectName(QString::fromUtf8("txtLockSight"));
        sizePolicy1.setHeightForWidth(txtLockSight->sizePolicy().hasHeightForWidth());
        txtLockSight->setSizePolicy(sizePolicy1);
        txtLockSight->setMinimumSize(QSize(100, 0));
        txtLockSight->setMaximumSize(QSize(100, 16777215));
        txtLockSight->setAlignment(Qt::AlignCenter);

        horizontalLayout_10->addWidget(txtLockSight);


        verticalLayout_7->addLayout(horizontalLayout_10);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labOfflineUnlimitedAmmo = new QLabel(tabCardOffLine);
        labOfflineUnlimitedAmmo->setObjectName(QString::fromUtf8("labOfflineUnlimitedAmmo"));
        sizePolicy.setHeightForWidth(labOfflineUnlimitedAmmo->sizePolicy().hasHeightForWidth());
        labOfflineUnlimitedAmmo->setSizePolicy(sizePolicy);
        labOfflineUnlimitedAmmo->setMinimumSize(QSize(100, 0));

        horizontalLayout_6->addWidget(labOfflineUnlimitedAmmo);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_5);

        ckbOfflineUnlimitedAmmo = new CQCheckBox(tabCardOffLine);
        ckbOfflineUnlimitedAmmo->setObjectName(QString::fromUtf8("ckbOfflineUnlimitedAmmo"));

        horizontalLayout_6->addWidget(ckbOfflineUnlimitedAmmo);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_6);

        txtOfflineUnlimitedAmmo = new CQLineEdit(tabCardOffLine);
        txtOfflineUnlimitedAmmo->setObjectName(QString::fromUtf8("txtOfflineUnlimitedAmmo"));
        sizePolicy1.setHeightForWidth(txtOfflineUnlimitedAmmo->sizePolicy().hasHeightForWidth());
        txtOfflineUnlimitedAmmo->setSizePolicy(sizePolicy1);
        txtOfflineUnlimitedAmmo->setMinimumSize(QSize(100, 0));
        txtOfflineUnlimitedAmmo->setMaximumSize(QSize(100, 16777215));
        txtOfflineUnlimitedAmmo->setAlignment(Qt::AlignCenter);

        horizontalLayout_6->addWidget(txtOfflineUnlimitedAmmo);


        verticalLayout_7->addLayout(horizontalLayout_6);

        verticalSpacer_3 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_3);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        labUnlimitedMelee = new QLabel(tabCardOffLine);
        labUnlimitedMelee->setObjectName(QString::fromUtf8("labUnlimitedMelee"));
        sizePolicy.setHeightForWidth(labUnlimitedMelee->sizePolicy().hasHeightForWidth());
        labUnlimitedMelee->setSizePolicy(sizePolicy);
        labUnlimitedMelee->setMinimumSize(QSize(100, 0));
        labUnlimitedMelee->setLayoutDirection(Qt::LeftToRight);
        labUnlimitedMelee->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_12->addWidget(labUnlimitedMelee);

        horizontalSpacer_15 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_15);

        ckbUnlimitedMelee = new CQCheckBox(tabCardOffLine);
        ckbUnlimitedMelee->setObjectName(QString::fromUtf8("ckbUnlimitedMelee"));

        horizontalLayout_12->addWidget(ckbUnlimitedMelee);

        horizontalSpacer_16 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_12->addItem(horizontalSpacer_16);

        txtUnlimitedMelee = new CQLineEdit(tabCardOffLine);
        txtUnlimitedMelee->setObjectName(QString::fromUtf8("txtUnlimitedMelee"));
        sizePolicy1.setHeightForWidth(txtUnlimitedMelee->sizePolicy().hasHeightForWidth());
        txtUnlimitedMelee->setSizePolicy(sizePolicy1);
        txtUnlimitedMelee->setMinimumSize(QSize(100, 0));
        txtUnlimitedMelee->setMaximumSize(QSize(100, 16777215));
        txtUnlimitedMelee->setAlignment(Qt::AlignCenter);

        horizontalLayout_12->addWidget(txtUnlimitedMelee);


        verticalLayout_7->addLayout(horizontalLayout_12);

        verticalSpacer_6 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_6);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        labAdjustPos = new QLabel(tabCardOffLine);
        labAdjustPos->setObjectName(QString::fromUtf8("labAdjustPos"));
        sizePolicy.setHeightForWidth(labAdjustPos->sizePolicy().hasHeightForWidth());
        labAdjustPos->setSizePolicy(sizePolicy);
        labAdjustPos->setMinimumSize(QSize(100, 0));
        labAdjustPos->setLayoutDirection(Qt::LeftToRight);
        labAdjustPos->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);

        horizontalLayout_13->addWidget(labAdjustPos);

        horizontalSpacer_17 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_17);

        ckbAdjustPos = new CQCheckBox(tabCardOffLine);
        ckbAdjustPos->setObjectName(QString::fromUtf8("ckbAdjustPos"));

        horizontalLayout_13->addWidget(ckbAdjustPos);

        horizontalSpacer_18 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_13->addItem(horizontalSpacer_18);

        txtAdjustPos = new CQLineEdit(tabCardOffLine);
        txtAdjustPos->setObjectName(QString::fromUtf8("txtAdjustPos"));
        sizePolicy1.setHeightForWidth(txtAdjustPos->sizePolicy().hasHeightForWidth());
        txtAdjustPos->setSizePolicy(sizePolicy1);
        txtAdjustPos->setMinimumSize(QSize(100, 0));
        txtAdjustPos->setMaximumSize(QSize(100, 16777215));
        txtAdjustPos->setAlignment(Qt::AlignCenter);

        horizontalLayout_13->addWidget(txtAdjustPos);


        verticalLayout_7->addLayout(horizontalLayout_13);

        verticalSpacer_7 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        labAdjustMainWeaponFireRate = new QLabel(tabCardOffLine);
        labAdjustMainWeaponFireRate->setObjectName(QString::fromUtf8("labAdjustMainWeaponFireRate"));
        sizePolicy.setHeightForWidth(labAdjustMainWeaponFireRate->sizePolicy().hasHeightForWidth());
        labAdjustMainWeaponFireRate->setSizePolicy(sizePolicy);
        labAdjustMainWeaponFireRate->setMinimumSize(QSize(100, 0));

        horizontalLayout_8->addWidget(labAdjustMainWeaponFireRate);

        horizontalSpacer_9 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_9);

        btnAdjustMainWeaponFireRateDown = new QPushButton(tabCardOffLine);
        btnAdjustMainWeaponFireRateDown->setObjectName(QString::fromUtf8("btnAdjustMainWeaponFireRateDown"));
        btnAdjustMainWeaponFireRateDown->setMinimumSize(QSize(30, 30));
        btnAdjustMainWeaponFireRateDown->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_8->addWidget(btnAdjustMainWeaponFireRateDown);

        txtAdjustMainWeaponFireRateValue = new QLineEdit(tabCardOffLine);
        txtAdjustMainWeaponFireRateValue->setObjectName(QString::fromUtf8("txtAdjustMainWeaponFireRateValue"));
        txtAdjustMainWeaponFireRateValue->setEnabled(true);
        txtAdjustMainWeaponFireRateValue->setMinimumSize(QSize(0, 30));
        txtAdjustMainWeaponFireRateValue->setMaximumSize(QSize(70, 16777215));
        txtAdjustMainWeaponFireRateValue->setAlignment(Qt::AlignCenter);
        txtAdjustMainWeaponFireRateValue->setReadOnly(true);

        horizontalLayout_8->addWidget(txtAdjustMainWeaponFireRateValue);

        btnAdjustMainWeaponFireRateUp = new QPushButton(tabCardOffLine);
        btnAdjustMainWeaponFireRateUp->setObjectName(QString::fromUtf8("btnAdjustMainWeaponFireRateUp"));
        btnAdjustMainWeaponFireRateUp->setMinimumSize(QSize(30, 30));
        btnAdjustMainWeaponFireRateUp->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_8->addWidget(btnAdjustMainWeaponFireRateUp);

        horizontalSpacer = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        txtAdjustMainWeaponFireRate = new CQLineEdit(tabCardOffLine);
        txtAdjustMainWeaponFireRate->setObjectName(QString::fromUtf8("txtAdjustMainWeaponFireRate"));
        sizePolicy1.setHeightForWidth(txtAdjustMainWeaponFireRate->sizePolicy().hasHeightForWidth());
        txtAdjustMainWeaponFireRate->setSizePolicy(sizePolicy1);
        txtAdjustMainWeaponFireRate->setMinimumSize(QSize(100, 0));
        txtAdjustMainWeaponFireRate->setMaximumSize(QSize(100, 16777215));
        txtAdjustMainWeaponFireRate->setAlignment(Qt::AlignCenter);

        horizontalLayout_8->addWidget(txtAdjustMainWeaponFireRate);


        verticalLayout_7->addLayout(horizontalLayout_8);

        verticalSpacer_4 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_7->addItem(verticalSpacer_4);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        labAdjustSencondWeaponFireRate = new QLabel(tabCardOffLine);
        labAdjustSencondWeaponFireRate->setObjectName(QString::fromUtf8("labAdjustSencondWeaponFireRate"));
        sizePolicy.setHeightForWidth(labAdjustSencondWeaponFireRate->sizePolicy().hasHeightForWidth());
        labAdjustSencondWeaponFireRate->setSizePolicy(sizePolicy);
        labAdjustSencondWeaponFireRate->setMinimumSize(QSize(100, 0));

        horizontalLayout_9->addWidget(labAdjustSencondWeaponFireRate);

        horizontalSpacer_11 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_11);

        btnAdjustSencondWeaponFireRateDown = new QPushButton(tabCardOffLine);
        btnAdjustSencondWeaponFireRateDown->setObjectName(QString::fromUtf8("btnAdjustSencondWeaponFireRateDown"));
        btnAdjustSencondWeaponFireRateDown->setMinimumSize(QSize(30, 30));
        btnAdjustSencondWeaponFireRateDown->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_9->addWidget(btnAdjustSencondWeaponFireRateDown);

        txtAdjustSencondWeaponFireRateValue = new QLineEdit(tabCardOffLine);
        txtAdjustSencondWeaponFireRateValue->setObjectName(QString::fromUtf8("txtAdjustSencondWeaponFireRateValue"));
        txtAdjustSencondWeaponFireRateValue->setEnabled(true);
        txtAdjustSencondWeaponFireRateValue->setMinimumSize(QSize(0, 30));
        txtAdjustSencondWeaponFireRateValue->setMaximumSize(QSize(70, 16777215));
        txtAdjustSencondWeaponFireRateValue->setAlignment(Qt::AlignCenter);
        txtAdjustSencondWeaponFireRateValue->setReadOnly(true);

        horizontalLayout_9->addWidget(txtAdjustSencondWeaponFireRateValue);

        btnAdjustSencondWeaponFireRateUp = new QPushButton(tabCardOffLine);
        btnAdjustSencondWeaponFireRateUp->setObjectName(QString::fromUtf8("btnAdjustSencondWeaponFireRateUp"));
        btnAdjustSencondWeaponFireRateUp->setMinimumSize(QSize(30, 30));
        btnAdjustSencondWeaponFireRateUp->setMaximumSize(QSize(30, 16777215));

        horizontalLayout_9->addWidget(btnAdjustSencondWeaponFireRateUp);

        horizontalSpacer_2 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_2);

        txtAdjustSencondWeaponFireRate = new CQLineEdit(tabCardOffLine);
        txtAdjustSencondWeaponFireRate->setObjectName(QString::fromUtf8("txtAdjustSencondWeaponFireRate"));
        sizePolicy1.setHeightForWidth(txtAdjustSencondWeaponFireRate->sizePolicy().hasHeightForWidth());
        txtAdjustSencondWeaponFireRate->setSizePolicy(sizePolicy1);
        txtAdjustSencondWeaponFireRate->setMinimumSize(QSize(100, 0));
        txtAdjustSencondWeaponFireRate->setMaximumSize(QSize(100, 16777215));
        txtAdjustSencondWeaponFireRate->setAlignment(Qt::AlignCenter);

        horizontalLayout_9->addWidget(txtAdjustSencondWeaponFireRate);


        verticalLayout_7->addLayout(horizontalLayout_9);


        formLayout->setLayout(1, QFormLayout::SpanningRole, verticalLayout_7);

        tabCard->addTab(tabCardOffLine, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_2 = new QHBoxLayout(tab_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labMusic = new QLabel(tab_2);
        labMusic->setObjectName(QString::fromUtf8("labMusic"));
        sizePolicy.setHeightForWidth(labMusic->sizePolicy().hasHeightForWidth());
        labMusic->setSizePolicy(sizePolicy);
        labMusic->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(labMusic);

        horizontalSpacer_7 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        ckbMusic = new CQCheckBox(tab_2);
        ckbMusic->setObjectName(QString::fromUtf8("ckbMusic"));

        horizontalLayout_4->addWidget(ckbMusic);

        horizontalSpacer_8 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_8);

        txtMusic = new CQLineEdit(tab_2);
        txtMusic->setObjectName(QString::fromUtf8("txtMusic"));
        sizePolicy1.setHeightForWidth(txtMusic->sizePolicy().hasHeightForWidth());
        txtMusic->setSizePolicy(sizePolicy1);
        txtMusic->setMinimumSize(QSize(100, 0));
        txtMusic->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_4->addWidget(txtMusic);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labHotKey = new QLabel(tab_2);
        labHotKey->setObjectName(QString::fromUtf8("labHotKey"));
        sizePolicy.setHeightForWidth(labHotKey->sizePolicy().hasHeightForWidth());
        labHotKey->setSizePolicy(sizePolicy);
        labHotKey->setMinimumSize(QSize(100, 0));

        horizontalLayout_7->addWidget(labHotKey);

        horizontalSpacer_14 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_14);

        ckbHotKey = new CQCheckBox(tab_2);
        ckbHotKey->setObjectName(QString::fromUtf8("ckbHotKey"));

        horizontalLayout_7->addWidget(ckbHotKey);

        horizontalSpacer_13 = new QSpacerItem(10, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_13);

        txtHotKey = new CQLineEdit(tab_2);
        txtHotKey->setObjectName(QString::fromUtf8("txtHotKey"));
        sizePolicy1.setHeightForWidth(txtHotKey->sizePolicy().hasHeightForWidth());
        txtHotKey->setSizePolicy(sizePolicy1);
        txtHotKey->setMinimumSize(QSize(100, 0));
        txtHotKey->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_7->addWidget(txtHotKey);


        verticalLayout_2->addLayout(horizontalLayout_7);


        horizontalLayout_2->addLayout(verticalLayout_2);

        tabCard->addTab(tab_2, QString());
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        txtAbout = new QTextEdit(tab);
        txtAbout->setObjectName(QString::fromUtf8("txtAbout"));

        verticalLayout->addWidget(txtAbout);

        tabCard->addTab(tab, QString());

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

        tabCard->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(WWZHunterClass);
    } // setupUi

    void retranslateUi(QWidget *WWZHunterClass)
    {
        WWZHunterClass->setWindowTitle(QCoreApplication::translate("WWZHunterClass", "WWZHunter", nullptr));
        labOfflineUnlimitedHealth->setText(QCoreApplication::translate("WWZHunterClass", "\346\227\240\351\231\220\350\241\200\351\207\217", nullptr));
        ckbOfflineUnlimitedHealth->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labLockSight->setText(QCoreApplication::translate("WWZHunterClass", "\346\227\240\345\220\216\345\272\247\345\212\233", nullptr));
        ckbLockSight->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labOfflineUnlimitedAmmo->setText(QCoreApplication::translate("WWZHunterClass", "\346\227\240\351\231\220\345\255\220\345\274\271", nullptr));
        ckbOfflineUnlimitedAmmo->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labUnlimitedMelee->setText(QCoreApplication::translate("WWZHunterClass", "\346\227\240\351\231\220\350\277\221\346\210\230", nullptr));
        ckbUnlimitedMelee->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labAdjustPos->setText(QCoreApplication::translate("WWZHunterClass", "\344\272\272\347\211\251\344\275\215\347\247\273", nullptr));
        ckbAdjustPos->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labAdjustMainWeaponFireRate->setText(QCoreApplication::translate("WWZHunterClass", "\344\270\273\346\255\246\345\231\250\345\260\204\351\200\237", nullptr));
        btnAdjustMainWeaponFireRateDown->setText(QCoreApplication::translate("WWZHunterClass", "-", nullptr));
        txtAdjustMainWeaponFireRateValue->setText(QCoreApplication::translate("WWZHunterClass", "0", nullptr));
        btnAdjustMainWeaponFireRateUp->setText(QCoreApplication::translate("WWZHunterClass", "+", nullptr));
        labAdjustSencondWeaponFireRate->setText(QCoreApplication::translate("WWZHunterClass", "\345\211\257\346\255\246\345\231\250\345\260\204\351\200\237", nullptr));
        btnAdjustSencondWeaponFireRateDown->setText(QCoreApplication::translate("WWZHunterClass", "-", nullptr));
        txtAdjustSencondWeaponFireRateValue->setText(QCoreApplication::translate("WWZHunterClass", "0", nullptr));
        btnAdjustSencondWeaponFireRateUp->setText(QCoreApplication::translate("WWZHunterClass", "+", nullptr));
        tabCard->setTabText(tabCard->indexOf(tabCardOffLine), QCoreApplication::translate("WWZHunterClass", "Tab 1", nullptr));
        labMusic->setText(QCoreApplication::translate("WWZHunterClass", "TextLabel", nullptr));
        ckbMusic->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        labHotKey->setText(QCoreApplication::translate("WWZHunterClass", "TextLabel", nullptr));
        ckbHotKey->setText(QCoreApplication::translate("WWZHunterClass", "CheckBox", nullptr));
        tabCard->setTabText(tabCard->indexOf(tab_2), QCoreApplication::translate("WWZHunterClass", "Tab 2", nullptr));
        txtAbout->setHtml(QCoreApplication::translate("WWZHunterClass", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'SimSun'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", nullptr));
        tabCard->setTabText(tabCard->indexOf(tab), QCoreApplication::translate("WWZHunterClass", "\351\241\265", nullptr));
        labTitle->setText(QCoreApplication::translate("WWZHunterClass", "WORLD WAR Zgtgtg ", nullptr));
        labState->setText(QCoreApplication::translate("WWZHunterClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WWZHunterClass: public Ui_WWZHunterClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WWZHUNTER_H
