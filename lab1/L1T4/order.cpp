#include "order.h"
#include <QMessageBox>
#include "productdata.h"

Order::Order()
{
    number = -1;
    date.setDate(1,1,1);
    requisit = "";
    show = 0;
    Prodptr = new Product[0];
    ProdSize = 0;
}

void Order::set_number(int num)
{
    number = num;
}

bool Order::set_date(int day, int year, int month, QWidget *ptr)
{
    if(date.setDate(year,month,day))
    {
        return 1;
    }
    else
    {
        QMessageBox::information(ptr, "", "Дата недействительна");
        return 0;
    }
}

bool Order::set_date(QString str)
{
    int year= 0,month= 0,day = 0;
    //переносим из QString в string
    //поскольку BA не работает с QString
    std::string stdstr;
    stdstr = str.toStdString();

    //создаем 2 ВА
    //один хранит все символы
    //второй будет использован как буфер
    QByteArray ba(11, '*');
    QByteArray anotherba(11,'*');

    //переносим строку в ВА
    ba = ba.fromStdString(stdstr);
    //проверка на длинну строки
    if(ba.size()!=10)
    {
//        QMessageBox::critical(parent, "Гы)", "Дата введена некорректно1");

        return false ;
    }

    //проверка на наличие двух точек
    int numb = 0;
    for(int i = 0; i< 10; i++)
    {
        if(ba.at(i) == '.')numb++;
    }
    if (numb != 2)
    {
//        QMessageBox::critical(parent, "Гы)", "Дата введена некорректно2");
        return false;
    }

    //переносим день
    anotherba = ba.left(2);

    //проверка на буквы
    if (checkinp(anotherba))
    {
//        QMessageBox::critical(parent, "Гы)", "Были встречены буквы в файле");
        return false;
    }
    //непосредственно заносим день
    day = anotherba.toInt();

    //переносим месяц
    anotherba =ba.mid(3,2);

    //проверка на буквы
    if (checkinp(anotherba))
    {
//        QMessageBox::critical(parent, "Гы)", "Были встречены буквы в файле");
        return false;
    }
    //непосредственно заносим месяц
    month = anotherba.toInt();



    //переносим год
    anotherba =ba.right(4);

    //проверка на буквы
    if (checkinp(anotherba))
    {
//        QMessageBox::critical(parent, "Гы)", "Были встречены буквы в файле");
        return false;
    }
    //непосредственно переносим год
    year = anotherba.toInt();

    //вводим дату в date
    date.setDate(year,month,day);

    if(!date.isValid())
    {
//        QMessageBox::critical(parent, "Гы)","дата недействительна");
        return false;
    }

    return true;
}

void Order::set_requisites(QString str)
{
    requisit = str;
}

void Order::set_Prodptr(Product *ptr)
{
    Prodptr = ptr;
}

void Order::set_show(bool b)
{
    show = b;
}

void Order::set_prodsize(int i)
{
    ProdSize = i;
}

bool Order::checkinp(QByteArray ba)
{
    for(int i = 0; i<ba.size();i++)
    {
        if((ba.at(i) >= 'a' && ba.at(i) <= 'z') || (ba.at(i) >= 'A' && ba.at(i) <= 'Z'))
        {
            return true;
        }
    }
    return false;
}

QString Order::get_date()
{
    return date.toString("dd.MM.yyyy");
}

int Order::get_number()
{
    return number;
}

int Order::get_prodsize()
{
    return ProdSize;
}

QString Order::get_requisit()
{
    return requisit;
}

Product *Order::get_prodptr()
{
    return Prodptr;
}

bool Order::get_show()
{
    return show;
}
