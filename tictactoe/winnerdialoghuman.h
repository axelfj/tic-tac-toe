#ifndef WINNERDIALOGHUMAN_H
#define WINNERDIALOGHUMAN_H

#include <QDialog>

namespace Ui {
class WinnerDialogHuman;
}

class WinnerDialogHuman : public QDialog
{
    Q_OBJECT

public:
    explicit WinnerDialogHuman(QWidget *parent = 0);
    ~WinnerDialogHuman();

private:
    Ui::WinnerDialogHuman *ui;
};

#endif // WINNERDIALOGHUMAN_H
