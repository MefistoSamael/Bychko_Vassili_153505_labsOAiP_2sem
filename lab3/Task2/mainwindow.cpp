#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "unique_ptr.cpp"
#include <QString>
#include <QDebug>
#include <QMessageBox>
#include <QFile>
#include <QFileDialog>
#include <stack.h>
#include <skobka.h>
#include <cstdlib>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bfigure=0;
    bsquare=0;
    bround=0;
    srand(time(0));

    stack = new Stack();
    ui->ResultLabel->setText("Здесь будет результат");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete stack;
}

bool MainWindow::isRus(QString str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i].script() == 5) return true;
    }
    return false;
}



QString MainWindow::check(QString str)
{
    bfigure=0;
    bsquare=0;
    bround=0;

    int row = 1;
    int clmn = 1;

    for(int i = 0; i<str.size();i++)
    {

        //если встречена открывающая скобка
        if (str[i] == '{')
        {
            Skobka skoba('{',row,clmn);
            push(skoba, stack, this);
            bfigure++;
        }
        else if (str[i] == '[')
        {
            Skobka skoba('[',row,clmn);
            push(skoba, stack, this);
            bsquare++;
        }
        else if (str[i] == '(')
        {
            Skobka skoba('(',row,clmn);
            push(skoba, stack, this);
            bround++;
        }



        //если встречена закрывающая скобка
        if (str[i] == "}")
        {

            //если баланс скобок равен нулю
            //или разная открывающая и закрывающая
            //то выходим из проги
            if (!bfigure || top(stack,stack->curSize, this) != '{')
            {
                return QString::number(row) + " " + QString::number(clmn);
                clean(stack,stack->curSize);
            }

            //если все хорошо - удаляем эллемент из стека
            pop(stack,stack->curSize);
            bfigure--;

        }
        else if (str[i] == "]")
        {

            //если баланс скобок равен нулю
            //или разная открывающая и закрывающая
            //то выходим из проги
            if (!bsquare || top(stack,stack->curSize, this) != '[')
            {
                return QString::number(row) + " " + QString::number(clmn);
                clean(stack,stack->curSize);
            }

            //если все хорошо - удаляем эллемент из стека
            pop(stack,stack->curSize);
            bsquare--;

        }
        else if (str[i] == ")")
        {

            //если баланс скобок равен нулю
            //или разная открывающая и закрывающая
            //то выходим из проги
            if (!bround || top(stack,stack->curSize, this) != '(')
            {
                return QString::number(row) + " " + QString::number(clmn);
                clean(stack,stack->curSize);
            }

            //если все хорошо - удаляем эллемент из стека
            pop(stack,stack->curSize);
            bround--;
        }


        //переходим к следующему эллементу
        clmn++;
        //если переходим на новую строку -
        //сбрасываем счетчик столбцов
        //и увеличиваем счетчик строк
        if(str[i] == '\n')
        {
            row++;
            clmn = 1;
        }
    }

    //если баланс по окончании проверки остался положительным
    //то выводим первую открытую скобку, не имеющую пары
    if (bfigure > 0 || bsquare >0 || bround>0)
    {
        //чистим стек, оставляя последний элемент
        for (int i = 0; i<stack->curSize-1;i++)
            pop(stack,stack->curSize);

        //возвращаем строку и столбец первой открытой скобки, не имеющей пары
        return pop(stack,stack->curSize);
    }
    else
    {
        if (rand()%10 == 0)
            return "SISIK";
        else return "success";
    }

}


void MainWindow::on_textEdit_textChanged()
{
    QString str;
    str = ui->textEdit->toPlainText();

//    //проверка на русские символы
//    if (isRus(str))
//    {
//        QMessageBox::critical(this,"","Встречены русские буквы в воде\nсогласно условию они недопустимы");
//        str = "";
//        ui->textEdit->setText(str);
//    }

    ui->ResultLabel->setText(check(str));
}


void MainWindow::on_LoadushButton_clicked()
{
    std::string str;

    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Открыть текстовый файл"), "",
           tr("Текстовый файл (*.txt);;All Files (*)"));

    std::ifstream fin;
    fin.open(fileName.toStdString());
    if (!fin.is_open())
    {
        QMessageBox::critical(this, "","Неудалось открыть файл");
        return;
    }

    while(!fin.eof())
    {
       fin>>str;
    }
    QString qstr;
    qstr.fromStdString(str);

    ui->textEdit->setText(qstr);
    ui->ResultLabel->setText(check(qstr));


}

