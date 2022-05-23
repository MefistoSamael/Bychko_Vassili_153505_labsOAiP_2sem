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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushBotton_Test;
    QTextEdit *textEdit;
    QTableWidget *tableWidget;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_class;
    QLabel *label_2;
    QLabel *label_struct;
    QLabel *label_3;
    QLabel *label_mass;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QTableWidget *tableEdit;
    QTableWidget *tableLogic;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(2560, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushBotton_Test = new QPushButton(centralwidget);
        pushBotton_Test->setObjectName(QStringLiteral("pushBotton_Test"));
        pushBotton_Test->setGeometry(QRect(10, 500, 111, 41));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 10, 411, 481));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        if (tableWidget->rowCount() < 100)
            tableWidget->setRowCount(100);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(430, 10, 701, 301));
        tableWidget->setRowCount(100);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1140, 10, 641, 431));
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        label_class = new QLabel(groupBox);
        label_class->setObjectName(QStringLiteral("label_class"));

        formLayout->setWidget(0, QFormLayout::FieldRole, label_class);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label_struct = new QLabel(groupBox);
        label_struct->setObjectName(QStringLiteral("label_struct"));

        formLayout->setWidget(2, QFormLayout::FieldRole, label_struct);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        label_mass = new QLabel(groupBox);
        label_mass->setObjectName(QStringLiteral("label_mass"));

        formLayout->setWidget(4, QFormLayout::FieldRole, label_mass);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(3, QFormLayout::LabelRole, verticalSpacer_2);

        tableEdit = new QTableWidget(centralwidget);
        if (tableEdit->columnCount() < 2)
            tableEdit->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableEdit->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableEdit->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        if (tableEdit->rowCount() < 100)
            tableEdit->setRowCount(100);
        tableEdit->setObjectName(QStringLiteral("tableEdit"));
        tableEdit->setGeometry(QRect(430, 320, 451, 231));
        tableEdit->setRowCount(100);
        tableLogic = new QTableWidget(centralwidget);
        if (tableLogic->columnCount() < 2)
            tableLogic->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableLogic->setHorizontalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableLogic->setHorizontalHeaderItem(1, __qtablewidgetitem10);
        if (tableLogic->rowCount() < 100)
            tableLogic->setRowCount(100);
        tableLogic->setObjectName(QStringLiteral("tableLogic"));
        tableLogic->setGeometry(QRect(890, 320, 361, 231));
        tableLogic->setRowCount(100);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(130, 500, 91, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(240, 500, 91, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 2560, 17));
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
        pushBotton_Test->setText(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\276 \321\215\321\202\320\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\242\320\270\320\277", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\230\320\275\320\270\321\206\320\270\320\260\320\273\320\270\320\267\320\260\321\206\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\223\320\273\321\203\320\261\320\270\320\275\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273-\320\262\320\276 \320\277\321\200\320\276\321\202\320\276\321\202\320\270\320\277\320\276\320\262", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \321\207\320\265\320\263\320\276-\320\275\320\270\320\261\321\203\320\264\321\214", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\232\320\273\320\260\321\201\321\201\321\213", Q_NULLPTR));
        label_class->setText(QString());
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\321\203\320\272\321\202\321\203\321\200\321\213", Q_NULLPTR));
        label_struct->setText(QString());
        label_3->setText(QApplication::translate("MainWindow", "\320\234\320\260\321\201\321\201\320\270\320\262\321\213", Q_NULLPTR));
        label_mass->setText(QString());
        QTableWidgetItem *___qtablewidgetitem7 = tableEdit->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableEdit->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\276\320\272\320\260 \321\201 \320\270\320\267\320\274\320\265\320\275\320\265\320\275\320\270\320\265\320\274", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableLogic->horizontalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\267\320\270\321\206\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableLogic->horizontalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\233\320\276\320\263\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \320\276\321\210\320\270\320\261\320\272\320\260", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "Chose FIle", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "Test Input", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
