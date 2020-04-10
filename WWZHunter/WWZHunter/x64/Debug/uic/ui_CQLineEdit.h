/********************************************************************************
** Form generated from reading UI file 'CQLineEdit.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CQLINEEDIT_H
#define UI_CQLINEEDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_CQLineEdit
{
public:

    void setupUi(QLineEdit *CQLineEdit)
    {
        if (CQLineEdit->objectName().isEmpty())
            CQLineEdit->setObjectName(QString::fromUtf8("CQLineEdit"));
        CQLineEdit->resize(404, 64);

        retranslateUi(CQLineEdit);

        QMetaObject::connectSlotsByName(CQLineEdit);
    } // setupUi

    void retranslateUi(QLineEdit *CQLineEdit)
    {
        CQLineEdit->setWindowTitle(QCoreApplication::translate("CQLineEdit", "CQLineEdit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CQLineEdit: public Ui_CQLineEdit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CQLINEEDIT_H
