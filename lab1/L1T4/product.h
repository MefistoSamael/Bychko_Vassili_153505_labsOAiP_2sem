#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>


class Product
{
public:
    Product();
    void set_numbprd(int num);
    void set_priceperone(int num);
    void set_name(QString str);

    int get_numbprd();
    int get_priceperone();
    QString get_name();


private:

    int numbprd;
    int priceperone;
    QString name;
};

#endif // PRODUCT_H
