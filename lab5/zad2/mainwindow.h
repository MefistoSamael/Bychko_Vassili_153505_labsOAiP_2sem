#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidgetItem>
#include <QMessageBox>
#include "DequeMVS.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void DequeOut();

private slots:
    void on_PopBackPushButton_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_PopFrontPushButton_clicked();

    void on_Push_BackPushButton_clicked();

    void on_Push_FrontPushButton_clicked();

    void on_ClearPushButton_clicked();

    void on_SizePushButton_clicked();

    void on_EmptyPushButton_clicked();

private:
    Ui::MainWindow *ui;
    Deque<int> d;
    int number;
};
#endif // MAINWINDOW_H
