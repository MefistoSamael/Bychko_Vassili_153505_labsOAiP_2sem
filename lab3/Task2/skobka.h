#ifndef SKOBKA_H
#define SKOBKA_H
#include <QChar>

struct Skobka
{
    Skobka();
    Skobka(QChar symb, int row, int column);


    QChar symb;//символ скобки
    int row;//строка
    int column;//столбец

};

#endif // SKOBKA_H
