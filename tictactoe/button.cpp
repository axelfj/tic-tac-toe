#include "button.h"

Button::Button(QString UrlOn, QString UrlOff){
    setPixmap(UrlOff);
    setAcceptHoverEvents(true);
    this->UrlOff = UrlOff;
    this->UrlOn = UrlOn;
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *event){
    setPixmap(UrlOff);
    emit clicked();
}

void Button::hoverEnterEvent(QGraphicsSceneHoverEvent *event){
    setPixmap(UrlOn);
}

void Button::hoverLeaveEvent(QGraphicsSceneHoverEvent *event){
    setPixmap(UrlOff);
}
