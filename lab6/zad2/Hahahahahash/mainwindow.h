#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "hash.h"


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

    void on_spinBox_valueChanged(int arg1);

    void on_pushButton_add_clicked();

    void on_pushButton_del_clicked();

    void on_pushButton_2_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:

    Ui::MainWindow *ui;

    HashTable h;

    int InD;

    QString str;

    void Rewrite();

    void Default();
};
#endif // MAINWINDOW_H
