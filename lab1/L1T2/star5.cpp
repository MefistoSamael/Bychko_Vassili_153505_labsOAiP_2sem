#include "star5.h"
#include <QPainter>

star5::star5()
{

}

star5::star5(QPainter *qp, double Base)
{
    b = Base;

    drawStar5(qp);
}
void star5::drawStar5(QPainter *qp)
{
    double var = 2*cos(72*3.1415/180)*b;
    double OB = var/2*tan(54*3.1415/180);
    double z = b*sin(72*3.1415/180);
    for(int i = 0; i<5; i++)
    {
        qp->drawLine(-var/2, -OB, 0, -OB - z);
        qp->drawLine(var/2, -OB, 0, -OB - z);
        qp->rotate(72);
    }


}
