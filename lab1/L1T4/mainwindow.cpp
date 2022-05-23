#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "orderdata.h"
#include "productdata.h"
#include "product.h"
#include "order.h"

#include <QMessageBox>
#include <QDebug>
#include <QFileDialog>
#include <iostream>
#include <fstream>
#include <filesystem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    order = 1;
    product = 0;

    Orderptr = new Order[0];

    OrdNumber = 1;

    OrdSize = 0;

    ProdNumber = 1;

    FNameOrd = "-1";
    FNameProd = "-1";

    enter = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ClearTable(bool b)
{
    if (b == 0)
    {
        for(int i = 0; i<5;i++)
        {
            QTableWidgetItem *item1 = new QTableWidgetItem;
            item1->setText("\0");
            ui->ProdtableWidget->setItem(i,0,item1);

            QTableWidgetItem *item2 = new QTableWidgetItem;
            item2->setText("\0");
            ui->ProdtableWidget->setItem(i,1,item2);

            QTableWidgetItem *item3 = new QTableWidgetItem;
            item3->setText("\0");
            ui->ProdtableWidget->setItem(i,2,item3);

        }

        ui->NumberTextlabel->setText("");
        ui->PriceTextlabel->setText("");

    }
    else
    {
        for(int i = 0; i<5;i++)
        {
            QTableWidgetItem *item1 = new QTableWidgetItem;
            item1->setText("\0");
            ui->OrdtableWidget->setItem(i,0,item1);

            QTableWidgetItem *item2 = new QTableWidgetItem;
            item2->setText("\0");
            ui->OrdtableWidget->setItem(i,1,item2);

            QTableWidgetItem *item3 = new QTableWidgetItem;
            item3->setText("\0");
            ui->OrdtableWidget->setItem(i,2,item3);


        }
    }
}







//заполнение таблицы информацией
void MainWindow::SetOrderInformation(int i)
{

    //установка номер заказа
    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setText(QString::number(Orderptr[i].get_number()));
    ui->OrdtableWidget->setItem(i,0,item1);

    //установка даты заказа
    QTableWidgetItem *item2 = new QTableWidgetItem;
    item2->setText(Orderptr[i].get_date());
    ui->OrdtableWidget->setItem(i,1,item2);

    //установка реквизитов
    QTableWidgetItem *item3 = new QTableWidgetItem;
    item3->setText(Orderptr[i].get_requisit());
    ui->OrdtableWidget->setItem(i,2,item3);

}

void MainWindow::SetProductInformation(int j)
{

    if (Orderptr[j].get_show()== 1 && Orderptr[j].get_number() == OrdNumber)
    {
    Product *bufptr = Orderptr[j].get_prodptr();
    ClearTable(0);

    int price = 0;
    for(int i = 0; i<Orderptr[j].get_prodsize();i++)
    {

        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setText(bufptr[i].get_name());
        ui->ProdtableWidget->setItem(i,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText(QString::number(bufptr[i].get_priceperone()));
        price+=bufptr[i].get_priceperone()*bufptr[i].get_numbprd();
        ui->ProdtableWidget->setItem(i,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item3->setText(QString::number(bufptr[i].get_numbprd()));
        ui->ProdtableWidget->setItem(i,2,item3);

    }
    ui->NumberTextlabel->setText(QString::number(j+1));
    ui->PriceTextlabel->setText(QString::number(price));


    }
    else
    {
        QMessageBox::information(this,"","Для данного заказа отсутсвует список товаров");
        return;
    }


}

void MainWindow::RewriteOrderInformatiom()
{
    for(int i = 0; i<5;i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setText("\0");
        ui->OrdtableWidget->setItem(i,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText("\0");
        ui->OrdtableWidget->setItem(i,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item3->setText("\0");
        ui->OrdtableWidget->setItem(i,2,item3);

    }

    for(int i = 0; i<OrdSize;i++)
    {
        QTableWidgetItem *item1 = new QTableWidgetItem;
        item1->setText(QString::number(Orderptr[i].get_number()));
        ui->OrdtableWidget->setItem(i,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem;
        item2->setText(Orderptr[i].get_date());

        ui->OrdtableWidget->setItem(i,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem;
        item3->setText(Orderptr[i].get_requisit());
        ui->OrdtableWidget->setItem(i,2,item3);


    }
}

int MainWindow::CheckN(std::string str)
{
    QString qstr = QString::fromStdString(str);

    if (qstr.size() != 1)
        return -1;

    else
    {
        if (qstr>=49 && qstr<= 53)
        {
            return qstr.toInt();
        }
        else return -1;
    }
}

bool MainWindow::CheckRus(std::string str)
{
   QString qstr(QString::fromStdString(str));

    for(int i = 0; i < str.length(); i++)
    {
        if (qstr[i].script() == 5) return true;
    }
    return false;

}

void MainWindow::on_LoadpushButton_clicked()
{
    ClearTable(1);
    ClearTable(0);


    bool success = 0;
    FNameOrd = QFileDialog::getOpenFileName(this,
                                         tr("Открыть текстовый файл"), "",
                                         tr("Текстовый файл (*.txt);;All Files (*)"));



    int numbappend = 0;

    std::ifstream fin;
    fin.open(FNameOrd.toStdString());
    if(!fin.is_open())
    {
        QMessageBox::information(this,"","Файл не открылся");
        delete[]Orderptr;
        Orderptr = new Order[0];
        OrdSize = 0;
        return;
    }





        //если был ввод до этого
        if (OrdSize != 0)
        {
            delete [] Orderptr;
            Orderptr = new Order[0];
            OrdSize = 0;
        }


        //переменные для ввода
        int numOrd = 1;
        std::string str;
        int number;
        if (OrdSize == 5)
        {
            QMessageBox::information(this, "","Массив заказов заполнен");
            return;
        }




        while (!fin.eof())
        {

            if (OrdSize == 5)
            {
                QMessageBox::information(this, "","Массив заказов прир вводе был заполнен");
                break;
            }

            //создание нового массива и перенос значений
            Order *bufptr = new Order[OrdSize+1];
            for (int i = 0; i<OrdSize;i++)
                bufptr[i]=Orderptr[i];
            OrdSize++;
            delete [] Orderptr;
            Orderptr = bufptr;

            fin>>str;

            //вводим реквизиты
            if (CheckRus(str))
            {
                QMessageBox::information(this,"","Встречены русские символы в строке ввода");
                delete[]Orderptr;
                Orderptr = new Order[0];
                OrdSize = 0;

                //полностью чистим файл ибо нех... ой
                //т.е русские буквы ломают файл
                QFile file(FNameOrd);
                if(!file.open(QIODevice::Append))
                {
                    QMessageBox::information(this,"","Что то пошло не так");
                    delete[]Orderptr;
                    Orderptr = new Order[0];
                    OrdSize = 0;
                    return;
                }
                file.resize(0);
                return;
            }
            if (str.size() > 15)
            {
                QMessageBox::information(this,"","Длинна строки больше 15");
                delete[]Orderptr;
                Orderptr = new Order[0];
                OrdSize = 0;
                return;
            }
            //проверка на пустую строку
            if (str.length() == 0 && OrdSize != 0)
            {
                Order *bufptr = new Order[OrdSize-1];
                for (int i = 0;i<OrdSize-1;i++)
                    bufptr[i]=Orderptr[i];

                OrdSize--;
                delete [] Orderptr;
                Orderptr = bufptr;
                break;
            }

            Orderptr[OrdSize-1].set_requisites(QString::fromStdString(str));

            //вводим номер заказа
            //если это не число от 1 до 5
            //выходим
//            fin >> str;
//            number = CheckN(str);
//            if (number == -1)
//            {
//                QMessageBox::information(this,"","Некорректный ввод номера заказа");
//                delete[]Orderptr;
//                Orderptr = new Order[0];
//                OrdSize = 0;
//                return;
//            }
//            Orderptr[OrdSize-1].set_number(number);
            Orderptr[OrdSize-1].set_number(numOrd);
            numOrd++;

            //вводим дату
            fin >> str;


            if(!Orderptr[OrdSize-1].set_date(QString::fromStdString(str)))
            {
                QMessageBox::information(this,"","Проверьте корректность введенной даты");
                delete[]Orderptr;
                Orderptr = new Order[0];
                OrdSize = 0;
                return;
            }
            numbappend += Orderptr[OrdSize - 1].get_date().size() + Orderptr[OrdSize - 1].get_requisit().size() + 2*2;


            //если будет пустая строка то дату считает в реквизиты
            if (Orderptr[OrdSize-1].get_date() == Orderptr[OrdSize-1].get_requisit())
            {
                QMessageBox::information(this, "", "Встречена пустая строка");
                delete[]Orderptr;
                Orderptr = new Order[0];
                OrdSize = 0;
                return;

            }
        }

        fin.close();
        QFile file(FNameOrd);
        if(!file.open(QIODevice::ReadWrite))
        {
            QMessageBox::information(this,"","Что то пошло не так");
            delete[]Orderptr;
            Orderptr = new Order[0];
            OrdSize = 0;
            return;
        }
        file.resize(numbappend-2);
        success = 1;
        enter = 1;



    if (success == 0)
    {
        QMessageBox::information(this,"","Недействительный ввод из файла");
        return;
    }
    else if(order == 1 && product == 0)
    {
        RewriteOrderInformatiom();

    }
}


void MainWindow::on_KeybordpushButton_clicked()
{
    if (FNameOrd == "-1")
    {
        QMessageBox::information(this,"","Сначала загрузи файл");
        return;
    }


    //переменная для проверки успешности внесения данных
    bool succes= 0;    


    //выбор какое окно открыть
    if (order == 1 && product == 0)
    {
            if (OrdSize >=5)
            {
                QMessageBox::information(this,"", "Достигнуто максимально количество заказов");
                return;
            }

        OrderData od(OrdSize,succes,Orderptr);
        od.setModal(true);
        od.exec();
        Orderptr = od.get_adress();

        write("OrdOut.txt");

    }
    else if (order == 0 && product == 1)
    {

            if (OrdSize == 0)
            {
                QMessageBox::information(this, "" , "Поле заказов пустое\nНевозможно внести список товаров");
                return;
            }
            if (OrdNumber > OrdSize)
            {
                QMessageBox::information(this, "" , "Данного заказа несуществует");
                return;
            }
            if (Orderptr[OrdNumber-1].get_prodsize() >=5)
            {
                QMessageBox::information(this,"", "Достигнуто максимально количество товаров");
                return;
            }



        ProductData pd(Orderptr[OrdNumber-1].get_prodsize(),succes,Orderptr[OrdNumber-1].get_prodptr(),Orderptr,OrdNumber);
        pd.setModal(true);
        pd.exec();

        Orderptr =pd.get_Ordptr();

        writeProd("OutProd.txt");



    }
    //если что то пойдет не так
    else QMessageBox::information(this, "", "Что-то пошло не так");

        if (succes == 0)
        {
            QMessageBox::information(this, "", "Значения не были внесены");
            return;
        }
    else if (order == 1 && product == 0)
    {
        SetOrderInformation(OrdSize - 1);
    }
    else if (order == 0 && product == 1)
    {
        SetProductInformation(OrdNumber-1);
    }




}


void MainWindow::on_SwitchcomboBox_currentTextChanged(const QString &arg1)
{
    if (enter == 0)
    {
        QMessageBox::information(this, "", "Сначала введи заказы");
        return;
    }
    if (arg1 == "Заказы")
    {
        order = 1;
        product = 0;
    }
    else if (arg1 == "Товары")
    {
        order = 0;
        product = 1;
    }
}


void MainWindow::on_OrderNumspinBox_valueChanged(int arg1)
{
    OrdNumber = arg1;
}


void MainWindow::on_LoadpushButton_2_clicked()
{
    if (FNameOrd == "-1")
    {
        QMessageBox::information(this,"","Сначала загрузи файл");
        return;
    }


    SetProductInformation(OrdNumber-1);
}

void MainWindow::on_ChangepushButton_clicked()
{
    if (FNameOrd == "-1")
    {
        QMessageBox::information(this,"","Сначала загрузи файл");
        return;
    }


    bool succes = 0;

    if (order == 1 && product == 0)
    {
        if (OrdSize == 0)
        {
            QMessageBox::information(this, "" , "Поле заказов пустое\nНевозможно изменить список заказов");
            return;
        }
        if (OrdNumber > OrdSize)
        {
            QMessageBox::information(this, "" , "Данного заказа несуществует");
            return;
        }

        OrderData od(OrdSize,succes,Orderptr, OrdNumber);
        od.setModal(true);
        od.exec();
        Orderptr = od.get_adress();

        write("OrdOut.txt");

    }
    else if (order == 0 && product == 1)
    {
        if (OrdSize == 0)
        {
            QMessageBox::information(this, "" , "Поле заказов пустое\nНевозможно внести список товаров");
            return;
        }
        if (OrdNumber > OrdSize)
        {
            QMessageBox::information(this, "" , "Данного заказа несуществует");
            return;
        }
        if (Orderptr[OrdNumber-1].get_prodsize() < ProdNumber)
        {
            QMessageBox::information(this,"","Вы изменяете несуществующий элемент списка товаров");
            return;
        }
       // if ()

        ProductData pd(Orderptr[OrdNumber-1].get_prodsize(),succes,Orderptr[OrdNumber-1].get_prodptr(),Orderptr,OrdNumber, ProdNumber);
        pd.setModal(true);
        pd.exec();

        Orderptr =pd.get_Ordptr();

        writeProd("OutProd.txt");

    }


    if (succes == 0)
    {
        QMessageBox::information(this, "", "Значения не были внесены");
        return;
    }
    else if (order == 1 && product == 0)
    {
       SetOrderInformation(OrdNumber-1);
    }
    else if (order == 0 && product == 1)
    {
       SetProductInformation(OrdNumber-1);
    }
}


void MainWindow::on_ProdNumspinBox_valueChanged(int arg1)
{
    ProdNumber = arg1;
}


void MainWindow::on_DeletepushButton_clicked()
{
    if (FNameOrd == "-1")
    {
        QMessageBox::information(this,"","Сначала загрузи файл");
        return;
    }

    bool succec = 0;
    if (order == 1 && product == 0)
    {
        if (OrdSize == 0)
        {
            QMessageBox::information(this, "" , "Поле заказов пустое\nНевозможно удалить заказ");
            return;
        }
        if (OrdNumber > OrdSize)
        {
            QMessageBox::information(this, "" , "Данного заказа несуществует");
            return;
        }


        succec = 1;
        Order *bufptr = new Order[OrdSize+1];

        for (int i = 0; i<OrdNumber - 1; i++)
            bufptr[i] = Orderptr[i];

        for (int i = OrdNumber - 1, j = OrdNumber; j<OrdSize; i++,j++)
        {
            bufptr[i] = Orderptr[j];
            bufptr[i].set_number(bufptr[i].get_number()-1);
        }

        delete [] Orderptr[OrdNumber-1].get_prodptr();
        delete [] Orderptr;

        Orderptr = bufptr;
        OrdSize--;
        ClearTable(0);

        write("OrdOut.txt");
    }
    else if (order == 0 && product == 1)
    {
        if (OrdSize == 0)
        {
            QMessageBox::information(this, "" , "Поле заказов пустое\nНевозможно внести список товаров");
            return;
        }
        if (OrdNumber > OrdSize)
        {
            QMessageBox::information(this, "" , "Данного заказа несуществует");
            return;
        }
        if (Orderptr[OrdNumber-1].get_prodsize() < ProdNumber)
        {
            QMessageBox::information(this,"","Вы удаляете несуществующий элемент списка товаров");
            return;
        }
        succec = 1;


        Product *Prodptr = Orderptr[OrdNumber-1].get_prodptr();
        Product *bufptr = new Product[Orderptr[OrdNumber-1].get_prodsize() - 1];

        for (int i = 0; i < ProdNumber-1;i++)
        {
            bufptr[i]=Prodptr[i];
        }

        for(int i = ProdNumber-1, j = ProdNumber; j<Orderptr[OrdNumber-1].get_prodsize(); i++,j++)
        {
            bufptr[i] = Prodptr[j];
        }

        Orderptr[OrdNumber-1].set_Prodptr(bufptr);
        Orderptr[OrdNumber-1].set_prodsize(Orderptr[OrdNumber-1].get_prodsize()-1);

        delete[] Prodptr;

        writeProd("OutProd.txt");
    }


    if (succec == 0)
    {
        QMessageBox::information(this, "", "Значения не были внесены");
        return;
    }
    else if (order == 1 && product == 0)
    {
        RewriteOrderInformatiom();
    }
    else if (order == 0 && product == 1)
    {
       SetProductInformation(OrdNumber-1);
    }

}

void MainWindow::write(std::string str)
{
    QFile file(QString::fromStdString(str));
    file.open(QIODevice::Truncate);
    file.resize(0);
    file.close();

    std::ofstream fout;
    fout.open(str, std::ios::app);

    if (!fout.is_open())
    {
        QMessageBox::information(this,"","невозможно открыть файл");
        return;
    }

    for(int i = 0; i<OrdSize;i++)
    {
        fout<< Orderptr[i].get_requisit().toStdString()<< "\n";
        fout<< Orderptr[i].get_date().toStdString()<< "\n";
    }

    fout.close();
}

void MainWindow::writeProd(std::string str)
{
    QFile file(QString::fromStdString(str));
    file.open(QIODevice::Truncate);
    file.resize(0);
    file.close();

    std::ofstream fout;
    fout.open(str, std::ios::app);

    if (!fout.is_open())
    {
        QMessageBox::information(this,"","невозможно открыть файл");
        return;
    }

    Product *bufptr = Orderptr[OrdNumber-1].get_prodptr();

    for(int i = 0; i<OrdSize;i++)
    {
        fout<< bufptr[i].get_name().toStdString()<< "\n";
        fout<< QString::number(bufptr[i].get_numbprd()).toStdString()<< "\n";
        fout<< QString::number(bufptr[i].get_priceperone()).toStdString()<< "\n";
    }

    fout.close();
}


void MainWindow::on_SavepushButton_clicked()
{
    if (FNameOrd == "-1")
    {
        QMessageBox::information(this,"","Сначала загрузи файл");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this,
        tr("Сохранить данные"), "",
        tr("Текст (*.txt);;All Files (*)"));


        if (OrdSize == 0)
        {
            QMessageBox::information(this,"","Список заказов пуст");
            return;
        }
    write(fileName.toStdString());


        if (Orderptr[OrdNumber-1].get_prodsize() == 0)
        {
            QMessageBox::information(this,"","Список товаров пуст");
            return;
        }
    writeProd("product.txt");

}

