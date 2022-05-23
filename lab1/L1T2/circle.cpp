#include "circle.h"
#include <QPainter>

circle::circle(){

}

circle::circle(QPainter *qp, double Height){

    h=Height;
    drawcircle(qp);
}

void circle::drawcircle(QPainter *qp)
{
    qp->drawEllipse(-h/2,-h/2,h,h);
}

