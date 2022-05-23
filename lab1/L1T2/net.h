#ifndef NET_H
#define NET_H

#include "figura.h"
#include <QPainter>

class neT : public figura
{
public:
    neT();
    neT(QPainter *qp, double Base);
    void drawNeT(QPainter *qp);
};

#endif // NET_H
