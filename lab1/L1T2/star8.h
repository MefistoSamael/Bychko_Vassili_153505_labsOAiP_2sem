#ifndef STAR8_H
#define STAR8_H

#include "figura.h"
#include <QPainter>

class star8 : public figura
{
public:
    star8();
    star8(QPainter *qp, double Base);
    void drawStar8(QPainter *qp);

};

#endif // STAR8_H
