#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->tableWidgetMap->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidgetMap->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);

    ui->tableWidgetSet->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    key = 1;
    data = "";
    isMap = 1;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    if (isMap)
        //работаем с Map
    {
        if(map.isEmpty())
        {
            QMessageBox::critical(this, "", "Map пуст");
            return;
        }

        map.Erase(key);

        ui->tableWidgetMap->clearContents();
    }
    else
        //работаем с Set
    {
        if(set.isEmpty())
        {
            QMessageBox::critical(this, "", "Set пуст");
            return;
        }

        set.Erase(key);

        ui->tableWidgetSet->clearContents();
    }

    Rewrite();
}


void MainWindow::on_pushButton_3_clicked()
{
    if (isMap)
        //работаем с Map
    {
        if(map.isEmpty())
        {
            QMessageBox::critical(this, "", "Map пуст");
            return;
        }

        if (map.Contains(key))
        {
            QMessageBox::information(this,"","Содержит");
        }
        else
        {
            QMessageBox::information(this,"","Не содержит");
        }
    }
    else
        //работаем с Set
    {
        if(set.isEmpty())
        {
            QMessageBox::critical(this, "", "Set пуст");
            return;
        }

        if(set.Contains(key))
        {
            QMessageBox::information(this,"","Содержит");
        }
        else
        {
            QMessageBox::information(this,"","Не содержит");
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (isMap)
        //работаем с Map
    {
        if(map.isEmpty())
        {
            QMessageBox::critical(this, "", "Map пуст");
            return;
        }
       map.Clear();

       ui->tableWidgetMap->clearContents();
    }
    else
        //работаем с Set
    {
        if(set.isEmpty())
        {
            QMessageBox::critical(this, "", "Set пуст");
            return;
        }
       set.Clear();

       ui->tableWidgetSet->clearContents();
    }
}


void MainWindow::on_pushButton_clicked()
{
    if (isMap)
        //работаем с Map
    {
       map.Insert(std::make_pair(key,data));

    }
    else
        //работаем с Set
    {
        set.Insert(key);
    }

    Rewrite();
}


void MainWindow::on_radioButtonMap_toggled(bool checked)
{
    isMap = 1;
}


void MainWindow::on_radioButtonSet_toggled(bool checked)
{
    isMap = 0;
}

void MainWindow::Rewrite()
{
    if (isMap)
    {
        int i = 0;
        QTableWidgetItem* item;
        for( auto it = map.begin(); it != map.end(); it++, i++)
        {
            item = new QTableWidgetItem();
            item->setText(QString::number(it->first));
            ui->tableWidgetMap->setItem(i,0, item);

            item = new QTableWidgetItem();
            item->setText(QString::fromStdString(it->second));
            ui->tableWidgetMap->setItem(i,1, item);
        }
    }
    else
    {
        int i = 0;
        QTableWidgetItem* item;
        for( auto it = set.begin(); it != set.end(); it++, i++)
        {
            item = new QTableWidgetItem();
            item->setText(QString::number(*it));
            ui->tableWidgetSet->setItem(i,0, item);
        }
    }
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    data = arg1.toStdString();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    key = arg1;
}

