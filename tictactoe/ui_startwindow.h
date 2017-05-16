/********************************************************************************
** Form generated from reading UI file 'startwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTWINDOW_H
#define UI_STARTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include <qlabel_event.h>

QT_BEGIN_NAMESPACE

class Ui_StartWindow
{
public:
    QWidget *centralwidget;
    qLabel_Event *logo;
    QLabel *select_title;
    QPushButton *btn_selectRobot;
    QPushButton *btn_selectHuman;
    qLabel_Event *gato;
    QCommandLinkButton *scoreRobot;
    QCommandLinkButton *scoreHuman;
    QPushButton *m2;
    QPushButton *m3;
    QPushButton *m5;
    QPushButton *m6;
    QPushButton *m4;
    QPushButton *m7;
    QPushButton *m9;
    QPushButton *m8;
    QPushButton *m1;
    QLabel *name_title;
    QLineEdit *name_edit;
    QPushButton *name_icon;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *StartWindow)
    {
        if (StartWindow->objectName().isEmpty())
            StartWindow->setObjectName(QStringLiteral("StartWindow"));
        StartWindow->resize(1200, 700);
        StartWindow->setMinimumSize(QSize(1200, 700));
        StartWindow->setMaximumSize(QSize(1200, 700));
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo/ic_logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        StartWindow->setWindowIcon(icon);
        centralwidget = new QWidget(StartWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        logo = new qLabel_Event(centralwidget);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setEnabled(true);
        logo->setGeometry(QRect(190, -40, 800, 800));
        logo->setMouseTracking(true);
        logo->setFrameShape(QFrame::NoFrame);
        logo->setAlignment(Qt::AlignCenter);
        select_title = new QLabel(centralwidget);
        select_title->setObjectName(QStringLiteral("select_title"));
        select_title->setEnabled(true);
        select_title->setGeometry(QRect(375, 230, 431, 51));
        QPalette palette;
        QBrush brush(QColor(0, 176, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        QBrush brush1(QColor(120, 120, 120, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        select_title->setPalette(palette);
        QFont font;
        font.setFamily(QStringLiteral("Product Sans"));
        font.setPointSize(20);
        select_title->setFont(font);
        select_title->setFrameShape(QFrame::NoFrame);
        select_title->setAlignment(Qt::AlignCenter);
        btn_selectRobot = new QPushButton(centralwidget);
        btn_selectRobot->setObjectName(QStringLiteral("btn_selectRobot"));
        btn_selectRobot->setGeometry(QRect(410, 310, 120, 90));
        QPalette palette1;
        QBrush brush2(QColor(255, 255, 255, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette1.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        btn_selectRobot->setPalette(palette1);
        btn_selectRobot->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/logo/ic_robot.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_selectRobot->setIcon(icon1);
        btn_selectRobot->setIconSize(QSize(80, 80));
        btn_selectRobot->setAutoDefault(true);
        btn_selectRobot->setDefault(true);
        btn_selectRobot->setFlat(true);
        btn_selectHuman = new QPushButton(centralwidget);
        btn_selectHuman->setObjectName(QStringLiteral("btn_selectHuman"));
        btn_selectHuman->setGeometry(QRect(660, 310, 120, 90));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette2.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette2.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        btn_selectHuman->setPalette(palette2);
        btn_selectHuman->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/logo/ic_human.png"), QSize(), QIcon::Normal, QIcon::Off);
        btn_selectHuman->setIcon(icon2);
        btn_selectHuman->setIconSize(QSize(80, 80));
        btn_selectHuman->setAutoDefault(true);
        btn_selectHuman->setDefault(true);
        btn_selectHuman->setFlat(true);
        gato = new qLabel_Event(centralwidget);
        gato->setObjectName(QStringLiteral("gato"));
        gato->setEnabled(true);
        gato->setGeometry(QRect(200, -60, 800, 800));
        gato->setMouseTracking(true);
        gato->setFrameShape(QFrame::NoFrame);
        gato->setAlignment(Qt::AlignCenter);
        scoreRobot = new QCommandLinkButton(centralwidget);
        scoreRobot->setObjectName(QStringLiteral("scoreRobot"));
        scoreRobot->setGeometry(QRect(40, 560, 90, 90));
        scoreRobot->setMinimumSize(QSize(0, 90));
        QPalette palette3;
        QBrush brush3(QColor(66, 66, 66, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        scoreRobot->setPalette(palette3);
        QFont font1;
        font1.setFamily(QStringLiteral("Segoe UI"));
        font1.setPointSize(18);
        scoreRobot->setFont(font1);
        scoreRobot->setStyleSheet(QStringLiteral("border: none;"));
        scoreRobot->setIcon(icon1);
        scoreRobot->setIconSize(QSize(80, 80));
        scoreHuman = new QCommandLinkButton(centralwidget);
        scoreHuman->setObjectName(QStringLiteral("scoreHuman"));
        scoreHuman->setGeometry(QRect(1060, 550, 90, 90));
        scoreHuman->setMinimumSize(QSize(0, 90));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush3);
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        scoreHuman->setPalette(palette4);
        scoreHuman->setFont(font1);
        scoreHuman->setStyleSheet(QStringLiteral("border: none;"));
        scoreHuman->setIcon(icon2);
        scoreHuman->setIconSize(QSize(80, 80));
        m2 = new QPushButton(centralwidget);
        m2->setObjectName(QStringLiteral("m2"));
        m2->setGeometry(QRect(520, 70, 160, 160));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m2->setPalette(palette5);
        m2->setStyleSheet(QStringLiteral("border: none;"));
        m2->setIconSize(QSize(100, 100));
        m2->setCheckable(true);
        m2->setChecked(true);
        m2->setDefault(true);
        m2->setFlat(true);
        m3 = new QPushButton(centralwidget);
        m3->setObjectName(QStringLiteral("m3"));
        m3->setGeometry(QRect(710, 70, 160, 160));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m3->setPalette(palette6);
        m3->setStyleSheet(QStringLiteral("border: none;"));
        m3->setIconSize(QSize(100, 100));
        m3->setCheckable(true);
        m3->setChecked(true);
        m3->setDefault(true);
        m3->setFlat(true);
        m5 = new QPushButton(centralwidget);
        m5->setObjectName(QStringLiteral("m5"));
        m5->setGeometry(QRect(520, 260, 160, 160));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m5->setPalette(palette7);
        m5->setStyleSheet(QStringLiteral("border: none;"));
        m5->setIconSize(QSize(100, 100));
        m5->setCheckable(true);
        m5->setChecked(true);
        m5->setDefault(true);
        m5->setFlat(true);
        m6 = new QPushButton(centralwidget);
        m6->setObjectName(QStringLiteral("m6"));
        m6->setGeometry(QRect(710, 260, 160, 160));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m6->setPalette(palette8);
        m6->setStyleSheet(QStringLiteral("border: none;"));
        m6->setIconSize(QSize(100, 100));
        m6->setCheckable(true);
        m6->setChecked(true);
        m6->setDefault(true);
        m6->setFlat(true);
        m4 = new QPushButton(centralwidget);
        m4->setObjectName(QStringLiteral("m4"));
        m4->setGeometry(QRect(330, 260, 160, 160));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m4->setPalette(palette9);
        m4->setStyleSheet(QStringLiteral("border: none;"));
        m4->setIconSize(QSize(100, 100));
        m4->setCheckable(true);
        m4->setChecked(true);
        m4->setDefault(true);
        m4->setFlat(true);
        m7 = new QPushButton(centralwidget);
        m7->setObjectName(QStringLiteral("m7"));
        m7->setGeometry(QRect(330, 450, 160, 160));
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m7->setPalette(palette10);
        m7->setStyleSheet(QStringLiteral("border: none;"));
        m7->setIconSize(QSize(100, 100));
        m7->setCheckable(true);
        m7->setChecked(true);
        m7->setDefault(true);
        m7->setFlat(true);
        m9 = new QPushButton(centralwidget);
        m9->setObjectName(QStringLiteral("m9"));
        m9->setGeometry(QRect(710, 450, 160, 160));
        QPalette palette11;
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m9->setPalette(palette11);
        m9->setStyleSheet(QStringLiteral("border: none;"));
        m9->setIconSize(QSize(100, 100));
        m9->setCheckable(true);
        m9->setChecked(true);
        m9->setDefault(true);
        m9->setFlat(true);
        m8 = new QPushButton(centralwidget);
        m8->setObjectName(QStringLiteral("m8"));
        m8->setGeometry(QRect(520, 450, 160, 160));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m8->setPalette(palette12);
        m8->setStyleSheet(QStringLiteral("border: none;"));
        m8->setIconSize(QSize(100, 100));
        m8->setCheckable(true);
        m8->setChecked(true);
        m8->setDefault(true);
        m8->setFlat(true);
        m1 = new QPushButton(centralwidget);
        m1->setObjectName(QStringLiteral("m1"));
        m1->setGeometry(QRect(330, 70, 160, 160));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        m1->setPalette(palette13);
        m1->setStyleSheet(QStringLiteral("border: none;"));
        m1->setIconSize(QSize(100, 100));
        m1->setCheckable(true);
        m1->setChecked(true);
        m1->setDefault(true);
        m1->setFlat(true);
        name_title = new QLabel(centralwidget);
        name_title->setObjectName(QStringLiteral("name_title"));
        name_title->setEnabled(true);
        name_title->setGeometry(QRect(375, 230, 431, 51));
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        name_title->setPalette(palette14);
        name_title->setFont(font);
        name_title->setFrameShape(QFrame::NoFrame);
        name_title->setAlignment(Qt::AlignCenter);
        name_edit = new QLineEdit(centralwidget);
        name_edit->setObjectName(QStringLiteral("name_edit"));
        name_edit->setGeometry(QRect(460, 320, 261, 51));
        QPalette palette15;
        QBrush brush4(QColor(33, 33, 33, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush4);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        name_edit->setPalette(palette15);
        name_edit->setFont(font);
        name_edit->setMaxLength(20);
        name_edit->setFrame(false);
        name_edit->setAlignment(Qt::AlignCenter);
        name_icon = new QPushButton(centralwidget);
        name_icon->setObjectName(QStringLiteral("name_icon"));
        name_icon->setEnabled(false);
        name_icon->setGeometry(QRect(530, 380, 120, 90));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush2);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush2);
        palette16.setBrush(QPalette::Active, QPalette::ToolTipText, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush2);
        palette16.setBrush(QPalette::Inactive, QPalette::ToolTipText, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush2);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::ToolTipText, brush2);
        name_icon->setPalette(palette16);
        name_icon->setStyleSheet(QStringLiteral("border: none;"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/logo/ic_start_pressed.png"), QSize(), QIcon::Normal, QIcon::Off);
        name_icon->setIcon(icon3);
        name_icon->setIconSize(QSize(80, 80));
        name_icon->setAutoDefault(true);
        name_icon->setDefault(true);
        name_icon->setFlat(true);
        StartWindow->setCentralWidget(centralwidget);
        gato->raise();
        m6->raise();
        m4->raise();
        m5->raise();
        m3->raise();
        btn_selectRobot->raise();
        m9->raise();
        m8->raise();
        m2->raise();
        m7->raise();
        btn_selectHuman->raise();
        scoreRobot->raise();
        scoreHuman->raise();
        select_title->raise();
        m1->raise();
        name_title->raise();
        name_edit->raise();
        name_icon->raise();
        logo->raise();
        menubar = new QMenuBar(StartWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 21));
        StartWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(StartWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        StartWindow->setStatusBar(statusbar);

        retranslateUi(StartWindow);
        QObject::connect(logo, SIGNAL(linkActivated(QString)), StartWindow, SLOT(hide()));

        QMetaObject::connectSlotsByName(StartWindow);
    } // setupUi

    void retranslateUi(QMainWindow *StartWindow)
    {
        StartWindow->setWindowTitle(QApplication::translate("StartWindow", "Tic Tac Toe", 0));
        logo->setText(QString());
        select_title->setText(QApplication::translate("StartWindow", "Select the first Player!", 0));
        btn_selectRobot->setText(QString());
        btn_selectHuman->setText(QString());
        gato->setText(QString());
        scoreRobot->setText(QApplication::translate("StartWindow", "    0", 0));
        scoreHuman->setText(QApplication::translate("StartWindow", "    0", 0));
        m2->setText(QString());
        m3->setText(QString());
        m5->setText(QString());
        m6->setText(QString());
        m4->setText(QString());
        m7->setText(QString());
        m9->setText(QString());
        m8->setText(QString());
        m1->setText(QString());
        name_title->setText(QApplication::translate("StartWindow", "Name your Player!", 0));
        name_edit->setPlaceholderText(QApplication::translate("StartWindow", "Dennis Aguilar", 0));
        name_icon->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StartWindow: public Ui_StartWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTWINDOW_H
