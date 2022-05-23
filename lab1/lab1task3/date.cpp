#include "date.h"
#include <QDebug>
#include <QMessageBox>
#include <string>



Date::Date()
{
    day = -1;
    month = -1;
    year = -1;

}
QString Date::get_data()
{
    return date;
}


bool Date::set_data(int day, int month, int year)
{
    this->day=day;
    this->month=month;
    this->year=year;

    QDate dt;
    if(!dt.setDate(year,month,day))
    {
        return 0;
    }
    date = dt.toString("dd.MM.yyyy");
    return 1;

}

bool Date::set_data(QWidget *parent,QString str)
{

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
        QMessageBox::critical(parent, "Гы)", "Дата введена некорректно1");

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
        QMessageBox::critical(parent, "Гы)", "Дата введена некорректно2");
        return false;
    }

    //переносим день
    anotherba = ba.left(2);

    //проверка на буквы
    if (checkinp(anotherba))
    {
        QMessageBox::critical(parent, "Гы)", "Были встречены буквы в файле");
        return false;
    }
    //непосредственно заносим день
    day = anotherba.toInt();

    //переносим месяц
    anotherba =ba.mid(3,2);

    //проверка на буквы
    if (checkinp(anotherba))
    {
        QMessageBox::critical(parent, "Гы)", "Были встречены буквы в файле");
        return false;
    }
    //непосредственно заносим месяц
    month = anotherba.toInt();



    //переносим год
    anotherba =ba.right(4);

    //проверка на буквы
    if (checkinp(anotherba))
    {
        QMessageBox::critical(parent, "Гы)", "Были встречены буквы в файле");
        return false;
    }
    //непосредственно переносим год
    year = anotherba.toInt();

    //вводим дату в date
    QDate dt;
    dt.setDate(year,month,day);
    date = dt.toString("dd.MM.yyyy");
    if(!dt.isValid())
    {
        QMessageBox::critical(parent, "Гы)","дата недействительна");
        return false;
    }

}

Date Date::NextDay()
{
    Date NextDate;
    QDate dt(year,month,day);

    dt = dt.addDays(1);
    dt.getDate(&NextDate.year,&NextDate.month,&NextDate.day);
    NextDate.date = dt.toString("dd.MM.yyyy");

    return NextDate;
}

Date Date::PreviousDay()
{
    Date PreviousDay;
    QDate dt(year,month,day);

    dt = dt.addDays(-1);
    dt.getDate(&PreviousDay.year,&PreviousDay.month,&PreviousDay.day);
    PreviousDay.date = dt.toString("dd.MM.yyyy");

    return PreviousDay;
}

bool Date::IsLeap()
{
    QDate dt(year,month,day);

    return dt.isLeapYear(year);
}

int Date::WeekNumber()
{
    QDate dt(year,month,day);

    return dt.weekNumber();
}


int Date::DaysTillBithDay(Date date)
{
    QDate curdt;
    curdt.setDate(year,month,day);

    if(date.day == 29 && date.month == 2 && curdt.isLeapYear(date.year))
    {
        //если сегодня високосный год но др не было
        if (curdt.isLeapYear(year) && ((month < date.month) || (month == date.month && day < date.day)))
        {
            date.year = year;
        }
        else
        {
        date.year = year+1;
        date.set_data(date.day,date.month,date.year);

        //пока год рождения не станет високосным опять
        while(!curdt.isLeapYear(date.year))
            {
                date.year+=1;
            }
        }
    }

    else if (((month < date.month) || (month == date.month && day < date.day))) //если дня рождения еще не было
    {
        date.year = year;
    }

    else if (month == date.month && day == date.day)
    {
        //вывести поздравление с др
        return -1;
    }

    else
    {
        date.year = year + 1;
    }





    QDate birdt;

    birdt.setDate(date.year,date.month,date.day);


    return curdt.daysTo(birdt);

}

int Date::Duration(Date date)
{
    QDate curdt(year,month,day);

    QDate toDate(date.year, date.month,date.day);

    return curdt.daysTo(toDate);
}

bool Date::checkinp(QByteArray ba)
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



