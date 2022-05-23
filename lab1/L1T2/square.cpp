#include "square.h"
#include <QPainter>

square::square(){}

square::square(QPainter *qp, int Height)
{ 
    h = Height;
    drawsquare(qp);
}

void square::drawsquare(QPainter *qp)
{
    qp->drawRect(0-h/2,0-h/2,h,h);
}

