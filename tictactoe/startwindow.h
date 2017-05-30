#ifndef STARTWINDOW_H
#define STARTWINDOW_H
#include <QLabel>
#include <QMainWindow>
#include <qlabel_event.h>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
class StartWindow;
}

class StartWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit StartWindow(QWidget *parent = 0);
    ~StartWindow();

    // -- deezfj functions --
    int *uiToMatrix();
    void computerMove();
    int miniMax(int matrix[9], int player);
    int checkWin(const int matrix[9]);
    int IAplay(int matrix[9]);
    int toMatrix(QString play1, int turn);

    // -- Show/Hide Activities --
    void logoShow();

    void nameSelectShow();
    void nameSelectHide();

    void selectPlayerShow();
    void selectPlayerHide();

    void gameShow();

    void winnerShow();
    void setWinner(QString w);

    void cambioTurno();
    void colocarFicha(QPushButton *mButton);
    void hideUi();

    // -- Validaciones de Gane --

    void checkWinner(QPushButton *mButton);
    bool checkHor(QPushButton *mButton);
    bool checkVert(QPushButton *mButton);
    bool checkDiag(QPushButton *mButton);

    void fakeClick();

    void makeAction(QPushButton *mButton);


    // -- Fade In/Out QWidgets --

    void labelFadeIn(QLabel *mLabel);
    void labelFadeOut(QLabel *mLabel);

    void lineEditFadeIn(QLineEdit *mLine);
    void lineEditFadeOut(QLineEdit *mLine);

    void buttonFadeIn(QPushButton *mButton);
    void buttonFadeOut(QPushButton *mButton);

    void hideAll();
    void hideMatrix();
    void showMatrix();

private slots:

    void mousePressed();

    // Name Select
    void on_name_btn_clicked();

    // Player 1 select

    void on_btn_selectRobot_clicked();
    void on_btn_selectHuman_clicked();

    void on_btn_selectHuman_pressed();
    void on_btn_selectRobot_pressed();

    // Matrix slots

    void on_m1_clicked();
    void on_m2_clicked();
    void on_m3_clicked();
    void on_m4_clicked();
    void on_m5_clicked();
    void on_m6_clicked();
    void on_m7_clicked();
    void on_m8_clicked();
    void on_m9_clicked();

    // Close button

    void on_winner_btn_clicked();
    void on_winner_btn_pressed();

private:
    Ui::StartWindow *ui;
    QString player1;
    int turn = 1;
    QString playerName;

};

#endif // STARTWINDOW_H
