#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <stack>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    dA = dB = dC = dE = dD = 0;
    num = 1;

    size = 0;

    primer = "";
    opz = "";

    ui->setupUi(this);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::priorBank(char v)
{
    if (v == '(') return 1;
    if (v == '+' || v == '-') return 2;
    if (v == '*' || v == '/') return 3;
    return -125;
}

bool MainWindow::operation(char c)
{
    if( c == '+' || c == '-' || c == '*' || c == '/') return true;
    return false;
}

bool MainWindow::bukva(char c)
{
    if(c >= 'a' && c <= 'z') return true;
    return false;
}

void MainWindow::Polska(std::string prim, std::string &opz)
{
    //qDebug() <<"PolskaStart " <<QString::fromStdString(prim);
    std::stack <char> S;
    int i = 0;

    //проверка примера
    while (prim[i] != '\0') {

        //проверка на букву
        //если буква - переносим в ответ
        if (bukva(prim[i]))
        {
//            opz+=" ";
//            opz[j] = prim[i];
//            j++;
            opz+=prim[i];
        }

        //если не буква - проверка на бинарный оператор
        else if (operation(prim[i]))
        {
            //если стек пуст или приоритет операции в верхнем элементе в стека
            //меньше чем данный приоритет - заносим в стек бинарный оператор
            if (S.empty() || priorBank(S.top()) < priorBank(prim[i]))S.push(prim[i]);

            else
            {
                //пока стек не пуст и приоритет оператора в верхнем элементе стека
                //больше чем данный приоритет - переносим операторы в ответ
                while (!S.empty() && (priorBank(S.top()) >= priorBank(prim[i])))
                {
//                    opz+=" ";
//                    opz[j] = S.top();
//                    j++;
                    opz+=S.top();
                    S.pop();
                }
                S.push(prim[i]);
            }
        }
        else if (prim[i] == '(')
        {
            S.push(prim[i]);
        }
        else if (prim[i] == ')')
        {
            if (S.empty() || S.top() == '(')
            {
                return;
            }
            else
            {
                while (S.top() != '(')
                {
                    //opz+=" ";
                    //opz[j] = S.top();
                    //j++;

                    opz+=S.top();
                    S.pop();
                }
            }
            S.pop();
        }
        i++;
    }



    while (!S.empty())
    {
        if (S.top() == '(')
        {
            return;
        }
        else
        {
            //opz+=" ";
            //opz[j] = S.top();
            //j++;

            opz+=S.top();
            S.pop();
        }
    }
    //qDebug() <<"Polska " <<QString::fromStdString(opz);
}

double MainWindow::Answer(std::string opz)
{
//    qDebug() <<"Answer " <<QString::fromStdString(opz);

    int j = 0;//счетчик
    double r1 = 0, r2 = 0;//операнды
    double c = 0;// временная переменная для внесения значения в операнд
    Stack S;//стек с операндами
    while (opz[j] != '\0')
        {
            if (opz[j] >= 'a' && opz[j] <= 'z')
            {
                if(opz[j] == 'a') c = dA;
                else if(opz[j] == 'b') c = dB;
                else if(opz[j] == 'c') c = dC;
                else if(opz[j] == 'd') c = dD;
                else c = dE;
                S.Push(c);
            }
            else if (operation(opz[j]))
            {
                r1 = S.Top();
                S.Pop();
                r2 = S.Top();
                S.Pop();
                switch (opz[j])
                {
                case '+':
                    S.Push(r2 + r1);
                    break;
                case '-':
                    S.Push(r2 - r1);
                    break;
                case '*':
                    S.Push(r2 * r1);
                    break;
                case '/':
                    S.Push(r2 / r1);
                    break;
                }
            }
            j++;
        }
    return (S.Top());
}

void MainWindow::read()
{
    std::ifstream fin;
    int i = 0;
    std::string rPrim;
    fin.open("task.txt");
    if (!fin.is_open())
    {
        return;
    }
    while (i < 15)
    {
        fin >> rPrim;
        QTableWidgetItem *item;
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(rPrim));
        ui->tableWidget->setItem(i, 0, item);
        i++;
        size++;
    }
}

bool MainWindow::checkPrim(std::string prim)
{
    if(prim.length() == 0) return 0;


    std::string time = "";//временная строка
    int k = 0;//переменная отвечающая за баланс

    //проверка на скобочки методом баланса(смотри лк по оаип)
    for(int i = 0; i < prim.length(); i++)
    {
        if(prim[i] == '(') k++;
        else if(prim[i] == ')') k--;
        else
        {
//            time += " ";
//            time[j] = prim[i];
            time += prim[i];
        }
        if(k < 0) return 0;
    }
    if(k != 0) return 0;



    for(int i = 0; i < time.length(); i++)
        //если i-ый элемент не является буквой от а до е и
        //не является символом бинарной операции
        if((time[i] < 'a' || time[i] > 'e') && !operation(time[i])) return 0;


    for(int i = 0; i < time.length() - 1; i++)
    {
        //если две буквы идут подряд
        if(bukva(time[i]) && bukva(time[i + 1])) return 0;
        //если два символа бинарнойоперации идут подряд
        if(operation(time[i]) && operation(time[i + 1])) return 0;
    }
    return 1;
}

void MainWindow::on_spinBox_Num_valueChanged(int arg1)
{
    num = arg1;
}

void MainWindow::on_pushButton_Read_clicked()
{
    read();
}

void MainWindow::on_doubleSpinBox_a_valueChanged(double arg1)
{
    dA = arg1;
}

void MainWindow::on_doubleSpinBox_b_valueChanged(double arg1)
{
    dB = arg1;
}

void MainWindow::on_doubleSpinBox_c_valueChanged(double arg1)
{
    dC = arg1;
}

void MainWindow::on_doubleSpinBox_d_valueChanged(double arg1)
{
    dD = arg1;
}

void MainWindow::on_doubleSpinBox_e_valueChanged(double arg1)
{
    dE = arg1;
}

void MainWindow::on_pushButton_Answer_clicked()
{
    if(num > size)
    {
        QMessageBox::information(this, "Опаа", "Примера нет");
        return;
    }
    QString time;
    primer = ui->tableWidget->item(num - 1,0)->text().toStdString();
    opz = "";
//    qDebug() <<"PushAnswer " <<QString::fromStdString(primer);
    Polska(primer, opz);
    QTableWidgetItem *item;
    item = new QTableWidgetItem;
    time.setNum(dA);
    item->setText(time);
    ui->tableWidget->setItem(num - 1, 1, item);
    item = new QTableWidgetItem;
    time.setNum(dB);
    item->setText(time);
    ui->tableWidget->setItem(num - 1, 2, item);
    item = new QTableWidgetItem;
    time.setNum(dC);
    item->setText(time);
    ui->tableWidget->setItem(num - 1, 3, item);
    item = new QTableWidgetItem;
    time.setNum(dD);
    item->setText(time);
    ui->tableWidget->setItem(num - 1, 4, item);
    item = new QTableWidgetItem;
    time.setNum(dE);
    item->setText(time);
    ui->tableWidget->setItem(num - 1, 5, item);
    item = new QTableWidgetItem;
    item->setText(QString::fromStdString(opz));
    ui->tableWidget->setItem(num - 1, 6, item);
    item = new QTableWidgetItem;
    time.setNum(Answer(opz));
    item->setText(time);
    ui->tableWidget->setItem(num - 1, 7, item);
}

void MainWindow::on_lineEdit_NewPrim_textEdited(const QString &arg1)
{
    bufprim = arg1.toStdString();
}

void MainWindow::on_pushButton_Add_clicked()
{
    if(!checkPrim(bufprim))
        QMessageBox::information(this, "Опаа", "Некорректный примерчик");
    else
    {
        QTableWidgetItem *item;
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(bufprim));
        ui->tableWidget->setItem(size, 0, item);
        size++;
    }
}

void MainWindow::on_pushButton_AnswerAll_clicked()
{
    for (int i = 1; i<= size; i++)
    {
        QString time;
        primer = ui->tableWidget->item(i - 1,0)->text().toStdString();
        opz = "";

        Polska(primer, opz);
        QTableWidgetItem *item;
        item = new QTableWidgetItem;
        time.setNum(dA);
        item->setText(time);
        ui->tableWidget->setItem(i - 1, 1, item);
        item = new QTableWidgetItem;
        time.setNum(dB);
        item->setText(time);
        ui->tableWidget->setItem(i - 1, 2, item);
        item = new QTableWidgetItem;
        time.setNum(dC);
        item->setText(time);
        ui->tableWidget->setItem(i - 1, 3, item);
        item = new QTableWidgetItem;
        time.setNum(dD);
        item->setText(time);
        ui->tableWidget->setItem(i - 1, 4, item);
        item = new QTableWidgetItem;
        time.setNum(dE);
        item->setText(time);
        ui->tableWidget->setItem(i - 1, 5, item);
        item = new QTableWidgetItem;
        item->setText(QString::fromStdString(opz));
        ui->tableWidget->setItem(i - 1, 6, item);
        item = new QTableWidgetItem;
        time.setNum(Answer(opz));
        item->setText(time);
        ui->tableWidget->setItem(i - 1, 7, item);
    }
}


