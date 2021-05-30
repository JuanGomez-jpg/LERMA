#ifndef PURCHASE_H
#define PURCHASE_H

#include <QString>

class Purchase
{
public:
    Purchase();

    QString getProductId() const;
    void setProductId(const QString &value);

    int getAmount() const;
    void setAmount(int value);

private:
    QString productId;
    int amount;
};

#endif // PURCHASE_H
