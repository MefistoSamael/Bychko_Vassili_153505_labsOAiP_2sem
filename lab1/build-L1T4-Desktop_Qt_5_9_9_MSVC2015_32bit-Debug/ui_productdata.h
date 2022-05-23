/********************************************************************************
** Form generated from reading UI file 'productdata.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTDATA_H
#define UI_PRODUCTDATA_H

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

class Ui_ProductData
{
public:
    QGroupBox *groupBox;
    QDialogButtonBox *buttonBox;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *Namelabel;
    QLineEdit *NamelineEdit;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_2;
    QLabel *Pricelabel;
    QSpinBox *PricespinBox;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *Numberlabel;
    QSpinBox *NumberspinBox;

    void setupUi(QDialog *ProductData)
    {
        if (ProductData->objectName().isEmpty())
            ProductData->setObjectName(QStringLiteral("ProductData"));
        ProductData->resize(400, 300);
        groupBox = new QGroupBox(ProductData);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(40, 20, 311, 221));
        buttonBox = new QDialogButtonBox(groupBox);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(50, 180, 161, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        layoutWidget = new QWidget(groupBox);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 120, 224, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Namelabel = new QLabel(layoutWidget);
        Namelabel->setObjectName(QStringLiteral("Namelabel"));

        horizontalLayout->addWidget(Namelabel);

        NamelineEdit = new QLineEdit(layoutWidget);
        NamelineEdit->setObjectName(QStringLiteral("NamelineEdit"));
        NamelineEdit->setMaxLength(15);

        horizontalLayout->addWidget(NamelineEdit);

        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(21, 70, 117, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        Pricelabel = new QLabel(layoutWidget1);
        Pricelabel->setObjectName(QStringLiteral("Pricelabel"));

        horizontalLayout_2->addWidget(Pricelabel);

        PricespinBox = new QSpinBox(layoutWidget1);
        PricespinBox->setObjectName(QStringLiteral("PricespinBox"));
        PricespinBox->setMinimum(1);
        PricespinBox->setMaximum(1001);

        horizontalLayout_2->addWidget(PricespinBox);

        layoutWidget2 = new QWidget(groupBox);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(21, 30, 106, 24));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        Numberlabel = new QLabel(layoutWidget2);
        Numberlabel->setObjectName(QStringLiteral("Numberlabel"));

        horizontalLayout_3->addWidget(Numberlabel);

        NumberspinBox = new QSpinBox(layoutWidget2);
        NumberspinBox->setObjectName(QStringLiteral("NumberspinBox"));
        NumberspinBox->setMinimum(1);

        horizontalLayout_3->addWidget(NumberspinBox);


        retranslateUi(ProductData);
        QObject::connect(buttonBox, SIGNAL(accepted()), ProductData, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), ProductData, SLOT(reject()));

        QMetaObject::connectSlotsByName(ProductData);
    } // setupUi

    void retranslateUi(QDialog *ProductData)
    {
        ProductData->setWindowTitle(QApplication::translate("ProductData", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("ProductData", "\320\242\320\276\320\262\320\260\321\200", Q_NULLPTR));
        Namelabel->setText(QApplication::translate("ProductData", "\320\235\320\260\320\270\320\274\320\265\320\275\320\276\320\262\320\260\320\275\320\270\320\265", Q_NULLPTR));
        Pricelabel->setText(QApplication::translate("ProductData", "\320\246\320\265\320\275\320\260 \320\267\320\260 \321\210\321\202.", Q_NULLPTR));
        Numberlabel->setText(QApplication::translate("ProductData", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProductData: public Ui_ProductData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTDATA_H
