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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidgetMap;
    QTableWidget *tableWidgetSet;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QSpinBox *spinBox;
    QLineEdit *lineEdit;
    QRadioButton *radioButtonMap;
    QRadioButton *radioButtonSet;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(820, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidgetMap = new QTableWidget(centralwidget);
        if (tableWidgetMap->columnCount() < 2)
            tableWidgetMap->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetMap->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetMap->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        if (tableWidgetMap->rowCount() < 10)
            tableWidgetMap->setRowCount(10);
        tableWidgetMap->setObjectName(QStringLiteral("tableWidgetMap"));
        tableWidgetMap->setGeometry(QRect(10, 10, 400, 250));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(5);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetMap->sizePolicy().hasHeightForWidth());
        tableWidgetMap->setSizePolicy(sizePolicy);
        tableWidgetMap->setRowCount(10);
        tableWidgetSet = new QTableWidget(centralwidget);
        if (tableWidgetSet->columnCount() < 1)
            tableWidgetSet->setColumnCount(1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetSet->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        if (tableWidgetSet->rowCount() < 10)
            tableWidgetSet->setRowCount(10);
        tableWidgetSet->setObjectName(QStringLiteral("tableWidgetSet"));
        tableWidgetSet->setGeometry(QRect(420, 10, 400, 250));
        tableWidgetSet->setRowCount(10);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(140, 290, 121, 41));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(270, 290, 131, 41));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(410, 290, 131, 41));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(550, 290, 131, 41));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(140, 340, 121, 41));
        spinBox->setMinimum(1);
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(270, 340, 411, 41));
        radioButtonMap = new QRadioButton(centralwidget);
        radioButtonMap->setObjectName(QStringLiteral("radioButtonMap"));
        radioButtonMap->setGeometry(QRect(700, 300, 69, 18));
        radioButtonMap->setChecked(true);
        radioButtonSet = new QRadioButton(centralwidget);
        radioButtonSet->setObjectName(QStringLiteral("radioButtonSet"));
        radioButtonSet->setGeometry(QRect(700, 350, 69, 18));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 820, 17));
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
        QTableWidgetItem *___qtablewidgetitem = tableWidgetMap->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\272\320\273\321\216\321\207", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetMap->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetSet->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\272\320\273\321\216\321\207/\320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\265", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\241\320\276\320\264\320\265\321\200\320\266\320\270\321\202?", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\237\320\276\321\207\320\270\321\201\321\202\320\270\321\202\321\214", Q_NULLPTR));
        radioButtonMap->setText(QApplication::translate("MainWindow", "Map", Q_NULLPTR));
        radioButtonSet->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
