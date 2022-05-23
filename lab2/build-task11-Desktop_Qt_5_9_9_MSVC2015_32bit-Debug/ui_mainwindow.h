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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
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
    QGroupBox *groupBox;
    QWidget *layoutWidget;
    QHBoxLayout *studentLayout;
    QVBoxLayout *verticalLayout;
    QLabel *labelLastName;
    QLabel *labelName;
    QLabel *labelPatronymic;
    QLabel *labelUniversity;
    QLabel *labelGrades;
    QLabel *labelExam;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lineEditLastName;
    QLineEdit *lineEditName;
    QLineEdit *lineEditPatronymic;
    QLineEdit *lineEditUniversity;
    QHBoxLayout *horizontalLayout;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QRadioButton *radioButtonExam;
    QGroupBox *groupBox_2;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButtonLoad;
    QPushButton *pushButtonSave;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QSpinBox *spinBox_4;
    QPushButton *pushButtonSearch;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QDoubleSpinBox *doubleSpinBox;
    QPushButton *pushButtonSort;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QSpinBox *spinBoxRowNumber;
    QPushButton *pushButtonAdd;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
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
        if (tableWidget->rowCount() < 15)
            tableWidget->setRowCount(15);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(3, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(4, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(5, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(6, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(7, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(8, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(9, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(10, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(11, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(12, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(13, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableWidget->setVerticalHeaderItem(14, __qtablewidgetitem21);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(6, 6, 1200, 750));
        tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(1210, 10, 341, 201));
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 20, 331, 181));
        studentLayout = new QHBoxLayout(layoutWidget);
        studentLayout->setObjectName(QStringLiteral("studentLayout"));
        studentLayout->setContentsMargins(0, 0, 0, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelLastName = new QLabel(layoutWidget);
        labelLastName->setObjectName(QStringLiteral("labelLastName"));

        verticalLayout->addWidget(labelLastName);

        labelName = new QLabel(layoutWidget);
        labelName->setObjectName(QStringLiteral("labelName"));

        verticalLayout->addWidget(labelName);

        labelPatronymic = new QLabel(layoutWidget);
        labelPatronymic->setObjectName(QStringLiteral("labelPatronymic"));

        verticalLayout->addWidget(labelPatronymic);

        labelUniversity = new QLabel(layoutWidget);
        labelUniversity->setObjectName(QStringLiteral("labelUniversity"));

        verticalLayout->addWidget(labelUniversity);

        labelGrades = new QLabel(layoutWidget);
        labelGrades->setObjectName(QStringLiteral("labelGrades"));

        verticalLayout->addWidget(labelGrades);

        labelExam = new QLabel(layoutWidget);
        labelExam->setObjectName(QStringLiteral("labelExam"));

        verticalLayout->addWidget(labelExam);


        studentLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        lineEditLastName = new QLineEdit(layoutWidget);
        lineEditLastName->setObjectName(QStringLiteral("lineEditLastName"));
        lineEditLastName->setMaxLength(20);

        verticalLayout_2->addWidget(lineEditLastName);

        lineEditName = new QLineEdit(layoutWidget);
        lineEditName->setObjectName(QStringLiteral("lineEditName"));
        lineEditName->setMaxLength(20);

        verticalLayout_2->addWidget(lineEditName);

        lineEditPatronymic = new QLineEdit(layoutWidget);
        lineEditPatronymic->setObjectName(QStringLiteral("lineEditPatronymic"));
        lineEditPatronymic->setMaxLength(20);

        verticalLayout_2->addWidget(lineEditPatronymic);

        lineEditUniversity = new QLineEdit(layoutWidget);
        lineEditUniversity->setObjectName(QStringLiteral("lineEditUniversity"));
        lineEditUniversity->setMaxLength(20);

        verticalLayout_2->addWidget(lineEditUniversity);


        verticalLayout_3->addLayout(verticalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        spinBox = new QSpinBox(layoutWidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setMinimum(1);
        spinBox->setMaximum(10);

        horizontalLayout->addWidget(spinBox);

        spinBox_2 = new QSpinBox(layoutWidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setMinimum(1);
        spinBox_2->setMaximum(10);

        horizontalLayout->addWidget(spinBox_2);

        spinBox_3 = new QSpinBox(layoutWidget);
        spinBox_3->setObjectName(QStringLiteral("spinBox_3"));
        spinBox_3->setMinimum(1);
        spinBox_3->setMaximum(10);

        horizontalLayout->addWidget(spinBox_3);


        verticalLayout_3->addLayout(horizontalLayout);

        radioButtonExam = new QRadioButton(layoutWidget);
        radioButtonExam->setObjectName(QStringLiteral("radioButtonExam"));

        verticalLayout_3->addWidget(radioButtonExam);


        studentLayout->addLayout(verticalLayout_3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(1210, 230, 541, 201));
        layoutWidget1 = new QWidget(groupBox_2);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 30, 521, 171));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButtonLoad = new QPushButton(layoutWidget1);
        pushButtonLoad->setObjectName(QStringLiteral("pushButtonLoad"));

        horizontalLayout_4->addWidget(pushButtonLoad);

        pushButtonSave = new QPushButton(layoutWidget1);
        pushButtonSave->setObjectName(QStringLiteral("pushButtonSave"));

        horizontalLayout_4->addWidget(pushButtonSave);

        pushButton = new QPushButton(layoutWidget1);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        horizontalLayout_4->addWidget(pushButton);


        verticalLayout_4->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_3->addWidget(label);

        spinBox_4 = new QSpinBox(layoutWidget1);
        spinBox_4->setObjectName(QStringLiteral("spinBox_4"));
        spinBox_4->setMinimum(1);
        spinBox_4->setMaximum(15);

        horizontalLayout_3->addWidget(spinBox_4);

        pushButtonSearch = new QPushButton(layoutWidget1);
        pushButtonSearch->setObjectName(QStringLiteral("pushButtonSearch"));

        horizontalLayout_3->addWidget(pushButtonSearch);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout_5->addWidget(label_2);

        doubleSpinBox = new QDoubleSpinBox(layoutWidget1);
        doubleSpinBox->setObjectName(QStringLiteral("doubleSpinBox"));
        doubleSpinBox->setMinimum(1);
        doubleSpinBox->setMaximum(10);

        horizontalLayout_5->addWidget(doubleSpinBox);

        pushButtonSort = new QPushButton(layoutWidget1);
        pushButtonSort->setObjectName(QStringLiteral("pushButtonSort"));

        horizontalLayout_5->addWidget(pushButtonSort);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout_6->addWidget(label_3);

        spinBoxRowNumber = new QSpinBox(layoutWidget1);
        spinBoxRowNumber->setObjectName(QStringLiteral("spinBoxRowNumber"));
        spinBoxRowNumber->setMinimum(1);
        spinBoxRowNumber->setMaximum(15);

        horizontalLayout_6->addWidget(spinBoxRowNumber);

        pushButtonAdd = new QPushButton(layoutWidget1);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        horizontalLayout_6->addWidget(pushButtonAdd);

        pushButton_2 = new QPushButton(layoutWidget1);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        horizontalLayout_6->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(layoutWidget1);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        horizontalLayout_6->addWidget(pushButton_3);


        verticalLayout_4->addLayout(horizontalLayout_6);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(1240, 450, 281, 31));
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
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "\321\204\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "\320\270\320\274\321\217", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "\320\276\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "\321\203\320\275\320\270\320\262\320\265\321\200\321\201\320\270\321\202\320\265\321\202", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "\320\276\321\206\320\265\320\275\320\272\320\270 \320\267\320\260 \321\215\320\272\320\267\320\260\320\274\320\265\320\275", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "\321\201\321\200\320\265\320\264\320\275\320\270\320\271 \320\261\320\260\320\273\320\273", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "\320\261\321\213\320\273 \320\275\320\260 \321\215\320\272\320\267\320\260\320\274\320\265\320\275\320\265?", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidget->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "1", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidget->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "2", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem9 = tableWidget->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QApplication::translate("MainWindow", "3", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem10 = tableWidget->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QApplication::translate("MainWindow", "4", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem11 = tableWidget->verticalHeaderItem(4);
        ___qtablewidgetitem11->setText(QApplication::translate("MainWindow", "5", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem12 = tableWidget->verticalHeaderItem(5);
        ___qtablewidgetitem12->setText(QApplication::translate("MainWindow", "6", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem13 = tableWidget->verticalHeaderItem(6);
        ___qtablewidgetitem13->setText(QApplication::translate("MainWindow", "7", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem14 = tableWidget->verticalHeaderItem(7);
        ___qtablewidgetitem14->setText(QApplication::translate("MainWindow", "8", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem15 = tableWidget->verticalHeaderItem(8);
        ___qtablewidgetitem15->setText(QApplication::translate("MainWindow", "9", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem16 = tableWidget->verticalHeaderItem(9);
        ___qtablewidgetitem16->setText(QApplication::translate("MainWindow", "10", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem17 = tableWidget->verticalHeaderItem(10);
        ___qtablewidgetitem17->setText(QApplication::translate("MainWindow", "11", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem18 = tableWidget->verticalHeaderItem(11);
        ___qtablewidgetitem18->setText(QApplication::translate("MainWindow", "12", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem19 = tableWidget->verticalHeaderItem(12);
        ___qtablewidgetitem19->setText(QApplication::translate("MainWindow", "13", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem20 = tableWidget->verticalHeaderItem(13);
        ___qtablewidgetitem20->setText(QApplication::translate("MainWindow", "14", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem21 = tableWidget->verticalHeaderItem(14);
        ___qtablewidgetitem21->setText(QApplication::translate("MainWindow", "15", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MainWindow", "\320\241\321\202\321\203\320\264\320\265\320\275\321\202", Q_NULLPTR));
        labelLastName->setText(QApplication::translate("MainWindow", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        labelName->setText(QApplication::translate("MainWindow", "\320\230\320\274\321\217", Q_NULLPTR));
        labelPatronymic->setText(QApplication::translate("MainWindow", "\320\236\321\202\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
        labelUniversity->setText(QApplication::translate("MainWindow", "\320\243\320\275\320\270\320\262\320\265\321\200\321\201\320\270\321\202\320\265\321\202", Q_NULLPTR));
        labelGrades->setText(QApplication::translate("MainWindow", "\320\236\321\206\320\265\320\275\320\272\320\270 \320\267\320\260 \321\215\320\272\320\267\320\260\320\274\320\265\320\275", Q_NULLPTR));
        labelExam->setText(QApplication::translate("MainWindow", "\320\221\321\213\320\273 \320\273\320\270 \320\275\320\260 \321\215\320\272\320\267\320\260\320\274\320\265\320\275\320\265", Q_NULLPTR));
        radioButtonExam->setText(QApplication::translate("MainWindow", "\320\221\321\213\320\273", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "\320\242\320\260\320\261\320\273\320\270\321\206\320\260", Q_NULLPTR));
        pushButtonLoad->setText(QApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\320\267\321\203\320\270\321\202\321\214", Q_NULLPTR));
        pushButtonSave->setText(QApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264 \320\262\321\201\320\265\320\263\320\276 \321\201\320\277\320\270\321\201\320\272\320\260", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\215\320\273\320\265\320\274\320\265\320\275\321\202\320\260", Q_NULLPTR));
        pushButtonSearch->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "\320\241\321\200\320\265\320\264\320\275\320\270\320\271 \320\261\320\260\320\273\320\273", Q_NULLPTR));
        pushButtonSort->setText(QApplication::translate("MainWindow", "\320\237\320\276\320\270\321\201\320\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "\320\235\320\276\320\274\320\265\321\200 \321\201\321\202\321\200\320\276\320\272\320\270", Q_NULLPTR));
        pushButtonAdd->setText(QApplication::translate("MainWindow", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("MainWindow", "\320\230\320\267\320\274\320\265\320\275\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_3->setText(QApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\320\270\321\202\321\214", Q_NULLPTR));
        pushButton_4->setText(QApplication::translate("MainWindow", "\320\247\320\265\321\201\321\202\320\275\320\276 \321\207\320\265\321\201\321\202\320\275\320\276, \321\215\321\202\320\276 \321\201\320\276\321\200\321\202\320\270\321\200\320\276\320\262\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
