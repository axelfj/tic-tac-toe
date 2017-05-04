#include "qlabel_event.h"

qLabel_Event::qLabel_Event(QWidget *parent) :
    QLabel(parent)
{
}

void qLabel_Event::mousePressEvent(QMouseEvent *ev)
{
    emit mousePressed();
}
