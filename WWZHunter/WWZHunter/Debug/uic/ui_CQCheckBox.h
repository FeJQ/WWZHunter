/********************************************************************************
** Form generated from reading UI file 'CQCheckBox.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQCHECKBOX_H
#define UI_CQCHECKBOX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>

QT_BEGIN_NAMESPACE

class Ui_CQCheckBox
{
public:

    void setupUi(QCheckBox *CQCheckBox)
    {
        if (CQCheckBox->objectName().isEmpty())
            CQCheckBox->setObjectName(QString::fromUtf8("CQCheckBox"));
        CQCheckBox->resize(400, 300);

        retranslateUi(CQCheckBox);

        QMetaObject::connectSlotsByName(CQCheckBox);
    } // setupUi

    void retranslateUi(QCheckBox *CQCheckBox)
    {
        CQCheckBox->setWindowTitle(QCoreApplication::translate("CQCheckBox", "CQCheckBox", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CQCheckBox: public Ui_CQCheckBox {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQCHECKBOX_H
