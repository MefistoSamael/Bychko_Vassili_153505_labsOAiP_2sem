#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      h()
{
    ui->setupUi(this);


    InD = 0;

    ui->tableWidget->setRowCount(15);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<< "Индекс"<<"Значение(он же ключ)");
    ui->tableWidget->setColumnWidth(1,500);

    Rewrite();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Rewrite()
{
    QTableWidgetItem *item;

    for(int i = 0;i < 15;i++)
    {
        QString ind;
        ind.setNum(i);

        item = new QTableWidgetItem(ind);
        ui->tableWidget->setItem(i,0,item);

        item = new QTableWidgetItem(h.stack_str(i));
        ui->tableWidget->setItem(i,1,item);
    }
}

void MainWindow::Default()
{
    srand(time(0));

    h.clean();

    for(int i = 0;i < 15;i++)
    {
        int a = rand() % 50 + 1;

        QString num;
        num.setNum(a);

        h.push(a,num);
    }
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    InD = arg1;
}

void MainWindow::on_pushButton_add_clicked()
{

    h.push(InD,QString::number(InD));

    Rewrite();
}


void MainWindow::on_pushButton_del_clicked()
{
    h.del(InD);

    Rewrite();
}


void MainWindow::on_pushButton_2_clicked()
{
    int ind = h.FindStack(InD);

    ui->label->setNum(ind);
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    str = arg1;
}


void MainWindow::on_pushButton_clicked()
{
    Default();

    Rewrite();
}


void MainWindow::on_pushButton_3_clicked()
{
    int i = 0;
    h.max_key_data(i);
    QMessageBox::information(this, "", "Индекс стека с максимальным элементом -" + QString::number(i));
}

