/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_widget
{
public:
    QWidget *centralwidget;
    QComboBox *comboBox;
    QSpinBox *X;
    QSpinBox *Y;
    QSpinBox *Height;
    QSpinBox *Base;
    QSpinBox *RotationAngle;
    QSpinBox *angle;
    QPushButton *Draw;
    QLabel *Sq;
    QLabel *Per;
    QLabel *Xx;
    QLabel *Yy;
    QLabel *Hh;
    QLabel *Bb;
    QLabel *RDrd;
    QLabel *degree;
    QLabel *square;
    QLabel *perimetr;
    QLabel *center;
    QLabel *show;
    QCheckBox *showcenter;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *widget)
    {
        if (widget->objectName().isEmpty())
            widget->setObjectName(QStringLiteral("widget"));
        widget->resize(1129, 600);
        centralwidget = new QWidget(widget);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(920, 190, 91, 22));
        X = new QSpinBox(centralwidget);
        X->setObjectName(QStringLiteral("X"));
        X->setGeometry(QRect(920, 10, 71, 22));
        X->setMaximum(1000);
        Y = new QSpinBox(centralwidget);
        Y->setObjectName(QStringLiteral("Y"));
        Y->setGeometry(QRect(920, 40, 71, 22));
        Y->setMaximum(1000);
        Height = new QSpinBox(centralwidget);
        Height->setObjectName(QStringLiteral("Height"));
        Height->setGeometry(QRect(920, 70, 71, 22));
        Height->setMaximum(1000);
        Base = new QSpinBox(centralwidget);
        Base->setObjectName(QStringLiteral("Base"));
        Base->setGeometry(QRect(920, 100, 71, 22));
        Base->setMaximum(1000);
        RotationAngle = new QSpinBox(centralwidget);
        RotationAngle->setObjectName(QStringLiteral("RotationAngle"));
        RotationAngle->setGeometry(QRect(920, 130, 71, 22));
        RotationAngle->setMaximum(999999999);
        angle = new QSpinBox(centralwidget);
        angle->setObjectName(QStringLiteral("angle"));
        angle->setGeometry(QRect(920, 160, 71, 22));
        angle->setMaximum(1000);
        Draw = new QPushButton(centralwidget);
        Draw->setObjectName(QStringLiteral("Draw"));
        Draw->setGeometry(QRect(1030, 10, 75, 23));
        Sq = new QLabel(centralwidget);
        Sq->setObjectName(QStringLiteral("Sq"));
        Sq->setGeometry(QRect(1030, 40, 47, 14));
        Per = new QLabel(centralwidget);
        Per->setObjectName(QStringLiteral("Per"));
        Per->setGeometry(QRect(1030, 60, 47, 14));
        Xx = new QLabel(centralwidget);
        Xx->setObjectName(QStringLiteral("Xx"));
        Xx->setGeometry(QRect(886, 10, 21, 20));
        Yy = new QLabel(centralwidget);
        Yy->setObjectName(QStringLiteral("Yy"));
        Yy->setGeometry(QRect(890, 40, 21, 20));
        Hh = new QLabel(centralwidget);
        Hh->setObjectName(QStringLiteral("Hh"));
        Hh->setGeometry(QRect(870, 70, 41, 20));
        Bb = new QLabel(centralwidget);
        Bb->setObjectName(QStringLiteral("Bb"));
        Bb->setGeometry(QRect(870, 100, 41, 20));
        RDrd = new QLabel(centralwidget);
        RDrd->setObjectName(QStringLiteral("RDrd"));
        RDrd->setGeometry(QRect(820, 130, 91, 20));
        degree = new QLabel(centralwidget);
        degree->setObjectName(QStringLiteral("degree"));
        degree->setGeometry(QRect(860, 160, 47, 14));
        square = new QLabel(centralwidget);
        square->setObjectName(QStringLiteral("square"));
        square->setGeometry(QRect(1050, 40, 49, 16));
        perimetr = new QLabel(centralwidget);
        perimetr->setObjectName(QStringLiteral("perimetr"));
        perimetr->setGeometry(QRect(1050, 60, 49, 16));
        center = new QLabel(centralwidget);
        center->setObjectName(QStringLiteral("center"));
        center->setGeometry(QRect(1050, 100, 61, 16));
        show = new QLabel(centralwidget);
        show->setObjectName(QStringLiteral("show"));
        show->setGeometry(QRect(1050, 80, 49, 16));
        showcenter = new QCheckBox(centralwidget);
        showcenter->setObjectName(QStringLiteral("showcenter"));
        showcenter->setGeometry(QRect(1030, 90, 16, 20));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(960, 540, 151, 21));
        widget->setCentralWidget(centralwidget);
        menubar = new QMenuBar(widget);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1129, 17));
        widget->setMenuBar(menubar);
        statusbar = new QStatusBar(widget);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        widget->setStatusBar(statusbar);

        retranslateUi(widget);

        QMetaObject::connectSlotsByName(widget);
    } // setupUi

    void retranslateUi(QMainWindow *widget)
    {
        widget->setWindowTitle(QApplication::translate("widget", "widget", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("widget", "\320\272\320\262\320\260\320\264\321\200\320\260\321\202", Q_NULLPTR)
         << QApplication::translate("widget", "\320\277\321\200\321\217\320\274\320\276\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", Q_NULLPTR)
         << QApplication::translate("widget", "\321\202\321\200\320\265\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", Q_NULLPTR)
         << QApplication::translate("widget", "\320\272\321\200\321\203\320\263", Q_NULLPTR)
         << QApplication::translate("widget", "\321\200\320\276\320\274\320\261", Q_NULLPTR)
         << QApplication::translate("widget", "\321\210\320\265\321\201\321\202\320\270\321\203\320\263\320\276\320\273\321\214\320\275\320\270\320\272", Q_NULLPTR)
         << QApplication::translate("widget", "\320\267\320\262\320\265\320\267\320\264\320\2606", Q_NULLPTR)
         << QApplication::translate("widget", "\320\267\320\262\320\265\320\267\320\264\320\2608", Q_NULLPTR)
         << QApplication::translate("widget", "\320\267\320\262\320\265\320\267\320\264\320\2605", Q_NULLPTR)
         << QApplication::translate("widget", "\320\242", Q_NULLPTR)
        );
        Draw->setText(QApplication::translate("widget", "\320\235\320\260\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214", Q_NULLPTR));
        Sq->setText(QApplication::translate("widget", "S = ", Q_NULLPTR));
        Per->setText(QApplication::translate("widget", "P = ", Q_NULLPTR));
        Xx->setText(QApplication::translate("widget", "X =", Q_NULLPTR));
        Yy->setText(QApplication::translate("widget", "Y =", Q_NULLPTR));
        Hh->setText(QApplication::translate("widget", "Height =", Q_NULLPTR));
        Bb->setText(QApplication::translate("widget", "Base =", Q_NULLPTR));
        RDrd->setText(QApplication::translate("widget", "Rotation degree =", Q_NULLPTR));
        degree->setText(QApplication::translate("widget", "Degree =", Q_NULLPTR));
        square->setText(QString());
        perimetr->setText(QString());
        center->setText(QApplication::translate("widget", "\320\261\320\260\321\200\320\270\321\206\320\265\320\275\321\202\321\200", Q_NULLPTR));
        show->setText(QApplication::translate("widget", "\320\237\320\276\320\272\320\260\320\267\320\260\321\202\321\214 ", Q_NULLPTR));
        showcenter->setText(QString());
        pushButton->setText(QApplication::translate("widget", "Canvas", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class widget: public Ui_widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
