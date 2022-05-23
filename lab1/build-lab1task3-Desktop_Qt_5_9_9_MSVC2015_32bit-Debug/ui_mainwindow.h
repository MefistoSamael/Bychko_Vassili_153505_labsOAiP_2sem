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
#include <QtWidgets/QLabel>
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
    QTableWidget *DateTable;
    QPushButton *EnterDataPushButton;
    QSpinBox *DaySpinBox;
    QSpinBox *MonthSpinBox;
    QSpinBox *YearSpinBox;
    QLabel *DayLabel;
    QLabel *MonthLabel;
    QLabel *YearLabel;
    QSpinBox *NumberSpinBox;
    QLabel *NumberLabel;
    QPushButton *ChangeDataPushButton;
    QPushButton *DeleteDataPushButton;
    QPushButton *SaveAsDataPushButton;
    QPushButton *LoadDataPushButton;
    QPushButton *Test;
    QPushButton *EnterBirthPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1200, 800);
        MainWindow->setStyleSheet(QStringLiteral(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        DateTable = new QTableWidget(centralwidget);
        if (DateTable->columnCount() < 7)
            DateTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setBackground(QColor(67, 35, 170));
        DateTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        DateTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        DateTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        DateTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        DateTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        DateTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        DateTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (DateTable->rowCount() < 10)
            DateTable->setRowCount(10);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        DateTable->setVerticalHeaderItem(9, __qtablewidgetitem16);
        DateTable->setObjectName(QStringLiteral("DateTable"));
        DateTable->setGeometry(QRect(10, 10, 1181, 221));
        DateTable->setStyleSheet(QLatin1String("	QTableWidget\n"
"{\n"
"background-color: #C0C0C0;\n"
"alternate-background-color:#606060;\n"
"}"));
        DateTable->setEditTriggers(QAbstractItemView::NoEditTriggers);
        DateTable->setAlternatingRowColors(true);
        DateTable->setSelectionMode(QAbstractItemView::NoSelection);
        DateTable->setTextElideMode(Qt::ElideLeft);
        DateTable->setShowGrid(true);
        DateTable->horizontalHeader()->setDefaultSectionSize(140);
        EnterDataPushButton = new QPushButton(centralwidget);
        EnterDataPushButton->setObjectName(QStringLiteral("EnterDataPushButton"));
        EnterDataPushButton->setGeometry(QRect(10, 360, 91, 51));
        DaySpinBox = new QSpinBox(centralwidget);
        DaySpinBox->setObjectName(QStringLiteral("DaySpinBox"));
        DaySpinBox->setGeometry(QRect(10, 240, 61, 22));
        DaySpinBox->setMinimum(1);
        DaySpinBox->setMaximum(31);
        MonthSpinBox = new QSpinBox(centralwidget);
        MonthSpinBox->setObjectName(QStringLiteral("MonthSpinBox"));
        MonthSpinBox->setGeometry(QRect(10, 270, 61, 22));
        MonthSpinBox->setMinimum(1);
        MonthSpinBox->setMaximum(12);
        YearSpinBox = new QSpinBox(centralwidget);
        YearSpinBox->setObjectName(QStringLiteral("YearSpinBox"));
        YearSpinBox->setGeometry(QRect(10, 300, 61, 22));
        YearSpinBox->setMinimum(1);
        YearSpinBox->setMaximum(9999);
        DayLabel = new QLabel(centralwidget);
        DayLabel->setObjectName(QStringLiteral("DayLabel"));
        DayLabel->setGeometry(QRect(80, 240, 49, 16));
        MonthLabel = new QLabel(centralwidget);
        MonthLabel->setObjectName(QStringLiteral("MonthLabel"));
        MonthLabel->setGeometry(QRect(80, 270, 49, 16));
        YearLabel = new QLabel(centralwidget);
        YearLabel->setObjectName(QStringLiteral("YearLabel"));
        YearLabel->setGeometry(QRect(80, 300, 49, 16));
        NumberSpinBox = new QSpinBox(centralwidget);
        NumberSpinBox->setObjectName(QStringLiteral("NumberSpinBox"));
        NumberSpinBox->setGeometry(QRect(10, 330, 61, 22));
        NumberSpinBox->setMinimum(1);
        NumberSpinBox->setMaximum(9999);
        NumberLabel = new QLabel(centralwidget);
        NumberLabel->setObjectName(QStringLiteral("NumberLabel"));
        NumberLabel->setGeometry(QRect(80, 330, 81, 16));
        ChangeDataPushButton = new QPushButton(centralwidget);
        ChangeDataPushButton->setObjectName(QStringLiteral("ChangeDataPushButton"));
        ChangeDataPushButton->setGeometry(QRect(10, 420, 91, 51));
        DeleteDataPushButton = new QPushButton(centralwidget);
        DeleteDataPushButton->setObjectName(QStringLiteral("DeleteDataPushButton"));
        DeleteDataPushButton->setGeometry(QRect(10, 480, 91, 51));
        SaveAsDataPushButton = new QPushButton(centralwidget);
        SaveAsDataPushButton->setObjectName(QStringLiteral("SaveAsDataPushButton"));
        SaveAsDataPushButton->setGeometry(QRect(110, 360, 91, 51));
        LoadDataPushButton = new QPushButton(centralwidget);
        LoadDataPushButton->setObjectName(QStringLiteral("LoadDataPushButton"));
        LoadDataPushButton->setGeometry(QRect(110, 420, 91, 51));
        Test = new QPushButton(centralwidget);
        Test->setObjectName(QStringLiteral("Test"));
        Test->setGeometry(QRect(320, 310, 91, 51));
        EnterBirthPushButton = new QPushButton(centralwidget);
        EnterBirthPushButton->setObjectName(QStringLiteral("EnterBirthPushButton"));
        EnterBirthPushButton->setGeometry(QRect(110, 480, 91, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1200, 17));
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
        QTableWidgetItem *___qtablewidgetitem = DateTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = DateTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\241\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = DateTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\237\321\200\320\265\320\264\321\213\320\264\321\203\321\211\320\270\320\271 \320\264\320\265\320\275\321\214", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = DateTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\222\320\270\321\201\320\276\320\272\320\276\321\201\320\275\321\213\320\271 \320\273\320\270 \320\263\320\276\320\264", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = DateTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\275\320\265\320\264\320\265\320\273\320\270", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = DateTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\224\320\275\320\265\320\271 \320\264\320\276 \320\264\320\275\321\217 \321\200\320\276\320\266\320\264\320\265\320\275\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = DateTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\224\320\275\320\270 \320\274\320\265\320\266\320\264\321\203 \321\202\320\265\320\272\321\203\321\211\320\270\320\274 \320\270 \321\201\320\273\320\265\320\264\321\203\321\216\321\211\320\270\320\274 \320\264\320\275\320\265\320\274 \320\262 \321\202\320\260\320\261\320\273\320\270\321\206\320\265", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = DateTable->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = DateTable->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = DateTable->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = DateTable->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = DateTable->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = DateTable->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = DateTable->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = DateTable->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = DateTable->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = DateTable->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        EnterDataPushButton->setText(QApplication::translate("MainWindow", "\320\222\320\275\320\265\321\201\321\202\320\270 \320\264\320\260\321\202\321\203", Q_NULLPTR));
        DayLabel->setText(QApplication::translate("MainWindow", "\320\224\320\265\320\275\321\214", Q_NULLPTR));
        MonthLabel->setText(QApplication::translate("MainWindow", "\320\234\320\265\321\201\321\217\321\206", Q_NULLPTR));
        YearLabel->setText(QApplication::translate("MainWindow", "\320\223\320\276\320\264", Q_NULLPTR));
        NumberLabel->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\217\321\207\320\265\320\271\320\272\320\270", Q_NULLPTR));
        ChangeDataPushButton->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214 \320\264\320\260\321\202\321\203", Q_NULLPTR));
        DeleteDataPushButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214 \320\264\320\260\321\202\321\203", Q_NULLPTR));
        SaveAsDataPushButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\272\320\260\320\272", Q_NULLPTR));
        LoadDataPushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214", Q_NULLPTR));
        Test->setText(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        EnterBirthPushButton->setText(QApplication::translate("MainWindow", "\320\222\320\275\320\265\321\201\321\202\320\270 \320\224\320\240", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
