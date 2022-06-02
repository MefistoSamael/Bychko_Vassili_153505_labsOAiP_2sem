#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTabWidget>
#include "Map.h"
#include "set.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_radioButtonMap_toggled(bool checked);

    void on_radioButtonSet_toggled(bool checked);

    void on_lineEdit_textChanged(const QString &arg1);

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;

    Map<int,std::string> map;
    Set<int> set;

    int key;
    std::string data;

    //переменная, отвечающая за то, с каким контейнером работаем
    bool isMap;

    void Rewrite();
};
#endif // MAINWINDOW_H
