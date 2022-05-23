#include "canv.h"
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>

Canv::Canv(QObject *parent):QGraphicsScene(parent)
{

}

Canv::~Canv()
{

}

void Canv::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->buttons()==Qt::LeftButton)
    {
        // Отрисовываем линии с использованием предыдущей координаты
           addLine(point.x(),
                   point.y(),
                   e->scenePos().x(),
                   e->scenePos().y(),
                   QPen(Qt::red,10,Qt::SolidLine,Qt::RoundCap));
           // Обновляем данные о предыдущей координате
           point = e->scenePos();    }
    if(e->buttons()==Qt::RightButton)
    {
        // Отрисовываем линии с использованием предыдущей координаты
           addLine(point.x(),
                   point.y(),
                   e->scenePos().x(),
                   e->scenePos().y(),
                   QPen(Qt::white,10,Qt::SolidLine,Qt::RoundCap));
           // Обновляем данные о предыдущей координате
           point = e->scenePos();     }

    point=e->scenePos();
}

void Canv::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->buttons() & Qt::LeftButton)
    {
        addEllipse(e->scenePos().x() - 5,
                       e->scenePos().y() - 5,
                       10,
                       10,
                       QPen(Qt::NoPen),
                       QBrush(Qt::red));
            // Сохраняем координаты точки нажатия
            point = e->scenePos();
    }
    if(e->button() & Qt::RightButton)
    {
        addEllipse(e->scenePos().x() - 5,
                       e->scenePos().y() - 5,
                       10,
                       10,
                       QPen(Qt::NoPen),
                       QBrush(Qt::white));
            // Сохраняем координаты точки нажатия
            point = e->scenePos();
    }

    point=e->scenePos();
}
