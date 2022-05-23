#ifndef HEXAGON_H
#define HEXAGON_H

#include "figura.h"
#include <QPainter>

class hexagon : public figura
{
public:
    hexagon();
    hexagon(QPainter *qp, double Base);
    void drawHex(QPainter *qp);
};

#endif // HEXAGON_H
