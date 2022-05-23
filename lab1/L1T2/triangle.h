#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figura.h"
#include <QPainter>

class triangle : public figura
{
public:
    triangle();
    triangle(QPainter *qp,double Height,double Base, double Degr);

private:
    void drawTriangle(QPainter *qp);
};

#endif // TRIANGLE_H
