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
    ui->m1->click();

    ui->m2->show();
    ui->m2->click();

    ui->m3->show();
    ui->m3->click();

    ui->m4->show();
    ui->m4->click();

    ui->m5->show();
    ui->m5->click();

    ui->m6->show();
    ui->m6->click();

    ui->m7->show();
    ui->m7->click();

    ui->m8->show();
    ui->m8->click();

    ui->m9->show();
    ui->m9->click();

    hideUi();

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

void StartWindow::colocarFicha(QPushButton *mButton){

    // Si el turno es de p1
    if(turn % 2 != 0){
        QPixmap pixmap(":logo/gato_x.png");
        QIcon ButtonIcon(pixmap);
        mButton->setIcon(pixmap);
        mButton->setText("1");

        // Si el turno es de p2
    } else {
        QPixmap pixmap(":logo/gato_o.png");
        QIcon ButtonIcon(pixmap);
        mButton->setIcon(pixmap);
        mButton->setText("2");

    }
}

void StartWindow::hideUi()
{

 ui->logo->hide();
 ui->select_title->hide();
 ui->btn_selectHuman->hide();
 ui->btn_selectRobot->hide();

}

// ----------------------------------------------------- Validaciones de gane -----------------------------------------------------

void StartWindow::valGanep1(QPushButton *mButton)
{
    WinnerDialog *wDialog = new WinnerDialog();
    wDialog->setModal(true);

    // Se coloca pieza en m1
    if(mButton == ui->m1 && ui->m1->text() == "1"){
        if(ui->m5->text() == "1" && ui->m9->text() == "1"){
            wDialog->show();
        } else if(ui->m2->text() == "1" && ui->m3->text() == "1"){
            wDialog->show();
        } else if(ui->m4->text() == "1" && ui->m7->text() == "1"){
            wDialog->show();
        }

        // Se coloca pieza en m2
    } else if(mButton == ui->m2 && ui->m2->text() == "1"){
        if(ui->m5->text() == "1" && ui->m8->text() == "1"){
            wDialog->show();
        }

        // Se coloca pieza en m3
    } else if(mButton == ui->m3 && ui->m3->text() == "1"){
        if(ui->m6->text() == "1" && ui->m9->text() == "1"){
            wDialog->show();
        } else if(ui->m5->text() == "1" && ui->m7->text() == "1"){
            wDialog->show();
        }

        // Se coloca pieza en m4
    } else if(mButton == ui->m4 && ui->m4->text() == "1"){
        if(ui->m1->text() == "1" && ui->m7->text() == "1"){
            wDialog->show();
        } else if(ui->m5->text() == "1" && ui->m6->text() == "1"){
            wDialog->show();
        }

    // Se coloca pieza en m5
    } else if(mButton == ui->m5 && ui->m5->text() == "1"){

        //Diagonal iniciando en m1
        if(ui->m1->text() == "1" && ui->m9->text() == "1"){
            wDialog->show();

            // Diagonal iniciando en m3
        } else if(ui->m3->text() == "1" && ui->m7->text() == "1") {
            wDialog->show();

            // Linea vertical
        } else if(ui->m2->text() == "1" && ui->m8->text() == "1"){
            wDialog->show();

            // Linea horizontal
        } else if(ui->m4->text() == "1" && ui->m6->text() == "1"){
            wDialog->show();
        }

    // Se coloca pieza en m6
    } else if(mButton == ui->m6){
        if(ui->m3->text() == "1" && ui->m9->text() == "1"){
            wDialog->show();
        } else if(ui->m4->text() == "1" && ui->m5->text() == "1"){
            wDialog->show();
        }

    // Se coloca pieza en m7
    } else if(mButton == ui->m7 && ui->m7->text() == "1"){
        if(ui->m1->text() == "1" && ui->m4->text() == "1"){
            wDialog->show();
        } else if(ui->m3->text() == "1" && ui->m5->text() == "1"){
            wDialog->show();
        } else if(ui->m8->text() == "1" && ui->m9->text() == "1"){
            wDialog->show();
        }

    // Se coloca pieza en m8
    } else if(mButton == ui->m8 && ui->m8->text() == "1"){
        if(ui->m2->text() == "1" && ui->m5->text() == "1"){
            wDialog->show();
        } else if(ui->m7->text() == "1" && ui->m9->text() == "1"){
            wDialog->show();
        }

    // Se coloca pieza en m9
    } else if(mButton == ui->m9 && ui->m9->text() == "1"){
        if(ui->m1->text() == "1" && ui->m5->text() == "1"){
            wDialog->show();
        } else if(ui->m7->text() == "1" && ui->m8->text() == "1"){
            wDialog->show();
        } else if(ui->m3->text() == "1" && ui->m6->text() == "1"){
            wDialog->show();
        }
    }
}

void StartWindow::valGanep2(QPushButton *mButton)
{
    WinnerDialogHuman *wDialogHuman = new WinnerDialogHuman();
    wDialogHuman->setModal(true);

      // Se coloca pieza en m1
      if(mButton == ui->m1 && ui->m1->text() == "2"){
          if(ui->m5->text() == "2" && ui->m9->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m2->text() == "2" && ui->m3->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m4->text() == "2" && ui->m7->text() == "2"){
              wDialogHuman->show();
          }

          // Se coloca pieza en m2
      } else if(mButton == ui->m2 && ui->m2->text() == "2"){
          if(ui->m5->text() == "2" && ui->m8->text() == "2"){
              wDialogHuman->show();
          }

          // Se coloca pieza en m3
      } else if(mButton == ui->m3 && ui->m3->text() == "2"){
          if(ui->m6->text() == "2" && ui->m9->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m5->text() == "2" && ui->m7->text() == "2"){
              wDialogHuman->show();
          }

          // Se coloca pieza en m4
      } else if(mButton == ui->m4 && ui->m4->text() == "2"){
          if(ui->m1->text() == "2" && ui->m7->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m5->text() == "2" && ui->m6->text() == "2"){
              wDialogHuman->show();
          }

      // Se coloca pieza en m5
      } else if(mButton == ui->m5 && ui->m5->text() == "2"){

          //Diagonal iniciando en m1
          if(ui->m1->text() == "2" && ui->m9->text() == "2"){
              wDialogHuman->show();

              // Diagonal iniciando en m3
          } else if(ui->m3->text() == "2" && ui->m7->text() == "2") {
              wDialogHuman->show();

              // Linea vertical
          } else if(ui->m2->text() == "2" && ui->m8->text() == "2"){
              wDialogHuman->show();

              // Linea horizontal
          } else if(ui->m4->text() == "2" && ui->m6->text() == "2"){
              wDialogHuman->show();
          }

      // Se coloca pieza en m6
      } else if(mButton == ui->m6){
          if(ui->m3->text() == "2" && ui->m9->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m4->text() == "2" && ui->m5->text() == "2"){
              wDialogHuman->show();
          }

      // Se coloca pieza en m7
      } else if(mButton == ui->m7 && ui->m7->text() == "2"){
          if(ui->m1->text() == "2" && ui->m4->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m3->text() == "2" && ui->m5->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m8->text() == "2" && ui->m9->text() == "2"){
              wDialogHuman->show();
          }

      // Se coloca pieza en m8
      } else if(mButton == ui->m8 && ui->m8->text() == "2"){
          if(ui->m2->text() == "2" && ui->m5->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m7->text() == "2" && ui->m9->text() == "2"){
              wDialogHuman->show();
          }

      // Se coloca pieza en m9
      } else if(mButton == ui->m9 && ui->m9->text() == "2"){
          if(ui->m1->text() == "2" && ui->m5->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m7->text() == "2" && ui->m8->text() == "2"){
              wDialogHuman->show();
          } else if(ui->m3->text() == "2" && ui->m6->text() == "2"){
              wDialogHuman->show();
          }
      }
}

// ----------------------------------------------------- Clicks en la matriz -----------------------------------------------------

void StartWindow::on_m1_clicked()
{
    if(ui->m1->isChecked()){

        // Coloca la ficha indicada según el turno
        colocarFicha(ui->m1);

        // Revisa que no haya algún ganador
        valGanep1(ui->m1);
        valGanep2(ui->m1);

        // Valida que no se pueda utilizar el campo nuevamente
        ui->m1->setChecked(false);
        ui->m1->setCheckable(false);

        // Cambia de turno
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m2_clicked()
{
    if(ui->m2->isChecked()){
        colocarFicha(ui->m2);

        // Revisa que no haya algún ganador
        valGanep1(ui->m2);
        valGanep2(ui->m2);

        ui->m2->setChecked(false);
        ui->m2->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m3_clicked()
{
    if(ui->m3->isChecked()){
        colocarFicha(ui->m3);

        // Revisa que no haya algún ganador
        valGanep1(ui->m3);
        valGanep2(ui->m3);

        ui->m3->setChecked(false);
        ui->m3->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m4_clicked()
{
    if(ui->m4->isChecked()){
        colocarFicha(ui->m4);

        // Revisa que no haya algún ganador
        valGanep1(ui->m4);
        valGanep2(ui->m4);

        ui->m4->setChecked(false);
        ui->m4->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m5_clicked()
{
    if(ui->m5->isChecked()){
        colocarFicha(ui->m5);

        // Revisa que no haya algún ganador
        valGanep1(ui->m5);
        valGanep2(ui->m5);

        ui->m5->setChecked(false);
        ui->m5->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m6_clicked()
{
    if(ui->m6->isChecked()){
        colocarFicha(ui->m6);

        // Revisa que no haya algún ganador
        valGanep1(ui->m6);
        valGanep2(ui->m6);

        ui->m6->setChecked(false);
        ui->m6->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m7_clicked()
{
    if(ui->m7->isChecked()){
        colocarFicha(ui->m7);

        // Revisa que no haya algún ganador
        valGanep1(ui->m7);
        valGanep2(ui->m7);

        ui->m7->setChecked(false);
        ui->m7->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m8_clicked()
{
    if(ui->m8->isChecked()){
        colocarFicha(ui->m8);

        // Revisa que no haya algún ganador
        valGanep1(ui->m8);
        valGanep2(ui->m8);

        ui->m8->setChecked(false);
        ui->m8->setCheckable(false);
        turn++;
        cambioTurno();
    }
}

void StartWindow::on_m9_clicked()
{
    if(ui->m9->isChecked()){
        colocarFicha(ui->m9);

        // Revisa que no haya algún ganador
        valGanep1(ui->m9);
        valGanep2(ui->m9);

        ui->m9->setChecked(false);
        ui->m9->setCheckable(false);
        turn++;
        cambioTurno();
    }
}
