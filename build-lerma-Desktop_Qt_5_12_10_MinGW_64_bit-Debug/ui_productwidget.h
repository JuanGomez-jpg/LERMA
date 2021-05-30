/********************************************************************************
** Form generated from reading UI file 'productwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRODUCTWIDGET_H
#define UI_PRODUCTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProductWidget
{
public:
    QLabel *lblName;
    QLabel *lblPrice;
    QLabel *lblPicture;
    QSpinBox *amountSB;
    QPushButton *addPB;

    void setupUi(QWidget *ProductWidget)
    {
        if (ProductWidget->objectName().isEmpty())
            ProductWidget->setObjectName(QString::fromUtf8("ProductWidget"));
        ProductWidget->resize(187, 224);
        ProductWidget->setMinimumSize(QSize(100, 200));
        lblName = new QLabel(ProductWidget);
        lblName->setObjectName(QString::fromUtf8("lblName"));
        lblName->setGeometry(QRect(10, 130, 151, 16));
        lblPrice = new QLabel(ProductWidget);
        lblPrice->setObjectName(QString::fromUtf8("lblPrice"));
        lblPrice->setGeometry(QRect(10, 150, 161, 16));
        lblPicture = new QLabel(ProductWidget);
        lblPicture->setObjectName(QString::fromUtf8("lblPicture"));
        lblPicture->setGeometry(QRect(20, 10, 131, 111));
        amountSB = new QSpinBox(ProductWidget);
        amountSB->setObjectName(QString::fromUtf8("amountSB"));
        amountSB->setGeometry(QRect(20, 170, 60, 27));
        amountSB->setMaximumSize(QSize(60, 30));
        addPB = new QPushButton(ProductWidget);
        addPB->setObjectName(QString::fromUtf8("addPB"));
        addPB->setEnabled(false);
        addPB->setGeometry(QRect(100, 170, 60, 27));
        addPB->setMaximumSize(QSize(60, 30));

        retranslateUi(ProductWidget);

        QMetaObject::connectSlotsByName(ProductWidget);
    } // setupUi

    void retranslateUi(QWidget *ProductWidget)
    {
        ProductWidget->setWindowTitle(QApplication::translate("ProductWidget", "Form", nullptr));
        lblName->setText(QApplication::translate("ProductWidget", "Name", nullptr));
        lblPrice->setText(QApplication::translate("ProductWidget", "Pricel", nullptr));
        lblPicture->setText(QApplication::translate("ProductWidget", "pic", nullptr));
        addPB->setText(QApplication::translate("ProductWidget", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProductWidget: public Ui_ProductWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRODUCTWIDGET_H
