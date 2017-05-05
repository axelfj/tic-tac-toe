#include "startwindow.h"
#include "ui_startwindow.h"
#include <QPixmap>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>
#include <QEventLoop>
#include <QTimer>
#include <qlabel_event.h>

StartWindow::StartWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::StartWindow)
{
    ui->setupUi(this);

    connect(ui->logo, SIGNAL(mousePressed()), this, SLOT(mousePressed()));

    // Crea una ventana con fondo blanco y maximizada
    this->setStyleSheet("background-color: white");
    this->setWindowState(Qt::WindowMaximized);

    ui->select_title->hide();
    ui->btn_selectRobot->hide();
    ui->btn_selectHuman->hide();
    ui->gato->hide();
    ui->scoreHuman->hide();
    ui->scoreRobot->hide();

    ui->m1->hide();
    ui->m2->hide();
    ui->m3->hide();
    ui->m4->hide();
    ui->m5->hide();
    ui->m6->hide();
    ui->m7->hide();
    ui->m8->hide();
    ui->m9->hide();

    // Genera la imagen del logo
    QPixmap logo(":logo/logo.png");
    ui->logo->setPixmap(logo.scaled(600,600,Qt::KeepAspectRatio));

    logoFadeIn();
    //fadeOut();
    // this->clear();

}

StartWindow::~StartWindow()
{
    delete ui;
}

// Evento mousePressed, detecta si el mouse fue presionado
// @author kevttob
// 04/05/17
void StartWindow::mousePressed(){

    if(!mouseWasPressed){
        logoFadeOut();
        selectPlayerFi();
        mouseWasPressed = true;
    }

}

// --------------------------------------------- INICIO METODOS FADE IN Y FADE OUT ---------------------------------------------

// logoFadeIn genera una animación para el logo en la pantalla de inicio
// @author kevttob
// 03/05/17
void StartWindow::logoFadeIn(){

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    ui->logo->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1400);
    animation->setStartValue(0);
    animation->setEndValue(1);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

}

// Inicia el proceso de Fade Out del logo
// @author kevttob
// 04/05/17
void StartWindow::logoFadeOut(){

    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(this);
    ui->logo->setGraphicsEffect(effect);

    QPropertyAnimation *animation = new QPropertyAnimation(effect,"opacity");
    animation->setDuration(1000);
    animation->setStartValue(1);
    animation->setEndValue(0);
    animation->setEasingCurve(QEasingCurve::InBack);
    animation->start(QPropertyAnimation::DeleteWhenStopped);

    ui->logo->lower();

}

// Genera una animacion de todos los elementos que componen la pantalla de seleccion de jugador
// @author kevttob
// 04/05/17
void StartWindow::selectPlayerFi(){

    // Fade in titulo
    ui->select_title->show();
    QGraphicsOpacityEffect *effect0 = new QGraphicsOpacityEffect(this);
    ui->select_title->setGraphicsEffect(effect0);

    QPropertyAnimation *animation0 = new QPropertyAnimation(effect0,"opacity");
    animation0->setDuration(1400);
    animation0->setStartValue(0);
    animation0->setEndValue(1);
    animation0->setEasingCurve(QEasingCurve::InBack);
    animation0->start(QPropertyAnimation::DeleteWhenStopped);

    // Fade in Robot
    ui->btn_selectRobot->show();
    QGraphicsOpacityEffect *effect1 = new QGraphicsOpacityEffect(this);
    ui->btn_selectRobot->setGraphicsEffect(effect1);

    QPropertyAnimation *animation1 = new QPropertyAnimation(effect1,"opacity");
    animation1->setDuration(1400);
    animation1->setStartValue(0);
    animation1->setEndValue(1);
    animation1->setEasingCurve(QEasingCurve::InBack);
    animation1->start(QPropertyAnimation::DeleteWhenStopped);


    // Fade In Humano
    ui->btn_selectHuman->show();
    QGraphicsOpacityEffect *effect2 = new QGraphicsOpacityEffect(this);
    ui->btn_selectHuman->setGraphicsEffect(effect2);

    QPropertyAnimation *animation2 = new QPropertyAnimation(effect2,"opacity");
    animation2->setDuration(1400);
    animation2->setStartValue(0);
    animation2->setEndValue(1);
    animation2->setEasingCurve(QEasingCurve::InBack);
    animation2->start(QPropertyAnimation::DeleteWhenStopped);
}

// Genera una animacion de salida para todos los elementos que componen la pantalla de seleccion de jugador
// @author kevttob
// 04/05/17
void StartWindow::selectPlayerFo(){

    // Fade out titulo
    QGraphicsOpacityEffect *effect0 = new QGraphicsOpacityEffect(this);
    ui->select_title->setGraphicsEffect(effect0);

    QPropertyAnimation *animation0 = new QPropertyAnimation(effect0,"opacity");
    animation0->setDuration(300);
    animation0->setStartValue(1);
    animation0->setEndValue(0);
    animation0->setEasingCurve(QEasingCurve::InBack);
    animation0->start(QPropertyAnimation::DeleteWhenStopped);

    //ui->select_title->hide();

    // Fade out Robot
    QGraphicsOpacityEffect *effect1 = new QGraphicsOpacityEffect(this);
    ui->btn_selectRobot->setGraphicsEffect(effect1);

    QPropertyAnimation *animation1 = new QPropertyAnimation(effect1,"opacity");
    animation1->setDuration(300);
    animation1->setStartValue(1);
    animation1->setEndValue(0);
    animation1->setEasingCurve(QEasingCurve::InBack);
    animation1->start(QPropertyAnimation::DeleteWhenStopped);

   // ui->btn_selectRobot->hide();

    // Fade out Humano
    QGraphicsOpacityEffect *effect2 = new QGraphicsOpacityEffect(this);
    ui->btn_selectHuman->setGraphicsEffect(effect2);

    QPropertyAnimation *animation2 = new QPropertyAnimation(effect2,"opacity");
    animation2->setDuration(300);
    animation2->setStartValue(1);
    animation2->setEndValue(0);
    animation2->setEasingCurve(QEasingCurve::InBack);
    animation2->start(QPropertyAnimation::DeleteWhenStopped);

    //ui->btn_selectHuman->hide();

}

// Genera una animacion de todos los elementos que componen la pantalla del gato
// @author kevttob
// 04/05/17
void StartWindow::gameFi(){

//    ui->select_title->hide();
//    ui->btn_selectHuman->hide();
//    ui->btn_selectRobot->hide();

    // Gato
    ui->gato->show();
    QPixmap gato(":logo/gato.png");
    ui->gato->setPixmap(gato.scaled(600,600,Qt::KeepAspectRatio));

    QGraphicsOpacityEffect *effect_gato = new QGraphicsOpacityEffect(this);
    ui->gato->setGraphicsEffect(effect_gato);

    QPropertyAnimation *animation_gato = new QPropertyAnimation(effect_gato,"opacity");
    animation_gato->setDuration(1400);
    animation_gato->setStartValue(0);
    animation_gato->setEndValue(1);
    animation_gato->setEasingCurve(QEasingCurve::InBack);
    animation_gato->start(QPropertyAnimation::DeleteWhenStopped);

    // Escoge el color de la ficha de p1
    cambioTurno();

    // Score Robot
    ui->scoreRobot->show();
    QGraphicsOpacityEffect *effect_scRobot = new QGraphicsOpacityEffect(this);
    ui->scoreRobot->setGraphicsEffect(effect_scRobot);

    QPropertyAnimation *animation_scRobot = new QPropertyAnimation(effect_scRobot,"opacity");
    animation_scRobot->setDuration(1400);
    animation_scRobot->setStartValue(0);
    animation_scRobot->setEndValue(1);
    animation_scRobot->setEasingCurve(QEasingCurve::InBack);
    animation_scRobot->start(QPropertyAnimation::DeleteWhenStopped);

    // Score Human
    ui->scoreHuman->show();
    QGraphicsOpacityEffect *effect_scHuman = new QGraphicsOpacityEffect(this);
    ui->scoreHuman->setGraphicsEffect(effect_scHuman);

    QPropertyAnimation *animation_scHuman = new QPropertyAnimation(effect_scHuman,"opacity");
    animation_scHuman->setDuration(1400);
    animation_scHuman->setStartValue(0);
    animation_scHuman->setEndValue(1);
    animation_scHuman->setEasingCurve(QEasingCurve::InBack);
    animation_scHuman->start(QPropertyAnimation::DeleteWhenStopped);

    // ----------------------- Botones de Gato --------------------

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

void StartWindow::gameFo(){}

// --------------------------------------------- FINAL METODOS FADE IN Y FADE OUT ---------------------------------------------

// Click en el icono del robot en seleccion p1, inicia el juego con bot como p1
// @author kevttob
// 04/05/17
void StartWindow::on_btn_selectRobot_clicked()
{
    QPixmap pixmap(":logo/ic_robotPressed.png");
    QIcon ButtonIcon(pixmap);
    ui->btn_selectRobot->setIcon(pixmap);
    selectPlayerFo();
    player1 = 'r';
    gameFi();
}

// Click en el icono del humano en seleccion p1, inicia el juego con humano como p1
// @author kevttob
// 04/05/17
void StartWindow::on_btn_selectHuman_clicked()
{
    QPixmap pixmap(":logo/ic_humanPressed.png");
    QIcon ButtonIcon(pixmap);
    ui->btn_selectHuman->setIcon(pixmap);
    selectPlayerFo();
    player1 = 'h';
    gameFi();
}


// Maneja el cambio de color en los iconos que señalan el turno actual
// @author kevttob
// 04/05/17
void StartWindow::cambioTurno(){

    // Si el Jugador 1 es robot
    if(player1 == 'r'){

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
    } else if(player1 == 'h'){

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

void StartWindow::on_m1_clicked()
{

    if(ui->m1->isVisible()){
        if(turn % 2 != 0){
            QPixmap pixmap(":logo/gato_x.png");
            QIcon ButtonIcon(pixmap);
            ui->m1->setIcon(pixmap);
        } else {
            QPixmap pixmap(":logo/gato_o.png");
            QIcon ButtonIcon(pixmap);
            ui->m1->setIcon(pixmap);
        }

        //ui->m1->setEnabled(false);
        turn++;
        cambioTurno();
    }
}
