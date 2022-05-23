#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::norm(MyVector<int>&c)
{
        for (int i = 0; i < c.get_size() - 1; ++i)
        {
            c[i + 1] += c[i] >> B;
            c[i] &= fm;
        }
}

void MainWindow::trim(MyVector<int> & c, int x)
{
        c.resize(x / B + 1);
        c[x / B] &= (1 << (x % B)) - 1;
}

MyVector<int> MainWindow::add(const MyVector<int> & a, const MyVector<int> & b, int k)
{
        MyVector<int> c(std::max(a.get_size(), b.get_size()) + 1);
        for (int i = 0; i < c.get_size(); ++i)
        {
            if (i < a.get_size()) c[i] += a[i];
            if (i < b.get_size()) c[i] += b[i];
        }
        norm(c);
        trim(c, k);
        return c;
}

int MainWindow::get_bit(const MyVector<int> & v, int b)
{
        return (v[b / B] >> (b % B)) & 1;
}

MyVector<int> MainWindow::mul(const MyVector<int> & a, int x, int k)
{
        MyVector<int> b = a;
        b.push_back(0);
        for (int i = 0; i < b.get_size(); ++i) b[i] *= x;
        norm(b);
        trim(b, k);
        return b;
}

void MainWindow::gen(MyVector<int> n, const MyVector<MyVector<int>> &p, int k, int i, MyVector<Pair<int, MyVector<int>> > &v)
{
        if (i == k)
        {
            n.resize(k + 1);
            if (get_bit(n, k)) v.push_back(make_Pair(k, n));
            return;
        }
        if (get_bit(n, i)) return;
        gen(n, p, k, i + 1, v);
        if (i) gen(add(n, p[i], k + 1), p, k, i + 1, v);
}

void MainWindow::Brus()
{
    if (n == 1) {
         ui->label->setText("1");
         return;
    }
    --n;

    MyVector<Pair<int, MyVector<int>> > v;
    for (int k = 1; n / 2 >= v.get_size(); ++k) {
        MyVector<int> vekt(k / B + 1);
        vekt[k / B] = 1 << (k % B);
        MyVector<MyVector<int>> p(k + 1);
        p[0].push_back(1);
        trim(p[0], k + 1);
        for (int i = 0; i < k; ++i) p[i + 1] = mul(p[i], 10, k + 1);
        gen(vekt, p, k, 0, v);
    }
    for (int i = 0; i < v.get_size(); ++i) Reverse(v[i].second.begin(), v[i].second.end());
    if(n > 5000)
        Qsort(v.begin(), v.end());
    MyVector<int> w = v[--n / 2].second;
   Reverse(w.begin(), w.end());
    if (n & 1) w[0] ^= 1;
    QString anser = "";
    for (int k = v[n / 2].first + 1 - 1; k >= 0; --k)
    {
        anser += QVariant(get_bit(w, k)).toString();;
    }

        ui->label->setText(anser);
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
     nn = arg1;
}


void MainWindow::on_pushButton_clicked()
{
    n = nn;
    Brus();
}


void MainWindow::on_pushButton_2_clicked()
{
    close();
}

