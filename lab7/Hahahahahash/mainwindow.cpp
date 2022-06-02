#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      h()
{
    ui->setupUi(this);


    InD = 1;

    ui->tableWidget->setRowCount(15);
    ui->tableWidget->setColumnCount(3);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "Индекс"<<"ключ"<<"Значение");
    ui->tableWidget->setColumnWidth(1,500);

    h.Rewrite(ui->tableWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::Default()
{
    srand(time(0));

    h.clear();

    for(int i = 0;i < 15;i++)
    {
        int a = rand() % 50 + 1;

        QString num;
        num.setNum(a);

        h.insert(std::make_pair(a,num.toStdString()));
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    InD = arg1;
}

void MainWindow::on_pushButton_add_clicked()
{

    h.insert(std::make_pair(InD,input.toStdString()));

    h.Rewrite(ui->tableWidget);;
}


void MainWindow::on_pushButton_del_clicked()
{
    if (!h.contains(InD))
    {
         QMessageBox::information(this,"","Нет такого элемента");
         return;
    }

    h.erase(InD);

    h.Rewrite(ui->tableWidget);;
}


void MainWindow::on_pushButton_2_clicked()
{
    if (!h.contains(InD))
    {
         QMessageBox::information(this,"","Нет такого элемента");
         return;
    }

    auto it = h.find(InD);

    ui->label->setText(QString::fromStdString(it->second));
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    str = arg1;
}


void MainWindow::on_pushButton_clicked()
{
    Default();

    h.Rewrite(ui->tableWidget);;
}

void MainWindow::on_lineEditInput_textEdited(const QString &arg1)
{
    input = arg1;
}


void MainWindow::on_pushButtonContains_clicked()
{
    if (h.contains(InD)) QMessageBox::information(this,"","Содержит");
    else QMessageBox::information(this,"","Не содержит");
}

