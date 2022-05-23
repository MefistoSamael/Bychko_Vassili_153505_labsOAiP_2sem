#ifndef PRODUCTDATA_H
#define PRODUCTDATA_H

#include <QDialog>
#include <QString>
#include "product.h"
#include "order.h"

namespace Ui {
class ProductData;
}

class ProductData : public QDialog
{
    Q_OBJECT

public:
    explicit ProductData(int size,bool &suc, Product *prodpt, Order *Ordpt,const int OrdNumb, QWidget *parent = nullptr);
    explicit ProductData(int size,bool &suc, Product *prodpt, Order *Ordpt,const int OrdNumb, int ProdNumb, QWidget *parent = nullptr);
    ~ProductData();



    Order *get_Ordptr();
    Product *get_Prodptr();
    bool get_succes();
    bool isRus(QString str);

private slots:
    void on_buttonBox_accepted();

    void on_NumberspinBox_valueChanged(int arg1);

    void on_PricespinBox_valueChanged(int arg1);

    void on_NamelineEdit_textChanged(const QString &arg1);

private:
    Ui::ProductData *ui;

    int BufNumber;
    int BufPricePerOne;
    QString BufName;

    int ProdSize;
    Product *Prodptr;
    Order *Ordptr;
    bool *succes;
    int OrdNumb;
    int ProdNumb;
    int VariantOfFunc;
};

#endif // PRODUCTDATA_H
