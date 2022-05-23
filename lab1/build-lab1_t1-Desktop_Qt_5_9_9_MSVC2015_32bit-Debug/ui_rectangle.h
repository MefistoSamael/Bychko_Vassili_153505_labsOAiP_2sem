/********************************************************************************
** Form generated from reading UI file 'rectangle.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECTANGLE_H
#define UI_RECTANGLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_rectangle
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *rectangle)
    {
        if (rectangle->objectName().isEmpty())
            rectangle->setObjectName(QStringLiteral("rectangle"));
        rectangle->resize(1171, 770);
        centralwidget = new QWidget(rectangle);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(540, 570, 101, 41));
        rectangle->setCentralWidget(centralwidget);
        menubar = new QMenuBar(rectangle);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 1171, 17));
        rectangle->setMenuBar(menubar);
        statusbar = new QStatusBar(rectangle);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        rectangle->setStatusBar(statusbar);

        retranslateUi(rectangle);

        QMetaObject::connectSlotsByName(rectangle);
    } // setupUi

    void retranslateUi(QMainWindow *rectangle)
    {
        rectangle->setWindowTitle(QApplication::translate("rectangle", "rectangle", Q_NULLPTR));
        pushButton->setText(QApplication::translate("rectangle", "\320\237\320\276\320\265\321\205\320\260\320\273\320\270!", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class rectangle: public Ui_rectangle {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECTANGLE_H
