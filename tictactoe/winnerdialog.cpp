#include "winnerdialog.h"
#include "ui_winnerdialog.h"
#include <startwindow.h>
#include <startwindow.h>

WinnerDialog::WinnerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WinnerDialog)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white");

    QPixmap label(":logo/ic_robotPressed.png");
    ui->label->setPixmap(label.scaled(80,80,Qt::KeepAspectRatio));

}

WinnerDialog::~WinnerDialog()
{
    delete ui;
}

void WinnerDialog::on_buttonBox_rejected()
{
    this->close();
}
