#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

     country = "";
     team ="Fiksiki";
     lastName="";
     name="";
     patronymic="";
     number=1;
     age=18;
     height=150;
     weight=40;

     minWeight = 40;
     maxWeight = 63;
     rowNumber = 1;
     elemNumber = 1;
     searchLastName = "";
     searchHeight = 150;
     searchAge = 18;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TableOut()
{

    for (int i = 1; i<=L.GetSize(); i++)
    {
        NodeHuini node = L.GetNodeHuini(i);


        QTableWidgetItem *item1 = new QTableWidgetItem(node.play.get_country());
        ui->tableWidget->setItem(i-1,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(node.play.get_team());
        ui->tableWidget->setItem(i-1,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(node.play.get_lastName());
        ui->tableWidget->setItem(i-1,2,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(node.play.get_name());
        ui->tableWidget->setItem(i-1,3,item4);

        QTableWidgetItem *item5 = new QTableWidgetItem(node.play.get_patronymic());
        ui->tableWidget->setItem(i-1,4,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(node.play.get_number()));
        ui->tableWidget->setItem(i-1,5,item6);

        QTableWidgetItem *item7 = new QTableWidgetItem(QString::number(node.play.get_age()));
        ui->tableWidget->setItem(i-1,6,item7);

        QTableWidgetItem *item8 = new QTableWidgetItem(QString::number(node.play.get_weight()));
        ui->tableWidget->setItem(i-1,7,item8);

        QTableWidgetItem *item9 = new QTableWidgetItem(QString::number(node.play.get_height()));
        ui->tableWidget->setItem(i-1,8,item9);
    }

}

void MainWindow::TableOut(int i)
{
    TableClear();

    NodeHuini node = L.GetNodeHuini(i);


    QTableWidgetItem *item1 = new QTableWidgetItem(node.play.get_country());
    ui->tableWidget->setItem(0,0,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(node.play.get_team());
    ui->tableWidget->setItem(0,1,item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(node.play.get_lastName());
    ui->tableWidget->setItem(0,2,item3);

    QTableWidgetItem *item4 = new QTableWidgetItem(node.play.get_name());
    ui->tableWidget->setItem(0,3,item4);

    QTableWidgetItem *item5 = new QTableWidgetItem(node.play.get_patronymic());
    ui->tableWidget->setItem(0,4,item5);

    QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(node.play.get_number()));
    ui->tableWidget->setItem(0,5,item6);

    QTableWidgetItem *item7 = new QTableWidgetItem(QString::number(node.play.get_age()));
    ui->tableWidget->setItem(0,6,item7);

    QTableWidgetItem *item8 = new QTableWidgetItem(QString::number(node.play.get_weight()));
    ui->tableWidget->setItem(0,7,item8);

    QTableWidgetItem *item9 = new QTableWidgetItem(QString::number(node.play.get_height()));
    ui->tableWidget->setItem(0,8,item9);
}

void MainWindow::TableOut(int i, int g)
{
    NodeHuini node = L.GetNodeHuini(i);


    QTableWidgetItem *item1 = new QTableWidgetItem(node.play.get_country());
    ui->tableWidget->setItem(g,0,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(node.play.get_team());
    ui->tableWidget->setItem(g,1,item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(node.play.get_lastName());
    ui->tableWidget->setItem(g,2,item3);

    QTableWidgetItem *item4 = new QTableWidgetItem(node.play.get_name());
    ui->tableWidget->setItem(g,3,item4);

    QTableWidgetItem *item5 = new QTableWidgetItem(node.play.get_patronymic());
    ui->tableWidget->setItem(g,4,item5);

    QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(node.play.get_number()));
    ui->tableWidget->setItem(g,5,item6);

    QTableWidgetItem *item7 = new QTableWidgetItem(QString::number(node.play.get_age()));
    ui->tableWidget->setItem(g,6,item7);

    QTableWidgetItem *item8 = new QTableWidgetItem(QString::number(node.play.get_weight()));
    ui->tableWidget->setItem(g,7,item8);

    QTableWidgetItem *item9 = new QTableWidgetItem(QString::number(node.play.get_height()));
    ui->tableWidget->setItem(g,8,item9);

}

void MainWindow::TableClear()
{
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            QTableWidgetItem *item1 = new QTableWidgetItem("");
            ui->tableWidget->setItem(i,j,item1);
        }
    }
}

bool MainWindow::isRus(QString str)
{
    for(int i = 0; i < str.length(); i++)
    {
    if (str[i].script() == 5) return true;
    }
    return false;
}


void MainWindow::on_lineEditCountry_textChanged(const QString &arg1)
{
    country = arg1;
}


void MainWindow::on_lineEditTeam_textChanged(const QString &arg1)
{
    team = arg1;
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    lastName = arg1;
}


void MainWindow::on_lineEditName_textChanged(const QString &arg1)
{
    name = arg1;
}


void MainWindow::on_lineEditPatronymic_textChanged(const QString &arg1)
{
    patronymic = arg1;
}


void MainWindow::on_spinBoxNumber_valueChanged(int arg1)
{
    number = arg1;
}


void MainWindow::on_spinBoxAge_valueChanged(int arg1)
{
    age = arg1;
}


void MainWindow::on_spinBoxHeight_valueChanged(int arg1)
{
    height = arg1;
}


void MainWindow::on_spinBoxWeight_valueChanged(int arg1)
{
    weight = arg1;
}


void MainWindow::on_pushButton_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст!");
        return;
    }

    TableClear();
    TableOut();
}

void MainWindow::on_pushButtonSearch_clicked()
{
    if (elemNumber > L.GetSize())
    {
        QMessageBox::information(this,"","Вывод несуществующего элемента");
        return;
    }
    TableClear();
    TableOut(elemNumber);
}


void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    elemNumber = arg1;
}


void MainWindow::on_spinBoxHeight_2_valueChanged(int arg1)
{
    searchHeight = arg1;
}


void MainWindow::on_comboBox_2_currentTextChanged(const QString &arg1)
{
    if(arg1 == "легкая")
    {
        minWeight = 40;
        maxWeight = 63;
    }
    else if (arg1 == "средняя")
    {
        minWeight = 64;
        maxWeight = 75;
    }
    else if (arg1 == "тяжелая")
    {
        minWeight = 76;
        maxWeight = 150;
    }

}


void MainWindow::on_lineEdit_2_textChanged(const QString &arg1)
{
    searchLastName = arg1;
}


void MainWindow::on_spinBoxRowNumber_valueChanged(int arg1)
{
    rowNumber = arg1;
}


void MainWindow::on_pushButtonAdd_clicked()
{
    if (rowNumber > L.GetSize() + 1)
    {
        QMessageBox::information(this,"","Сюда добавить нельзя");
        return;
    }
    if (L.GetSize() == 15)
    {
        QMessageBox::information(this,"","Список полон");
        return;
    }

    if (country == "" || lastName == "" || name == "" || patronymic == "")
    {
        QMessageBox::information(this, "", "Заполнены не все поля");
        return;
    }

    Player play(lastName,name,patronymic,country,team,number,age,height,weight);

    L.Insert(rowNumber,play);

    TableClear();
    TableOut();

}

void MainWindow::on_pushButton_7_clicked()
{
    L.QSort(1, L.GetSize());
    TableClear();
    TableOut();
}


void MainWindow::on_comboBox_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Fiksiki")
        team = "Fiksiki";
    else if (arg1 == "O4kozavri")
        team = "O4kozavri";
    else if (arg1 == "Bulbashi")
        team = "Bulbashi";
}


void MainWindow::on_pushButton_2_clicked()
{
    if (rowNumber >L.GetSize())
    {
        QMessageBox::information(this,"","Изменение несуществующего элемента");
        return;
    }
    if (country == "" || lastName == "" || name == "" || patronymic == "")
    {
        QMessageBox::information(this, "", "Заполнены не все поля");
        return;
    }


    Player play(lastName,name,patronymic,country,team,number,age,height,weight);

    L.SetPlayerInNodeHuini(rowNumber, play);

    TableClear();
    TableOut();

}


void MainWindow::on_pushButton_3_clicked()
{
    if (rowNumber >L.GetSize())
    {
        QMessageBox::information(this,"","Изменение несуществующего элемента");
        return;
    }

    L.Del(rowNumber);

    TableClear();
    TableOut();

}


void MainWindow::on_pushButtonSave_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this, "","Список пуст");
        return;
    }

    fileName = QFileDialog::getSaveFileName(this,
            tr("Сохранить данные"), "",
            tr("Текст (*.txt);;All Files (*)"));

    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite))
    {
        QMessageBox::information(this, tr("невозможно открыть файл"),
        file.errorString());
        return;
    }
    QTextStream out(&file);

//    std::ofstream out;
//    out.open(fileName.toStdString());


//    if(!out.is_open())
//    {
//        QMessageBox::information(this, "","Файл не открылся");
//        return;
//    }

    for (int i = 1; i<=L.GetSize(); i++)
    {
        NodeHuini temp = L.GetNodeHuini(i);

        if (i != L.GetSize())
        {
            out << temp.play.get_country() << '\n';
            out << temp.play.get_team() << '\n';
            out << temp.play.get_lastName() << '\n';
            out << temp.play.get_name() << '\n';
            out << temp.play.get_patronymic() << '\n';
            out << temp.play.get_number() << '\n';
            out << temp.play.get_age() << '\n';
            out << temp.play.get_height() << '\n';
            out << temp.play.get_weight() << '\n';

        }
        else
        {
            out << temp.play.get_country() << '\n';
            out << temp.play.get_team() << '\n';
            out << temp.play.get_lastName() << '\n';
            out << temp.play.get_name() << '\n';
            out << temp.play.get_patronymic() << '\n';
            out << temp.play.get_number() << '\n';
            out << temp.play.get_age() << '\n';
            out << temp.play.get_height() << '\n';
            out << temp.play.get_weight();

        }
    }


    file.close();
}


void MainWindow::on_pushButtonSearch_2_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }
    TableClear();

    int row = 0;

    for (int i = 1; i<=L.GetSize();i++)
    {
        NodeHuini tempNode = L.GetNodeHuini(i);
        if (tempNode.play.get_lastName() == searchLastName)
        {
            TableOut(i,row);
            row++;
        }
    }
}


void MainWindow::on_pushButton_4_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }
    TableClear();

    int row = 0;

    for (int i = 1; i <= L.GetSize(); i++)
    {
        NodeHuini tempNode = L.GetNodeHuini(i);
        if (tempNode.play.get_weight()>= minWeight && tempNode.play.get_weight() <=maxWeight)
        {
            TableOut(i,row);
            row++;
        }
    }
}


void MainWindow::on_pushButton_5_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }

    Team fiksiki;
    Team o4kozavri;
    Team bulbashi;
    fiksiki.set_name("Fiksiki");
    o4kozavri.set_name("O4kozavri");
    bulbashi.set_name("Bulbashi");

    NodeHuini tempNode;
    for (int i = 1; i<= L.GetSize(); i++)
    {
        tempNode = L.GetNodeHuini(i);
        if (tempNode.play.get_team() == "Fiksiki")
        {
            fiksiki.addAgeHeight(tempNode.play.get_age(), tempNode.play.get_height());
        }
        else if (tempNode.play.get_team() == "O4kozavri")
        {
            o4kozavri.addAgeHeight(tempNode.play.get_age(), tempNode.play.get_height());
        }
        else
        {
            bulbashi.addAgeHeight(tempNode.play.get_age(), tempNode.play.get_height());
        }
    }

    if (fiksiki.get_avgHeight() >= searchHeight) QMessageBox::information(this,"Это не ошибка","В команде фиксики средний рост больше введенного вами");
    if (o4kozavri.get_avgHeight() >= searchHeight) QMessageBox::information(this,"Это не ошибка","В команде о4козавры средний рост больше введенного вами");
    if (bulbashi.get_avgHeight() > searchHeight) QMessageBox::information(this,"Это не ошибка","В команде бульбаши средний рост больше введенного вами");

}


void MainWindow::on_pushButton_6_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }

    Team fiksiki;
    Team o4kozavri;
    Team bulbashi;
    fiksiki.set_name("Fiksiki");
    o4kozavri.set_name("O4kozavri");
    bulbashi.set_name("Bulbashi");



    NodeHuini tempNode;
    for (int i = 1; i<= L.GetSize(); i++)
    {
        tempNode = L.GetNodeHuini(i);
        if (tempNode.play.get_team() == "Fiksiki")
        {
            fiksiki.addAgeHeight(tempNode.play.get_age(), tempNode.play.get_height());
        }
        else if (tempNode.play.get_team() == "O4kozavri")
        {
            o4kozavri.addAgeHeight(tempNode.play.get_age(), tempNode.play.get_height());
        }
        else
        {
            bulbashi.addAgeHeight(tempNode.play.get_age(), tempNode.play.get_height());
        }
    }

    if (fiksiki.get_avgAge() <= o4kozavri.get_avgAge() && fiksiki.get_avgAge() <= bulbashi.get_avgAge()) QMessageBox::information(this,"Это не ошибка", "Самая молодая команда - Фиксики");
    else if (o4kozavri.get_avgAge() <= fiksiki.get_avgAge() && o4kozavri.get_avgAge() <= bulbashi.get_avgAge()) QMessageBox::information(this,"Это не ошибка", "Самая молодая команда - О4козавры");
    else if (bulbashi.get_avgAge() <= fiksiki.get_avgAge() && bulbashi.get_avgAge() <= o4kozavri.get_avgAge()) QMessageBox::information(this,"Это не ошибка", "Самая молодая команда - Бульбаши");

}


void MainWindow::on_pushButtonLoad_clicked()
{

    fileName = QFileDialog::getOpenFileName(this, tr("Открыть текстовый файл"), "", tr("Текстовый файл (*.txt);;All Files (*)"));

    std::ifstream fin;
    fin.open(fileName.toStdString());

    if(!fin.is_open())
    {
        QMessageBox::information(this, "","Файл не открылся");
        return;
    }

    if (L.GetSize() != 0)L.DelAll();
    TableClear();

    std::string str;
    int numb = 0;
    NodeHuini tempNode;

    while(!fin.eof())
    {
        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод остановлен по причине наличия в файле русских символов");
            L.DelAll();
            return;
        }
        if (str == "" || str == "\n")
        {
            QMessageBox::information(this,"", "Встречена пустая строка");
            L.DelAll();
            return;
        }
        if (QString::fromStdString(str).size() > 20)
        {
            QMessageBox::information(this,"","Строка неподходящей длинны");
            L.DelAll();
            return;
        }
        tempNode.play.set_country(QString::fromStdString(str));


        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод остановлен по причине наличия в файле русских символов");
            L.DelAll();
            return;
        }
        if (str == "" || str == "\n")
        {
            QMessageBox::information(this,"", "Встречена пустая строка");
            L.DelAll();
            return;
        }
        if (QString::fromStdString(str).size() > 20)
        {
            QMessageBox::information(this,"","Строка неподходящей длинны");
            L.DelAll();
            return;
        }
        if (str != "Fiksiki" && str != "O4kozavri" && str != "Bulbashi")
        {
            QMessageBox::information(this, "", "Недействительная команда");
            return;
        }
        tempNode.play.set_team(QString::fromStdString(str));


        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод остановлен по причине наличия в файле русских символов");
            L.DelAll();
            return;
        }
        if (str == "" || str == "\n")
        {
            QMessageBox::information(this,"", "Встречена пустая строка");
            L.DelAll();
            return;
        }
        if (QString::fromStdString(str).size() > 20)
        {
            QMessageBox::information(this,"","Строка неподходящей длинны");
            L.DelAll();
            return;
        }
        tempNode.play.set_lastName(QString::fromStdString(str));


        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод остановлен по причине наличия в файле русских символов");
          L.DelAll();
            return;
         }
         if (str == "" || str == "\n")
        {
            QMessageBox::information(this,"", "Встречена пустая строка");
            L.DelAll();
            return;
        }
        if (QString::fromStdString(str).size() > 20)
        {
            QMessageBox::information(this,"","Строка неподходящей длинны");
            L.DelAll();
            return;
        }
        tempNode.play.set_name(QString::fromStdString(str));


        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод остановлен по причине наличия в файле русских символов");
          L.DelAll();
            return;
         }
         if (str == "" || str == "\n")
        {
            QMessageBox::information(this,"", "Встречена пустая строка");
            L.DelAll();
            return;
        }
        if (QString::fromStdString(str).size() > 20)
        {
            QMessageBox::information(this,"","Строка неподходящей длинны");
            L.DelAll();
            return;
        }
        tempNode.play.set_patronymic(QString::fromStdString(str));


        fin >> numb;
        if(fin.fail())
        {
            QMessageBox::information(this,"","При вводе чисел произошла ошибка");
            L.DelAll();
            return;
        }
        if (numb <1 || numb > 10)
        {
            QMessageBox::information(this,"","Недопустимое значение для номера игрока");
            L.DelAll();
            return;
        }
        tempNode.play.set_number(numb);


        fin >> numb;
        if(fin.fail())
        {
            QMessageBox::information(this,"","При вводе чисел произошла ошибка");
            L.DelAll();
            return;
        }
        if(numb < 18 || numb > 70)
        {
            QMessageBox::information(this,"","Недопустимый возраст");
            L.DelAll();
            return;
        }
        tempNode.play.set_age(numb);


        fin >> numb;
        if(fin.fail())
        {
            QMessageBox::information(this,"","При вводе чисел произошла ошибка");
            L.DelAll();
            return;
        }
        if (numb < 150 || numb > 210)
        {
            QMessageBox::information(this,"","Недопустимое значение роста");
            L.DelAll();
            return;
        }
        tempNode.play.set_height(numb);

        fin >> numb;
        if(fin.fail())
        {
            QMessageBox::information(this,"","При вводе чисел произошла ошибка");
            L.DelAll();
            return;
        }
        if (numb < 40 || numb >150)
        {
            QMessageBox::information(this,"","Недопустимое значение веса");
            L.DelAll();
            return;
        }
        tempNode.play.set_weight(numb);
        getline(fin, str);

        L.Insert(L.GetSize() + 1,tempNode.play);

    }
    TableOut();
}
