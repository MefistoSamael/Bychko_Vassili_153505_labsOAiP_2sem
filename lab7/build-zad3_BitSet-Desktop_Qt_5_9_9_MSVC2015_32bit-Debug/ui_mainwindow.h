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
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButtonAll;
    QPushButton *pushButtonAny;
    QPushButton *pushButtonCount;
    QPushButton *pushButtonNone;
    QPushButton *pushButtonReset;
    QPushButton *pushButtonSet;
    QPushButton *pushButtonSize;
    QPushButton *pushButtonTest;
    QSpinBox *spinBox;
    QRadioButton *radioButtonBitSet1;
    QRadioButton *radioButtonBitSet2;
    QLineEdit *lineEditBitSet1;
    QLabel *label;
    QLineEdit *lineEditBitSet2;
    QLabel *label_2;
    QTextEdit *textEdit;
    QSpinBox *spinBox_2;
    QPushButton *pushButton;
    QTextEdit *textEditOutput;
    QPushButton *pushButtonULL;
    QPushButton *pushButtonUL;
    QPushButton *pushButtonAnd;
    QPushButton *pushButtonOr;
    QPushButton *pushButtonXor;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButtonAll = new QPushButton(centralwidget);
        pushButtonAll->setObjectName(QStringLiteral("pushButtonAll"));
        pushButtonAll->setGeometry(QRect(10, 10, 111, 51));
        pushButtonAny = new QPushButton(centralwidget);
        pushButtonAny->setObjectName(QStringLiteral("pushButtonAny"));
        pushButtonAny->setGeometry(QRect(10, 70, 111, 51));
        pushButtonCount = new QPushButton(centralwidget);
        pushButtonCount->setObjectName(QStringLiteral("pushButtonCount"));
        pushButtonCount->setGeometry(QRect(130, 10, 111, 51));
        pushButtonNone = new QPushButton(centralwidget);
        pushButtonNone->setObjectName(QStringLiteral("pushButtonNone"));
        pushButtonNone->setGeometry(QRect(130, 70, 111, 51));
        pushButtonReset = new QPushButton(centralwidget);
        pushButtonReset->setObjectName(QStringLiteral("pushButtonReset"));
        pushButtonReset->setGeometry(QRect(10, 130, 111, 51));
        pushButtonSet = new QPushButton(centralwidget);
        pushButtonSet->setObjectName(QStringLiteral("pushButtonSet"));
        pushButtonSet->setGeometry(QRect(130, 130, 111, 51));
        pushButtonSize = new QPushButton(centralwidget);
        pushButtonSize->setObjectName(QStringLiteral("pushButtonSize"));
        pushButtonSize->setGeometry(QRect(10, 190, 231, 51));
        pushButtonTest = new QPushButton(centralwidget);
        pushButtonTest->setObjectName(QStringLiteral("pushButtonTest"));
        pushButtonTest->setGeometry(QRect(10, 250, 111, 51));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QStringLiteral("spinBox"));
        spinBox->setGeometry(QRect(130, 260, 111, 31));
        spinBox->setMaximum(11);
        radioButtonBitSet1 = new QRadioButton(centralwidget);
        radioButtonBitSet1->setObjectName(QStringLiteral("radioButtonBitSet1"));
        radioButtonBitSet1->setGeometry(QRect(700, 30, 91, 31));
        radioButtonBitSet1->setChecked(true);
        radioButtonBitSet2 = new QRadioButton(centralwidget);
        radioButtonBitSet2->setObjectName(QStringLiteral("radioButtonBitSet2"));
        radioButtonBitSet2->setGeometry(QRect(700, 70, 91, 31));
        lineEditBitSet1 = new QLineEdit(centralwidget);
        lineEditBitSet1->setObjectName(QStringLiteral("lineEditBitSet1"));
        lineEditBitSet1->setGeometry(QRect(480, 20, 141, 41));
        lineEditBitSet1->setReadOnly(true);
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(630, 30, 61, 21));
        lineEditBitSet2 = new QLineEdit(centralwidget);
        lineEditBitSet2->setObjectName(QStringLiteral("lineEditBitSet2"));
        lineEditBitSet2->setGeometry(QRect(480, 70, 141, 41));
        lineEditBitSet2->setReadOnly(true);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(630, 80, 61, 21));
        textEdit = new QTextEdit(centralwidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(270, 10, 201, 111));
        textEdit->setReadOnly(true);
        spinBox_2 = new QSpinBox(centralwidget);
        spinBox_2->setObjectName(QStringLiteral("spinBox_2"));
        spinBox_2->setGeometry(QRect(270, 130, 111, 41));
        spinBox_2->setMinimum(0);
        spinBox_2->setMaximum(999);
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(390, 130, 80, 41));
        textEditOutput = new QTextEdit(centralwidget);
        textEditOutput->setObjectName(QStringLiteral("textEditOutput"));
        textEditOutput->setGeometry(QRect(270, 180, 201, 121));
        textEditOutput->setReadOnly(true);
        pushButtonULL = new QPushButton(centralwidget);
        pushButtonULL->setObjectName(QStringLiteral("pushButtonULL"));
        pushButtonULL->setGeometry(QRect(10, 310, 111, 51));
        pushButtonUL = new QPushButton(centralwidget);
        pushButtonUL->setObjectName(QStringLiteral("pushButtonUL"));
        pushButtonUL->setGeometry(QRect(130, 310, 111, 51));
        pushButtonAnd = new QPushButton(centralwidget);
        pushButtonAnd->setObjectName(QStringLiteral("pushButtonAnd"));
        pushButtonAnd->setGeometry(QRect(10, 400, 111, 51));
        pushButtonOr = new QPushButton(centralwidget);
        pushButtonOr->setObjectName(QStringLiteral("pushButtonOr"));
        pushButtonOr->setGeometry(QRect(130, 400, 111, 51));
        pushButtonXor = new QPushButton(centralwidget);
        pushButtonXor->setObjectName(QStringLiteral("pushButtonXor"));
        pushButtonXor->setGeometry(QRect(10, 460, 111, 51));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 17));
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
        pushButtonAll->setText(QApplication::translate("MainWindow", "ALL", Q_NULLPTR));
        pushButtonAny->setText(QApplication::translate("MainWindow", "Any", Q_NULLPTR));
        pushButtonCount->setText(QApplication::translate("MainWindow", "Count", Q_NULLPTR));
        pushButtonNone->setText(QApplication::translate("MainWindow", "None", Q_NULLPTR));
        pushButtonReset->setText(QApplication::translate("MainWindow", "Reset", Q_NULLPTR));
        pushButtonSet->setText(QApplication::translate("MainWindow", "Set", Q_NULLPTR));
        pushButtonSize->setText(QApplication::translate("MainWindow", "Size", Q_NULLPTR));
        pushButtonTest->setText(QApplication::translate("MainWindow", "Test", Q_NULLPTR));
        radioButtonBitSet1->setText(QApplication::translate("MainWindow", "BitSet1", Q_NULLPTR));
        radioButtonBitSet2->setText(QApplication::translate("MainWindow", "BitSet2", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "BitSet1", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "BitSet2", Q_NULLPTR));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\222\320\262\320\276\320\264 \320\262 BitSet \320\277\321\200\320\276\320\270\320\267\320\262\320\276\320\264\320\270\321\202\321\201\321\217 \320\277\320\276 \321\201\321\200\320\265\320\264\321\201\321\202\320\262\320\276\320\274 \321\207\320\270\321\201\320\273\320\260, \320\262\320\262\320\265\320\264\320\265\320\275\320\276\320\263\320\276 \320\275\320\270\320\266\320\265</p></body></html>", Q_NULLPTR));
        pushButton->setText(QApplication::translate("MainWindow", "\320\222\320\262\320\276\320\264", Q_NULLPTR));
        textEditOutput->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><meta charset=\"utf-8\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Segoe UI'; font-size:9pt; font-weight:400; font-style:normal;\">\n"
"<p align=\"center\" style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\">\320\227\320\264\320\265\321\201\321\214 \320\261\321\203\320\264\320\265\321\202 \320\275\320\265\320\272\320\276\321\202\320\276\321\200\321\213\320\271 \320\262\321\213\320\262\320\276\320\264</p></body></html>", Q_NULLPTR));
        pushButtonULL->setText(QApplication::translate("MainWindow", "to_ullong", Q_NULLPTR));
        pushButtonUL->setText(QApplication::translate("MainWindow", "to_ulong", Q_NULLPTR));
        pushButtonAnd->setText(QApplication::translate("MainWindow", "And", Q_NULLPTR));
        pushButtonOr->setText(QApplication::translate("MainWindow", "Or", Q_NULLPTR));
        pushButtonXor->setText(QApplication::translate("MainWindow", "Xor", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
