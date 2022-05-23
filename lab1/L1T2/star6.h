#ifndef STAR6_H
#define STAR6_H

#include "figura.h"
#include <QPainter>

class star6 : public figura
{
public:
    star6();
    star6(QPainter *qp, double Base);
    void drawStar6(QPainter *qp);
};

#endif // STAR6_H
