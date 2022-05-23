#include "product.h"

Product::Product()
{
    numbprd = 0;
    priceperone = 0;
    name = "***";
}

void Product::set_numbprd(int num)
{
    numbprd = num;
}

void Product::set_priceperone(int num)
{
    priceperone = num;
}

void Product::set_name(QString str)
{
    name = str;
}

int Product::get_numbprd()
{
    return numbprd;
}

int Product::get_priceperone()
{
    return priceperone;
}

QString Product::get_name()
{
    return name;
}
