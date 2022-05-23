#include "star8.h"
#include <QPainter>

star8::star8()
{

}

star8::star8(QPainter *qp, double Base)
{
    b = Base;

    drawStar8(qp);
}

void star8::drawStar8(QPainter *qp)
{
    for(int i = 0; i<8; i++)
    {
        qp->drawLine(-b/2*1.41, -b/2*1.41, -b/2*1.41, -b/2*1.41 - b);
        qp->drawLine(-b/2*1.41, -b/2*1.41 - b, 0, -b);
        qp->rotate(45);
    }

}
