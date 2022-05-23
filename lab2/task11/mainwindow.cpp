#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    lastName = "";
    name = "";
    patronymic = "";
    university = "";
    grades = new int [3];
    grades[0] = 1;
    grades[1] = 1;
    grades[2] = 1;
    exam = 0;

    averageSearch = 1;
    pos = 1;
    elementNumber = 1;
    numbPlaces = 15;
    QString fileName = 0;
    success = 0;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::TableOut()
{
    Node *temp;
    if (L.GetSize() != 0)
        temp = L.GetNode(1);
    else return;
    for(int i = 1; i<=L.GetSize();i++)
    {



        QTableWidgetItem *item1 = new QTableWidgetItem(temp->abiturient.get_lastName());
        ui->tableWidget->setItem(i-1,0,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem(temp->abiturient.get_name());
        ui->tableWidget->setItem(i-1,1,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem(temp->abiturient.get_patronymic());
        ui->tableWidget->setItem(i-1,2,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem(temp->abiturient.get_university());
        ui->tableWidget->setItem(i-1,3,item4);

        int *bufgr = temp->abiturient.get_grades();
        QString str = QString::number(bufgr[0]) + ", " +QString::number(bufgr[1])+ ", " +QString::number(bufgr[2]);
        QTableWidgetItem *item5 = new QTableWidgetItem(str);
        ui->tableWidget->setItem(i-1,4,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(temp->abiturient.get_average()));
        ui->tableWidget->setItem(i-1,5,item6);

        QTableWidgetItem *item7 = new QTableWidgetItem;
        if (temp->abiturient.get_exam() != 0) item7->setText("был");
        else item7->setText("не был");
        ui->tableWidget->setItem(i-1,6,item7);

        if (temp->next == 0)
            break;
        temp = temp->next;
    }
}

void MainWindow::TableOut(int i)
{
    Node *temp;
    if (L.GetSize() != 0)
        temp = L.HeadOrEnd(i);
    else return;

    //если с конца
    if (temp->next == 0)
    {
        int counter =L.GetSize();
        while (counter > i)
        {
            temp = temp->prev;
            counter--;
        }
    }
    //если с начала
    else
    {
        int counter = 0;
        while (counter < i)
        {
            temp= temp->next;
            counter++;
        }
    }

    QTableWidgetItem *item1 = new QTableWidgetItem(temp->abiturient.get_lastName());
    ui->tableWidget->setItem(0,0,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(temp->abiturient.get_name());
    ui->tableWidget->setItem(0,1,item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(temp->abiturient.get_patronymic());
    ui->tableWidget->setItem(0,2,item3);

    QTableWidgetItem *item4 = new QTableWidgetItem(temp->abiturient.get_university());
    ui->tableWidget->setItem(0,3,item4);

    int *bufgr = temp->abiturient.get_grades();
    QString str = QString::number(bufgr[0]) + ", " +QString::number(bufgr[1])+ ", " +QString::number(bufgr[2]);
    QTableWidgetItem *item5 = new QTableWidgetItem(str);
    ui->tableWidget->setItem(0,4,item5);

    QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(temp->abiturient.get_average()));
    ui->tableWidget->setItem(0,5,item6);

    QTableWidgetItem *item7;
    if (temp->abiturient.get_exam()) item7 = new QTableWidgetItem("был");
    else item7 = new QTableWidgetItem("не был");
    ui->tableWidget->setItem(0,6,item7);
}

void MainWindow::TableOut(int i, int g)
{
    Node *temp;
    if (L.GetSize() != 0)
        temp = L.HeadOrEnd(i);
    else return;

    //если с конца
    if (temp->next == 0)
    {
        int counter =L.GetSize();
        while (counter > i)
        {
            temp = temp->prev;
            counter--;
        }
    }
    //если с начала
    else
    {
        int counter = 0;
        while (counter < i)
        {
            temp= temp->next;
            counter++;
        }
    }

    QTableWidgetItem *item1 = new QTableWidgetItem(temp->abiturient.get_lastName());
    ui->tableWidget->setItem(g,0,item1);

    QTableWidgetItem *item2 = new QTableWidgetItem(temp->abiturient.get_name());
    ui->tableWidget->setItem(g,1,item2);

    QTableWidgetItem *item3 = new QTableWidgetItem(temp->abiturient.get_patronymic());
    ui->tableWidget->setItem(g,2,item3);

    QTableWidgetItem *item4 = new QTableWidgetItem(temp->abiturient.get_university());
    ui->tableWidget->setItem(g,3,item4);

    int *bufgr = temp->abiturient.get_grades();
    QString str = QString::number(bufgr[0]) + ", " +QString::number(bufgr[1])+ ", " +QString::number(bufgr[2]);
    QTableWidgetItem *item5 = new QTableWidgetItem(str);
    ui->tableWidget->setItem(g,4,item5);

    QTableWidgetItem *item6 = new QTableWidgetItem(QString::number(temp->abiturient.get_average()));
    ui->tableWidget->setItem(g,5,item6);

    QTableWidgetItem *item7;
    if (temp->abiturient.get_exam()) item7 = new QTableWidgetItem("был");
    else item7 = new QTableWidgetItem("не был");
    ui->tableWidget->setItem(g,6,item7);
}

void MainWindow::TableClear()
{
    for(int i = 1; i<=15;i++)
    {

        for (int j = 0; j<=6;j++)
        {
        QTableWidgetItem *item1 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item1);

        QTableWidgetItem *item2 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item2);

        QTableWidgetItem *item3 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item3);

        QTableWidgetItem *item4 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item4);

        QTableWidgetItem *item5 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item5);

        QTableWidgetItem *item6 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item6);

        QTableWidgetItem *item7 = new QTableWidgetItem("");
        ui->tableWidget->setItem(i-1,j,item7);
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

void MainWindow::on_lineEditLastName_textChanged(const QString &arg1)
{
    if (isRus(arg1))
    {
        ui->lineEditLastName->setText("");
        return;
    }
    lastName = arg1;
}


void MainWindow::on_lineEditName_textChanged(const QString &arg1)
{
    if (isRus(arg1))
    {
        ui->lineEditName->setText("");
        return;
    }
    name = arg1;
}


void MainWindow::on_lineEditPatronymic_textChanged(const QString &arg1)
{
    if (isRus(arg1))
    {
        ui->lineEditPatronymic->setText("");
        return;
    }

    patronymic = arg1;
}


void MainWindow::on_lineEditUniversity_textChanged(const QString &arg1)
{
    if (isRus(arg1))
    {
        ui->lineEditUniversity->setText("");
        return;
    }

    university = arg1;
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    grades[0] = arg1;
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    grades[1] = arg1;
}


void MainWindow::on_spinBox_3_valueChanged(int arg1)
{
    grades[2] = arg1;
}


void MainWindow::on_radioButtonExam_clicked()
{
    if (exam == 0) exam = 1;
    else exam = 0;
}


void MainWindow::on_spinBox_4_valueChanged(int arg1)
{
    elementNumber = arg1;
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    averageSearch = arg1;
}


void MainWindow::on_spinBoxRowNumber_valueChanged(int arg1)
{
    pos = arg1;
}


void MainWindow::on_pushButtonAdd_clicked()
{
    if (pos > L.GetSize() +1)
    {
        QMessageBox::information(this, "", "Сюда добавлять нельзя");
        return;
    }
    if (L.GetSize() == 15)
    {
        QMessageBox::information(this,"","Больше низя");
        return;
    }
    if (lastName == "" || name == "" || patronymic == "" || university == "")
    {
        QMessageBox::critical(this,"","Невведено какое то поле");
        return;
    }


    abitura a(lastName,name,patronymic,grades,university,exam);

    L.Insert(pos,a);

    TableClear();
    TableOut();


}


void MainWindow::on_pushButton_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }
    TableClear();
    TableOut();
}


void MainWindow::on_pushButtonSearch_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }
    TableClear();
    TableOut(elementNumber);
}


void MainWindow::on_pushButton_2_clicked()
{
    if (pos > L.GetSize())
    {
        QMessageBox::information(this,"","Нельзя изменить этот элемент");
        return;
    }

    if (lastName == "" || name == "" || patronymic == "" || university == "")
    {
        QMessageBox::critical(this,"","Невведено какое то поле");
        return;
    }

    Node *temp = L.HeadOrEnd(pos);

    if (temp->next == 0)
    {
        int counter = L.GetSize();
        while (counter > pos)
        {
            temp = temp->prev;
            counter--;
        }
    }
    else
    {   int counter = 1;
        while (counter <pos)
        {
            temp = temp->next;
            counter++;
        }
    }

    temp->abiturient.set_lastName(lastName);
    temp->abiturient.set_name(name);
    temp->abiturient.set_patronymic(patronymic);
    temp->abiturient.set_university(university);
    temp->abiturient.set_grades(grades);
    temp->abiturient.set_average();
    temp->abiturient.set_exam(exam);

    TableOut();

}


void MainWindow::on_pushButton_3_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }
    if (pos > L.GetSize())
    {
        QMessageBox::information(this,"","Удаление несуществующего элемента");
        return;
    }

    L.Del(pos);

    TableClear();
    TableOut();
}


void MainWindow::on_pushButtonSort_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }

    TableClear();
    Node *temp = L.HeadOrEnd(0);
    int counter = 1;
    int g = 0;
    while (true)
    {
        if (temp->abiturient.get_average() >= averageSearch)
        {
            TableOut(counter,g);
            g++;
        }



        if (temp->next == 0)
            break;
        temp = temp->next;
        counter++;
    }
}


void MainWindow::on_pushButtonSave_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
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

    Node *temp = L.HeadOrEnd(0);
    while (true)
    {
        if (temp->next != 0)
        {
            out << temp->abiturient.get_lastName() << "\n";
            out << temp->abiturient.get_name() << "\n";
            out << temp->abiturient.get_patronymic() << "\n";
            out << temp->abiturient.get_university()<< "\n";
            out << temp->abiturient.get_grades()[0] << " "
                << temp->abiturient.get_grades()[1] << " "
                << temp->abiturient.get_grades()[2] << "\n";
            out << temp->abiturient.get_exam()<<"\n";

        }
        else
        {
            out << temp->abiturient.get_lastName() << "\n";
            out << temp->abiturient.get_name() << "\n";
            out << temp->abiturient.get_patronymic() << "\n";
            out << temp->abiturient.get_university()<< "\n";
            out << temp->abiturient.get_grades()[0] << " "
                << temp->abiturient.get_grades()[1] << " "
                << temp->abiturient.get_grades()[2] << "\n";
            out << temp->abiturient.get_exam();
            break;
        }
        temp = temp->next;
    }
    file.close();
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

    abitura abiturient;
    if (L.GetSize() != 0)
        L.DelAll();

    std::string str;
    int *array = new int[3];


    while(!fin.eof())
    {
        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод отсановлен по причине наличия в файле русских символов");
            L.DelAll();
            TableClear();
            return;
        }
        if (str == "" || str == "\n")
        {
            QMessageBox::information(this,"", "Встречена пустая строка");
            L.DelAll();
            TableClear();
            return;
        }
        if (QString::fromStdString(str).size() > 20)
        {
            QMessageBox::information(this,"","Строка неподходящей длинны");
            L.DelAll();
            return;
        }
        abiturient.set_lastName(QString::fromStdString(str));


        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод отсановлен по причине наличия в файле русских символов");
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
        abiturient.set_name(QString::fromStdString(str));

        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод отсановлен по причине наличия в файле русских символов");
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
        abiturient.set_patronymic(QString::fromStdString(str));


        getline(fin, str);
        if (isRus(QString::fromStdString(str)))
        {
            QMessageBox::information(this,"","Ввод отсановлен по причине наличия в файле русских символов");
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
        abiturient.set_university(QString::fromStdString(str));


        fin >> array[0] >> array[1] >> array[2];
        if(fin.fail())
        {
            QMessageBox::information(this,"","При вводе чисел произошла ошибка");
            L.DelAll();
            return;
        }
        abiturient.set_grades(array);
        abiturient.set_average();



        fin  >> array[0];
        if(fin.fail())
        {
            QMessageBox::information(this,"","При вводе переменной экзамена произошла ошибка");
            L.DelAll();
            return;
        }
        if (array[0] != 1 && array[0] != 0)
        {
            QMessageBox:: information(this, "", "Введено некорректное значение");
            L.DelAll();
            return;
        }
        abiturient.set_exam(array[0]);

        L.AddTail(abiturient);

        getline(fin,str);



    }

    success = 1;
    TableOut();
    delete[] array;
}


/*void MainWindow::on_pushButtonSave_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this,"","Список пуст");
        return;
    }
    fileName = QFileDialog::getSaveFileName(this,
            tr("Сохранить данные"), "",
            tr("Текст (*.txt);;All Files (*)"));

    if (fileName.isEmpty()) return;

//    QFile file(fileName);
//    if (!file.open(QIODevice::ReadWrite))
//    {
//        QMessageBox::information(this, tr("невозможно открыть файл"),
//        file.errorString());
//        return;
//    }
//    QTextStream out(&file);

    std::ofstream out;
    out.open(fileName.toStdString());


    if(!out.is_open())
    {
        QMessageBox::information(this, "","Файл не открылся");
        return;
    }

    Node *temp = L.HeadOrEnd(0);
    while (true)
    {
        out << temp->abiturient.get_lastName() << "\n";
        out << temp->abiturient.get_name() << "\n";
        out << temp->abiturient.get_patronymic() << "\n";
        out << temp->abiturient.get_university()<< "\n";
        out << temp->abiturient.get_grades()[0] << " "
            << temp->abiturient.get_grades()[1] << " "
            << temp->abiturient.get_grades()[2] << "\n";
        out << temp->abiturient.get_exam() << "\n";

        if (temp->next == 0)
            break;
        temp = temp->next;
    }
    file.close();
}
*/


void MainWindow::on_pushButton_4_clicked()
{
    if (L.GetSize() == 0)
    {
        QMessageBox::information(this, "","Список пуст");
        return;
    }
    TableClear();
    L.sortNum(1,L.GetSize());
    TableOut();
}

