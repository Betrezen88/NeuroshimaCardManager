#include "Item.h"

Item::Item(QObject* parent) : Data(parent)
{

}

Item::Item(const QString &name,
           const QString &description,
           const int& price,
           QObject *parent)
    : Data(name, description, parent)
    , m_price(price)
{

}
