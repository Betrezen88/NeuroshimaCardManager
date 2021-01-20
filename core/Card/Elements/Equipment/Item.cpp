#include "Item.h"

#include <QDebug>

Item::Item(QObject* parent) : Data(parent)
{

}

Item::Item(const Type &type
           , const QString &name
           , const QString &description
           , const int& price
           , const int &quantity
           , const QMap<QString, QVariant> &stats
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

int Item::requiredBody() const
{
    if ( m_stats.contains("REQUIREMENT") )
        return m_stats.value("REQUIREMENT").toInt();
    return 0;
}

QStringList Item::damage() const
{
    if ( m_stats.contains("DAMAGE") )
        return m_stats.value("DAMAGE").toStringList();
    return QStringList();
}

int Item::penetration() const
{
    if ( m_stats.contains("PENETRATION") )
        return m_stats.value("PENETRATION").toInt();
    return 0;
}

int Item::durability() const
{
    if ( m_stats.contains("DURABILITY") )
        return m_stats.value("DURABILITY").toInt();
    return 0;
}

int Item::reputation() const
{
    if ( m_stats.contains("REPUTATION") )
        return m_stats.value("REPUTATION").toInt();
    return 0;
}

QString Item::magazine() const
{
    if ( m_stats.contains("MAGAZINE") )
        return m_stats.value("MAGAZINE").toString();
    return QString();
}

int Item::rateOfFire() const
{
    if ( m_stats.contains("RATEOFFIRE") )
        return m_stats.value("RATEOFFIRE").toInt();
    return 0;
}

int Item::ammunition() const
{
    if ( m_stats.contains("AMMUNITION") )
        return m_stats.value("AMMUNITION").toInt();
    return 0;
}

QMap<QString, QVariant> Item::dexBonus() const
{
    if ( m_stats.contains("BONUS") )
        return m_stats.value("BONUS").toMap();
    return QMap<QString, QVariant>();
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

bool Item::hasStat(const QString &stat) const
{
    return m_stats.contains(stat);
}

QString Item::bullet() const
{
    if ( m_stats.contains("BULLET") )
        return m_stats.value("BULLET").toString();
    return QString();
}

QList<QVariant> Item::special() const
{
    if ( m_stats.contains("SPECIAL") )
        return m_stats.value("SPECIAL").toList();
    return QList<QVariant>();
}

QMap<QString, QVariant> Item::locations() const
{
    if ( m_stats.contains("LOCATIONS") )
        return m_stats.value("LOCATIONS").toMap();
    return QMap<QString, QVariant>();
}

QList<QVariant> Item::penalties() const
{
    if ( m_stats.contains("PENALTIES") )
        return m_stats.value("PENALTIES").toList();
    return QList<QVariant>();
}

QList<QVariant> Item::features() const
{
    if ( m_stats.contains("FEATURES") )
        return m_stats.value("FEATURES").toList();
    return QList<QVariant>();
}

void Item::setQuantity(int quantity)
{
    if (m_quantity == quantity)
        return;

    m_quantity = quantity;
    emit quantityChanged(m_quantity);
}
