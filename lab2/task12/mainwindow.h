#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QTableWidget>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <fstream>
#include "team.h"
#include "player.h"
#include "listhuini.h"


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
    void on_lineEditCountry_textChanged(const QString &arg1);

    void on_lineEditTeam_textChanged(const QString &arg1);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_lineEditName_textChanged(const QString &arg1);

    void on_lineEditPatronymic_textChanged(const QString &arg1);

    void on_spinBoxNumber_valueChanged(int arg1);

    void on_spinBoxAge_valueChanged(int arg1);

    void on_spinBoxHeight_valueChanged(int arg1);

    void on_spinBoxWeight_valueChanged(int arg1);

    void on_pushButton_clicked();

    void on_pushButton_7_clicked();

    void on_pushButtonSearch_clicked();

    void on_spinBox_4_valueChanged(int arg1);

    void on_spinBoxHeight_2_valueChanged(int arg1);

    void on_comboBox_2_currentTextChanged(const QString &arg1);

    void on_lineEdit_2_textChanged(const QString &arg1);

    void on_spinBoxRowNumber_valueChanged(int arg1);

    void on_pushButtonAdd_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButtonSave_clicked();

    void on_pushButtonSearch_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_pushButtonLoad_clicked();

private:
    Ui::MainWindow *ui;

    QString country;
    QString team;
    QString lastName;
    QString name;
    QString patronymic;
    int number;
    int age;
    int height;
    int weight;

    int minWeight;
    int maxWeight;
    QString searchLastName;
    int searchHeight;
    int searchAge;

    int rowNumber;
    int elemNumber;

    ListHuini L;
    QString fileName;

};
#endif // MAINWINDOW_H
