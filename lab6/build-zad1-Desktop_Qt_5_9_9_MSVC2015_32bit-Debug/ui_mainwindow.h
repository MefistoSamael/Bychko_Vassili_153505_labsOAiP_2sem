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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *OutputLabel;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QTreeWidget *treeWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout_2;
    QPushButton *AddPushButton;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *InsKeyspinBox;
    QLineEdit *DataLineEdit;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ShowByKeyPushButton;
    QPushButton *DelByKeyPushButton;
    QSpinBox *OtherKeySpinBox;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *PreOrderPushButton;
    QPushButton *PostOrderPushButton;
    QPushButton *InnerLeftPushButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *BalancePushButton;
    QPushButton *SomethinPushButton;
    QPushButton *TaskPushButton;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        OutputLabel = new QLabel(centralwidget);
        OutputLabel->setObjectName(QStringLiteral("OutputLabel"));
        OutputLabel->setGeometry(QRect(620, 460, 101, 16));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 0, 601, 541));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        treeWidget = new QTreeWidget(widget);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));

        verticalLayout_4->addWidget(treeWidget);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        AddPushButton = new QPushButton(widget);
        AddPushButton->setObjectName(QStringLiteral("AddPushButton"));

        verticalLayout_2->addWidget(AddPushButton);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        InsKeyspinBox = new QSpinBox(widget);
        InsKeyspinBox->setObjectName(QStringLiteral("InsKeyspinBox"));
        InsKeyspinBox->setMinimum(1);

        horizontalLayout_2->addWidget(InsKeyspinBox);

        DataLineEdit = new QLineEdit(widget);
        DataLineEdit->setObjectName(QStringLiteral("DataLineEdit"));

        horizontalLayout_2->addWidget(DataLineEdit);


        verticalLayout_2->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout_2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ShowByKeyPushButton = new QPushButton(widget);
        ShowByKeyPushButton->setObjectName(QStringLiteral("ShowByKeyPushButton"));

        horizontalLayout->addWidget(ShowByKeyPushButton);

        DelByKeyPushButton = new QPushButton(widget);
        DelByKeyPushButton->setObjectName(QStringLiteral("DelByKeyPushButton"));

        horizontalLayout->addWidget(DelByKeyPushButton);


        verticalLayout->addLayout(horizontalLayout);

        OtherKeySpinBox = new QSpinBox(widget);
        OtherKeySpinBox->setObjectName(QStringLiteral("OtherKeySpinBox"));
        OtherKeySpinBox->setMinimum(1);

        verticalLayout->addWidget(OtherKeySpinBox);


        horizontalLayout_3->addLayout(verticalLayout);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        PreOrderPushButton = new QPushButton(widget);
        PreOrderPushButton->setObjectName(QStringLiteral("PreOrderPushButton"));

        horizontalLayout_4->addWidget(PreOrderPushButton);

        PostOrderPushButton = new QPushButton(widget);
        PostOrderPushButton->setObjectName(QStringLiteral("PostOrderPushButton"));

        horizontalLayout_4->addWidget(PostOrderPushButton);

        InnerLeftPushButton = new QPushButton(widget);
        InnerLeftPushButton->setObjectName(QStringLiteral("InnerLeftPushButton"));

        horizontalLayout_4->addWidget(InnerLeftPushButton);


        verticalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(verticalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        BalancePushButton = new QPushButton(widget);
        BalancePushButton->setObjectName(QStringLiteral("BalancePushButton"));

        horizontalLayout_5->addWidget(BalancePushButton);

        SomethinPushButton = new QPushButton(widget);
        SomethinPushButton->setObjectName(QStringLiteral("SomethinPushButton"));

        horizontalLayout_5->addWidget(SomethinPushButton);

        TaskPushButton = new QPushButton(widget);
        TaskPushButton->setObjectName(QStringLiteral("TaskPushButton"));

        horizontalLayout_5->addWidget(TaskPushButton);


        verticalLayout_4->addLayout(horizontalLayout_5);

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
        OutputLabel->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\262\320\276\320\264:", Q_NULLPTR));
        AddPushButton->setText(QApplication::translate("MainWindow", "\320\264\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\215\320\273\320\265\320\274\320\265\320\275\321\202", Q_NULLPTR));
        ShowByKeyPushButton->setText(QApplication::translate("MainWindow", "\320\276\321\202\320\276\320\261\321\200\320\260\320\267\320\270\321\202\321\214 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", Q_NULLPTR));
        DelByKeyPushButton->setText(QApplication::translate("MainWindow", "\321\203\320\264\320\260\320\273\320\270\321\202\321\214 \320\277\320\276 \320\272\320\273\321\216\321\207\321\203", Q_NULLPTR));
        PreOrderPushButton->setText(QApplication::translate("MainWindow", "\320\277\321\200\321\217\320\274\320\276\320\271", Q_NULLPTR));
        PostOrderPushButton->setText(QApplication::translate("MainWindow", "\320\276\320\261\321\200\320\260\321\202\320\275\321\213\320\271", Q_NULLPTR));
        InnerLeftPushButton->setText(QApplication::translate("MainWindow", "\320\277\320\276 \320\262\320\276\320\267\321\200\321\200\320\260\321\201\321\202\320\260\320\275\320\270\321\216", Q_NULLPTR));
        BalancePushButton->setText(QApplication::translate("MainWindow", "\320\221\320\260\320\273\320\260\320\275\321\201", Q_NULLPTR));
        SomethinPushButton->setText(QApplication::translate("MainWindow", "\320\247\321\202\320\276-\320\275\320\270\320\261\321\203\320\264\321\214", Q_NULLPTR));
        TaskPushButton->setText(QApplication::translate("MainWindow", "\320\242\320\260\321\201\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
