#include "orderdata.h"
#include "ui_orderdata.h"
#include "order.h"
#include "mainwindow.h"
#include <QMessageBox>

#include <QDebug>

OrderData::OrderData(int& size,bool &succes, Order *Ordpt,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderData)
{
    ui->setupUi(this);

    BufNumber = 1;
    BufDay = 1;
    BufMonth = 1;
    BufYear = 1;
    BufRequisites = "";

    //добавление
    VariantOfFunc = 1;
    OrdSize = &size;
    Ordptr = Ordpt;
    suc = &succes;
    OrdNumber = 0;
}

OrderData::OrderData(int& size,bool &succes, Order *Ordpt,int OrdNumber,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderData)
{
    ui->setupUi(this);

    BufNumber = 1;
    BufDay = 1;
    BufMonth = 1;
    BufYear = 1;
    BufRequisites = "";

    //изменение
    VariantOfFunc = 2;
    OrdSize = &size;
    Ordptr = Ordpt;
    suc = &succes;
    this->OrdNumber = OrdNumber;
}

OrderData::OrderData(int &size,bool &succec,  Order *Ordpt,int OrdNumber,char ch,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::OrderData)
{
    ui->setupUi(this);

    BufNumber = 1;
    BufDay = 1;
    BufMonth = 1;
    BufYear = 1;
    BufRequisites = "";

    //удаление
    VariantOfFunc = 3;
    OrdSize = &size;
    Ordptr = Ordpt;
    suc = &succec;
    this->OrdNumber = OrdNumber;
}



OrderData::~OrderData()
{
    delete ui;
}

Order *OrderData::get_adress()
{
    return Ordptr;
}

bool OrderData::isRus(QString str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i].script() == 5) return true;
    }
    return false;
}


void OrderData::on_DayspinBox_valueChanged(int arg1)
{
    BufDay = arg1;
}


void OrderData::on_MonthspinBox_valueChanged(int arg1)
{
    BufMonth = arg1;
}


void OrderData::on_YearspinBox_valueChanged(int arg1)
{
    BufYear = arg1;
}


void OrderData::on_RequisiteslineEdit_textChanged(const QString &arg1)
{
    if (isRus(arg1))
    {
        ui->RequisiteslineEdit->setText("\0");
    }
    BufRequisites = arg1;
}


void OrderData::on_buttonBox_accepted()
{
    QDate dt;
    if(!dt.setDate(BufYear,BufMonth,BufDay))
    {
        QMessageBox::information(this, "", "Дата недействительна");
        return;
    }
    if (VariantOfFunc == 1)//Добавление
    {

    //переносим значения
    Order *bufptr = new Order[*OrdSize+1];

    for(int i = 0; i<*OrdSize; i++)
    {
        bufptr[i] = Ordptr[i];
    }

    //успешность установки
    if(bufptr[*OrdSize].set_date(BufDay,BufYear,BufMonth, this))
        *suc = 1;
    bufptr[*OrdSize].set_number(*OrdSize+1);
    bufptr[*OrdSize].set_requisites(BufRequisites);

    delete[] Ordptr;
    Ordptr = bufptr;
    (*OrdSize)++;
    }
    if (VariantOfFunc == 2)//Изменение
    {
        if (Ordptr[OrdNumber-1].set_date(BufDay,BufYear,BufMonth, this)) *suc = 1;
        Ordptr[OrdNumber-1].set_requisites(BufRequisites);
    }
    if (VariantOfFunc == 3)//Удаление
    {
        *suc = 1;
        Order *bufptr = new Order[*OrdSize+1];

        for (int i = 0; i<OrdNumber - 1; i++)
            bufptr[i] = Ordptr[i];

        for (int i = OrdNumber - 1, j = OrdNumber; j<*OrdSize; i++,j++)
        {
            bufptr[i] = Ordptr[j];
            bufptr[i].set_number(bufptr[i].get_number()-1);
        }

        delete [] Ordptr[OrdNumber-1].get_prodptr();
        delete [] Ordptr;

        Ordptr = bufptr;
        (*OrdSize)--;
    }


}

