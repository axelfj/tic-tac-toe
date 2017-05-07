#include "tiedialog.h"
#include "ui_tiedialog.h"

TieDialog::TieDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TieDialog)
{
    ui->setupUi(this);
}

TieDialog::~TieDialog()
{
    delete ui;
}
