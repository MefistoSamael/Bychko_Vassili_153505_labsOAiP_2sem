#include "productdata.h"
#include "ui_productdata.h"
#include <QDebug>
#include <QMessageBox>

ProductData::ProductData(int size,bool &suc, Product *prodpt, Order *Ordpt,int OrdNumb,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductData)

{
    ui->setupUi(this);

    BufNumber = 1;
    BufPricePerOne = 1;
    BufName = "";

    ProdSize = size;
    succes = &suc;
    Prodptr = prodpt;
    Ordptr = Ordpt;
    this->OrdNumb = OrdNumb;
    VariantOfFunc = 1;//добавление
}

ProductData::ProductData(int size, bool &suc, Product *prodpt, Order *Ordpt, const int OrdNumb, int ProdNumb, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ProductData)
{
    ui->setupUi(this);

    BufNumber = 1;
    BufPricePerOne = 1;
    BufName = "";

    ProdSize = size;
    succes = &suc;
    Prodptr = prodpt;
    Ordptr = Ordpt;
    this->OrdNumb = OrdNumb;
    this->ProdNumb = ProdNumb;
    VariantOfFunc = 2;//изменение
}


ProductData::~ProductData()
{
    delete ui;
}

Order *ProductData::get_Ordptr()
{
    return Ordptr;
}

Product *ProductData::get_Prodptr()
{
    return Prodptr;
}

bool ProductData::get_succes()
{
    return *succes;
}

bool ProductData::isRus(QString str)
{
    for(int i = 0; i < str.length(); i++)
    {
        if (str[i].script() == 5) return true;
    }
    return false;
}


void ProductData::on_buttonBox_accepted()
{
    if (VariantOfFunc == 1)
    {
    Product* bufptr = new Product[ProdSize + 1];

    for(int i = 0; i<ProdSize;i++)
        bufptr[i]=Prodptr[i];
    bufptr[ProdSize].set_name(BufName);
    bufptr[ProdSize].set_priceperone(BufPricePerOne);
    bufptr[ProdSize].set_numbprd(BufNumber);


    delete[]Prodptr;
    Prodptr = bufptr;
    Ordptr[OrdNumb-1].set_Prodptr(Prodptr);

    Ordptr[OrdNumb-1].set_show(1);

    ProdSize++;
    Ordptr[OrdNumb-1].set_prodsize(ProdSize);
    *succes = 1;
    }
    if (VariantOfFunc == 2)
    {
        if (ProdSize < ProdNumb)
        {
            QMessageBox::information(this, "", "Вы пытаетесь изменить несуществующий товар");
            return;
        }


        Prodptr[ProdNumb-1].set_name(BufName);
        Prodptr[ProdNumb-1].set_priceperone(BufPricePerOne);
        Prodptr[ProdNumb-1].set_numbprd(BufNumber);

        Ordptr[OrdNumb-1].set_Prodptr(Prodptr);
        *succes = 1;
    }


}


void ProductData::on_NumberspinBox_valueChanged(int arg1)
{
    BufNumber = arg1;
}


void ProductData::on_PricespinBox_valueChanged(int arg1)
{
    BufPricePerOne = arg1;
}


void ProductData::on_NamelineEdit_textChanged(const QString &arg1)
{
    if (isRus(arg1))
    {
        ui->NamelineEdit->setText("\0");
    }
    BufName = arg1;
}

