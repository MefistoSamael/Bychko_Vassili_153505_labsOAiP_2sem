#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "date.h"
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QMessageBox>
#include <QFileDialog>
#include <QDebug>
#include <QTextStream>
#include <QIODevice>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    bday = 1;
    bmonth = 1;
    byear = 1;
    bnumber = 1;

    size = 0;
    ptrdate = new Date[0];

    pptr = parent;
    SuccesReadnLoad = 0;

    birthday = new Date;
    birthday->set_data(6,5,2004);
}


MainWindow::~MainWindow()
{
    delete ui;
    delete table;
    delete [] ptrdate;
}

/*
 * QMainWindow{
background-color:qradialgradient(spread:repeat, cx:0.5, cy:0.5, radius:0.077, fx:0.5, fy:0.5, stop:0 rgba(0, 169, 255, 147), stop:0.497326 rgba(0, 0, 0, 147), stop:1 rgba(0, 169, 255, 147));
}
 */

void MainWindow::on_DaySpinBox_valueChanged(int arg1)
{
    bday = arg1;
}


void MainWindow::on_MonthSpinBox_valueChanged(int arg1)
{
    bmonth = arg1;
}


void MainWindow::on_YearSpinBox_valueChanged(int arg1)
{
    byear =  arg1;
}


void MainWindow::on_NumberSpinBox_valueChanged(int arg1)
{
    bnumber = arg1;
}


bool MainWindow::checkN(std::string fname)
{
    std::ifstream fin;
    fin.open(fname);
    if (!fin.is_open())
    {
        QMessageBox::information(this, "", "Не удалось открыть файл для считывания (checkN)");
        return 0;
    }
    fin.seekg(size*12);
}
void MainWindow::on_EnterDataPushButton_clicked()
{
    if (!SuccesReadnLoad)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Данные были прочитаны неверно или невведены в файл");
        return;
    }
    if (size == 10)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Размер очень большой");
        return;
    }

    QDate bt;
    if (!bt.setDate(byear,bmonth,bday))
    {
        QMessageBox::information(this,"", "Дата недействительна");
                return;
    }


    Date *bufptrdate = new Date[size+1];

    for(int i = 0; i<size; i++)
    {
        bufptrdate[i] = ptrdate[i];
    }

    //вводим новое значение
    bufptrdate[size].set_data(bday, bmonth, byear);

    //заносим данные в ячейку
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText(bufptrdate[size].get_data());
    ui->DateTable->setItem(size,0,item);


    size++;


    delete[] ptrdate;
    ptrdate= bufptrdate;
    fillTable(size-1);
    durationUpdate();




    //сохранение без полной перезаписи

    QFile file(fname);
    if(!file.open(QIODevice::ReadWrite | QIODevice::Append))
    {
        QMessageBox::information(this, "", "Невозможно открыть файл для записи");
        return;
    }
    QTextStream out(&file);
    if(size != 1)
    {
        file.resize((size-1)*12 - 2);
        out<<"\r\n"<<ptrdate[size-1].get_data();
    }
    else out << ptrdate[size-1].get_data();

}


void MainWindow::on_ChangeDataPushButton_clicked()
{
    if (!SuccesReadnLoad)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Данные были прочитаны неверно или невведены в файл");
        return;
    }
    if (bnumber > size)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Вы изменяете несуществующую ячейку");
        return;
    }



    //вводим новое значение
    if(!ptrdate[bnumber-1].set_data(bday,bmonth,byear))
    {
        QMessageBox::information(this,"","Дата недейвтительна");
        return;
    }

    //заносим данные в ячейку
    QTableWidgetItem *item = new QTableWidgetItem;
    item->setText(ptrdate[bnumber-1].get_data());
    ui->DateTable->setItem(bnumber-1,0,item);
    fillTable(bnumber-1);
    durationUpdate();


    //ввод в файл
    QFile file(fname);
    QTextStream out(&file);

    //readwrite потому что если брать writeonly
    //то будет дополнительно вызван qiodevice::truncate
    //это приведет к удалению старой информации
    if(!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this,"", "Невозможно открыть файл для вывода");
        return;
    }

    //выбрано именно значения, т.к. в начале каждой строки
    //находится символ \n и \r поэтому фактически новые строки
    //начинаются не с 11/22/33 а с 12/24/36 символа
    if(bnumber != 1)
        file.seek((bnumber-1)*12);
    out<<ptrdate[bnumber-1].get_data();


}


void MainWindow::on_DeleteDataPushButton_clicked()
{
    if (!SuccesReadnLoad)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Данные были прочитаны неверно или невведены в файл");
        return;
    }
    if(bnumber >size)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Вы удаляете несуществующую ячейку");
        return;
    }



    Date *bufptrdate = new Date[size-1];
    for(int i =0; i<bnumber-1;i++)
        bufptrdate[i]= ptrdate[i];
    for(int i = bnumber-1; i<size-1;i++)
        bufptrdate[i] = ptrdate[i+1];



    size--;
    delete[] ptrdate;
    ptrdate = bufptrdate;
    for(int i  = bnumber; i<size+1;i++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText(ptrdate[i-1].get_data());
        ui->DateTable->setItem(i-1,0,item);
    }
    //отчистка таблицы
    for(int j = 0; j<7;j++)
    {
        QTableWidgetItem *item = new QTableWidgetItem;
        item->setText("");
        ui->DateTable->setItem(size,j,item);
    }


    //запись в файл
    QFile file(fname);
    QTextStream out(&file);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, "", "Невозможно открыть файл для вывода");
        return;
    }

    file.seek((bnumber-1)*12);
    for (int i = bnumber; i<=size; i++)
    {
        out <<ptrdate[i-1].get_data() << "\r\n";
    }
    file.resize(size*12);
    if (size == 0)
        file.resize(0);
}



void MainWindow::on_SaveAsDataPushButton_clicked()
{
    if (!SuccesReadnLoad)
    {
        QMessageBox::information(this, "АЛЯЯЯЯЯРМ", "Данные были прочитаны неверно или невведены в файл");
        return;
    }

   write();
}


void MainWindow::write()
{
    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Сохранить данные"), "",
        tr("Текст (*.txt);;All Files (*)"));

    if (fileName.isEmpty()) return;
    else
    {
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::information(this, tr("невозможно открыть файл"),
        file.errorString());
        return;
    }
    QTextStream out(&file);
    for(int i = 0; i<size;i++)
    out << ptrdate[i].get_data()<<"\n\r";
    file.close();
    }
}


void MainWindow::fillTable(int i)
{
    QTableWidgetItem *item = new QTableWidgetItem;
    Date dt = ptrdate[i].NextDay();
    item->setText(dt.get_data());
    ui->DateTable->setItem(i,1,item);

    QTableWidgetItem *item2 = new QTableWidgetItem;
    dt = ptrdate[i].PreviousDay();
    item2->setText(dt.get_data());
    ui->DateTable->setItem(i,2,item2);

    QTableWidgetItem *item3 = new QTableWidgetItem;
    if (ptrdate[i].IsLeap() == 1)
        item3->setText("да");
    else
        item3->setText("нет");
    ui->DateTable->setItem(i,3,item3);

    QTableWidgetItem *item4 = new QTableWidgetItem;
    item4->setText(QString::number(dt.WeekNumber()));
    ui->DateTable->setItem(i,4,item4);

    QTableWidgetItem *item5 = new QTableWidgetItem;
    if (ptrdate[i].DaysTillBithDay(*birthday) == -1)
        item5->setText("День рождение сегодня");
    else item5->setText(QString::number(ptrdate[i].DaysTillBithDay(*birthday)));
    ui->DateTable->setItem(i,5,item5);

}

void MainWindow::updatebday()
{
    for(int i = 0; i<size;i++)
    {
        QTableWidgetItem *item5 = new QTableWidgetItem;
        if (ptrdate[i].DaysTillBithDay(*birthday) == -1 || ptrdate[i].DaysTillBithDay(*birthday) == 1461)
            item5->setText("День рождение сегодня" );
        else item5->setText(QString::number(ptrdate[i].DaysTillBithDay(*birthday)));
        ui->DateTable->setItem(i,5,item5);
    }
}

void MainWindow::durationUpdate()
{
    for(int i = 0; i<size;i++)
    {
        QTableWidgetItem *item6 = new QTableWidgetItem;
        if (i == size -1)
             item6->setText("дата в конце списка находится");
        else item6->setText(QString::number(ptrdate[i].Duration(ptrdate[i+1])));
        ui->DateTable->setItem(i,6,item6);
    }
}


void MainWindow::on_LoadDataPushButton_clicked()
{
    for(int i = 0; i<size;i++)
    {
        for(int j = 0; j<7;j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText('\0');
            ui->DateTable->setItem(size,j,item);
        }
    }
    //если до этого был успешшный ввод
    if (SuccesReadnLoad)
    {
        delete[] ptrdate;
        ptrdate = new Date[0];

        //стираем данные из таблицы
        size = 0;
        read();
        for(int i = 0; i<size;i++)
            fillTable(i);
        durationUpdate();
    }
    else
    {
        read();
        for(int i = 0; i<size;i++)
            fillTable(i);
        durationUpdate();
    }


}


void MainWindow::read()
{


    QString fileName = QFileDialog::getOpenFileName(this,
           tr("Открыть текстовый файл"), "",
           tr("Текстовый файл (*.txt);;All Files (*)"));

    //сохраняем название файла
    fname = fileName;
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(this, "Ух тыж блин", "Что то пошло не так");

        return;
    }
        QTextStream in(&file);



        for(int i = 0; !in.atEnd();i++)
        {
            //считываем данные
           QString str;
           in.readLineInto(&str);

           //почему то забирал символ: ""
           //для этого пришлось сделать этот if
           if(str == "")
           {
               i--;
               continue;
           }


            //расширяем массив ptrdate
            Date *bufptrdate = new Date[size+1];

            for(int j = 0; j<size;j++)
                bufptrdate[j]=ptrdate[j];

            delete[] ptrdate;
            ptrdate=bufptrdate;


            //вносим значения в массив date
            //так же учитываем успешность ввода
            if(!ptrdate[i].set_data(pptr,str))
            {
                //удаляем массив
                delete[] ptrdate;
                ptrdate = new Date[0];

                //чистим таблицу
                for(int i = 0; i<=size;i++)
                {
                    for(int j = 0; j<7; j++)
                    {
                        QTableWidgetItem *item = new QTableWidgetItem;
                        item->setText('\0');
                        ui->DateTable->setItem(i,j,item);
                    }
                }
                size = 0;
                return;
            }

            //вносим данные

            QTableWidgetItem *item = new QTableWidgetItem;
            item->setText(ptrdate[i].get_data());
            ui->DateTable->setItem(i,0,item);



            size++;

            //учитываем, что массив максимум из 10 эллементво
            //вызвано ограничением размера таблицы
            //это просто я ленивая жопа и не хочу расширять таблицу))))
            if (size == 10)
            {
                QMessageBox::information(this, "", "Размер достиг 10\nбольше низя");
                SuccesReadnLoad = 1;
                return;
            }
        }
    SuccesReadnLoad = 1;
}

void MainWindow::on_Test_clicked()
{
   QFile file(fname);

   QTextStream out (&file);

   if(!file.open(QIODevice::ReadWrite))
   {
       QMessageBox::information(this, "", "хуй");
       return;
   }

   int str = 3;
   file.seek(24);
   out << "hui";

}

/*QFile data("output.txt");
if (data.open(QFile::WriteOnly | QFile::Truncate)) {
    QTextStream out(&data);
    out << "Result: " << qSetFieldWidth(5) << left << 3.14 << 2.7;
    //такая тема
    //qSetFieldWidth(5) задайт длинну вывода в символах промежуточной части
    // т.е на каждые << будет отведено данной количество символов
    //если ты введешь 3 символа то будет добито еще 2 пробелами
    //left\right решает сначала идут пробелы или сразу символы
}*/


void MainWindow::on_EnterBirthPushButton_clicked()
{
    if(!birthday->set_data(bday,bmonth,byear))
    {
        QMessageBox::information(this,"","Дата ДР недействительна");
        return;
    }
    updatebday();
}

