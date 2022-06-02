#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "unordered_map.h"


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


    void on_lineEditInput_textEdited(const QString &arg1);

    void on_pushButtonContains_clicked();

private:

    Ui::MainWindow *ui;

    Unordered_Map<int,std::string>  h;

    int InD;
    QString input;

    QString str;

    void Default();
};
#endif // MAINWINDOW_H
