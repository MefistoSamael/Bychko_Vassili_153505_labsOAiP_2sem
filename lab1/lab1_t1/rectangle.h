#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class rectangle; }
QT_END_NAMESPACE

class rectangle : public QMainWindow
{
    Q_OBJECT

public:
    rectangle(QWidget *parent = nullptr);
    ~rectangle();

    bool pushbut = 0;


private:
    Ui::rectangle *ui;

protected:
    void paintEvent(QPaintEvent *pe);
    void timerEvent(QTimerEvent *te);
    void drawrect(QPainter *qp);


    int x,y,width,height, angle;

    int timerId;
private slots:
    void on_pushButton_clicked();
};
QT_BEGIN_NAMESPACE
namespace Ui { class Wagon; }
QT_END_NAMESPACE

class Wagon : public rectangle {

public:
    void paintEvent(QPaintEvent *pe);
    void drawWheels(QPainter *qp);
};
#endif // RECTANGLE_H
