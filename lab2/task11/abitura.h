#ifndef ABITURA_H
#define ABITURA_H

#include <QString>
#include <QDebug>

class abitura
{
public:
    abitura();
    abitura(QString lastName, QString name, QString patronymic, int *grades, QString university = "BSUIR", bool exam = 1);


    QString get_lastName();
    QString get_name();
    QString get_patronymic();
    QString get_university();
    int *get_grades();
    double get_average();
    bool get_exam();


    void set_lastName(QString str);
    void set_name(QString str);
    void set_patronymic(QString str);
    void set_university(QString str);
    void set_grades(int *array);
    void set_average(double i);
    void set_average();
    void set_exam(bool b);

private:

    //фамилия
    QString lastName;
    //имя
    QString name;
    //отчество
    QString patronymic;
    //название универа
    QString university;
    //оценки за экзамеН
    int *grades;
    //средний балл
    double average;
    //сдавал ли экзамен
    //по умолчанию - да
    bool exam;

    //подсчет среднего балла
    double calculateAverage();
};

#endif // ABITURA_H
