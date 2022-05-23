#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include "C:/QtProj/lab4/zad13/Vectorlib/vectorlib.h"
#include <algorithm>
//using namespace std;



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void Brus();
    void norm(MyVector<int>&c);
    void trim(MyVector<int> & c, int x);
    MyVector<int> add(const MyVector<int> & a, const MyVector<int> & b, int k);
    int get_bit(const MyVector<int> & v, int b);
    MyVector<int> mul(const MyVector<int> & a, int x, int k);
    void gen(MyVector<int> n, const MyVector<MyVector<int>> &p, int k, int i, MyVector<Pair<int, MyVector<int>> > &v);
    ~MainWindow();

private slots:
    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    int n,nn;
    int B = 1;
    const int fm = (1 << B) - 1;
};
#endif // MAINWINDOW_H
