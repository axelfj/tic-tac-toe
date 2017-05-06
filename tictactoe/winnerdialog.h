#ifndef WINNERDIALOG_H
#define WINNERDIALOG_H

#include <QDialog>

namespace Ui {
class WinnerDialog;
}

class WinnerDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerDialog(QWidget *parent = 0);
    ~WinnerDialog();

private slots:
    void on_buttonBox_rejected();

private:
    Ui::WinnerDialog *ui;
};

#endif // WINNERDIALOG_H
