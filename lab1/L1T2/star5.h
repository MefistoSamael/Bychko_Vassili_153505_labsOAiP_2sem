#ifndef STAR5_H
#define STAR5_H

#include "figura.h"
#include <QPainter>

class star5 : public figura
{
public:
    star5();
    star5(QPainter *qp, double Base);
    void drawStar5(QPainter *qp);
};

#endif // STAR5_H
