#include "player.h"

Player::Player()
{

}

Player::Player(QString lastName, QString name, QString patronymic, QString country, QString team, int number, int age, int height, int weight)
{
        this->lastName = lastName;
        this->name = name;
        this->patronymic = patronymic;
        this->country = country;
        this->team = team;
        this-> number = number;
        this-> age = age;
        this-> height = height;
        this-> weight = weight;
}

void Player::set_lastName(QString str)
{
    lastName = str;
}

void Player::set_name(QString str)
{
    name = str;
}

void Player::set_patronymic(QString str)
{
    patronymic = str;
}

void Player::set_country(QString str)
{
    country = str;
}

void Player::set_team(QString str)
{
    team = str;
}

void Player::set_number(int i)
{
    number = i;
}

void Player::set_age(int i)
{
    age = i;
}

void Player::set_height(int i)
{
    height = i;
}

void Player::set_weight(int i)
{
    weight = i;
}

QString Player::get_lastName()
{
    return lastName;
}

QString Player::get_name()
{
    return name;
}

QString Player::get_patronymic()
{
    return patronymic;
}

QString Player::get_country()
{
    return country;
}

QString Player::get_team()
{
    return team;
}

int Player::get_number()
{
    return number;
}

int Player::get_age()
{
    return age;
}

int Player::get_height()
{
    return height;
}

int Player::get_weight()
{
    return weight;
}
