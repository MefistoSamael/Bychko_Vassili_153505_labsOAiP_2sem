#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include "date.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void write();
    void read();
    bool checkN(std::string fname);//функция проверяет наличие символов \n
    void fillTable(int i);
    void updatebday();
    void durationUpdate();
    QTableWidget *table;
    Date *birthday;

private:

    Date *ptrdate;
    int size;
    int bday;
    int bmonth;
    int byear;
    int bnumber;


    QWidget *pptr = 0;
    QString fname;
    bool load;
    bool SuccesReadnLoad;

private slots:


    void on_EnterDataPushButton_clicked();

    void on_DaySpinBox_valueChanged(int arg1);

    void on_MonthSpinBox_valueChanged(int arg1);

    void on_YearSpinBox_valueChanged(int arg1);

    void on_NumberSpinBox_valueChanged(int arg1);

    void on_ChangeDataPushButton_clicked();

    void on_DeleteDataPushButton_clicked();

    void on_LoadDataPushButton_clicked();

    void on_SaveAsDataPushButton_clicked();

    void on_Test_clicked();

    void on_EnterBirthPushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
