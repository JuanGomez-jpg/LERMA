#ifndef PRODUCTWIDGET_H
#define PRODUCTWIDGET_H

#include <QWidget>
#include <QString>

namespace Ui {
class ProductWidget;
}

class ProductWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ProductWidget(QWidget *parent = nullptr);
    ~ProductWidget();

    QString getId() const;
    void setId(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    QString getPrice() const;
    void setPrice(const QString &value);

    void showProduct();

signals:
    void addItem(QString id, int amount);

private slots:
    void on_addPB_clicked();

    void on_amountSB_valueChanged(int arg1);

private:
    Ui::ProductWidget *ui;
    QString id;
    QString name;
    QString price;

};

#endif // PRODUCTWIDGET_H
