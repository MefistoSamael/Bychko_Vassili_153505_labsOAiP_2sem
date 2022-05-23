#ifndef CIRCLE_H
#define CIRCLE_H

#include <QMainWindow>
#include "figura.h"
class circle : public figura{

    void drawcircle(QPainter *qp);

public:
     circle();
     circle(QPainter *qp, double Height);
};

#endif // CIRCLE_H
