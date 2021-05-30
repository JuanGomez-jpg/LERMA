#include "purchase.h"

Purchase::Purchase()
{

}

QString Purchase::getProductId() const
{
    return productId;
}

void Purchase::setProductId(const QString &value)
{
    productId = value;
}

int Purchase::getAmount() const
{
    return amount;
}

void Purchase::setAmount(int value)
{
    amount = value;
}
