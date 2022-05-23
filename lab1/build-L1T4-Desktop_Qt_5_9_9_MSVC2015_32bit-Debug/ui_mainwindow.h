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
#include <QtWidgets/QComboBox>
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
    QTableWidget *ProdtableWidget;
    QTableWidget *OrdtableWidget;
    QLabel *NumberNamelabel;
    QLabel *NumberTextlabel;
    QLabel *PriceNamelabe;
    QLabel *PriceTextlabel;
    QPushButton *SavepushButton;
    QPushButton *LoadpushButton;
    QComboBox *SwitchcomboBox;
    QPushButton *KeybordpushButton;
    QSpinBox *OrderNumspinBox;
    QLabel *Ordlabel;
    QPushButton *LoadpushButton_2;
    QPushButton *ChangepushButton;
    QLabel *ProductNumberlabel;
    QSpinBox *ProdNumspinBox;
    QPushButton *DeletepushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1500, 700);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        ProdtableWidget = new QTableWidget(centralwidget);
        if (ProdtableWidget->columnCount() < 3)
            ProdtableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        ProdtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        ProdtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        ProdtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        if (ProdtableWidget->rowCount() < 5)
            ProdtableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        ProdtableWidget->setVerticalHeaderItem(0, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        ProdtableWidget->setVerticalHeaderItem(1, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        ProdtableWidget->setVerticalHeaderItem(2, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        ProdtableWidget->setVerticalHeaderItem(3, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        ProdtableWidget->setVerticalHeaderItem(4, __qtablewidgetitem7);
        ProdtableWidget->setObjectName(QStringLiteral("ProdtableWidget"));
        ProdtableWidget->setGeometry(QRect(380, 40, 321, 181));
        ProdtableWidget->setStyleSheet(QLatin1String("QTableWidget{\n"
"background-color: #C0C0C0;\n"
"alternate-background-color: #606060;\n"
"selection-background-color: #282828;\n"
"}"));
        ProdtableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ProdtableWidget->setAlternatingRowColors(true);
        ProdtableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        OrdtableWidget = new QTableWidget(centralwidget);
        if (OrdtableWidget->columnCount() < 3)
            OrdtableWidget->setColumnCount(3);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        OrdtableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        OrdtableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        OrdtableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        if (OrdtableWidget->rowCount() < 5)
            OrdtableWidget->setRowCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        OrdtableWidget->setVerticalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        OrdtableWidget->setVerticalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        OrdtableWidget->setVerticalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        OrdtableWidget->setVerticalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        OrdtableWidget->setVerticalHeaderItem(4, __qtablewidgetitem15);
        OrdtableWidget->setObjectName(QStringLiteral("OrdtableWidget"));
        OrdtableWidget->setGeometry(QRect(20, 40, 331, 189));
        OrdtableWidget->setStyleSheet(QLatin1String("QTableWidget{\n"
"background-color: #C0C0C0;\n"
"alternate-background-color: #606060;\n"
"selection-background-color: #282828;\n"
"}"));
        OrdtableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        OrdtableWidget->setAlternatingRowColors(true);
        OrdtableWidget->setSelectionMode(QAbstractItemView::NoSelection);
        NumberNamelabel = new QLabel(centralwidget);
        NumberNamelabel->setObjectName(QStringLiteral("NumberNamelabel"));
        NumberNamelabel->setGeometry(QRect(390, 20, 91, 16));
        NumberTextlabel = new QLabel(centralwidget);
        NumberTextlabel->setObjectName(QStringLiteral("NumberTextlabel"));
        NumberTextlabel->setGeometry(QRect(490, 20, 31, 16));
        PriceNamelabe = new QLabel(centralwidget);
        PriceNamelabe->setObjectName(QStringLiteral("PriceNamelabe"));
        PriceNamelabe->setGeometry(QRect(570, 20, 81, 16));
        PriceTextlabel = new QLabel(centralwidget);
        PriceTextlabel->setObjectName(QStringLiteral("PriceTextlabel"));
        PriceTextlabel->setGeometry(QRect(660, 20, 31, 16));
        SavepushButton = new QPushButton(centralwidget);
        SavepushButton->setObjectName(QStringLiteral("SavepushButton"));
        SavepushButton->setGeometry(QRect(20, 240, 111, 41));
        LoadpushButton = new QPushButton(centralwidget);
        LoadpushButton->setObjectName(QStringLiteral("LoadpushButton"));
        LoadpushButton->setGeometry(QRect(140, 240, 111, 41));
        SwitchcomboBox = new QComboBox(centralwidget);
        SwitchcomboBox->setObjectName(QStringLiteral("SwitchcomboBox"));
        SwitchcomboBox->setGeometry(QRect(20, 290, 69, 22));
        KeybordpushButton = new QPushButton(centralwidget);
        KeybordpushButton->setObjectName(QStringLiteral("KeybordpushButton"));
        KeybordpushButton->setGeometry(QRect(260, 240, 161, 41));
        OrderNumspinBox = new QSpinBox(centralwidget);
        OrderNumspinBox->setObjectName(QStringLiteral("OrderNumspinBox"));
        OrderNumspinBox->setGeometry(QRect(191, 290, 27, 22));
        OrderNumspinBox->setMinimum(1);
        OrderNumspinBox->setMaximum(5);
        Ordlabel = new QLabel(centralwidget);
        Ordlabel->setObjectName(QStringLiteral("Ordlabel"));
        Ordlabel->setGeometry(QRect(110, 290, 75, 22));
        LoadpushButton_2 = new QPushButton(centralwidget);
        LoadpushButton_2->setObjectName(QStringLiteral("LoadpushButton_2"));
        LoadpushButton_2->setGeometry(QRect(430, 240, 111, 41));
        ChangepushButton = new QPushButton(centralwidget);
        ChangepushButton->setObjectName(QStringLiteral("ChangepushButton"));
        ChangepushButton->setGeometry(QRect(550, 240, 111, 41));
        ProductNumberlabel = new QLabel(centralwidget);
        ProductNumberlabel->setObjectName(QStringLiteral("ProductNumberlabel"));
        ProductNumberlabel->setGeometry(QRect(240, 290, 81, 16));
        ProdNumspinBox = new QSpinBox(centralwidget);
        ProdNumspinBox->setObjectName(QStringLiteral("ProdNumspinBox"));
        ProdNumspinBox->setGeometry(QRect(330, 290, 27, 22));
        ProdNumspinBox->setMinimum(1);
        ProdNumspinBox->setMaximum(5);
        DeletepushButton = new QPushButton(centralwidget);
        DeletepushButton->setObjectName(QStringLiteral("DeletepushButton"));
        DeletepushButton->setGeometry(QRect(550, 290, 111, 41));
        MainWindow->setCentralWidget(centralwidget);
        ProdtableWidget->raise();
        OrdtableWidget->raise();
        NumberNamelabel->raise();
        NumberTextlabel->raise();
        PriceNamelabe->raise();
        PriceTextlabel->raise();
        SavepushButton->raise();
        LoadpushButton->raise();
        KeybordpushButton->raise();
        SwitchcomboBox->raise();
        OrderNumspinBox->raise();
        Ordlabel->raise();
        LoadpushButton_2->raise();
        ChangepushButton->raise();
        ProductNumberlabel->raise();
        ProdNumspinBox->raise();
        DeletepushButton->raise();
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1500, 17));
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
        QTableWidgetItem *___qtablewidgetitem = ProdtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = ProdtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\246\320\265\320\275\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = ProdtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = ProdtableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = ProdtableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = ProdtableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = ProdtableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = ProdtableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = OrdtableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = OrdtableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "\320\224\320\260\321\202\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = OrdtableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "\320\240\320\265\320\272\320\262\320\270\320\267\320\270\321\202\321\213", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = OrdtableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = OrdtableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = OrdtableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = OrdtableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = OrdtableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        NumberNamelabel->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260\342\204\226:", Q_NULLPTR));
        NumberTextlabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        PriceNamelabe->setText(QApplication::translate("MainWindow", "\320\230\321\202\320\276\320\263\320\276\320\262\320\260\321\217 \321\206\320\265\320\275\320\260", Q_NULLPTR));
        PriceTextlabel->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        SavepushButton->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 \320\262", Q_NULLPTR));
        LoadpushButton->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267", Q_NULLPTR));
        SwitchcomboBox->clear();
        SwitchcomboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\227\320\260\320\272\320\260\320\267\321\213", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\320\242\320\276\320\262\320\260\321\200\321\213", Q_NULLPTR)
        );
        KeybordpushButton->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\241 \320\272\320\273\320\260\320\262\320\270\320\260\321\202\321\203\321\200\321\213", Q_NULLPTR));
        Ordlabel->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \320\267\320\260\320\272\320\260\320\267\320\260", Q_NULLPTR));
        LoadpushButton_2->setText(QApplication::translate("MainWindow", "\320\241\320\277\320\270\321\201\320\276\320\272 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", Q_NULLPTR));
        ChangepushButton->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        ProductNumberlabel->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\202\320\276\320\262\320\260\321\200\320\260", Q_NULLPTR));
        DeletepushButton->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
