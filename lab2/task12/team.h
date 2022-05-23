#ifndef TEAM_H
#define TEAM_H

#include <QString>

class Team
{
public:
    Team();

    void addAgeHeight(int Age, int Height);
    void set_name(QString str);

    QString get_name();
    int get_avgAge();
    int get_avgHeight();
    void set_playersNumb(int num);


private:
    QString name;
    int playersNumb;
    int age;
    int avgAge;
    int height;
    int avgHeight;

};

#endif // TEAM_H
