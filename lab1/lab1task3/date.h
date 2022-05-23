#ifndef DATE_H
#define DATE_H

#include <QWidget>
#include <QDate>
#include <QMessageBox>

class Date
{
public:
    Date();

    QString get_data();
    bool set_data(int day, int month, int year);
    bool set_data(QWidget *parent, QString str);
    void set_birthday();



    Date NextDay();
    Date PreviousDay();
    bool IsLeap();
    int WeekNumber();
    int DaysTillBithDay(Date date);
    int Duration(Date date);

    bool checkinp(QByteArray ba);



private:
    int day;
    int month;
    int year;

    QString date;
};

#endif // DATE_H
