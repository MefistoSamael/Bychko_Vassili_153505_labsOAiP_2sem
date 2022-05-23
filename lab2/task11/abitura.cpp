#include "abitura.h"

abitura::abitura()
{

}

abitura::abitura(QString lastName, QString name, QString patronymic, int *grades, QString university, bool exam)
{
    this->grades = new int [3];
    this->lastName = lastName;
    this->name = name;
    this->patronymic = patronymic;
    for(int i = 0; i<3;i++)
        this->grades[i] = grades[i];
    this->university = university;
    this->average = calculateAverage();
    this->exam = exam;
}

QString abitura::get_lastName()
{
    return lastName;
}

QString abitura::get_name()
{
    return name;
}

QString abitura::get_patronymic()
{
    return patronymic;
}

QString abitura::get_university()
{
    return university;
}

int *abitura::get_grades()
{
    return grades;
}

double abitura::get_average()
{
    return average;
}

bool abitura::get_exam()
{
    return exam;
}

void abitura::set_lastName(QString str)
{
    lastName = str;
}

void abitura::set_name(QString str)
{
    name = str;
}

void abitura::set_patronymic(QString str)
{
    patronymic = str;
}

void abitura::set_university(QString str)
{
    university = str;
}

void abitura::set_grades(int *array)
{
    grades = new int[3];
    for(int i = 0; i<3;i++)
        grades[i]=array[i];
}

void abitura::set_average(double i)
{
    average = i;
}

void abitura::set_average()
{
    average = calculateAverage();
}

void abitura::set_exam(bool b)
{
    exam = b;
}

double abitura::calculateAverage()
{
    int avg = 0;
    for(int i = 0; i<3;i++)
        avg+=grades[i];
    return avg/3;
}
