#ifndef BUTTON_H
#define BUTTON_H

#include <QGraphicsRectItem>
#include <QGraphicsSceneMouseEvent>
#include <QBrush>
#include <QGraphicsTextItem>
#include <QGraphicsPixmapItem>
#include "iostream"

using namespace std;

class Button : public QObject, public QGraphicsPixmapItem{

    Q_OBJECT

public:
    Button(QString UrlOn, QString UrlOff);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void hoverEnterEvent(QGraphicsSceneHoverEvent *event);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *event);

signals:
    void clicked();

private:
    QString UrlOn;
    QString UrlOff;
    int play;
};

#endif // BUTTON_H
