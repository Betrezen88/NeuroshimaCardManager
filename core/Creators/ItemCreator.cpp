#include "ItemCreator.h"

#include "../Card/Elements/Equipment/Item.h"

#include <QJsonObject>

ItemCreator::ItemCreator(QObject *parent) : QObject(parent)
{

}

Item *ItemCreator::create(const QJsonObject &data)
{
    return create(data.toVariantMap());
}

Item *ItemCreator::create(const QVariantMap &data)
{
    Item::Type type = Item::stringToType(data.value("type").toString());
    QMap<Item::Stat, QVariant> itemStats;

    if ( data.contains("stats") ) {
        const QMap<QString, QVariant> &stats = data.value("stats").toMap();

        if ( stats.contains("reputation") )
            itemStats.insert(Item::Stat::REPUTATION,
                             stats.value("reputation").toInt());

        if ( stats.contains("durability") )
            itemStats.insert(Item::Stat::DURABILITY,
                             stats.value("durability").toInt());

        if ( stats.contains("penetration") )
            itemStats.insert(Item::Stat::PENETRATION,
                             stats.value("penetration").toInt());

        if ( stats.contains("rateOfFire") )
            itemStats.insert(Item::Stat::RATEOFFIRE,
                             stats.value("rateOfFire").toInt());

        if ( stats.contains("damage") ) {
            QStringList damage;
            for ( const QVariant& dmg: stats.value("damage").toList() )
                damage << dmg.toString();

            itemStats.insert(Item::Stat::DAMAGE, damage);
        }
    }

    return new Item(type
                    , data.value("name").toString()
                    , data.value("description").toString()
                    , data.value("price").toInt()
                    , data.value("quantity").toInt()
                    , itemStats );
}
