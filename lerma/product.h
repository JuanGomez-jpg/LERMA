#ifndef PRODUCT_H
#define PRODUCT_H

#include <QString>

class Product
{
public:
    Product();

    QString getId() const;
    void setId(const QString &value);

    QString getName() const;
    void setName(const QString &value);

    double getPrice() const;
    void setPrice(double value);

    double getWeight() const;
    void setWeight(double value);

private:
    QString id;
    QString name;
    double price;
    double weight;
};

#endif // PRODUCT_H
