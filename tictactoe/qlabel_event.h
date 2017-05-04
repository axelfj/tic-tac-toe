#ifndef QLABEL_EVENT_H
#define QLABEL_EVENT_H

#include <QLabel>
#include <QMouseEvent>
#include <QEvent>

class qLabel_Event : public QLabel
{
    Q_OBJECT
public:
    explicit qLabel_Event(QWidget *parent = 0);

    void mouseEvent(QMouseEvent *ev);
    void mousePressEvent(QMouseEvent *ev);


signals:
    void mousePressed();

public slots:

};

#endif // QLABEL_EVENT_H
