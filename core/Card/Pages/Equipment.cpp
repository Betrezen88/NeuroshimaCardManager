#include "Equipment.h"
#include "../Elements/Equipment/Item.h"
#include "../Elements/Equipment/Location.h"
#include "../../Creators/ItemCreator.h"

#include <QDebug>

Equipment::Equipment(QObject *parent) : Page(Page::Type::EQUIPMENT, parent)
{

}

Equipment::Equipment(const QList<Item *> &backpack,
                     const QList<Item *> &weapons,
                     const int &drugs,
                     const int &food,
                     const int &water,
                     QObject *parent)
    : Page(Page::Type::EQUIPMENT, parent)
    , m_backpack(backpack)
    , m_weapons(weapons)
    , m_drugs(drugs)
    , m_food(food)
    , m_water(water)
{
    while ( m_backpack.count() < 18 )
        m_backpack.append(new Item("EMPTY", "", "", 0, 0, QMap<QString, QVariant>(), this));
}

void Equipment::addItemToBackpack(Item *item)
{
    Item* pItem = findItemInBackpack(item->name());
    if ( !pItem ) {
        int empty = findEmptyInBackpack();
        if ( empty > 0 ) {
            delete m_backpack.takeAt(empty);
            m_backpack.insert(empty, item);
        }
        else
            m_backpack.append(item);
        emit backpackChanged();
        item->setParent(this);
    }
    else
        pItem->setQuantity(pItem->quantity()+item->quantity());

    if ( !m_backpack.contains(item) )
        delete item;
}

void Equipment::addItemToBackpack(const QVariantMap &itemData)
{
    int empty = findEmptyInBackpack();
    ItemCreator creator;
    if ( empty > -1 ) {
        delete m_backpack.takeAt(empty);
        m_backpack.insert( empty, creator.create(itemData) );
    }
    else
        m_backpack.append( creator.create(itemData) );

    emit backpackChanged();
}

QQmlListProperty<Item> Equipment::backpack()
{
    return QQmlListProperty<Item>(this, this,
                                  &Equipment::backpackCount,
                                  &Equipment::backpackItem);
}

int Equipment::backpackCount() const
{
    return m_backpack.count();
}

Item *Equipment::backpackItem(const int &index) const
{
    if ( index < 0 || index > m_backpack.count() )
        return nullptr;

    return m_backpack.at(index);
}

void Equipment::throwBackpackItem(const int &index)
{
    if ( index < 0 || index > m_backpack.count() )
        return;

    delete m_backpack.takeAt(index);
    emit backpackChanged();
}

QList<Item *> Equipment::backpack() const
{
    return m_backpack;
}

QQmlListProperty<Item> Equipment::weapons()
{
    return QQmlListProperty<Item>(this, this,
                                  &Equipment::weaponsCount,
                                  &Equipment::weapon);
}

QList<Item *> Equipment::weapons() const
{
    return m_weapons;
}

int Equipment::weaponsCount() const
{
    return m_weapons.count();
}

Item *Equipment::weapon(const int &index) const
{
    return m_weapons.at(index);
}

void Equipment::equipWeapon(const int &index)
{
    if ( index < 0 || index > m_backpack.size() )
        return;

    const int& quantity = m_backpack.at(index)->quantity();

    if ( 1 == quantity ) {
        m_weapons.append( m_backpack.takeAt(index) );
        emit backpackChanged();
    }
    else {
        ItemCreator creator;
        m_weapons.append( creator.create(m_backpack.at(index)) );
        m_backpack.at(index)->setQuantity(quantity-1);
    }

    emit weaponsChanged();
}

void Equipment::unequipWeapon(const int &index)
{
    if ( index < 0 || index > m_weapons.size() )
        return;

    addItemToBackpack( m_weapons.takeAt(index) );
    emit weaponsChanged();
}

void Equipment::throwWeapon(const int &index)
{
    if ( index < 0 || index > m_weapons.size() )
        return;

    delete m_weapons.takeAt(index);
    emit weaponsChanged();
}

void Equipment::equipArmor(const int &index)
{
    if ( index < 0 || index > m_backpack.size() )
        return;

    const int& quantity = m_backpack.at(index)->quantity();

    if ( 1 == quantity ) {
        m_armor.append( m_backpack.takeAt(index) );
        emit backpackChanged();
    }
    else {
        ItemCreator creator;
        m_armor.append( creator.create(m_backpack.at(index)) );
        m_backpack.at(index)->setQuantity(quantity-1);
    }

    emit armorChanged();
}

Item *Equipment::getArmor(const QString &location)
{
    for ( Item* pItem: m_armor ) {
        if ( pItem->locations().contains(location) )
            return pItem;
    }
    return nullptr;
}

int Equipment::drugs() const
{
    return m_drugs;
}

int Equipment::food() const
{
    return m_food;
}

int Equipment::water() const
{
    return m_water;
}

void Equipment::setDrugs(int drugs)
{
    if (m_drugs == drugs)
        return;

    m_drugs = drugs;
    emit drugsChanged(m_drugs);
}

void Equipment::setFood(int food)
{
    if (m_food == food)
        return;

    m_food = food;
    emit foodChanged(m_food);
}

void Equipment::setWater(int water)
{
    if (m_water == water)
        return;

    m_water = water;
    emit waterChanged(m_water);
}

Item *Equipment::findItemInBackpack(const QString &name)
{
    for ( Item* item: m_backpack ) {
        if ( item->name() == name) {
            return item;
        }
    }
    return nullptr;
}

int Equipment::findEmptyInBackpack()
{
    for (Item* pItem: m_backpack)
        if ( pItem->type() == "EMPTY" )
            return m_backpack.indexOf(pItem);
    return -1;
}

int Equipment::backpackCount(QQmlListProperty<Item> *list)
{
    return reinterpret_cast<Equipment*>(list->data)->backpackCount();
}

Item *Equipment::backpackItem(QQmlListProperty<Item> *list, int index)
{
    return reinterpret_cast<Equipment*>(list->data)->backpackItem(index);
}

int Equipment::weaponsCount(QQmlListProperty<Item> *list)
{
    return reinterpret_cast<Equipment*>(list->data)->weaponsCount();
}

Item *Equipment::weapon(QQmlListProperty<Item> *list, int index)
{
    return reinterpret_cast<Equipment*>(list->data)->weapon(index);
}
