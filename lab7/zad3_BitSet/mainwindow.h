#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include "BitSet.h"

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
    void on_pushButtonAll_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_spinBox_2_valueChanged(int arg1);

    void on_radioButtonBitSet1_toggled(bool checked);

    void on_radioButtonBitSet2_toggled(bool checked);

    void on_pushButton_clicked();

    void on_pushButtonCount_clicked();

    void on_pushButtonAny_clicked();

    void on_pushButtonNone_clicked();

    void on_pushButtonReset_clicked();

    void on_pushButtonSet_clicked();

    void on_pushButtonSize_clicked();

    void on_pushButtonTest_clicked();

    void on_pushButtonULL_clicked();

    void on_pushButtonUL_clicked();

    void on_pushButtonAnd_clicked();

    void on_pushButtonOr_clicked();

    void on_pushButtonXor_clicked();

private:
    Ui::MainWindow *ui;

    BitSet<12> bitset1;
    BitSet<12> bitset2;

    bool isBitSet1;

    int input;
    int index;

};
#endif // MAINWINDOW_H
