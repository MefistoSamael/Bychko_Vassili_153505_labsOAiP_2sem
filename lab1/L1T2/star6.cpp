#include "star6.h"

star6::star6()
{

}

star6::star6(QPainter *qp, double Base)
{
    b = Base;

    drawStar6(qp);
}


void star6::drawStar6(QPainter *qp)
{
    for(int i = 0; i<6; i++)
    {
        qp->drawLine(-b/2, -b*1.71/2, 0, -b*1.71);
        qp->drawLine(0, -b*1.71,b/2, -b*1.71/2);
        qp->rotate(60);
    }
}
