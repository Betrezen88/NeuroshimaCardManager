#include "Equipment.h"

#include "../Equipment/Item.h"
#include "../Equipment/ItemStats.h"

#include "../../Creators/ItemCreator.h"

#include <QDebug>

Equipment::Equipment(QObject *parent) : Page(Type::EQUIPMENT, parent)
{

}

Equipment::Equipment(const EquipmentData &data, QObject *parent)
    : Page(Type::EQUIPMENT, parent)
    , m_data(data)
{
    for ( QSharedPointer<ItemData> tItem : m_data.backpack )
        m_backpack.append( new Item(tItem.get(), this) );

    for ( QSharedPointer<ItemData> tWeapon : m_data.weapon )
        m_weapons.append( new Item(tWeapon.get(), this) );

    for ( QSharedPointer<ItemData> tArmor : m_data.armor )
        m_armor.append( new Item(tArmor.get(), this) );
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

Item *Equipment::backpackItem(const int index) const
{
    if ( index < 0 || index > m_backpack.count() )
        return nullptr;

    return m_backpack.at(index);
}

QQmlListProperty<Item> Equipment::weapons()
{
    return QQmlListProperty<Item>(this, this,
                                  &Equipment::weaponCount,
                                  &Equipment::weapon);
}

int Equipment::weaponCount() const
{
    return m_weapons.count();
}

Item *Equipment::weapon(const int index) const
{
    if ( index < 0 || index > m_weapons.count() )
        return nullptr;

    return m_weapons.at(index);
}

QQmlListProperty<Item> Equipment::armor()
{
    return QQmlListProperty<Item>(this, this,
                                  &Equipment::armorCount,
                                  &Equipment::armorItem);
}

int Equipment::armorCount() const
{
    return m_armor.count();
}

Item *Equipment::armorItem(const int index) const
{
    if ( index < 0 || index > m_armor.count() )
        return nullptr;

    return m_armor.at(index);
}

int Equipment::drugs() const
{
    return m_data.drugs;
}

int Equipment::food() const
{
    return m_data.food;
}

int Equipment::water() const
{
    return m_data.water;
}

const EquipmentData &Equipment::data() const
{
    return m_data;
}

Item *Equipment::armorItem(const QString &location)
{
    for ( Item* pItem : m_armor )
        if ( pItem->stats()->location(location) != nullptr )
            return pItem;

    return nullptr;
}

void Equipment::addItemToBackpack(const QVariantMap &data)
{
    ItemCreator creator;
    ItemData item = creator.create( data );

    auto backpackIt = std::find_if(m_data.backpack.begin(), m_data.backpack.end(),
                                [&item](const QSharedPointer<ItemData>& other){
        return item == *other.data();
    });
    if ( backpackIt == m_data.backpack.end() )
        addBackpackItem( item );
    else
        m_backpack.at( m_data.backpack.indexOf(*backpackIt) )->increaseQuantity();
}

void Equipment::removeItemFromBackpack(const int index)
{
    if ( index < 0 || index > m_backpack.count() ) {
        qDebug() << "removeItemFromBackpack() invalid index: " << index
                 << " m_backpack.count()" << m_backpack.count();
        return;
    }

    eraseBackpackItem( index );
}

void Equipment::equipWeapon(const int index)
{
    if ( index < 0 || index > m_backpack.count() ) {
        qDebug() << "equipWeapon() invalid index: " << index
                 << " m_backpack.count()" << m_backpack.count();
        return;
    }

    addWeapon( *m_data.backpack.at(index) );

    if ( m_backpack.at(index)->quantity() == 1 )
        eraseBackpackItem( index );
    else
        m_backpack.at(index)->decreaseQuantity();
}

void Equipment::unequipWeapon(const int index)
{
    if ( index < 0 || index > m_weapons.count() ) {
        qDebug() << "unequipWeapon() invalid index: " << index
                 << " m_weapons.count()" << m_weapons.count();
        return;
    }

    Item* pWeapon = m_weapons.at(index);
    auto backpackIt = std::find_if(m_data.backpack.begin(), m_data.backpack.end(),
                                [&pWeapon](const QSharedPointer<ItemData>& item){
        return pWeapon->data() == *item.data();
    });
    if ( backpackIt == m_data.backpack.end() )
        addBackpackItem( pWeapon->data() );
    else
        m_backpack.at( m_data.backpack.indexOf(*backpackIt) )->increaseQuantity();

    eraseWeapon( index );
}

void Equipment::removeWeapon(const int index)
{
    if ( index < 0 || index > m_weapons.count() ) {
        qDebug() << "removeWeapon() invalid index: " << index
                 << " m_weapons.count()" << m_weapons.count();
        return;
    }

    eraseWeapon( index );
}

void Equipment::equipArmor(const int index)
{
    if ( index < 0 || index > m_backpack.count() ) {
        qDebug() << "equipArmor() invalid index: " << index
                 << " m_backpack.count()" << m_backpack.count();
        return;
    }

    removeCollidedArmor( m_data.backpack.at(index).get() );
    addArmor( *m_data.backpack.at(index) );

    if ( m_backpack.at(index)->quantity() == 1 )
        eraseBackpackItem( index );
    else
        m_backpack.at(index)->decreaseQuantity();
}

void Equipment::unequipArmor(Item *armor)
{
    const int index = m_armor.indexOf( armor );

    if ( -1 == index ) {
        qDebug() << "unequipArmor(): Given armor does not exist." << index;
        return;
    }

    auto backpackIt = std::find_if(m_data.backpack.begin(), m_data.backpack.end(),
                                [&armor](const QSharedPointer<ItemData>& item){
        return armor->data() == *item.data();
    });
    if ( backpackIt == m_data.backpack.end() )
        addBackpackItem( *m_data.armor.at(index) );
    else
        m_backpack.at( m_data.backpack.indexOf(*backpackIt) )->increaseQuantity();

    eraseArmor( index );
}

void Equipment::removeArmor(Item *armor)
{
    const int index = m_armor.indexOf( armor );
    if ( -1 == index ) {
        qDebug() << "removeArmor(): Given armor does not exist." << index;
        return;
    }

    eraseArmor( index );
}

void Equipment::addBackpackItem(const ItemData &data)
{
    m_data.backpack.push_back( QSharedPointer<ItemData>( new ItemData(data)) );
    m_backpack.push_back( new Item(m_data.backpack.last().get(), this) );
    emit backpackChanged();
}

void Equipment::addWeapon(const ItemData &data)
{
    m_data.weapon.push_back( QSharedPointer<ItemData>( new ItemData(data)) );
    m_weapons.push_back( new Item(m_data.weapon.last().get(), this) );
    emit weaponsChanged();
}

void Equipment::addArmor(const ItemData &data)
{
    m_data.armor.push_back( QSharedPointer<ItemData>( new ItemData(data)) );
    m_armor.push_back( new Item(m_data.armor.last().get(), this) );
    emit armorChanged();
}

void Equipment::eraseBackpackItem(const int index)
{
    m_backpack.takeAt(index)->deleteLater();
    m_data.backpack.takeAt(index);
    emit backpackChanged();
}

void Equipment::eraseWeapon(const int index)
{
    m_weapons.takeAt(index)->deleteLater();
    m_data.weapon.takeAt(index);
    emit weaponsChanged();
}

void Equipment::eraseArmor(const int index)
{
    m_armor.takeAt(index)->deleteLater();
    m_data.armor.takeAt(index);
    emit armorChanged();
}

void Equipment::removeCollidedArmor(ItemData *armor)
{
    QSet<int> index;
    for ( QSharedPointer<ItemData> item : m_data.armor ) {
        for ( const LocationData& location : armor->itemStats.locations ) {
            auto locationIt = std::find_if(item->itemStats.locations.begin(),
                                           item->itemStats.locations.end(),
                                           [&location](const LocationData& other){
                return location.name == other.name;
            });
            if ( locationIt != item->itemStats.locations.end() )
                index.insert( m_data.armor.indexOf(item) );
        }
    }
    foreach( const int &i, index )
        unequipArmor( m_armor.at(i) );
}

int Equipment::backpackCount(QQmlListProperty<Item> *list)
{
    return reinterpret_cast<Equipment*>(list->data)->backpackCount();
}

Item *Equipment::backpackItem(QQmlListProperty<Item> *list, int index)
{
    return reinterpret_cast<Equipment*>(list->data)->backpackItem(index);
}

int Equipment::weaponCount(QQmlListProperty<Item> *list)
{
    return reinterpret_cast<Equipment*>(list->data)->weaponCount();
}

Item *Equipment::weapon(QQmlListProperty<Item> *list, int index)
{
    return reinterpret_cast<Equipment*>(list->data)->weapon(index);
}

int Equipment::armorCount(QQmlListProperty<Item> *list)
{
    return reinterpret_cast<Equipment*>(list->data)->armorCount();
}

Item *Equipment::armorItem(QQmlListProperty<Item> *list, int index)
{
    return reinterpret_cast<Equipment*>(list->data)->armorItem(index);
}
