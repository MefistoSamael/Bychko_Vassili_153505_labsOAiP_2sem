#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stack.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    //функция проверки на русские символы по скрипту
    //(в QString кирилица имеет скрипт 5)
    bool isRus(QString str);

    //функция проверки введенной строки на скобочки
    //возвращает минус один в случае успеха
    //в остальных случаях QString с номером строки
    //и столбца где произошла ошибка
    QString check(QString str);

    //переменные отвечающие за баланс круглых,квадратных
    //и фигурных скобочек
    int bfigure;
    int bsquare;
    int bround;

    Stack *stack;



private slots:
    void on_textEdit_textChanged();

    void on_LoadushButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
