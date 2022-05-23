#include "rectangle.h"
#include <QPainter>

rectangle::rectangle(QPainter *qp, double Height, double Base)
{
    figura::h = Height;
    figura::b = Base;

    drawrectangle(qp);
}

void rectangle::drawrectangle(QPainter *qp)
{
    qp->drawRect(-b/2,-h/2, b,h);
}
