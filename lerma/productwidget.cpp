#include "productwidget.h"
#include "ui_productwidget.h"

ProductWidget::ProductWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProductWidget)
{
    ui->setupUi(this);
}

ProductWidget::~ProductWidget()
{
    delete ui;
}

QString ProductWidget::getId() const
{
    return id;
}

void ProductWidget::setId(const QString &value)
{
    id = value;
}

QString ProductWidget::getName() const
{
    return name;
}

void ProductWidget::setName(const QString &value)
{
    name = value;
}

QString ProductWidget::getPrice() const
{
    return price;
}

void ProductWidget::setPrice(const QString &value)
{
    price = value;
}

void ProductWidget::showProduct()
{
    QPixmap pix(":/Resources/imgs/" + id + ".jpg");
    int w = ui->lblPicture->width();
    int h = ui->lblPicture->height();
    ui->lblPicture->setPixmap(pix.scaled(w,h,Qt::IgnoreAspectRatio));
    ui->lblName->setText(name);
    ui->lblPrice->setText(price);
}

void ProductWidget::on_addPB_clicked()
{
    emit addItem(id , ui->amountSB->value());
    ui->amountSB->setValue(0);
}

void ProductWidget::on_amountSB_valueChanged(int arg1)
{
    if (arg1 > 0)
    {
        ui->addPB->setEnabled(true);
    }
    else
    {
        ui->addPB->setEnabled(false);
    }
}
