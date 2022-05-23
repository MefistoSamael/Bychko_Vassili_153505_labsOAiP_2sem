#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow www;
    www.resize(1200,800);
    www.show();
    return a.exec();
}
