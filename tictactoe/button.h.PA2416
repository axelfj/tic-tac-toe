#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QPixmap>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "iostream"

using namespace std;

class Button : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:
    Button(QString UrlOn, QString UrlOff); // change the ctor if you want //
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

    // -- New methods --
   void setText(QString text);
    void setIcon(QPixmap pixmap);
    QString getText();

signals:
    void clicked();

private:
    QString UrlOn; // pressed
    QString UrlOff; // not pressed
    QString text;
};

#endif // BUTTON_H
