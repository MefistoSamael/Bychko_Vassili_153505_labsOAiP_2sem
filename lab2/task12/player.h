#ifndef PLAYER_H
#define PLAYER_H

#include <QString>
class Player
{
public:
    Player();
    Player(QString lastName,
    QString name,
    QString patronymic,
    QString country,
    QString team,
    int number,
    int age,
    int height,
    int weight);


    void set_lastName(QString str);
    void set_name(QString str);
    void set_patronymic(QString str);
    void set_country(QString str);
    void set_team(QString str);
    void set_number(int i);
    void set_age(int i);
    void set_height(int i);
    void set_weight(int i);

    QString get_lastName();
    QString get_name();
    QString get_patronymic();
    QString get_country();
    QString get_team();
    int get_number();
    int get_age();
    int get_height();
    int get_weight();

private:
    QString lastName;
    QString name;
    QString patronymic;
    QString country;
    QString team;
    int number;
    int age;
    int height;
    int weight;


};

#endif // PLAYER_H
