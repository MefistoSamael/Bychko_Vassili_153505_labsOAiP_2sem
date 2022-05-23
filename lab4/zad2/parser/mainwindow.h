#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <regex>
#include "C:/QtProj/lab4/zad2/StringLib/stringlib.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void read_code();       //считывает файл .срр и сразу каждую строку отправляет на проверку

    void checkStr(String str);  //проверка регулярками строки

    void if_type_data(std::cmatch result);

    void if_function(std::cmatch result);

    void checkName(String nameFunc);

    void OutFunc();

    void outEdit(std::cmatch str);

    void IfFor(std::cmatch result);

    void LolOut(std::cmatch result);


private slots:
    void on_pushBotton_Test_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QString Text, dput;
    String testik;
    std::pair<String, int> *NameOfFunc;
    int sizeName;
    int coordinate;
    int in_table, in_edit, in_fail;
    int balance;
    int classSize;
    int structSize;
    int massSize;
};
#endif // MAINWINDOW_H
