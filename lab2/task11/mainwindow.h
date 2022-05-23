#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include "abitura.h"
#include <QDebug>
#include <QTableWidget>
#include <QFileDialog>
#include <fstream>
#include <filesystem>
#include <iostream>
#include <string>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void TableOut();
    void TableOut(int i);
    void TableOut(int i, int g);
    void TableClear();
    bool isRus(QString str);


private slots:

    void on_lineEditLastName_textChanged(const QString &arg1);

    void on_lineEditName_textChanged(const QString &arg1);

    void on_lineEditPatronymic_textChanged(const QString &arg1);

    void on_lineEditUniversity_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_spinBox_3_valueChanged(int arg1);

    void on_radioButtonExam_clicked();

    void on_spinBox_4_valueChanged(int arg1);

    void on_doubleSpinBox_valueChanged(double arg1);

    void on_spinBoxRowNumber_valueChanged(int arg1);

    void on_pushButtonAdd_clicked();

    void on_pushButton_clicked();

    void on_pushButtonSearch_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonSort_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonLoad_clicked();


    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;

    QString lastName;
    QString name;
    QString patronymic;
    QString university;
    int *grades;
    bool exam;

    double averageSearch;
    int elementNumber;
    int pos;
    int numbPlaces;

    List L;

    QString fileName;
    bool success;
};
#endif // MAINWINDOW_H
