#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow),
      t(),
      insertionKey(1),
      otherKey(1),
      data("")

{
    ui->setupUi(this);

    ui->treeWidget->setColumnCount(2);
    ui->treeWidget->setColumnWidth(0,300);
    ui->treeWidget->setColumnWidth(1,179);
    ui->treeWidget->setHeaderLabels(QStringList() << "Key"<< "Data");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_InsKeyspinBox_valueChanged(int arg1)
{
    insertionKey = arg1;
}


void MainWindow::on_DataLineEdit_textChanged(const QString &arg1)
{
    data = arg1.toStdString();
}


void MainWindow::on_OtherKeySpinBox_valueChanged(int arg1)
{
    otherKey = arg1;
}


void MainWindow::on_AddPushButton_clicked()
{
    if(data == "")
    {
        QMessageBox::critical(this, "warning", "поле строки пусто");
        return;
    }

     t.AddKey(insertionKey, data, t.get_root());
     Rewrite();
}


void MainWindow::on_ShowByKeyPushButton_clicked()
{
    if (t.get_root() == nullptr)
    {
        QMessageBox::critical(this, "warning", "дерево является пустым");
        return;
    }


    Node* temp = t.SearchByKey(otherKey, t.get_root());
    ui->OutputLabel->setText(QString::fromStdString(temp->data));
}


void MainWindow::on_DelByKeyPushButton_clicked()
{
    if (t.get_root() == nullptr)
    {
        QMessageBox::critical(this, "warning", "дерево является пустым");
        return;
    }

    t.DeleteByKey(otherKey, t.get_root());

    Rewrite();
}


void MainWindow::on_PreOrderPushButton_clicked()
{
    if (t.get_root() == nullptr)
    {
        QMessageBox::critical(this, "warning", "дерево является пустым");
        return;
    }
}


void MainWindow::on_PostOrderPushButton_clicked()
{
    if (t.get_root() == nullptr)
    {
        QMessageBox::critical(this, "warning", "дерево является пустым");
        return;
    }
}


void MainWindow::on_InnerLeftPushButton_clicked()
{
    if (t.get_root() == nullptr)
    {
        QMessageBox::critical(this, "warning", "дерево является пустым");
        return;
    }
}

void MainWindow::Rewrite()
{
    ui->treeWidget->clear();

    AddTree(t.get_root());

    ui->treeWidget->expandAll();
}

void MainWindow::AddTree(Node *n, QTreeWidgetItem *parent)
{
    if (n == nullptr) return;

    QTreeWidgetItem* item = new QTreeWidgetItem();

    item->setText(0, QString::number(n->key));
    item->setText(1, QString::fromStdString(n->data));

    if(n == t.get_root()) ui->treeWidget->addTopLevelItem(item);
    else parent->addChild(item);

    AddTree(n->left, item);
    AddTree(n->right, item);
}


void MainWindow::on_BalancePushButton_clicked()
{
    if (t.get_root() == nullptr)
    {
        QMessageBox::critical(this, "warning", "дерево является пустым");
        return;
    }

    t.FindBalance();

    Rewrite();
}


void MainWindow::on_SomethinPushButton_clicked()
{
    std::vector<std::pair<int,std::string>> vec;
    for(int i = 1; i<=11;i++)
        vec.push_back(std::make_pair(i,QString::number(i).toStdString()));

    t.AddFromVec(t.get_root(), vec);

    Rewrite();


}

