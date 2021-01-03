#include "Equipment.h"
#include "../Elements/Equipment/Item.h"
#include "../Elements/Equipment/Location.h"
#include "../../Creators/ItemCreator.h"

#include <QDebug>

Equipment::Equipment(QObject *parent) : Page(Page::Type::EQUIPMENT, parent)
{

}

Equipment::Equipment(const QList<Item *> &backpack,
                     QObject *parent)
    : Page(Page::Type::EQUIPMENT, parent)
    , m_backpack(backpack)
{
    while ( m_backpack.count() < 18 ) {
        m_backpack.append(new Item(Item::Type::EMPTY,
                                   "", "", 0, 0,
                                   QMap<Item::Stat, QVariant>(), this));
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

Item *Equipment::getItemFromBackpack(const int& index)
{
    if ( index < 0 || index > m_backpack.count() )
        return nullptr;

    return m_backpack.at(index);
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
