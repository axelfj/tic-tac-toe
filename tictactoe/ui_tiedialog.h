/********************************************************************************
** Form generated from reading UI file 'tiedialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIEDIALOG_H
#define UI_TIEDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_TieDialog
{
public:
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *TieDialog)
    {
        if (TieDialog->objectName().isEmpty())
            TieDialog->setObjectName(QStringLiteral("TieDialog"));
        TieDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(TieDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);

        retranslateUi(TieDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), TieDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), TieDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(TieDialog);
    } // setupUi

    void retranslateUi(QDialog *TieDialog)
    {
        TieDialog->setWindowTitle(QApplication::translate("TieDialog", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class TieDialog: public Ui_TieDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIEDIALOG_H
