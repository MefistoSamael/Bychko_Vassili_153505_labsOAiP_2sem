#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "square.h"
#include <QMainWindow>

class rectangle : public square{
public:
    rectangle();
    rectangle(QPainter *qp, double Height , double Base = 100);

private:
    void drawrectangle(QPainter *qp);

};

#endif // RECTANGLE_H
