#include "winnerdialoghuman.h"
#include "ui_winnerdialoghuman.h"

WinnerDialogHuman::WinnerDialogHuman(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerDialogHuman)
{
    ui->setupUi(this);

    this->setStyleSheet("background-color: white");

    QPixmap label(":logo/ic_humanPressed.png");
    ui->label->setPixmap(label.scaled(80,80,Qt::KeepAspectRatio));
}

WinnerDialogHuman::~WinnerDialogHuman()
{
    delete ui;
}
