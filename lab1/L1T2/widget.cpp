#include <QMessageBox>
#include <QPainter>
#include <math.h>
#include "widget.h"
#include "ui_widget.h"
#include "square.h"
#include "rectangle.h"
#include "circle.h"
#include "triangle.h"
#include "rzhomba.h"
#include "hexagon.h"
#include "star6.h"
#include "star8.h"
#include "star5.h"
#include "net.h"
#include "dialog.h"

widget::widget(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::widget)
{
    ui->setupUi(this);
    choice = "квадрат";
    bufchoice = "квадрат";
    timerId = startTimer(1);
     X = 0;
     x = 0;
     Y = 0;
     y = 0;
     Height = 0;
     h = 0;
     Base =0;
     b = 0;
     RotationAngle = 0;
     r = 0;
     Angle = 1;
     a = 1;

     k = 0;//костыль для choice и bufchoice

     bufX = 0;
     bufY = 0;
     bufHeight = 0;
     bufBase = 0;
     bufRotationAngle = 0;
     bufAngle = 1;
}

widget::~widget()
{
    delete ui;
}

void widget::timerEvent(QTimerEvent *te) {



    if (x < X) x++;
    else if (x > X) x--;

    else if (y < Y) y++;
    else if(y > Y) y--;

    if (h < Height) h++;
    else if (h > Height) h--;

    if (b < Base) b++;
    else if (b > Base) b--;

    if (r < RotationAngle) r++;
    else if (r > RotationAngle) r--;

    if (a < Angle) a++;
    else if (a > Angle) a--;


    if (h == 1 || b == 1)
    {
        choice = bufchoice;
        Height = bufHeight;
        Base = bufBase;
        Angle = bufAngle;
    }



    repaint();
}

void widget::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe)



    QPainter *bb = new QPainter (this);

    QPen pen1(Qt::black, 2, Qt::SolidLine);
    bb->setPen(pen1);
    bb->translate(QPoint(x,y));
    if (showcenter == 1)
    {
        bb->drawLine(-10,0,10,0);
        bb->drawLine(0,-10,0,10);
    }

    QPainter *qp = new QPainter (this);
    QPen pen(Qt::black, 2, Qt::SolidLine);

    qp->setPen(pen);
    qp->translate(QPoint(x,y));
    qp->rotate(r);

    if (choice == "прямоугольник")
    {
        rectangle (qp,h,b);
        ui->square->setNum(h*b);
        ui->perimetr->setNum((h+b)*2);
    }
    if (choice == "квадрат")
    {
        square sq(qp,h);
        ui->square->setNum(h*h);
        ui->perimetr->setNum(h*4);
    }
    if (choice == "круг")
    {
        circle circ(qp,h);
        ui->square->setNum(3.14*h*h);
        ui->perimetr->setNum(h*2*3.14);
    }
    if (choice == "треугольник")
    {
        triangle triang(qp,h,b,a);
        ui->square->setNum(0.5*h*b);
        ui->perimetr->setNum(b+(sin(a/180*3.1415)*h)+sqrt(h*h + (b-sin(a/180*3.1415)*h*cos(a/180*3.1415))*(b-sin(a)*h*cos(a/180*3.1415))));
    }
    if (choice == "ромб")
    {
        rzhomba AdskiyHohotach(qp, b, a);
        ui->square->setNum(b*a*3.1415/180);
        ui->perimetr->setNum(4*b);
    }
    if (choice == "шестиугольник")
    {
        hexagon hex(qp,b);
        ui->square->setNum(3*1.72/2*b*b);
        ui->perimetr->setNum(6*b);
    }
    if (choice == "звезда6")
    {
        star6 star(qp,b);
        ui->square->setNum(12*b*b*1.71/4);
        ui->perimetr->setNum(12*b);
    }
    if (choice == "звезда8")
    {
        star8 star(qp,b);
        ui->square->setNum(4*1.41*b*b);
        ui->perimetr->setNum(16*b);
    }
    if (choice == "звезда5")
    {
        star5 star(qp,b);

        double z = b*sin(72*3.1415/180);
        double side = sqrt((1/tan(72*3.1415/180)+a)*(1/tan(72*3.1415/180)+a)+z*z);
        double BigSquare = 5/4*b*b*1/tan(36*3.1415/180);//площадь пятиугольника
        double littlesquare = 1/2*b*b*sin(108*3.1415/180);


        ui->square->setNum(BigSquare - 5*littlesquare);
        ui->perimetr->setNum(10*b);
    }
    if (choice == "Т")
    {
        neT T(qp,b);
        ui->square->setNum(2*b*b+b*3*b);
        ui->perimetr->setNum(12*b);
    }


    delete bb;
    delete qp;

    QPainter gg(this);

    gg.setBrush(QBrush("white"));
    gg.drawRect(800,0,1129,600);

}


void widget::on_X_valueChanged(int arg1)
{
    bufX = arg1;
}

void widget::on_Y_valueChanged(int arg1)
{
    bufY = arg1;
}

void widget::on_Height_valueChanged(int arg1)
{
    bufHeight = arg1;
}

void widget::on_Base_valueChanged(int arg1)
{
    bufBase = arg1;
}

void widget::on_RotationAngle_valueChanged(int arg1)
{
    bufRotationAngle = arg1;
}



void widget::on_Draw_clicked()
{
    X = bufX;
    Y = bufY;
    RotationAngle = bufRotationAngle;
    Height = bufHeight;
    Base = bufBase;
    Angle = bufAngle;
   if (choice != bufchoice)
    {
        Height = 0;
        Base = 0;
        Angle = 0;

    }







}


void widget::on_comboBox_currentIndexChanged(const QString &arg1)
{
    k++;
    if (k == 1) choice = arg1;

    bufchoice = arg1;

}

void widget::on_showcenter_clicked()
{
    if (showcenter == 0) showcenter = 1;
    else showcenter = 0;
}


void widget::on_angle_valueChanged(int arg1)
{
    bufAngle = arg1;
}


void widget::on_pushButton_clicked()
{
    Dialog app;
    app.setModal(1);
    app.exec();
}

