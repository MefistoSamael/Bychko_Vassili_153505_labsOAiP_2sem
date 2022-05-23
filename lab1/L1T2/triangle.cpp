#include "triangle.h"
#include <QPainter>
#include <math.h>
triangle::triangle()
{

}

triangle::triangle(QPainter *qp, double Height, double Base, double Degr)
{
    h = Height;
    b = Base;
    a = Degr/180*3.1415;
    drawTriangle(qp);
}

void triangle::drawTriangle(QPainter *qp)
{
    double var = h/tan(a);
    qp->drawLine( (-b-var)/3.0 , h/3.0 ,(2*var-b)/3, (-2.0/3.0)*h );
    qp->drawLine((2*var-b)/3, (-2.0/3.0)*h, (2*b-var)/3 , h/3.0);
    qp->drawLine( (-b-var)/3.0 , h/3.0 , (2*b-var)/3 , h/3.0);
}
