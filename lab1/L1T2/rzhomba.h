#ifndef RZHOMBA_H
#define RZHOMBA_H

#include "square.h"
#include <QPainter>

class rzhomba : public square
{
public:
    rzhomba();
    rzhomba(QPainter *qp, double Base, double Angle);

private:
    void drawRzhombu(QPainter *qp);
};

#endif // RZHOMBA_H
