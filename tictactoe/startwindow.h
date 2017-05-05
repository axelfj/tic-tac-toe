#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <qlabel_event.h>
#include <QPushButton>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();
    void logoFadeIn();
    void logoFadeOut();
    void selectPlayerFi();
    void selectPlayerFo();
    void gameFi();
    void gameFo();
    void cambioTurno();
    void colocarFicha(QPushButton m);
    void hideUi();
    bool valGane(int button, int turn);

private slots:
    //void on_commandLinkButton_clicked();
    void mousePressed();

    void on_btn_selectRobot_clicked();
    void on_btn_selectHuman_clicked();

    void on_m1_clicked();

    void on_m2_clicked();

    void on_m3_clicked();

    void on_m4_clicked();

    void on_m5_clicked();

    void on_m6_clicked();

    void on_m7_clicked();

    void on_m8_clicked();

    void on_m9_clicked();

private:
    Ui::StartWindow *ui;
    bool mouseWasPressed = false;
    char player1;
    int turn = 1;
};

#endif // STARTWINDOW_H
