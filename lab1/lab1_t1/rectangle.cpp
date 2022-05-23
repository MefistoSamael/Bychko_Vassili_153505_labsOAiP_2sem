#include "rectangle.h"
#include "ui_rectangle.h"
#include <QPainter>

rectangle::rectangle(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::rectangle)
{
    ui->setupUi(this);
    x = 200;
    y = 200;
    angle = 0;
    timerId = startTimer(16);
}


rectangle::~rectangle()
{
    delete ui;
}

void rectangle::paintEvent(QPaintEvent *e) {

  Q_UNUSED(e)

  QPainter qp(this);
  rectangle::drawrect(&qp);
}

void rectangle::drawrect(QPainter *qp) {


  qp->translate(QPoint(x,y));
  qp->drawRect(0, 0, 120, 60);

  if(x == 1200) x = -120;
}

void rectangle::timerEvent(QTimerEvent *te){
    Q_UNUSED(te);

    if (pushbut){
    x+=2;
    angle+=2;
    repaint();
    }
}


void rectangle::on_pushButton_clicked()
{
    if (pushbut == 0) pushbut = 1;
    else pushbut = 0;
}

void Wagon::paintEvent(QPaintEvent *pe)
{
    Q_UNUSED(pe);

    QPainter qp(this);
    drawrect(&qp);
    drawWheels(&qp);
}

void Wagon::drawWheels(QPainter *qp)
{

    qp->setBrush(QBrush("white"));
    qp->drawEllipse(-15,45,30,30);
    qp->drawEllipse(105,45,30,30);




    qp->translate(0,60);
    qp->rotate(angle);
    qp->drawLine(-15,0,15,0);
    qp->drawLine(0,-15,0,15);

    QPainter gp(this);
    gp.translate(QPoint(x,y));
    gp.translate(120,60);
    gp.rotate(angle);
    gp.drawLine(-15,0,15,0);
    gp.drawLine(0,-15,0,15);
    gp.translate(QPoint(x,y));



    QPainter Qp(this);
    Qp.drawLine(-1000,275, 1500,275);


}


