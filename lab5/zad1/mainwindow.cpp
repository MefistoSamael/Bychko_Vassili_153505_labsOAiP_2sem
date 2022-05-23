#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //для рандома
    srand(time(0));
    //(1);
}

MainWindow::~MainWindow()
{
    delete ui;
    generate = 0;
}

int MainWindow::FindMin()
{
    //номер минимального элемента в списке
    int index = 1;
    //значение минимального элемента в списке
    int data = L.GetElem(1).lock()->data;


    for(int i =1; i<=10; i++)
    {
        //если мы нашли элемент меньше чем запомненный
        //то запоминаем новый
        if(data > L.GetElem(i).lock()->data)
        {
            index = i;
            data = L.GetElem(i).lock()->data;
        }
    }

    return index;
}

int MainWindow::FindMax()
{
    //номер максимального элемента в списке
    int index = 1;
    //значение максимального элемента в списке
    int data = L.GetElem(1).lock()->data;


    for(int i =1; i<=10; i++)
    {
        //если мы нашли элемент больше чем запомненный
        //то запоминаем новый
        if(data < L.GetElem(i).lock()->data)
        {
            index = i;
            data = L.GetElem(i).lock()->data;
        }
    }

    return index;
}


void MainWindow::on_GeneratePushButton_clicked()
{
    //если список не пустой
    //чистим список
    while(L.GetCount() != 0)
            L.Del(1);

    //добавляем элементы в список
    for (int i = 1 ; i<=10; i++)
        L.Insert(1, rand()%1000);


    //вывод элементов в TextEdit
    //строка со всеми элементами
    QString str;
    for(int i = 1; i<=10; i++)
        str+=QString::number(L.GetElem(i).lock()->data) + "  ";

    //выводим строку
    ui->textEdit->setText(str);

    generate = 1;
}


void MainWindow::on_DeletePushButton_clicked()
{
    if (generate == 0)
    {
        QMessageBox::critical(this, "","Нельзя вызвать удаление");
        return;
    }


    int indexOfMin = FindMin();
    int indexOfMax = FindMax();

    //если сначала идет минимальный
    if (indexOfMin < indexOfMax)
    {
        for(int i = indexOfMin + 1; i< indexOfMax; i++)
            L.Del(indexOfMin + 1);
    }
    else
    {
        for (int i = indexOfMax + 1;i< indexOfMin; i++)
            L.Del(indexOfMax + 1);
    }

    //вывод элементов в TextEdit
    //строка со всеми элементами
    QString str;
    str = "Изначально: " + ui->textEdit->toPlainText() + "\n";
    for(int i = 1; i<=L.GetCount(); i++)
        str+=QString::number(L.GetElem(i).lock()->data) + "  ";

    //выводим строку
    ui->textEdit->setText(str);

    generate = 0;
}

