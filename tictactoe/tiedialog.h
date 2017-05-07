#ifndef TIEDIALOG_H
#define TIEDIALOG_H

#include <QDialog>

namespace Ui {
class TieDialog;
}

class TieDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TieDialog(QWidget *parent = 0);
    ~TieDialog();

private:
    Ui::TieDialog *ui;
};

#endif // TIEDIALOG_H
