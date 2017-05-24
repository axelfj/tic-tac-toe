#include "startwindow.h"
#include "ui_startwindow.h"
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEventLoop>
#include <QTimer>
#include <qlabel_event.h>
#include <QPushButton>
#include <winnerdialog.h>
#include <winnerdialoghuman.h>
#include <QString>
#include <tiedialog.h>
#include <QIcon>
#include <QThread>
#include <QDebug>
using namespace std;
// --------------------------------------------- VENTANA DE INICIO ---------------------------------------------

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    connect(ui->logo, SIGNAL(mousePressed()), this, SLOT(mousePressed()));

    // Crea una ventana con fondo blanco y maximizada
    this->setStyleSheet("background-color: white");
    this->setWindowState(Qt::WindowMaximized);

    // Oculta todos los elementos de la interfaz
    hideAll();

    // Genera la imagen del logo
    QPixmap logo(":logo/logo.png");
    ui->logo->setPixmap(logo.scaled(600,600,Qt::KeepAspectRatio));

    // Inicia el programa mostrando el logo
    logoShow();
}

StartWindow::~StartWindow()
{
    delete ui;
}

// Evento mousePressed, detecta si el mouse fue presionado
// @author kevttob
// 04/05/17
void StartWindow::mousePressed(){

}

// logoShow genera una animación para el logo en la pantalla de inicio
// @author kevttob
// 03/05/17
void StartWindow::logoShow(){

    ui->logo->show();

    labelFadeIn(ui->logo);
    labelFadeOut(ui->logo);

    nameSelectShow();
}

// --------------------------------------------- SELECCIONAR NOMBRE JUGADOR ---------------------------------------------

// nameSelectShow muestra en pantalla la actividad para seleccionar el nombre del jugador
// @author kevttob
// 15/05/17
void StartWindow::nameSelectShow()
{

    // Muestra las piezas que componen la interfaz
    ui->name_title->show();
    ui->name_edit->show();
    ui->name_btn->show();

    // -----------------------

    labelFadeIn(ui->name_title);
    lineEditFadeIn(ui->name_edit);
    buttonFadeIn(ui->name_btn);

    ui->logo->lower();


}

// nameSelectHide oculta la actividad para seleccionar el nombre del jugador
// @author kevttob
// 15/05/17
void StartWindow::nameSelectHide()
{
    labelFadeOut(ui->name_title);
    lineEditFadeOut(ui->name_edit);
    buttonFadeOut(ui->name_btn);
}

// on_name_btn_clicked realiza el evento de click en el botón de name player
// @author kevttob
// 15/05/17
void StartWindow::on_name_btn_clicked()
{
    if(ui->name_edit->text() != ""){
        playerName = ui->name_edit->text();
    } else {
        playerName = "User";
    }

    nameSelectHide();
    selectPlayerShow();
}

// --------------------------------------------- SELECCIONAR PRIMER JUGADOR ---------------------------------------------

// Genera una animacion de todos los elementos que componen la pantalla de seleccion de jugador
// @author kevttob
// 04/05/17
void StartWindow::selectPlayerShow(){

    // Fade in titulo
    ui->select_title->show();
    labelFadeIn(ui->select_title);

    // Fade in Robot
    ui->btn_selectRobot->show();
    buttonFadeIn(ui->btn_selectRobot);

    // Fade In Humano
    ui->btn_selectHuman->show();
    buttonFadeIn(ui->btn_selectHuman);


}

// Genera una animacion de salida para todos los elementos que componen la pantalla de seleccion de jugador
// @author kevttob
// 04/05/17
void StartWindow::selectPlayerHide(){

    // Fade out titulo
    labelFadeOut(ui->select_title);
    //ui->select_title->hide();

    // Fade out Robot
    buttonFadeOut(ui->btn_selectRobot);
   // ui->btn_selectRobot->hide();

    // Fade out Humano
    buttonFadeOut(ui->btn_selectHuman);
    //ui->btn_selectHuman->hide();

}

// -------------------------------------------------------- JUEGO --------------------------------------------------------

// Genera una animacion de todos los elementos que componen la pantalla del gato
// @author kevttob
// 04/05/17
void StartWindow::gameShow(){

//    ui->select_title->hide();
//    ui->btn_selectHuman->hide();
//    ui->btn_selectRobot->hide();

    // Gato
    ui->gato->show();
    QPixmap gato(":logo/gato.png");
    ui->gato->setPixmap(gato.scaled(600,600,Qt::KeepAspectRatio));

    labelFadeIn(ui->gato);

    // Escoge el color de la ficha de p1
    cambioTurno();

    // Score Robot
    ui->scoreRobot->show();
    buttonFadeIn(ui->scoreRobot);

    // Score Human
    ui->scoreHuman->show();
    buttonFadeIn(ui->scoreHuman);


    showMatrix();

    // Los botones requieren 2 clicks para funcionar, se hace un fake click para
    // que funcionen al primer toque
    fakeClick();

    // Esconder el resto de UI porque se pueden accionar widgets en el fonto
    hideUi();

}


// Click en el icono del robot en seleccion p1, inicia el juego con bot como p1
// @author kevttob
// 04/05/17
void StartWindow::on_btn_selectRobot_clicked()
{
    QPixmap pixmap(":logo/ic_robotPressed.png");
    QIcon ButtonIcon(pixmap);
    ui->btn_selectRobot->setIcon(pixmap);
    selectPlayerHide();
    player1 = "r";
    gameShow();
}

// Click en el icono del humano en seleccion p1, inicia el juego con humano como p1
// @author kevttob
// 04/05/17
void StartWindow::on_btn_selectHuman_clicked()
{
    QPixmap pixmap(":logo/ic_humanPressed.png");
    QIcon ButtonIcon(pixmap);
    ui->btn_selectHuman->setIcon(pixmap);
    selectPlayerHide();
    player1 = "h";
    gameShow();
}

// Oculta elementos en la interfaz que no se necesitan para el juego
// @author kevttob
// 05/05/2017
void StartWindow::hideUi()
{

    for(int i = 0; i < 500; i++)

    // Logo
    ui->logo->hide();

    // Name
    ui->name_btn->hide();
    ui->name_edit->hide();
    ui->name_title->hide();

    // Select Player 1
    ui->select_title->hide();
    ui->btn_selectHuman->hide();
    ui->btn_selectRobot->hide();

}
// --------------------------------------------- INTERFAZ DEL JUEGO ---------------------------------------------

// Maneja el cambio de color en los iconos que señalan el turno actual
// @author kevttob
// 04/05/17
void StartWindow::cambioTurno(){

    // Si el Jugador 1 es robot
    if(player1 == "r"){

        // Y es turno de robot
        if(turn % 2 != 0){

            // Robot es color azul
            QPixmap pixmap(":logo/ic_robotPressed.png");
            QIcon ButtonIcon(pixmap);
            ui->scoreRobot->setIcon(pixmap);

            // Humano es de color gris
            QPixmap pixmap2(":logo/ic_human.png");
            QIcon ButtonIcon2(pixmap2);
            ui->scoreHuman->setIcon(pixmap2);

            // Si es turno del humano
        } else {

            // Humano va de color gris oscuro
            QPixmap pixmap(":logo/ic_humanGame.png");
            QIcon ButtonIcon(pixmap);
            ui->scoreHuman->setIcon(pixmap);

            // Y robot va de color gris
            QPixmap pixmap2(":logo/ic_robot.png");
            QIcon ButtonIcon2(pixmap2);
            ui->scoreRobot->setIcon(pixmap2);
        }

        // Si el Jugador 1 es el humano
    } else if(player1 == "h"){

        // Y es turno del Jugador 1
        if(turn % 2 != 0){

            // El humano es azul
            QPixmap pixmap(":logo/ic_humanPressed.png");
            QIcon ButtonIcon(pixmap);
            ui->scoreHuman->setIcon(pixmap);

            // Y el robot es gris
            QPixmap pixmap2(":logo/ic_robot.png");
            QIcon ButtonIcon2(pixmap2);
            ui->scoreRobot->setIcon(pixmap2);

            // Si es turno del robot
        } else {

            // El robot es color negro
            QPixmap pixmap(":logo/ic_robotGame.png");
            QIcon ButtonIcon(pixmap);
            ui->scoreRobot->setIcon(pixmap);

            // Y el humano color gris
            QPixmap pixmap2(":logo/ic_human.png");
            QIcon ButtonIcon2(pixmap2);
            ui->scoreHuman->setIcon(pixmap2);
        }
    }
}

// Coloca una ficha según el turno
// @author kevttob
// 05/05/2017
void StartWindow::colocarFicha(QPushButton *mButton){

    // Si el turno es de p1
    if(turn % 2 != 0){
        QPixmap pixmap(":logo/gato_x.png");
        QIcon ButtonIcon(pixmap);
        mButton->setIcon(pixmap);
        mButton->setText("1");

    }
    // Si el turno es de p2
    else {
        QPixmap pixmap(":logo/gato_o.png");
        QIcon ButtonIcon(pixmap);
        mButton->setIcon(pixmap);
        mButton->setText("2");

    }
}


// -------------------------- VALIDACIONES DE GANE --------------------------

// Valida si el jugador 1 ganó con el movimiento que se acaba de realizar
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::checkWinner(QPushButton *mButton)
{

    if(mButton == ui->m1){
        if(checkHor(ui->m1) || checkVert(ui->m1) || checkDiag(ui->m1)){
            setWinner(ui->m1->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m2){
        if(checkHor(ui->m2) || checkVert(ui->m2)){
            setWinner(ui->m2->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m3){
        if(checkHor(ui->m3) || checkVert(ui->m3) || checkDiag(ui->m3)){
            setWinner(ui->m3->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m4){
        if(checkHor(ui->m4) || checkVert(ui->m4)){
            setWinner(ui->m4->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m5){
        if(checkHor(ui->m5) || checkVert(ui->m5) || checkDiag(ui->m5)){
            setWinner(ui->m5->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m6){
        if(checkHor(ui->m6) || checkVert(ui->m6)){
            setWinner(ui->m6->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m7){
        if(checkHor(ui->m7) || checkVert(ui->m7) || checkDiag(ui->m7)){
            setWinner(ui->m7->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m8){
        if(checkHor(ui->m8) || checkVert(ui->m8)){
            setWinner(ui->m8->text());
        } else if(turn == 9){
            setWinner("t");
        }

    } else if(mButton == ui->m9){
        if(checkHor(ui->m9) || checkVert(ui->m9) || checkDiag(ui->m9)){
            setWinner(ui->m9->text());
        } else if(turn == 9){
            setWinner("t");
        }
    }
}

// retorna true si hay un gane en horizontal
// @author kevttob
// 23/05/17
bool StartWindow::checkHor(QPushButton *mButton)
{
    // Primera fila
    if(mButton == ui->m1 || mButton == ui->m2 || mButton == ui->m3){

        return ui->m1->text() == ui->m2->text() && ui->m1->text() == ui->m3->text();

        // Segunda fila
    } else if(mButton == ui->m4 || mButton == ui->m5 || mButton == ui->m6){

        return ui->m4->text() == ui->m5->text() && ui->m4->text() == ui->m6->text();

        // Tercera fila
    } else if(mButton == ui->m7 || mButton == ui->m8 || mButton == ui->m9){

        return ui->m7->text() == ui->m8->text() && ui->m7->text() == ui->m9->text();

    }

}

// retorna true si hay un gane en vertical
// @author kevttob
// 23/05/17
bool StartWindow::checkVert(QPushButton *mButton)
{

    // Primera columna
    if(mButton == ui->m1 || mButton == ui->m4 || mButton == ui->m7){

        return ui->m1->text() == ui->m4->text() && ui->m1->text() == ui->m7->text();

        // Segunda columna
    } else if(mButton == ui->m2 || mButton == ui->m5 || mButton == ui->m8){

        return ui->m2->text() == ui->m5->text() && ui->m2->text() == ui->m8->text();

        // Tercera columna
    } else if(mButton == ui->m3 || mButton == ui->m6 || mButton == ui->m9){

        return ui->m3->text() == ui->m6->text() && ui->m3->text() == ui->m9->text();
    }

}

// retorna true si hay un gane en diagonal
// @author kevttob
// 23/05/17
bool StartWindow::checkDiag(QPushButton *mButton)
{
    // Diagonal 1 - 5 - 9
    if(mButton == ui->m1 || mButton == ui->m5 || mButton == ui->m9){

        return ui->m1->text() == ui->m5->text() && ui->m1->text() == ui->m9->text();

        // Diagonal 3 - 5 - 7
    } else if(mButton == ui->m3 || mButton == ui->m5 || mButton == ui->m7){

        return ui->m3->text() == ui->m5->text() && ui->m3->text() == ui->m7->text();

    }
}

// --------------------------------------------- EVENTOS EN MATRIZ ---------------------------------------------

// Evento de click o touch en el espacio 1 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m1_clicked()
{    

    makeAction(ui->m1);

}

// Evento de click o touch en el espacio 2 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m2_clicked()
{

    makeAction(ui->m2);

}

// Evento de click o touch en el espacio 3 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m3_clicked()
{
    makeAction(ui->m3);

}

// Evento de click o touch en el espacio 4 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m4_clicked()
{
    makeAction(ui->m4);

}

// Evento de click o touch en el espacio 5 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m5_clicked()
{
    makeAction(ui->m5);

}

// Evento de click o touch en el espacio 6 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m6_clicked()
{
    makeAction(ui->m6);

}

// Evento de click o touch en el espacio 7 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m7_clicked()
{
    makeAction(ui->m7);

}

// Evento de click o touch en el espacio 8 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m8_clicked()
{
    makeAction(ui->m8);

}

// Evento de click o touch en el espacio 9 en la matriz.
// Coloca la ficha, valida si hay gane, cambia el turno y valida que el espacio no se pueda sobreescribir
// @author kevttob
// 05/05/17 - M: 23/05/17
void StartWindow::on_m9_clicked()
{
    makeAction(ui->m9);

}

// Produce un click falso (usado en botones donde los eventos se activan con doble click)
// @author kevttob
// 06/05/17
void StartWindow::fakeClick()
{
    ui->m1->click();
    ui->m2->click();
    ui->m3->click();
    ui->m4->click();
    ui->m5->click();
    ui->m6->click();
    ui->m7->click();
    ui->m8->click();
    ui->m9->click();
}

// -------------------------------------------------------- WINNER --------------------------------------------------------

void StartWindow::winnerShow()
{
    // Se debe mantener, se pueden accionar clicks en fondo
    hideAll();

    ui->winner_icon->show();
    ui->winner_title->show();
    ui->winner_bg->show();
    ui->winner_btn->show();

    labelFadeIn(ui->winner_title);
    labelFadeIn(ui->winner_bg);
    buttonFadeIn(ui->winner_icon);
    buttonFadeIn(ui->winner_btn);
}

void StartWindow::setWinner(QString w)
{

    if(player1 == "r"){

        if(w == "1"){
            QPixmap pixmap(":logo/winner_robot.png");
            QIcon ButtonIcon(pixmap);
            ui->winner_icon->setIcon(pixmap);

            ui->winner_title->setText("The bot wins!");

        } else if(w == "2"){

            QPixmap pixmap(":logo/winner_human.png");
            QIcon ButtonIcon(pixmap);
            ui->winner_icon->setIcon(pixmap);

            ui->winner_title->setText(playerName + " wins the game!");

    } else if(player1 == "h"){

        if(w == "1"){

            QPixmap pixmap(":logo/winner_human.png");
            QIcon ButtonIcon(pixmap);
            ui->winner_icon->setIcon(pixmap);

            ui->winner_title->setText(playerName + " wins the game!");

        } else if(w == "2"){

            QPixmap pixmap(":logo/winner_robot.png");
            QIcon ButtonIcon(pixmap);
            ui->winner_icon->setIcon(pixmap);

            ui->winner_title->setText("The bot wins!");

        }

    } else if(w == "t"){
        QPixmap pixmap(":logo/winner_human.png");
        QIcon ButtonIcon(pixmap);
        ui->winner_icon->setIcon(pixmap);

        ui->winner_title->setText("It's a tie, well played " + playerName + "!");
    }


    winnerShow();

    }
}

// Crea el efecto Fade In en un QLabel
// @author kevttob
// 15/05/17
void StartWindow::labelFadeIn(QLabel *mLabel)
{

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    mLabel->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}

// Crea el efecto Fade Out en un QLabel
// @author kevttob
// 15/05/17
void StartWindow::labelFadeOut(QLabel *mLabel)
{

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    mLabel->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");

    if(mLabel == ui->logo){
        animation->setDuration(10000);
    }
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

void StartWindow::lineEditFadeIn(QLineEdit *mLine)
{
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    mLine->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}

void StartWindow::lineEditFadeOut(QLineEdit *mLine)
{
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    mLine->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);
}

// Produce un efecto fade In en el botón que recibe como parametro
// @author kevttob
// 06/05/17
void StartWindow::buttonFadeIn(QPushButton *mButton)
{

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    mButton->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1000);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}

// Produce un efecto fade out en el botón que recibe como parametro
// @author kevttob
// 06/05/17
void StartWindow::buttonFadeOut(QPushButton *mButton)
{

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    mButton->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}

// Oculta todos los elementos de la interfaz
// @author kevttob
// 15/05/17
void StartWindow::hideAll()
{

    // Splash
    ui->logo->hide();

    // Name your Player
    ui->name_title->hide();
    ui->name_edit->hide();
    ui->name_btn->hide();

    // Select first Player
    ui->select_title->hide();
    ui->btn_selectRobot->hide();
    ui->btn_selectHuman->hide();

    // Game
    ui->gato->hide();
    ui->scoreHuman->hide();
    ui->scoreRobot->hide();
    hideMatrix();

    // Winner
    ui->winner_icon->hide();
    ui->winner_title->hide();
    ui->winner_bg->hide();
    ui->winner_btn->hide();
}

// Oculta los botones de la matriz de gato
// @author kevttob
// 15/05/17
void StartWindow::hideMatrix()
{
    ui->m1->hide();
    ui->m2->hide();
    ui->m3->hide();
    ui->m4->hide();
    ui->m5->hide();
    ui->m6->hide();
    ui->m7->hide();
    ui->m8->hide();
    ui->m9->hide();
}

// Muestra los botones de la matriz de gato
// @author kevttob
// 15/05/17
void StartWindow::showMatrix()
{
    ui->m1->show();
    ui->m2->show();
    ui->m3->show();
    ui->m4->show();
    ui->m5->show();
    ui->m6->show();
    ui->m7->show();
    ui->m8->show();
    ui->m9->show();
}

// Cierra el programa al tocar el boton
// @author kevttob
// 18/05/17
void StartWindow::on_winner_btn_clicked()
{
    this->close();
}

// Genera una accion en click dentro de la matriz recibiendo el boton que se ha accionado
// @author kevttob
// 23/05/17
void StartWindow::makeAction(QPushButton *mButton)
{
    if(mButton->isChecked()){
        colocarFicha(mButton);
        checkWinner(mButton);
        mButton->setChecked(false);
        mButton->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

// Cambia la imagen del boton de close al presionarlo
// @author kevttob
// 23/05/17
void StartWindow::on_winner_btn_pressed()
{
    QPixmap pixmap(":logo/ic_close_pressed.png");
    QIcon ButtonIcon(pixmap);
    ui->winner_btn->setIcon(pixmap);
}

// Cambia la imagen del boton de robot al presionarlo
// @author kevttob
// 23/05/17
void StartWindow::on_btn_selectRobot_pressed()
{
    QPixmap pixmap(":logo/ic_robotPressed.png");
    QIcon ButtonIcon(pixmap);
    ui->btn_selectRobot->setIcon(pixmap);
}

// Cambia la imagen del boton de humano al presionarlo
// @author kevttob
// 23/05/17
void StartWindow::on_btn_selectHuman_pressed()
{
    QPixmap pixmap(":logo/ic_humanPressed.png");
    QIcon ButtonIcon(pixmap);
    ui->btn_selectHuman->setIcon(pixmap);
}

char* StartWindow::uiToMatrix()
{
    // m1 to matrix
    if (ui->m1->isChecked() == true && ui->m1->text() == ""){matrix[1] = '-';} // add to the matrix '-' if m1 is empty
    if (ui->m1->isChecked() == true && ui->m1->text() == 1){matrix[1] = 'x';} // add to the matrix 'x' if m1 is X
    if (ui->m1->isChecked() == true && ui->m1->text() == 2){matrix[1] = 'o';} // add to the matrix 'o' if m1 is O

    // m2 to matrix
    if (ui->m2->isChecked() == true && ui->m2->text() == ""){matrix[2] = '-';} // add to the matrix '-' if m2 is empty
    if (ui->m2->isChecked() == true && ui->m2->text() == 1){matrix[2] = 'x';} // add to the matrix 'x' if m2 is X
    if (ui->m2->isChecked() == true && ui->m2->text() == 2){matrix[2] = 'o';} // add to the matrix 'o' if m2 is O

    // m3 to matrix
    if (ui->m3->isChecked() == true && ui->m3->text() == ""){matrix[3] = '-';} // add to the matrix '-' if m3 is empty
    if (ui->m3->isChecked() == true && ui->m3->text() == 1){matrix[3] = 'x';} // add to the matrix 'x' if m3 is X
    if (ui->m3->isChecked() == true && ui->m3->text() == 2){matrix[3] = 'o';} // add to the matrix 'o' if m3 is O

    // m4 to matrix
    if (ui->m4->isChecked() == true && ui->m4->text() == ""){matrix[4] = '-';} // add to the matrix '-' if m4 is empty
    if (ui->m4->isChecked() == true && ui->m4->text() == 1){matrix[4] = 'x';} // add to the matrix 'x' if m4 is X
    if (ui->m4->isChecked() == true && ui->m4->text() == 2){matrix[4] = 'o';} // add to the matrix 'o' if m4 is O

    // m5 to matrix
    if (ui->m5->isChecked() == true && ui->m5->text() == ""){matrix[5] = '-';} // add to the matrix '-' if m5 is empty
    if (ui->m5->isChecked() == true && ui->m5->text() == 1){matrix[5] = 'x';} // add to the matrix 'x' if m5 is X
    if (ui->m5->isChecked() == true && ui->m5->text() == 2){matrix[5] = 'o';} // add to the matrix 'o' if m5 is O

    // m6 to matrix
    if (ui->m6->isChecked() == true && ui->m6->text() == ""){matrix[6] = '-';} // add to the matrix '-' if m6 is empty
    if (ui->m6->isChecked() == true && ui->m6->text() == 1){matrix[6] = 'x';} // add to the matrix 'x' if m6 is X
    if (ui->m6->isChecked() == true && ui->m6->text() == 2){matrix[6] = 'o';} // add to the matrix 'o' if m6 is O

    // m7 to matrix
    if (ui->m7->isChecked() == true && ui->m7->text() == ""){matrix[7] = '-';} // add to the matrix '-' if m7 is empty
    if (ui->m7->isChecked() == true && ui->m7->text() == 1){matrix[7] = 'x';} // add to the matrix 'x' if m7 is X
    if (ui->m7->isChecked() == true && ui->m7->text() == 2){matrix[7] = 'o';} // add to the matrix 'o' if m7 is O

    // m8 to matrix
    if (ui->m8->isChecked() == true && ui->m8->text() == ""){matrix[8] = '-';} // add to the matrix '-' if m8 is empty
    if (ui->m8->isChecked() == true && ui->m8->text() == 1){matrix[8] = 'x';} // add to the matrix 'x' if m8 is X
    if (ui->m8->isChecked() == true && ui->m8->text() == 2){matrix[8] = 'o';} // add to the matrix 'o' if m8 is O

    // m9 to matrix
    if (ui->m9->isChecked() == true && ui->m9->text() == ""){matrix[9] = '-';} // add to the matrix '-' if m8 is empty
    if (ui->m9->isChecked() == true && ui->m9->text() == 1){matrix[9] = 'x';} // add to the matrix 'x' if m8 is X
    if (ui->m9->isChecked() == true && ui->m9->text() == 2){matrix[9] = 'o';} // add to the matrix 'o' if m8 is O

    return matrix;
}

void StartWindow::bestPosition()
{
    char* theMatrix = uiToMatrix();
    int thePosition = 1;

    thePosition = minMax(turn,theMatrix,0);
    if (thePosition == 1){colocarFicha(ui->m1);}
    if (thePosition == 2){colocarFicha(ui->m2);}
    if (thePosition == 3){colocarFicha(ui->m3);}
    if (thePosition == 4){colocarFicha(ui->m4);}
    if (thePosition == 5){colocarFicha(ui->m5);}
    if (thePosition == 6){colocarFicha(ui->m6);}
    if (thePosition == 7){colocarFicha(ui->m7);}
    if (thePosition == 8){colocarFicha(ui->m8);}
    if (thePosition == 9){colocarFicha(ui->m9);}
}

int StartWindow::minMax(int turn, char* matrix, int depth)
{
    max = 1;
    min = -1;
    char* theMatrix = matrix;

    for(int i = 1; i <= 9; i++)
    {
        if (turn == 1)
        {
            matrix[i] = 'x'; // it fills the space with the x option and go to the best option recursively
            int bestChoice = minMax(2,theMatrix,depth+1);

            matrix[i] = '-';
            if(bestChoice>max)
            {
                max = bestChoice;
                if (depth == 0)
                {
                    posMax = i;
                }
            }
        }
        if (turn == 2)
        {
            matrix[i] = 'o'; // it fills the space with the o option and goes to the best option recursively
            int bestChoice = minMax(1,theMatrix,depth+1);

            matrix[i] = '-';
            if(bestChoice<min)
            {
                min = bestChoice;
                if (depth == 0)
                {
                    posMin = i;
                }
            }
        }
    }
    if (turn == 1)
    {
        return max;
    }
    else{
        return min;
    }
}
