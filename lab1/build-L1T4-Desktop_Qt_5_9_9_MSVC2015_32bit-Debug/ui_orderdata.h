/********************************************************************************
** Form generated from reading UI file 'orderdata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERDATA_H
#define UI_ORDERDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderData
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Daylabel;
    QSpinBox *DayspinBox;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Monthlabel;
    QSpinBox *MonthspinBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *Yearlabel;
    QSpinBox *YearspinBox;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QLineEdit *RequisiteslineEdit;

    void setupUi(QDialog *OrderData)
    {
        if (OrderData->objectName().isEmpty())
            OrderData->setObjectName(QStringLiteral("OrderData"));
        OrderData->resize(400, 300);
        groupBox = new QGroupBox(OrderData);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(30, 20, 351, 221));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(90, 180, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 50, 68, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Daylabel = new QLabel(layoutWidget);
        Daylabel->setObjectName(QStringLiteral("Daylabel"));

        horizontalLayout_2->addWidget(Daylabel);

        DayspinBox = new QSpinBox(layoutWidget);
        DayspinBox->setObjectName(QStringLiteral("DayspinBox"));
        DayspinBox->setMinimum(1);
        DayspinBox->setMaximum(31);

        horizontalLayout_2->addWidget(DayspinBox);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 80, 77, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Monthlabel = new QLabel(layoutWidget1);
        Monthlabel->setObjectName(QStringLiteral("Monthlabel"));

        horizontalLayout_3->addWidget(Monthlabel);

        MonthspinBox = new QSpinBox(layoutWidget1);
        MonthspinBox->setObjectName(QStringLiteral("MonthspinBox"));
        MonthspinBox->setMinimum(1);
        MonthspinBox->setMaximum(12);

        horizontalLayout_3->addWidget(MonthspinBox);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 110, 72, 24));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        Yearlabel = new QLabel(layoutWidget2);
        Yearlabel->setObjectName(QStringLiteral("Yearlabel"));

        horizontalLayout_4->addWidget(Yearlabel);

        YearspinBox = new QSpinBox(layoutWidget2);
        YearspinBox->setObjectName(QStringLiteral("YearspinBox"));
        YearspinBox->setMinimum(1);
        YearspinBox->setMaximum(9999);

        horizontalLayout_4->addWidget(YearspinBox);

        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 140, 256, 24));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget3);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout_5->addWidget(label);

        RequisiteslineEdit = new QLineEdit(layoutWidget3);
        RequisiteslineEdit->setObjectName(QStringLiteral("RequisiteslineEdit"));
        RequisiteslineEdit->setMaxLength(15);

        horizontalLayout_5->addWidget(RequisiteslineEdit);


        retranslateUi(OrderData);
        QObject::connect(buttonBox, SIGNAL(accepted()), OrderData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), OrderData, SLOT(reject()));

        QMetaObject::connectSlotsByName(OrderData);
    } // setupUi

    void retranslateUi(QDialog *OrderData)
    {
        OrderData->setWindowTitle(QApplication::translate("OrderData", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("OrderData", "\320\227\320\260\320\272\320\260\320\267", Q_NULLPTR));
        Daylabel->setText(QApplication::translate("OrderData", "\320\224\320\265\320\275\321\214", Q_NULLPTR));
        Monthlabel->setText(QApplication::translate("OrderData", "\320\234\320\265\321\201\321\217\321\206", Q_NULLPTR));
        Yearlabel->setText(QApplication::translate("OrderData", "\320\223\320\276\320\264", Q_NULLPTR));
        label->setText(QApplication::translate("OrderData", "\320\240\320\265\320\262\320\272\320\270\320\267\320\270\321\202\321\213 \320\267\320\260\320\272\320\260\320\267\321\207\320\270\320\272\320\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class OrderData: public Ui_OrderData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERDATA_H
