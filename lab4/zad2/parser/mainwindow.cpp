#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <regex>
#include <QFileDialog>
#include <QMessageBox>
#pragma warning(disable : 4996)
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    in_table = 0, in_edit = 0, in_fail = 0;
    coordinate = 1;
    balance = 0;
    classSize = 0;
    structSize = 0;
    massSize = 0;
    sizeName = 0;
    dput = "C:/Users/ASUS/Desktop/forParser.cpp";
    NameOfFunc = new std::pair<String, int>[sizeName];
    ui->tableWidget->setColumnWidth(5, 60);
    ui->tableWidget->setColumnWidth(0, 60);
    ui->tableWidget->setColumnWidth(6, 120);
    ui->tableEdit->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableLogic->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::read_code()     //считывает файл .срр и сразу каждую строку отправляет на проверку
{
    Text = "\0";
    testik = "\0";
    String str;
    char tim[100] = { };
    QString Tim = "\0";
    std::ifstream fin;
    fin.open(dput.toStdString());
    if (!fin.is_open())
    {
        return;
    }
    while (!fin.eof())
    {
        ////qDebug() <<"read";
        fin.getline(tim, 100, '\n');
        testik += tim;
        testik = testik + '\n';
        str = tim;
        checkStr(str);
        Tim.fromStdString(tim);
        Text += "\n" + Tim;
        coordinate++;
    }
    //qDebug() <<balance;
    ui->textEdit->setText(QString::fromLatin1(testik.c_str()));

    ui->label_class->setNum(classSize);
    ui->label_struct->setNum(structSize);
    ui->label_mass->setNum(massSize);
    OutFunc();
}

void MainWindow::checkStr(String str) //проверка регулярками строки
{
    //если пустая строка
    const std::regex empty(R"(\s*)");
    //баланс фигурных скобок(для глубины и локальное или глобальное)
    const std::regex balOpen(R"(\s*\{)");
    const std::regex balClose(R"(\s*\};?)");
    //Если переменная
    const std::regex if_type("\\s*((const )?(long |short |signed |unsigned )?(long |short |signed |unsigned )?(int|double|char|bool|int\\*|double\\*|char\\*|bool\\*)\\s(.+;)$)");
    //Если функция
    const std::regex if_func("\\s*((const )?(long |short |signed |unsigned )?(long |short |signed |unsigned )?(void|int|double|char|bool|int\\*|double\\*|char\\*|bool\\*)?\\s?(.+)\\((.+)?\\)$)");
    //если клсасс
    const std::regex if_class("\\s*class.*");
    //если структура
    const std::regex if_struct("\\s*struct.*");
    //Изменение(типа ++, --)
    const std::regex edit1("^\\s*([\\d\\w\\[\\]\\*\\&_\\(\\)]+(\\+\\+|--));$");
    //Изменение(типа +=, -=, *=, /=, =)
    const std::regex edit2("^\\s*([\\d\\w\\[\\]\\*\\&_\\(\\)]+( = | \\+= | \\*= | /= | -= )[\\d\\w\\[\\]\\*\\&_\\(\\)]+);$");
    //отдельно for
    const std::regex if_for("^\\s*for\\s?\\((.*;)\\s?(.*);\\s?(.*)\\)$");
    //логические ошибки(while(true/false), if(true/false), goto?)))
    const std::regex lol("\\s*((while|if)\\s?\\((true|false)\\);?)$");

    std::cmatch result;

    if(std::regex_match(str.c_str(), empty))
        return;
    else if(std::regex_match(str.c_str(), balOpen))
        balance++;
    else if(std::regex_match(str.c_str(), balClose))
        balance--;
    else if(std::regex_match(str.c_str(), result, if_for))
        IfFor(result);
    else if(std::regex_match(str.c_str(), result, lol))
        LolOut(result);
    else if(std::regex_match(str.c_str(), result, if_func))
        if_function(result);
    else if(std::regex_match(str.c_str(), result, if_type))
        if_type_data(result);
    else if(std::regex_match(str.c_str(), if_class))
        classSize++;
    else if(std::regex_match(str.c_str(), if_struct))
        structSize++;
    else if(std::regex_match(str.c_str(), result, edit1))
        outEdit(result);
    else if(std::regex_match(str.c_str(), result, edit2))
        outEdit(result);
}

void MainWindow::if_type_data(std::cmatch result)   //если объявление переменной
{
    //qDebug() <<"if type";
    String type, name, init;
    std::cmatch puk;
    //Нужна для работы с указателями
    //С указателями такая система: всегда звездочка идет к типу, а имя оставляем без нее
    bool pointer = false;
    QTableWidgetItem *item;
    //неинициализированная переменная
    const std::regex noinit("\\s?(\\*?[\\w\\d]+(\\[\\d+\\])?)[,;]");
    //инициализированная переменная(через равно или круглые скобки)
    const std::regex inint("(\\*?[\\w\\d]+(\\[\\d+\\])?)( = |\\()[\\{']?([\\\\\"\\w\\d\\s=;,.\\+]+)'?[\\)\\}\"]?[,;]");
    //Защита от функции(в инициализации не могут быть объявленны переменные)
    const std::regex nonfunc("int|double|char|bool|int\\*|double\\*|char\\*|bool\\*");
    //Защита от защиты(если, например, объявляют строку, в иницилиализации есть тип данных)
    const std::regex nonfunc2("\\\\\"");

    for (int i = 2; i < result.size(); i++)
    {
        ////qDebug() << i << " result " << result[i].str().c_str() <<"\n";
        if (result[i].str().size() == 0) continue;
        if (result[i].str() == "const " || result[i].str() == "signed " || result[i].str() == "unsigned " || result[i].str() == "short " || result[i].str() == "long ")
        {
            //проверяем на модификатор и добавляем его в тип переменной
            type += result[i].str().c_str();
        }
        else if (result[i].str() == "int" || result[i].str() == "double" || result[i].str() == "char" || result[i].str() == "bool")
        {
            //проверяем на сам тип
            type += result[i].str().c_str();
            pointer = false;
            //cout << type;
        }
        else if (result[i].str() == "int*" || result[i].str() == "double*" || result[i].str() == "char*" || result[i].str() == "bool*")
        {
            //Если в типе есть звездочка, то мы ее удаляем(т.к. добавим позже)
            //и булевую переменную делаем тру
            type += result[i].str().c_str();
            type.erase(type.Lenght() - 1, 1);
            pointer = true;
            //qDebug() <<"bool* " <<QString::fromLatin1(type.c_str()) <<" pointer " <<pointer;
            //cout << type;
        }
        else
        {
            //Здесь мы работаем с объявлением переменных
            //qDebug() <<"bool* " <<QString::fromLatin1(type.c_str()) <<" pointer " <<pointer;
            String pak = result[i].str().c_str();
            //qDebug() <<"pak " <<pak.c_str();
            //вначале ищем инициализированные переменные(!!тут прикол, что максимум 5 найдет)))
            for (int h = 0; h < 5; h++)
            {
                if (regex_search(pak.c_str(), puk, inint))
                {
                    name = puk[1].str().c_str();
                    init = puk[4].str().c_str();
                    if (regex_search(init.c_str(), nonfunc) && !regex_search(init.c_str(), nonfunc2))
                    {
                        return;
                    }
                    //если в имени звездочка, то мы ее убираем и делаем булевую тру
                    if(name[0] == '*')
                    {
                        pointer = true;
                        name.erase(0, 1);
                        //qDebug() <<"2bool* " <<QString::fromLatin1(type.c_str());
                    }
                    //Здесь вывод всего, что нужно в таблицу
                    item = new QTableWidgetItem;
                    if(pointer)
                        item->setText("указатель");
                    else
                        item->setText("Переменная");
                    if(name[name.Lenght() - 1] == ']')
                    {
                        item->setText("Массив");
                        massSize++;
                    }
                    ui->tableWidget->setItem(in_table, 1, item);
                    item = new QTableWidgetItem;
                    QString a;
                    a.setNum(coordinate);
                    item->setText(a);
                    ui->tableWidget->setItem(in_table, 0, item);
                    item = new QTableWidgetItem;
                    a.setNum(balance);
                    item->setText(a);
                    ui->tableWidget->setItem(in_table, 5, item);
                    item = new QTableWidgetItem;
                    //qDebug() <<"bool* " <<QString::fromLatin1(type.c_str()) <<" pointer " <<pointer;
                    //Если указатель, то вставляем в конец типа звездочку
                    if(pointer)
                    {
                        type.insert(type.Lenght(), "*");
                        item->setText(QString::fromLatin1(type.c_str()));
                        //qDebug() <<"3bool* " <<QString::fromLatin1(type.c_str());
                    }
                    else
                        item->setText(QString::fromLatin1(type.c_str()));
                    ui->tableWidget->setItem(in_table, 2, item);
                    item = new QTableWidgetItem;
                    item->setText(QString::fromLatin1(name.c_str()));
                    ui->tableWidget->setItem(in_table, 3, item);
                    item = new QTableWidgetItem;
                    item->setText(QString::fromLatin1(init.c_str()));
                    ui->tableWidget->setItem(in_table, 4, item);
                    in_table++;
                    //Удаляем звездочку, если добавляли
                    if(pointer)
                    {
                        type.erase(type.Lenght() - 1, 1);
                        pointer = false;
                        //qDebug() <<"4bool* " <<QString::fromLatin1(type.c_str());
                    }


                    //cout << type << " " << name << " " << init << "\n";
                    ////qDebug() <<
                    //bool* k, g,  *vcv, xcv;


                    //Т.к. поиск инициализированной переменной находит каждый раз первую
                    //подходящую, которую не убирает, из-за чего каждый раз находили бы
                    //одно и то же
                    //Так что надо будет убирать то, что просмотрели
                    if (puk[2] == '(')
                    {
                        ////qDebug() <<"if ( " <<pak[name.Lenght()];
                        if(pak[name.Lenght() + init.Lenght() + 2] == ';')
                            pak.erase(puk.position(), name.Lenght() + init.Lenght() + 3);
                        else
                         pak.erase(puk.position(), name.Lenght() + init.Lenght() + 4);
                    }
                    else
                    {
                        ////qDebug() <<"if no ( " <<pak[name.Lenght()];
                        if(pak[name.Lenght() + 3 + init.Lenght()] == ';')
                            pak.erase(puk.position(), name.Lenght() + 3 + init.Lenght() + 1);
                        else
                           pak.erase(puk.position(), name.Lenght() + 3 + init.Lenght() + 2);
                    }
                }
            }
            //Аналогично ищем неинициализированные
            for (int h = 0; h < 5; h++)
            {

                if (regex_search(pak.c_str(), puk, noinit))
                {
                    name = puk[1].str().c_str();
                    if(name[0] == '*')
                    {
                        pointer = true;
                        name.erase(0, 1);
                        ////qDebug() <<"Name " <<QString::fromStdString(name);
                    }
                    item = new QTableWidgetItem;
                    if(pointer)
                        item->setText("указатель");
                    else
                        item->setText("Переменная");
                    if(name[name.Lenght() - 1] == ']')
                    {
                        item->setText("Массив");
                        massSize++;
                    }
                    ui->tableWidget->setItem(in_table, 1, item);
                    item = new QTableWidgetItem;
                    QString a;
                    a.setNum(coordinate);
                    item->setText(a);
                    ui->tableWidget->setItem(in_table, 0, item);
                    item = new QTableWidgetItem;
                    a.setNum(balance);
                    item->setText(a);
                    ui->tableWidget->setItem(in_table, 5, item);
                    item = new QTableWidgetItem;
                    //qDebug() <<"12bool* " <<QString::fromLatin1(type.c_str());
                    if(pointer)
                    {
                        type.insert(type.Lenght(), "*");
                        item->setText(QString::fromLatin1(type.c_str()));
                    }
                    else
                        item->setText(QString::fromLatin1(type.c_str()));
                    ui->tableWidget->setItem(in_table, 2, item);
                    item = new QTableWidgetItem;
                    item->setText(QString::fromLatin1(name.c_str()));
                    ui->tableWidget->setItem(in_table, 3, item);
                    in_table++;
                    //qDebug() <<"14bool* " <<QString::fromLatin1(type.c_str());
                    if(pointer)
                    {
                        type.erase(type.Lenght() - 1, 1);
                        pointer = false;
                    }

                    //cout << type << " " << name << "\n";
                    ////qDebug() <<puk.position() <<"   " <<name[name.Lenght() - 1];
                    if(pak[name.Lenght()] == ';')
                        pak.erase(puk.position(), name.Lenght() + 1);
                    else
                        pak.erase(puk.position(), name.Lenght() + 2);
                }
            }
        }
    }
    //qDebug() <<"if type end";
}

void MainWindow::if_function(std::cmatch result)    //если объявление функции
{
    //!!есть прикол: нам надо прототипы каждой функции, ну а я решил, что,
    //! чтоб не проверть на повторение, просто искать сразу реализации
    //! функций и из них делать прототип(т.е. прототип без реализации не прокатит)
    //Аналогичная проверка, как для переменной, но не обязательно будет тип(конструктор)
    //и строчка не заканчивается ;(из-за реализации)
    //qDebug() <<"if function ";
    String type, name, init;
    std::cmatch puk;
    QTableWidgetItem *item;
    //const regex inint("(const )?(long |short |signed |unsigned )?(long |short |signed |unsigned )?(int|double|char|bool|int*|double*|char*|bool*)([\\w\\d]+)(\\(| = )?(.+)?\\)?,?");
    for (int i = 2; i < result.size(); i++)
    {
        if (result[i].str().size() == 0) continue;
        if (result[i].str() == "const " || result[i].str() == "signed " || result[i].str() == "unsigned " || result[i].str() == "short " || result[i].str() == "long ")
        {
            type += result[i].str().c_str();
        }
        else if (result[i].str() == "void" || result[i].str() == "int" || result[i].str() == "double" || result[i].str() == "char" || result[i].str() == "bool"
            || result[i].str() == "int*" || result[i].str() == "double*" || result[i].str() == "char*" || result[i].str() == "bool*")
        {
            type += result[i].str().c_str();
        }
        else
        {
            name = result[i].str().c_str();
            i++;
            init = result[i].str().c_str();

            item = new QTableWidgetItem;
            item->setText("Функция");
            ui->tableWidget->setItem(in_table, 1, item);
            item = new QTableWidgetItem;
            QString a;
            a.setNum(coordinate);
            item->setText(a);
            ui->tableWidget->setItem(in_table, 0, item);
            //item = new QTableWidgetItem;
            //a.setNum(balance);
            //item->setText(a);
            //ui->tableWidget->setItem(in_table, 5, item);
            item = new QTableWidgetItem;
            item->setText(QString::fromLatin1(type.c_str()));
            ui->tableWidget->setItem(in_table, 2, item);
            item = new QTableWidgetItem;
            item->setText(QString::fromLatin1(name.c_str()));
            ui->tableWidget->setItem(in_table, 3, item);
            item = new QTableWidgetItem;
            item->setText(QString::fromLatin1(init.c_str()));
            ui->tableWidget->setItem(in_table, 4, item);
            in_table++;
            checkName(name);
            ////qDebug() <<"After Chek Name";
            //cout << type << " " << name << " " << init <<"\n";
         }
    }
    //qDebug() <<"if function end";
}

void MainWindow::checkName(String nameFunc) //поиск перегрузок
{
    //!Какой тут прикол: я сделал массив пары(имя функции и сколько раз встречалась)
    //! Когда нахожу строку с функцией, то здесь сначала ищу такое имя в массиве
    //! если нахожу, то кол-во перегрузок увеличивается, если нет, то добавляю новую пару
    //qDebug() <<"Check Name";
    bool found = 0;
    int i;
    for(i = 0; i < sizeName; i++)
    {
        if(NameOfFunc[i].first == nameFunc)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        NameOfFunc[i].second++;
    }
    else
    {
        std::pair<String, int> *temp = new std::pair<String, int>[sizeName + 1];
        for(int j = 0; j < sizeName; j++)
        {
            ////qDebug() <<""
            temp[j].first = NameOfFunc[j].first;
            temp[j].second = NameOfFunc[j].second;
        }
        delete[]NameOfFunc;
        sizeName++;
        NameOfFunc = temp;
        NameOfFunc[sizeName - 1].second = 1;
        NameOfFunc[sizeName - 1].first = nameFunc;
    }
    //qDebug() <<"Check Name end";
}

void MainWindow::OutFunc() //выводит кол-во перегрузок
{

    //qDebug() <<"Out Func";
    QTableWidgetItem *item;
    int k;
//    for(int j = 0; j < sizeName; j++)
//    {
//        //qDebug() <<j <<" " <<QString::fromStdString(NameOfFunc[j].first);
//    }
    //цикл, который перебирает каждое имя функций
    for(int i = 0; i < sizeName; i++)
    {
        //переменная, которая запоминает, сколько раз в таблице должны
        //встретить в таблице такое имя
        k = NameOfFunc[i].second;
        //цикл, который идет по таблице и ищет функции по имени
        for(int j = 0; ;j++)
        {
            //если им совпало, то в отдельный столбец выводим кол-во перегрузок
            if(NameOfFunc[i].first == ui->tableWidget->item(j,3)->text().toStdString())
            {
                ////qDebug() <<"if " <<ui->tableWidget->item(j,3)->text() <<" == " <<QString::fromStdString(NameOfFunc[i].first);
                item = new QTableWidgetItem;
                QString a;
                a.setNum(NameOfFunc[i].second);
                item->setText(a);
                ui->tableWidget->setItem(j, 6, item);
                k--;
            }
            //как только вы встретили в таблице все разы функцию, то выходим из цикла
            if(k == 0) break;
        }
    }
    //qDebug() <<"Out Func end";
}

void MainWindow::outEdit(std::cmatch str) //вывод всех строк с изменениями
{
    QTableWidgetItem *item;
    item = new QTableWidgetItem;
    item->setText(QString::fromStdString(str[1].str()));
    ui->tableEdit->setItem(in_edit, 1, item);

    item = new QTableWidgetItem;
    QString a;
    a.setNum(coordinate);
    item->setText(a);
    ui->tableEdit->setItem(in_edit, 0, item);

    in_edit++;
}

void MainWindow::IfFor(std::cmatch result) //отдельная функция для фора
{
    //!она существует, т.к. в форе и встречаем объявление, и изменение, и логическую ошибку можем
    //qDebug() <<"If for";
    String Bool, data, edit;
    String full;
    //Если переменная
    const std::regex if_type("\\s*((const )?(long |short |signed |unsigned )?(long |short |signed |unsigned )?(int|double|char|bool|int\\*|double\\*|char\\*|bool\\*)\\s(.+;)$)");
    //Изменение(типа ++, --)
    const std::regex edit1("^\\s*([\\d\\w\\[\\]\\*\\&_\\(\\)]+(\\+\\+|--))$");
    //Изменение(типа +=, -=, *=, /=, =)
    const std::regex edit2("^\\s*([\\d\\w\\[\\]\\*\\&_\\(\\)]+( = | \\+= | \\*= | /= | -= )[\\d\\w\\[\\]\\*\\&_\\(\\)]+)$");

    std::cmatch miniresult;

    data = result[1].str().c_str();
    Bool = result[2].str().c_str();
    edit = result[3].str().c_str();
    //!прикол моих стрингов
    full = "for (";
    full += data;
    full += " ";
    full += Bool;
    full += "; ";
    full += edit;
    full += ")";
    ////qDebug() <<QString::fromStdString(data) <<" " <<QString::fromStdString(Bool) <<" " <<QString::fromStdString(edit);

    if(regex_match(data.c_str(), miniresult, if_type))
            if_type_data(miniresult);

    if(regex_match(edit.c_str(), miniresult, edit1))
            outEdit(miniresult);
    else if(regex_match(edit.c_str(), miniresult, edit2))
            outEdit(miniresult);

    if(Bool == "true" || Bool == "false")
    {
        QTableWidgetItem *item;

        item = new QTableWidgetItem;
        QString a;
        a.setNum(coordinate);
        item->setText(a);
        ui->tableLogic->setItem(in_fail, 0, item);

        item = new QTableWidgetItem;
        item->setText(QString::fromLatin1(full.c_str()));
        ui->tableLogic->setItem(in_fail, 1, item);

        in_fail++;
    }
    //qDebug() <<"If for end";
}

void MainWindow::LolOut(std::cmatch result) //Вывод логических ошибок
{
    QTableWidgetItem *item;

    String fail(result[1].str().c_str());

    item = new QTableWidgetItem;
    QString a;
    a.setNum(coordinate);
    item->setText(a);
    ui->tableLogic->setItem(in_fail, 0, item);

    item = new QTableWidgetItem;
    item->setText(QString::fromLatin1(fail.c_str()));
    ui->tableLogic->setItem(in_fail, 1, item);

    in_fail++;
}

void MainWindow::on_pushBotton_Test_clicked() //проверка из .срр
{
    ui->tableWidget->clearContents();
    ui->tableLogic->clearContents();
    ui->tableEdit->clearContents();
    in_table = 0, in_edit = 0, in_fail = 0;
    coordinate = 1;
    balance = 0;
    classSize = 0;
    structSize = 0;
    massSize = 0;
    sizeName = 0;
    NameOfFunc = new std::pair<String, int>[sizeName];
    read_code();
}

void MainWindow::on_pushButton_clicked() //путь к .срр
{
    dput = QFileDialog::getOpenFileName(this,"","",tr("*.cpp"));
    if(dput == "\0")
        QMessageBox::information(this, "Опаа", "Файла по данному пути нет");
}


void MainWindow::on_pushButton_2_clicked()  //проверка из тексэдита
{
    ui->tableWidget->clearContents();
    ui->tableLogic->clearContents();
    ui->tableEdit->clearContents();
    in_table = 0, in_edit = 0, in_fail = 0;
    coordinate = 1;
    balance = 0;
    classSize = 0;
    structSize = 0;
    massSize = 0;
    sizeName = 0;
    NameOfFunc = new std::pair<String, int>[sizeName];
    QString Text = ui->textEdit->toPlainText();
    char* puk = new char[Text.size() + 1];
    spd::Strncpy(puk, Text.toStdString().c_str(), Text.size());
    String str;
    char* for_tok = spd::Strtok(puk, "\n");
    while(for_tok != NULL)
    {
        str = for_tok;
        checkStr(str);
        for_tok = spd::Strtok(NULL, "\n");
        coordinate++;
    }

    ui->label_class->setNum(classSize);
    ui->label_struct->setNum(structSize);
    ui->label_mass->setNum(massSize);
    OutFunc();
    delete[]puk;
}
