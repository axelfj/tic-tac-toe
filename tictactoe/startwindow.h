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
    void logoFadeIn();
    void logoFadeOut();
    void selectPlayerFi();
    void selectPlayerFo();
    void gameFi();
    void gameFo();
    void cambioTurno();
    void colocarFicha(QPushButton *mButton);
    void hideUi();
    bool valGanep1(QPushButton *mButton);
    bool valGanep2(QPushButton *mButton);
    void valEmpate(QPushButton *mButton);

    void setButtonsCheckeable();
    void setButtonsChecked();
    void changeButtonIcons();
    void fadeInMatrix();
    void fadeOutMatrix();
    void resetGame();

    void fakeClick();
    void setTextNormal();



    void testState(QPushButton *mButton);
    void nameEditShow();

    // -- FADE IN/OUT WIDGETS --
    void fadeInButton(QPushButton *mButton);
    void fadeOutButton(QPushButton *mButton);

    void labelFadeIn(QLabel *mLabel);
    void labelFadeOut(QLabel *mLabel);

    void lineFadeIn(QLineEdit *mLineEdit);
    void lineFadeOut(QLineEdit *mLineEdit);


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
    int scoreBot = 0;
    int scoreHuman = 0;
};

#endif // STARTWINDOW_H
