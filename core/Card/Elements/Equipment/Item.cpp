#include "Item.h"

#include "DataSources/Elements/Stats/Requirement.h"
#include "Card/Elements/Equipment/DexterityBonus.h"
#include "Card/Elements/Equipment/Location.h"

#include <QDebug>

Item::Item(QObject* parent) : Data(parent)
{

}

Item::Item(const QString &type
           , const QString &name
           , const QString &description
           , const int& price
           , const int &quantity
           , QObject *parent)
    : Data(name, description, parent)
    , m_type(type)
    , m_price(price)
    , m_quantity(quantity)
{

}

QString Item::type() const
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

int Item::reputation() const
{
    return m_reputation;
}

QStringList Item::damage() const
{
    return m_damage;
}

int Item::penetration() const
{
    return m_penetration;
}

QQmlListProperty<Data> Item::specials()
{
    return QQmlListProperty<Data>(this, this,
                                  &Item::specialsCount,
                                  &Item::special);
}

QList<Data *> Item::specials() const
{
    return m_specials;
}

int Item::specialsCount() const
{
    return m_specials.count();
}

Data *Item::special(const int index) const
{
    return m_specials.at(index);
}

QQmlListProperty<DexterityBonus> Item::dexterityBonuses()
{
    return QQmlListProperty<DexterityBonus>(this, this,
                                            &Item::dexterityBonusesCount,
                                            &Item::dexterityBonus);
}

QList<DexterityBonus *> Item::dexterityBonuses() const
{
    return m_dexterityBonus;
}

int Item::dexterityBonusesCount() const
{
    return m_dexterityBonus.count();
}

DexterityBonus *Item::dexterityBonus(const int index) const
{
    return m_dexterityBonus.at(index);
}

int Item::ammunition() const
{
    return m_amunition;
}

int Item::rateOfFire() const
{
    return m_rateOfFire;
}

QString Item::bullet() const
{
    return m_bullet;
}

QString Item::magazine() const
{
    return m_magazine;
}

QString Item::jam() const
{
    return m_jam;
}

Requirement *Item::requirement() const
{
    return m_pRequirement;
}

Durability *Item::durability() const
{
    return m_pDurability;
}

QQmlListProperty<Location> Item::locations()
{
    return QQmlListProperty<Location>(this, this,
                                      &Item::locationsCount,
                                      &Item::location);
}

QList<Location *> Item::locations() const
{
    return m_locations;
}

int Item::locationsCount() const
{
    return m_locations.count();
}

Location *Item::location(const int index) const
{
    return m_locations.at(index);
}

bool Item::coversLocation(const QString &location) const
{
    for ( const Location* tLocation: m_locations ) {
        if ( tLocation->location() == location )
            return true;
    }
    return false;
}

Location *Item::location(const QString &name) const
{
//    qDebug() << "Item::location()" << name;
    for ( int i{0}; i<m_locations.count(); ++i )
        if ( m_locations.at(i)->location() == name ) {
//            qDebug() << "Found location for " << name;
            return m_locations.at(i);
        }
    return nullptr;
}

QQmlListProperty<Penalty> Item::penalties()
{
    return QQmlListProperty<Penalty>(this, this,
                                     &Item::penaltiesCount,
                                     &Item::penalty);
}

QList<Penalty *> Item::penalties() const
{
    return m_penalties;
}

int Item::penaltiesCount() const
{
    return m_penalties.count();
}

Penalty *Item::penalty(const int index) const
{
    return m_penalties.at(index);
}

QQmlListProperty<Data> Item::features()
{
    return QQmlListProperty<Data>(this, this,
                                  &Item::featuresCount,
                                  &Item::feature);
}

QList<Data *> Item::features() const
{
    return m_features;
}

int Item::featuresCount() const
{
    return m_features.count();
}

Data *Item::feature(int index) const
{
    return m_features.at(index);
}

int Item::armor() const
{
    return m_armor;
}

void Item::setQuantity(const int quantity)
{
    if ( m_quantity == quantity )
        return;

    m_quantity = quantity;
    emit quantityChanged( m_quantity );
}

int Item::specialsCount(QQmlListProperty<Data> *list)
{
    return reinterpret_cast<Item*>(list->data)->specialsCount();
}

Data *Item::special(QQmlListProperty<Data> *list, int index)
{
    return reinterpret_cast<Item*>(list->data)->special(index);
}

int Item::dexterityBonusesCount(QQmlListProperty<DexterityBonus> *list)
{
    return reinterpret_cast<Item*>(list->data)->dexterityBonusesCount();
}

DexterityBonus *Item::dexterityBonus(QQmlListProperty<DexterityBonus> *list, int index)
{
    return reinterpret_cast<Item*>(list->data)->dexterityBonus(index);
}

int Item::locationsCount(QQmlListProperty<Location> *list)
{
    return reinterpret_cast<Item*>(list->data)->locationsCount();
}

Location *Item::location(QQmlListProperty<Location> *list, int index)
{
    return reinterpret_cast<Item*>(list->data)->location(index);
}

int Item::penaltiesCount(QQmlListProperty<Penalty> *list)
{
    return reinterpret_cast<Item*>(list->data)->penaltiesCount();
}

Penalty *Item::penalty(QQmlListProperty<Penalty> *list, int index)
{
    return reinterpret_cast<Item*>(list->data)->penalty(index);
}

int Item::featuresCount(QQmlListProperty<Data> *list)
{
    return reinterpret_cast<Item*>(list->data)->featuresCount();
}

Data *Item::feature(QQmlListProperty<Data> *list, int index)
{
    return reinterpret_cast<Item*>(list->data)->feature(index);
}
