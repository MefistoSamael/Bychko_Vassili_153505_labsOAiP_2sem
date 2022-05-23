#ifndef widget_H
#define widget_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class widget; }
QT_END_NAMESPACE

class widget : public QMainWindow
{
    Q_OBJECT

public:
    widget(QWidget *parent = nullptr);
    ~widget();

    double X;
    double x;
    double Y;
    double y;
    double Height;
    double Base;
    double RotationAngle;
    double Angle;
    double h;
    double b;
    double r;
    double a;

    double bufX;
    double bufY;
    double bufHeight;
    double bufBase;
    double bufRotationAngle;
    double bufAngle;

    int k;

    bool showcenter = 0;

    QString bufchoice;
    QString choice;
    int timerId = 0;

    bool pushbut = 0;

    void paintEvent(QPaintEvent *pe);
    void timerEvent(QTimerEvent *te);




private slots:


    void on_X_valueChanged(int arg1);

    void on_RotationAngle_valueChanged(int arg1);

    void on_Y_valueChanged(int arg1);

    void on_Height_valueChanged(int arg1);

    void on_Base_valueChanged(int arg1);

    void on_Draw_clicked();

    void on_comboBox_currentIndexChanged(const QString &arg1);



    void on_showcenter_clicked();

    void on_angle_valueChanged(int arg1);

    void on_pushButton_clicked();

private:
    Ui::widget *ui;

protected:


};
#endif // widget_H
