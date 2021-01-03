#include "Item.h"

Item::Item(QObject* parent) : Data(parent)
{

}

Item::Item(const Type &type
           , const QString &name
           , const QString &description
           , const int& price
           , const int &quantity
           , const QMap<Stat, QVariant>& stats
           , QObject *parent)
    : Data(name, description, parent)
    , m_type(type)
    , m_price(price)
    , m_quantity(quantity)
    , m_stats(stats)
{

}

Item::Type Item::type() const
{
    return m_type;
}

int Item::price() const
{
    return m_price;
}

int Item::quantity() const
{
    return m_quantity;
}

Item::Type Item::stringToType(const QString &type)
{
    if ( "armor" == type ) return Type::ARMOR;
    else if ( "handweapon" == type ) return Type::HANDWEAPON;
    else if ( "rangedweapon" == type ) return Type::RANGEDWEAPON;
    else if ( "shield" == type ) return Type::SHIELD;
    else if ( "consumable" == type ) return Type::CONSUMABLE;
    else return Type::OTHER;
}

QVariant Item::stat(const Item::Stat &stat) const
{
    if ( m_stats.contains(stat) )
        return m_stats.value(stat);

    return QVariant();
}

bool Item::hasStat(const Item::Stat &stat) const
{
    return m_stats.contains(stat);
}

void Item::setQuantity(int quantity)
{
    if (m_quantity == quantity)
        return;

    m_quantity = quantity;
    emit quantityChanged(m_quantity);
}
