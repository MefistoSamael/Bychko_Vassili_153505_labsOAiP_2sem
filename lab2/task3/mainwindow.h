#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

#include <fstream>
#include <filesystem>
#include "steak.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
    int size;//кол-во примеров

    double dA, dB, dC, dE, dD;//переменные А В С Е D
    int num;//номер примера с которым работаем

    std::string bufprim;
    std::string primer;
    std::string opz;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //функция определение приоритета
    int priorBank(char v);

    //проверка на символ + - * /
    bool operation(char c);

    //проверка на букву
    bool bukva(char c);

    //перевод в опз
    void Polska(std::string prim, std::string &opz);

    //вывод ответ итоговое число
    double Answer(std::string opz);

    //считывание файла
    void read();

    //проверка примера на корректность
    bool checkPrim(std::string prim);
private slots:
    void on_spinBox_Num_valueChanged(int arg1);

    void on_pushButton_Read_clicked();

    void on_doubleSpinBox_a_valueChanged(double arg1);

    void on_doubleSpinBox_b_valueChanged(double arg1);

    void on_doubleSpinBox_c_valueChanged(double arg1);

    void on_doubleSpinBox_d_valueChanged(double arg1);

    void on_doubleSpinBox_e_valueChanged(double arg1);

    void on_pushButton_Answer_clicked();

    void on_lineEdit_NewPrim_textEdited(const QString &arg1);

    void on_pushButton_Add_clicked();

    void on_pushButton_AnswerAll_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H

