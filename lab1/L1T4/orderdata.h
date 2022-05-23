#ifndef ORDERDATA_H
#define ORDERDATA_H

#include <QDialog>
#include <QDate>
#include "order.h"

namespace Ui {
class OrderData;
}

class OrderData : public QDialog
{
    Q_OBJECT

public:
    explicit OrderData(int &size,bool &succec,  Order *Ordpt,int OrdNumber,QWidget *parent = nullptr);
    explicit OrderData(int &size,bool &succec,  Order *Ordpt,QWidget *parent = nullptr);
    explicit OrderData(int &size,bool &succec,  Order *Ordpt,int OrdNumber,char ch,QWidget *parent = nullptr);


    ~OrderData();

    int BufNumber;
    int BufDay;
    int BufMonth;
    int BufYear;
    QString BufRequisites;

    int *OrdSize;
    Order *Ordptr;
    bool *suc;//успешность ввода данных
    int OrdNumber;

    int VariantOfFunc;

    Order *get_adress();
    bool isRus(QString str);



private slots:

    void on_DayspinBox_valueChanged(int arg1);

    void on_MonthspinBox_valueChanged(int arg1);

    void on_YearspinBox_valueChanged(int arg1);

    void on_RequisiteslineEdit_textChanged(const QString &arg1);

    void on_buttonBox_accepted();

private:
    Ui::OrderData *ui;
};

#endif // ORDERDATA_H
