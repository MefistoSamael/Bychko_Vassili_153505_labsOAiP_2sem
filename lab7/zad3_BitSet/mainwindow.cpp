#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    input = 0;
    isBitSet1 = 1;
    index = 0;

    bitset1 = 0;
    bitset2 = 0;

    ui->lineEditBitSet1->setText(QString::fromStdString(bitset1.to_string()));
    ui->lineEditBitSet2->setText(QString::fromStdString(bitset2.to_string()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonAll_clicked()
{
    if (isBitSet1)
    {
        if(bitset1.all())
        {
            QMessageBox::information(this, "", "Все биты BitSet1 - 1");
        }
        else
        {
            QMessageBox::information(this, "", "Все биты BitSet1 - 0");

        }
    }
    else
    {
        if(bitset2.all())
        {
            QMessageBox::information(this, "", "Все биты BitSet2 - 1");
        }
        else
        {
            QMessageBox::information(this, "", "Все биты BitSet2 - 0");

        }
    }
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    index = arg1;
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    input = arg1;
}


void MainWindow::on_radioButtonBitSet1_toggled(bool checked)
{
    isBitSet1 = 1;
}


void MainWindow::on_radioButtonBitSet2_toggled(bool checked)
{
    isBitSet1 = 0;
}


void MainWindow::on_pushButton_clicked()
{
    if (isBitSet1)
    {
        bitset1 = input;
        std::string ans = bitset1.to_string();
        std::reverse(ans.begin(),ans.end());
        ui->lineEditBitSet1->setText(QString::fromStdString(ans));
    }
    else
    {
        bitset2 = input;
        std::string ans = bitset2.to_string();
        std::reverse(ans.begin(),ans.end());
        ui->lineEditBitSet2->setText(QString::fromStdString(ans));

    }
}


void MainWindow::on_pushButtonCount_clicked()
{
    size_t ans = 0;
    if (isBitSet1) ans = bitset1.count();
    else ans = bitset2.count();

    QMessageBox::information(this,"","Количество единиц - "+ QString::number(ans));
}


void MainWindow::on_pushButtonAny_clicked()
{
    if(isBitSet1)
    {
        if (bitset1.any()) QMessageBox::information(this,"","В bitset1 есть хотя бы одна единица");
        else QMessageBox::information(this,"","В bitset1 нет хотя бы одной единицы");
    }
    else
    {
        if (bitset2.any()) QMessageBox::information(this,"","В bitset2 есть хотя бы одна единица");
        else QMessageBox::information(this,"","В bitset2 нет хотя бы одной единицы");

    }
}


void MainWindow::on_pushButtonNone_clicked()
{
    if(isBitSet1)
    {
        if (bitset1.none()) QMessageBox::information(this,"","В bitset1 нет единиц");
        else QMessageBox::information(this,"","В bitset1 есть единицы");
    }
    else
    {
        if (bitset2.none()) QMessageBox::information(this,"","В bitset2 нет единиц");
        else QMessageBox::information(this,"","В bitset2 есть единицы");
    }

}


void MainWindow::on_pushButtonReset_clicked()
{
    if (isBitSet1)
    {
        bitset1.reset();
        ui->lineEditBitSet1->setText(QString::fromStdString(bitset1.to_string()));
    }
    else
    {
        bitset2.reset();
        ui->lineEditBitSet2->setText(QString::fromStdString(bitset2.to_string()));
    }
}


void MainWindow::on_pushButtonSet_clicked()
{
    if (isBitSet1)
    {
        bitset1.set();
        ui->lineEditBitSet1->setText(QString::fromStdString(bitset1.to_string()));
    }
    else
    {
        bitset2.set();
        ui->lineEditBitSet2->setText(QString::fromStdString(bitset2.to_string()));
    }
}


void MainWindow::on_pushButtonSize_clicked()
{
    if (isBitSet1)
    {
        QMessageBox::information(this,"","Размер bitset1 - " + QString::number(bitset1.size()));
    }
    else
    {
        QMessageBox::information(this,"","Размер bitset2 - " + QString::number(bitset2.size()));
    }
}


void MainWindow::on_pushButtonTest_clicked()
{
    if (isBitSet1)
    {
        if(index >= bitset1.size())
        {
            QMessageBox::information(this,"","индекс больше количества элементов в bitset1");
            return;
        }

        QMessageBox::information(this,"","По данному индексу находится " + QString::number(bitset1.test(index)));
    }
    else
    {
        if(index >= bitset2.size())
        {
            QMessageBox::information(this,"","индекс больше количества элементов в bitset2");
            return;
        }

        QMessageBox::information(this,"","По данному индексу находится " + QString::number(bitset2.test(index)));

    }

}


void MainWindow::on_pushButtonULL_clicked()
{
    unsigned long long ans;

    if (isBitSet1)
    {
       ans = bitset1.to_ullong();
    }
    else
    {
        ans = bitset2.to_ullong();
    }

    ui->textEditOutput->setText(QString::number(ans));

}


void MainWindow::on_pushButtonUL_clicked()
{
    unsigned long ans;

    if (isBitSet1)
    {
       ans = bitset1.to_ulong();
    }
    else
    {
        ans = bitset2.to_ulong();
    }

    ui->textEditOutput->setText(QString::number(ans));

}


void MainWindow::on_pushButtonAnd_clicked()
{
    std::string ans = (bitset1 & bitset2).to_string();
    std::reverse(ans.begin(),ans.end());
    ui->textEditOutput->setText(QString::fromStdString(ans));
}


void MainWindow::on_pushButtonOr_clicked()
{
    std::string ans = (bitset1|bitset2).to_string();
    std::reverse(ans.begin(),ans.end());
    ui->textEditOutput->setText(QString::fromStdString(ans));

}


void MainWindow::on_pushButtonXor_clicked()
{
    std::string ans = (bitset1^bitset2).to_string();
    std::reverse(ans.begin(),ans.end());
    ui->textEditOutput->setText(QString::fromStdString(ans));

}

