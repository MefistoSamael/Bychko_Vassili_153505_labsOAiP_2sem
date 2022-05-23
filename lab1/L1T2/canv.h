#ifndef CANV_H
#define CANV_H

#include <QGraphicsScene>
#include <QObject>
#include <QMouseEvent>

class Canv : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Canv(QObject *parent=0);
    ~Canv();

private:
    QPointF point;

    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
};

#endif // CANV_H
