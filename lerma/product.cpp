#include "product.h"

Product::Product()
{

}

QString Product::getId() const
{
    return id;
}

void Product::setId(const QString &value)
{
    id = value;
}

QString Product::getName() const
{
    return name;
}

void Product::setName(const QString &value)
{
    name = value;
}

double Product::getPrice() const
{
    return price;
}

void Product::setPrice(double value)
{
    price = value;
}

double Product::getWeight() const
{
    return weight;
}

void Product::setWeight(double value)
{
    weight = value;
}
