#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}

//проверку на количество оставшихся мест для др. вузов
//запихнуть ее в функцию добавления и удаления
