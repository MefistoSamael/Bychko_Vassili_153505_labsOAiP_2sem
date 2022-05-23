#ifndef ORDER_H
#define ORDER_H

#include <QDate>
#include <QWidget>
#include "product.h"

class Order
{
public:
    Order();

    void set_number(int num);
    bool set_date(int day, int year, int month, QWidget *ptr);
    bool set_date(QString str);
    void set_requisites(QString str);
    void set_Prodptr(Product* ptr);
    void set_show(bool b);
    void set_prodsize(int i);
    bool checkinp(QByteArray ba);//только для проверки даты qstring

    int get_number();
    int get_prodsize();
    QString get_date();
    QString get_requisit();
    Product* get_prodptr();
    bool get_show();

private:

    int number;
    QDate date;
    QString requisit;
    Product* Prodptr;
    int ProdSize;
    //переменная отвечает за возможность отображения
    //списка товаров данного заказа
    bool show;
};

#endif // ORDER_H
