#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidget>
#include <QMessageBox>
#include "Tree.h"

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
    void on_InsKeyspinBox_valueChanged(int arg1);

    void on_DataLineEdit_textChanged(const QString &arg1);

    void on_OtherKeySpinBox_valueChanged(int arg1);

    void on_AddPushButton_clicked();

    void on_ShowByKeyPushButton_clicked();

    void on_DelByKeyPushButton_clicked();

    void on_PreOrderPushButton_clicked();

    void on_PostOrderPushButton_clicked();

    void on_InnerLeftPushButton_clicked();

    void on_BalancePushButton_clicked();

    void on_SomethinPushButton_clicked();

private:
    Ui::MainWindow *ui;

    void Rewrite();

    void AddTree(Node* n, QTreeWidgetItem *parent = nullptr);

    Tree t;

    int insertionKey;
    int otherKey;

    std::string data;

};
#endif // MAINWINDOW_H
