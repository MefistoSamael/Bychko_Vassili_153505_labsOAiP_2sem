#include "team.h"

Team::Team()
{
    name = "";
    age = 0;
    height = 0;
    avgAge = 0;
    avgHeight = 0;
    playersNumb = 0;
}

void Team::addAgeHeight(int Age, int Height)
{
    age+= Age;
    height+=Height;
    playersNumb++;

    avgAge = age/playersNumb;
    avgHeight = height/playersNumb;
}

void Team::set_name(QString str)
{
    name = str;
}

QString Team::get_name()
{
    return name;
}

int Team::get_avgAge()
{
    return avgAge;
}

int Team::get_avgHeight()
{
    return avgHeight;
}

void Team::set_playersNumb(int num)
{
 playersNumb = num;
}
