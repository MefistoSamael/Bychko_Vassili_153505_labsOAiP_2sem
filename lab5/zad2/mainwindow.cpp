#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    number = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::DequeOut()
{
    int i = 0;
    for(Deque<int>::Iteratork it = d.begin(); ; )
    {
        if(it == d.end()) return;
        QTableWidgetItem* item = new QTableWidgetItem();
        item->setText(QString::number(*it));
        ui->tableWidget->setItem(i,0, item);
        ++it;
        i++;
    }
}


void MainWindow::on_PopBackPushButton_clicked()
{
    if (d.is_empty())
    {
        QMessageBox::critical(this, "","Дек пуст");
        return;
    }

    ui->tableWidget->clearContents();
    d.pop_back();
    DequeOut();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    number = arg1;
}


void MainWindow::on_PopFrontPushButton_clicked()
{
    if (d.is_empty())
    {
        QMessageBox::critical(this, "","Дек пуст");
        return;
    }

    ui->tableWidget->clearContents();
    d.pop_front();
    DequeOut();
}


void MainWindow::on_Push_BackPushButton_clicked()
{
    if (d.get_size() == 15)
    {
        QMessageBox::information(this,"","Место в таблице кончилось");
        return;
    }
    d.push_back(number);

    ui->tableWidget->clearContents();
    DequeOut();
}


void MainWindow::on_Push_FrontPushButton_clicked()
{
    if (d.get_size() == 15)
    {
        QMessageBox::information(this,"","Место в таблице кончилось");
        return;
    }
    d.push_front(number);

    ui->tableWidget->clearContents();
    DequeOut();
}


void MainWindow::on_ClearPushButton_clicked()
{
    if (d.is_empty())
    {
        QMessageBox::information(this,"","Дек пуст");
        return;
    }
    d.clear();
    ui->tableWidget->clearContents();
}


void MainWindow::on_SizePushButton_clicked()
{
    QMessageBox::information(this,"",QString::number(d.get_size()));
}


void MainWindow::on_EmptyPushButton_clicked()
{
    if (d.is_empty())
        QMessageBox::information(this,"","Пуст");
    else
        QMessageBox::information(this,"","Не Пуст");

}

