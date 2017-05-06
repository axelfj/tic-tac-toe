/********************************************************************************
** Form generated from reading UI file 'winnerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINNERDIALOG_H
#define UI_WINNERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WinnerDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;

    void setupUi(QDialog *WinnerDialog)
    {
        if (WinnerDialog->objectName().isEmpty())
            WinnerDialog->setObjectName(QStringLiteral("WinnerDialog"));
        WinnerDialog->resize(400, 300);
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/ic_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        WinnerDialog->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(WinnerDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        label = new QLabel(WinnerDialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 60, 80, 80));
        label_2 = new QLabel(WinnerDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 140, 320, 80));
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label_2->sizePolicy().hasHeightForWidth());
        label_2->setSizePolicy(sizePolicy);
        QPalette palette;
        QBrush brush(QColor(0, 176, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_2->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Product Sans"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(WinnerDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(440, 230, 80, 80));
        label_4 = new QLabel(WinnerDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(320, 310, 320, 80));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        label_4->setPalette(palette1);
        label_4->setFont(font);
        label_4->setAlignment(Qt::AlignCenter);
        buttonBox->raise();
        label_2->raise();
        label->raise();
        label_3->raise();
        label_4->raise();

        retranslateUi(WinnerDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinnerDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinnerDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinnerDialog);
    } // setupUi

    void retranslateUi(QDialog *WinnerDialog)
    {
        WinnerDialog->setWindowTitle(QApplication::translate("WinnerDialog", "Winner!", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("WinnerDialog", "The bot takes the game!", 0));
        label_3->setText(QString());
        label_4->setText(QApplication::translate("WinnerDialog", "The bot takes the game!", 0));
    } // retranslateUi

};

namespace Ui {
    class WinnerDialog: public Ui_WinnerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINNERDIALOG_H
