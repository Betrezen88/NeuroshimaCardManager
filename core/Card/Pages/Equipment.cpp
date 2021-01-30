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
                     QObject *parent)
    : Page(Page::Type::EQUIPMENT, parent)
    , m_backpack(backpack)
    , m_weapons(weapons)
{
    while ( m_backpack.count() < 18 ) {
        m_backpack.append(new Item(Item::Type::EMPTY,
                                   "", "", 0, 0,
                                   QMap<QString, QVariant>(), this));
    }
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
    return QQmlListProperty<Item>(this, &m_backpack);
}

Item *Equipment::backpackItem(const int &index) const
{
    if ( index < 0 || index > m_backpack.count() )
        return nullptr;

    return m_backpack.at(index);
}

QList<Item *> Equipment::backpack() const
{
    return m_backpack;
}

QQmlListProperty<Item> Equipment::weapons()
{
    return QQmlListProperty<Item>(this, &m_weapons);
}

QList<Item *> Equipment::weapons() const
{
    return m_weapons;
}

Item *Equipment::weaponAt(const int &index) const
{
    if ( index < 0 || index > m_weapons.size() )
        return nullptr;

    return m_weapons.at(index);
}

void Equipment::addWeaponItem(Item *item)
{
    if ( item == nullptr )
        return;

    m_weapons.append(item);
    emit weaponsChanged();
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
        m_weapons.append( new Item(m_backpack.at(index)) );
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
        if ( pItem->type() == Item::Type::EMPTY )
            return m_backpack.indexOf(pItem);
    return -1;
}
