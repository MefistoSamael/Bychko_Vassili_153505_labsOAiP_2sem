#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "product.h"
#include "order.h"
#include <QTableWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    //переменные отвечают за выбор окна для внесения данных
    bool order;
    bool product;

    Order *Orderptr;
    int OrdNumber;
    int OrdSize;
    int ProdNumber;
    QString FNameOrd;
    QString FNameProd;
    bool enter;//отвечает за то был ли ввод

    void ClearTable(bool b);//1 - OrdTable

    void QsortProd();

    int compare(const void *i, const void *j);

    void write(std::string str);

    void writeProd(std::string str);

    void SetOrderInformation(int i);

    void SetProductInformation(int i);

    void RewriteOrderInformatiom();

    int CheckN(std::string str);//проверка числа

    bool CheckRus(std::string str);//проверка на русские буквы

private slots:
    void on_KeybordpushButton_clicked();

    void on_SwitchcomboBox_currentTextChanged(const QString &arg1);

    void on_OrderNumspinBox_valueChanged(int arg1);

    void on_LoadpushButton_2_clicked();

    void on_ChangepushButton_clicked();

    void on_ProdNumspinBox_valueChanged(int arg1);

    void on_DeletepushButton_clicked();

    void on_LoadpushButton_clicked();

    void on_SavepushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
