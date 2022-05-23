#include "rzhomba.h"
#include <QPainter>


rzhomba::rzhomba()
{

}

rzhomba::rzhomba(QPainter *qp, double Base, double Angle)
{
    b = Base;
    a = Angle/180*3.1415;
    drawRzhombu(qp);
}

void rzhomba::drawRzhombu(QPainter *qp)
{
    qp->drawLine(-b*sin(a/2.0), 0, 0, -b*cos(a/2.0));
    qp->drawLine(0, -b*cos(a/2.0), b*sin(a/2.0), 0);
    qp->drawLine(b*sin(a/2.0), 0, 0, b*cos(a/2.0));
    qp->drawLine(0, b*cos(a/2.0), -b*sin(a/2.0), 0);
}
