#include <skobka.h>


Skobka::Skobka()
{

}

Skobka::Skobka(QChar symb, int row, int column)
{
    this->symb = symb;
    this->column = column;
    this->row = row;
}
