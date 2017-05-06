/********************************************************************************
** Form generated from reading UI file 'winnerdialoghuman.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINNERDIALOGHUMAN_H
#define UI_WINNERDIALOGHUMAN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WinnerDialogHuman
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QLabel *label_2;

    void setupUi(QDialog *WinnerDialogHuman)
    {
        if (WinnerDialogHuman->objectName().isEmpty())
            WinnerDialogHuman->setObjectName(QStringLiteral("WinnerDialogHuman"));
        WinnerDialogHuman->resize(400, 300);
        QFont font;
        font.setFamily(QStringLiteral("MS Serif"));
        WinnerDialogHuman->setFont(font);
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/ic_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        WinnerDialogHuman->setWindowIcon(icon);
        buttonBox = new QDialogButtonBox(WinnerDialogHuman);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Close);
        label = new QLabel(WinnerDialogHuman);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(160, 50, 80, 80));
        label_2 = new QLabel(WinnerDialogHuman);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(40, 130, 320, 80));
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
        QFont font1;
        font1.setFamily(QStringLiteral("Product Sans"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(WinnerDialogHuman);
        QObject::connect(buttonBox, SIGNAL(accepted()), WinnerDialogHuman, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), WinnerDialogHuman, SLOT(reject()));

        QMetaObject::connectSlotsByName(WinnerDialogHuman);
    } // setupUi

    void retranslateUi(QDialog *WinnerDialogHuman)
    {
        WinnerDialogHuman->setWindowTitle(QApplication::translate("WinnerDialogHuman", "Winner!", 0));
        label->setText(QString());
        label_2->setText(QApplication::translate("WinnerDialogHuman", "The human wins!", 0));
    } // retranslateUi

};

namespace Ui {
    class WinnerDialogHuman: public Ui_WinnerDialogHuman {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINNERDIALOGHUMAN_H
