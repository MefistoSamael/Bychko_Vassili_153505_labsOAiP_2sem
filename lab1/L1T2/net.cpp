#include "net.h"


neT::neT()
{

}

neT::neT(QPainter *qp, double Base)
{
    b = Base;

    drawNeT(qp);
}
void neT::drawNeT(QPainter *qp)
{
    qp->drawLine(-1.5*b, 11.0/10.0*b,1.5*b,11.0/10.0*b);
    qp->drawLine(-1.5*b, 11.0/10.0*b,-1.5*b, 1/10.0*b);
    qp->drawLine(1.5*b,11.0/10.0*b,1.5*b, 1/10.0*b);
    qp->drawLine(-1.5*b, 1/10.0*b, -0.5*b,1/10.0*b);
    qp->drawLine(1.5*b, 1/10.0*b, 0.5*b,1/10.0*b);
    qp->drawLine(-0.5*b,1/10.0*b,-0.5*b, -1.9*b);
    qp->drawLine(0.5*b,1/10.0*b,0.5*b,-1.9*b);
    qp->drawLine(-0.5*b,-1.9*b,0.5*b,-1.9*b);
}
