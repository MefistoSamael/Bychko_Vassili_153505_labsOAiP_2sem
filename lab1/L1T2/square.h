#ifndef SQUARE_H
#define SQUARE_H
#include <QMainWindow>
#include "figura.h"


class square : public figura {
public:
    square();
    square(QPainter *qp, int Height = 100);


private:

    void drawsquare(QPainter *qp);

};

#endif // SQUARE_H
