/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QSpinBox *spinBox_Num;
    QPushButton *pushButton_Read;
    QPushButton *pushButton_Answer;
    QPushButton *pushButton_Add;
    QLineEdit *lineEdit_NewPrim;
    QPushButton *pushButton_AnswerAll;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QDoubleSpinBox *doubleSpinBox_a;
    QDoubleSpinBox *doubleSpinBox_b;
    QDoubleSpinBox *doubleSpinBox_c;
    QDoubleSpinBox *doubleSpinBox_d;
    QDoubleSpinBox *doubleSpinBox_e;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 8)
            tableWidget->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        if (tableWidget->rowCount() < 30)
            tableWidget->setRowCount(30);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(0, 0, 801, 391));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        tableWidget->setRowCount(30);
        tableWidget->horizontalHeader()->setDefaultSectionSize(60);
        tableWidget->horizontalHeader()->setMinimumSectionSize(10);
        spinBox_Num = new QSpinBox(centralwidget);
        spinBox_Num->setObjectName(QStringLiteral("spinBox_Num"));
        spinBox_Num->setGeometry(QRect(310, 450, 42, 21));
        spinBox_Num->setMinimum(1);
        spinBox_Num->setMaximum(30);
        pushButton_Read = new QPushButton(centralwidget);
        pushButton_Read->setObjectName(QStringLiteral("pushButton_Read"));
        pushButton_Read->setGeometry(QRect(10, 390, 91, 41));
        pushButton_Answer = new QPushButton(centralwidget);
        pushButton_Answer->setObjectName(QStringLiteral("pushButton_Answer"));
        pushButton_Answer->setGeometry(QRect(100, 390, 81, 41));
        pushButton_Add = new QPushButton(centralwidget);
        pushButton_Add->setObjectName(QStringLiteral("pushButton_Add"));
        pushButton_Add->setGeometry(QRect(10, 430, 91, 41));
        lineEdit_NewPrim = new QLineEdit(centralwidget);
        lineEdit_NewPrim->setObjectName(QStringLiteral("lineEdit_NewPrim"));
        lineEdit_NewPrim->setGeometry(QRect(190, 450, 113, 20));
        pushButton_AnswerAll = new QPushButton(centralwidget);
        pushButton_AnswerAll->setObjectName(QStringLiteral("pushButton_AnswerAll"));
        pushButton_AnswerAll->setGeometry(QRect(100, 430, 81, 41));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(210, 400, 16, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(260, 400, 16, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(310, 400, 21, 16));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(370, 400, 21, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(420, 400, 16, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(190, 420, 266, 24));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        doubleSpinBox_a = new QDoubleSpinBox(widget);
        doubleSpinBox_a->setObjectName(QStringLiteral("doubleSpinBox_a"));

        horizontalLayout->addWidget(doubleSpinBox_a);

        doubleSpinBox_b = new QDoubleSpinBox(widget);
        doubleSpinBox_b->setObjectName(QStringLiteral("doubleSpinBox_b"));

        horizontalLayout->addWidget(doubleSpinBox_b);

        doubleSpinBox_c = new QDoubleSpinBox(widget);
        doubleSpinBox_c->setObjectName(QStringLiteral("doubleSpinBox_c"));

        horizontalLayout->addWidget(doubleSpinBox_c);

        doubleSpinBox_d = new QDoubleSpinBox(widget);
        doubleSpinBox_d->setObjectName(QStringLiteral("doubleSpinBox_d"));

        horizontalLayout->addWidget(doubleSpinBox_d);

        doubleSpinBox_e = new QDoubleSpinBox(widget);
        doubleSpinBox_e->setObjectName(QStringLiteral("doubleSpinBox_e"));

        horizontalLayout->addWidget(doubleSpinBox_e);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\321\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "b", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "c", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "d", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "e", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\236\320\237\320\227", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\267\321\203\320\273\321\214\321\202\320\260\321\202", Q_NULLPTR));
        pushButton_Read->setText(QApplication::translate("MainWindow", "\320\241\321\207\320\270\321\202\320\260\321\202\321\214", Q_NULLPTR));
        pushButton_Answer->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202", Q_NULLPTR));
        pushButton_Add->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_AnswerAll->setText(QApplication::translate("MainWindow", "\320\236\321\202\320\262\320\265\321\202 \320\262\321\201\320\265", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "a", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "b", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "c", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "d", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "e", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
