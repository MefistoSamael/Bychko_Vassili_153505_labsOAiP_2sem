#include "hexagon.h"
#include <QPainter>

hexagon::hexagon()
{

}

hexagon::hexagon(QPainter *qp, double Base)
{
    b = Base;

    drawHex(qp);
}

void hexagon::drawHex(QPainter *qp)
{
    for(int i = 0; i<=360; i+=60)
    {
        qp->drawLine(-b/2, b*sin(60*3.1415/180), b/2,b*sin(60*3.1415/180));
        qp->rotate(60);
    }
}
