#include "ItemCreator.h"

#include "../Card/Elements/Equipment/Item.h"
#include "../Card/Elements/Equipment/Location.h"
#include "../Card/Elements/Equipment/DexterityBonus.h"
#include "../Card/Elements/Equipment/Durability.h"
#include "../DataSources/Elements/Stats/Requirement.h"
#include "../Card/Elements/Stats/Penalty.h"

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
    const int& index = m_types.indexOf(data.value("TYPE").toString().toUpper());
    const QString& type = (index>-1) ? m_types.at(index) : m_types.at(6);

    Item* item = new Item(type
                          , data.value("NAME").toString()
                          , data.value("DESCRIPTION").toString()
                          , data.value("PRICE").toInt()
                          , data.value("QUANTITY").toInt() );

    setStats(item, data.value("STATS").toMap());

    return item;
}

Item *ItemCreator::create(const Item *item)
{
    return new Item( item->m_type,
                     item->name(),
                     item->description(),
                     item->m_price,
                     item->m_quantity );
}

void ItemCreator::setStats(Item *item, const QVariantMap &stats)
{
    if ( stats.contains("REPUTATION") )
        item->m_reputation = stats.value("REPUTATION").toInt();

    if ( stats.contains("PENETRATION") )
        item->m_penetration = stats.value("PENETRATION").toInt();

    if ( stats.contains("AMMUNITION") )
        item->m_amunition = stats.value("AMMUNITION").toInt();

    if ( stats.contains("RATEOFFIRE") )
        item->m_rateOfFire = stats.value("RATEOFFIRE").toInt();

    if ( stats.contains("JAM") )
        item->m_jam = stats.value("JAM").toString();

    if ( stats.contains("BULLET") )
        item->m_bullet = stats.value("BULLET").toString();

    if ( stats.contains("MAGAZINE") )
        item->m_magazine = stats.value("MAGAZINE").toString();

    if ( stats.contains("DAMAGE") )
        item->m_damage = stats.value("DAMAGE").toStringList();

    if ( stats.contains("FEATURES") ) {
        for ( const QVariant& feature: stats.value("FEATURES").toList() ) {
            const QMap<QString, QVariant>& tFeature = feature.toMap();
            item->m_features.append( createData(tFeature, item) );
        }
    }

    if ( stats.contains("PENALTIES") ) {
        for ( const QVariant& penalty: stats.value("PENALTIES").toList() ) {
            const QMap<QString, QVariant>& tPenalty = penalty.toMap();
            item->m_penalties.append( createPenalty(tPenalty, item) );
        }
    }

    if ( stats.contains("LOCATIONS") ) {
        for ( const QVariant& location: stats.value("LOCATIONS").toList() ) {
            const QMap<QString, QVariant>& tLocation = location.toMap();
            item->m_locations.append( createLocation(tLocation, item) );
        }
    }

    if ( stats.contains("DEXBONUS") ) {
        for ( const QVariant& bonus: stats.value("DEXBONUS").toList() ) {
            const QMap<QString, QVariant>& tBonus = bonus.toMap();
            item->m_dexterityBonus.append( createDexbonus(tBonus, item) );
        }
    }

    if ( stats.contains("SPECIAL") ) {
        for ( const QVariant& special: stats.value("SPECIAL").toList() ) {
            const QMap<QString, QVariant>& tSpecial = special.toMap();
            item->m_specials.append( createData(tSpecial, item) );
        }
    }

    if ( stats.contains("DURABILITY") ) {
        const QMap<QString, QVariant>& durability = stats.value("DURABILITY").toMap();
        item->m_pDurability = new Durability( durability.value("max").toInt(),
                                              durability.value("current").toInt(),
                                              item );
    }

    if ( stats.contains("REQUIREMENT") ) {
        const QMap<QString, QVariant>& requirement = stats.value("REQUIREMENT").toMap();
        item->m_pRequirement = new Requirement( requirement.value("NAME").toString(),
                                                requirement.value("VALUE").toInt(),
                                                false,
                                                Requirement::Type::ATTRIBUTE,
                                                item );
    }
}

Data *ItemCreator::createData(const QMap<QString, QVariant> &input, Item* parent)
{
    return new Data( input.value("NAME").toString(),
                     input.value("DESCRIPTION").toString(),
                     parent );
}

Penalty *ItemCreator::createPenalty(const QMap<QString, QVariant> &input, Item *parent)
{
    return new Penalty( input.value("NAME").toString(),
                        input.value("VALUE").toInt(),
                        input.value("TYPE").toString(),
                        parent );
}

Location *ItemCreator::createLocation(const QMap<QString, QVariant> &input, Item *parent)
{
    return new Location( input.value("LOCATION").toString(),
                         input.value("ARMOR").toInt(),
                         input.value("CUTTING").toInt(),
                         parent );
}

DexterityBonus *ItemCreator::createDexbonus(const QMap<QString, QVariant> &input, Item *parent)
{
    return new DexterityBonus( input.value("NAME").toString(),
                               input.value("VALUE").toInt(),
                               parent );
}
