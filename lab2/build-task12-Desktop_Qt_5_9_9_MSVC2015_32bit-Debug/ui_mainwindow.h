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
#include <QtWidgets/QGroupBox>
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
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QGroupBox *groupBoxParticipant;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayoutCountry;
    QLabel *label;
    QLineEdit *lineEditCountry;
    QHBoxLayout *horizontalLayout;
    QLabel *label_2;
    QComboBox *comboBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLineEdit *lineEditName;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_5;
    QLineEdit *lineEditPatronymic;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_6;
    QSpinBox *spinBoxNumber;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_7;
    QSpinBox *spinBoxAge;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_8;
    QSpinBox *spinBoxHeight;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_9;
    QSpinBox *spinBoxWeight;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_9;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_12;
    QLabel *label_12;
    QSpinBox *spinBoxRowNumber;
    QPushButton *pushButtonAdd;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QHBoxLayout *horizontalLayout_11;
    QLabel *label_11;
    QLineEdit *lineEdit_2;
    QPushButton *pushButtonSearch_2;
    QHBoxLayout *horizontalLayout_13;
    QLabel *label_13;
    QComboBox *comboBox_2;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout_14;
    QLabel *label_14;
    QSpinBox *spinBoxHeight_2;
    QPushButton *pushButton_5;
    QHBoxLayout *horizontalLayout_15;
    QLabel *label_15;
    QPushButton *pushButton_6;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_10;
    QSpinBox *spinBox_4;
    QPushButton *pushButtonSearch;
    QPushButton *pushButton_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1924, 1050);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        if (tableWidget->columnCount() < 9)
            tableWidget->setColumnCount(9);
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
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(8, __qtablewidgetitem8);
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem23);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 10, 1200, 750));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        groupBoxParticipant = new QGroupBox(centralwidget);
        groupBoxParticipant->setObjectName(QStringLiteral("groupBoxParticipant"));
        groupBoxParticipant->setGeometry(QRect(1220, 10, 311, 171));
        layoutWidget = new QWidget(groupBoxParticipant);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 161, 141));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayoutCountry = new QHBoxLayout();
        horizontalLayoutCountry->setObjectName(QStringLiteral("horizontalLayoutCountry"));
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayoutCountry->addWidget(label);

        lineEditCountry = new QLineEdit(layoutWidget);
        lineEditCountry->setObjectName(QStringLiteral("lineEditCountry"));
        lineEditCountry->setMaxLength(20);

        horizontalLayoutCountry->addWidget(lineEditCountry);


        verticalLayout->addLayout(horizontalLayoutCountry);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        comboBox = new QComboBox(layoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout->addWidget(comboBox);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_4->addWidget(label_3);

        lineEdit = new QLineEdit(layoutWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMaxLength(20);

        horizontalLayout_4->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_3->addWidget(label_4);

        lineEditName = new QLineEdit(layoutWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMaxLength(20);

        horizontalLayout_3->addWidget(lineEditName);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEditPatronymic = new QLineEdit(layoutWidget);
        lineEditPatronymic->setObjectName(QStringLiteral("lineEditPatronymic"));
        lineEditPatronymic->setMaxLength(20);

        horizontalLayout_2->addWidget(lineEditPatronymic);


        verticalLayout->addLayout(horizontalLayout_2);

        layoutWidget1 = new QWidget(groupBoxParticipant);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(180, 20, 121, 141));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_5->addWidget(label_6);

        spinBoxNumber = new QSpinBox(layoutWidget1);
        spinBoxNumber->setObjectName(QStringLiteral("spinBoxNumber"));
        spinBoxNumber->setMinimum(1);
        spinBoxNumber->setMaximum(10);

        horizontalLayout_5->addWidget(spinBoxNumber);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_7 = new QLabel(layoutWidget1);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_6->addWidget(label_7);

        spinBoxAge = new QSpinBox(layoutWidget1);
        spinBoxAge->setObjectName(QStringLiteral("spinBoxAge"));
        spinBoxAge->setMinimum(18);
        spinBoxAge->setMaximum(70);

        horizontalLayout_6->addWidget(spinBoxAge);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        label_8 = new QLabel(layoutWidget1);
        label_8->setObjectName(QStringLiteral("label_8"));

        horizontalLayout_7->addWidget(label_8);

        spinBoxHeight = new QSpinBox(layoutWidget1);
        spinBoxHeight->setObjectName(QStringLiteral("spinBoxHeight"));
        spinBoxHeight->setMinimum(150);
        spinBoxHeight->setMaximum(210);

        horizontalLayout_7->addWidget(spinBoxHeight);


        verticalLayout_2->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        label_9 = new QLabel(layoutWidget1);
        label_9->setObjectName(QStringLiteral("label_9"));

        horizontalLayout_8->addWidget(label_9);

        spinBoxWeight = new QSpinBox(layoutWidget1);
        spinBoxWeight->setObjectName(QStringLiteral("spinBoxWeight"));
        spinBoxWeight->setMinimum(40);
        spinBoxWeight->setMaximum(150);

        horizontalLayout_8->addWidget(spinBoxWeight);


        verticalLayout_2->addLayout(horizontalLayout_8);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1220, 190, 601, 271));
        layoutWidget_2 = new QWidget(groupBox_2);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 584, 211));
        verticalLayout_4 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        pushButtonLoad = new QPushButton(layoutWidget_2);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));

        horizontalLayout_9->addWidget(pushButtonLoad);

        pushButtonSave = new QPushButton(layoutWidget_2);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        horizontalLayout_9->addWidget(pushButtonSave);

        pushButton = new QPushButton(layoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_9->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_9);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        label_12 = new QLabel(layoutWidget_2);
        label_12->setObjectName(QStringLiteral("label_12"));

        horizontalLayout_12->addWidget(label_12);

        spinBoxRowNumber = new QSpinBox(layoutWidget_2);
        spinBoxRowNumber->setObjectName(QStringLiteral("spinBoxRowNumber"));
        spinBoxRowNumber->setMinimum(1);
        spinBoxRowNumber->setMaximum(15);

        horizontalLayout_12->addWidget(spinBoxRowNumber);

        pushButtonAdd = new QPushButton(layoutWidget_2);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        horizontalLayout_12->addWidget(pushButtonAdd);

        pushButton_2 = new QPushButton(layoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_12->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_12->addWidget(pushButton_3);


        verticalLayout_4->addLayout(horizontalLayout_12);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        label_11 = new QLabel(layoutWidget_2);
        label_11->setObjectName(QStringLiteral("label_11"));

        horizontalLayout_11->addWidget(label_11);

        lineEdit_2 = new QLineEdit(layoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_11->addWidget(lineEdit_2);

        pushButtonSearch_2 = new QPushButton(layoutWidget_2);
        pushButtonSearch_2->setObjectName(QStringLiteral("pushButtonSearch_2"));

        horizontalLayout_11->addWidget(pushButtonSearch_2);


        verticalLayout_4->addLayout(horizontalLayout_11);

        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setObjectName(QStringLiteral("horizontalLayout_13"));
        label_13 = new QLabel(layoutWidget_2);
        label_13->setObjectName(QStringLiteral("label_13"));

        horizontalLayout_13->addWidget(label_13);

        comboBox_2 = new QComboBox(layoutWidget_2);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));

        horizontalLayout_13->addWidget(comboBox_2);

        pushButton_4 = new QPushButton(layoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        horizontalLayout_13->addWidget(pushButton_4);


        verticalLayout_4->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setObjectName(QStringLiteral("horizontalLayout_14"));
        label_14 = new QLabel(layoutWidget_2);
        label_14->setObjectName(QStringLiteral("label_14"));

        horizontalLayout_14->addWidget(label_14);

        spinBoxHeight_2 = new QSpinBox(layoutWidget_2);
        spinBoxHeight_2->setObjectName(QStringLiteral("spinBoxHeight_2"));
        spinBoxHeight_2->setMinimum(150);
        spinBoxHeight_2->setMaximum(210);

        horizontalLayout_14->addWidget(spinBoxHeight_2);

        pushButton_5 = new QPushButton(layoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        horizontalLayout_14->addWidget(pushButton_5);


        verticalLayout_4->addLayout(horizontalLayout_14);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setObjectName(QStringLiteral("horizontalLayout_15"));
        label_15 = new QLabel(layoutWidget_2);
        label_15->setObjectName(QStringLiteral("label_15"));

        horizontalLayout_15->addWidget(label_15);

        pushButton_6 = new QPushButton(layoutWidget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        horizontalLayout_15->addWidget(pushButton_6);


        verticalLayout_4->addLayout(horizontalLayout_15);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        label_10 = new QLabel(layoutWidget_2);
        label_10->setObjectName(QStringLiteral("label_10"));

        horizontalLayout_10->addWidget(label_10);

        spinBox_4 = new QSpinBox(layoutWidget_2);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(1);
        spinBox_4->setMaximum(15);

        horizontalLayout_10->addWidget(spinBox_4);

        pushButtonSearch = new QPushButton(layoutWidget_2);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        horizontalLayout_10->addWidget(pushButtonSearch);


        verticalLayout_4->addLayout(horizontalLayout_10);

        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(1460, 470, 161, 41));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1924, 17));
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
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\321\201\321\202\321\200\320\260\320\275\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\272\320\276\320\274\320\260\320\275\320\264\320\260", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\321\204\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\276\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\320\275\320\276\320\274\320\265\321\200", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\262\320\276\320\267\321\200\320\260\321\201\321\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "\320\262\320\265\321\201", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->horizontalHeaderItem(8);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "\321\200\320\276\321\201\321\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem22 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem22->setText(QApplication::translate("MainWindow", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem23 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem23->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
        groupBoxParticipant->setTitle(QApplication::translate("MainWindow", "\320\243\321\207\320\260\321\201\321\202\320\275\320\270\320\272 \320\272\320\276\320\274\320\260\320\275\320\264\321\213", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\241\321\202\321\200\320\260\320\275\320\260", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\232\320\276\320\274\320\260\320\275\320\264\320\260", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Fiksiki", Q_NULLPTR)
         << QApplication::translate("MainWindow", "O4kozavri", Q_NULLPTR)
         << QApplication::translate("MainWindow", "Bulbashi", Q_NULLPTR)
        );
        label_3->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_4->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        label_6->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200", Q_NULLPTR));
        label_7->setText(QApplication::translate("MainWindow", "\320\222\320\276\320\267\321\200\320\260\321\201\321\202", Q_NULLPTR));
        label_8->setText(QApplication::translate("MainWindow", "\320\240\320\276\321\201\321\202", Q_NULLPTR));
        label_9->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\201", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\320\267\321\203\320\270\321\202\321\214", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\262\321\201\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260", Q_NULLPTR));
        label_12->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        label_11->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217                                                        ", Q_NULLPTR));
        pushButtonSearch_2->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", Q_NULLPTR));
        label_13->setText(QApplication::translate("MainWindow", "\320\222\320\265\321\201\320\276\320\262\320\260\321\217 \320\272\320\260\321\202\320\265\320\263\320\276\321\200\320\270\321\217", Q_NULLPTR));
        comboBox_2->clear();
        comboBox_2->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "\320\273\320\265\320\263\320\272\320\260\321\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\321\201\321\200\320\265\320\264\320\275\321\217\321\217", Q_NULLPTR)
         << QApplication::translate("MainWindow", "\321\202\321\217\320\266\320\265\320\273\320\260\321\217", Q_NULLPTR)
        );
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", Q_NULLPTR));
        label_14->setText(QApplication::translate("MainWindow", "\320\240\320\276\321\201\321\202", Q_NULLPTR));
        pushButton_5->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", Q_NULLPTR));
        label_15->setText(QApplication::translate("MainWindow", "\320\241\320\260\320\274\320\260\321\217 \320\274\320\276\320\273\320\276\320\264\320\260\321\217 \320\272\320\276\320\274\320\260\320\275\320\264\320\260", Q_NULLPTR));
        pushButton_6->setText(QApplication::translate("MainWindow", "\320\262\321\213\320\262\320\276\320\264", Q_NULLPTR));
        label_10->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", Q_NULLPTR));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", Q_NULLPTR));
        pushButton_7->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260(\321\202\320\276\321\207\320\275\320\276-\321\202\320\276\321\207\320\275\320\276)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
