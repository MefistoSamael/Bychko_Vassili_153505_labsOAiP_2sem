#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "list.h"
#include <cstdlib>
#include <QMessageBox>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int FindMin();
    int FindMax();

private slots:
    void on_GeneratePushButton_clicked();

    void on_DeletePushButton_clicked();

private:
    Ui::MainWindow *ui;
    bool generate;

    List L;



};
#endif // MAINWINDOW_H
