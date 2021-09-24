#include "ItemCreator.h"

#include <QDebug>

ItemCreator::ItemCreator(QObject *parent) : QObject(parent)
{

}

ItemData ItemCreator::create(const QVariantMap &data)
{
    ItemData item;
    item.name = data.value("NAME").toString();
    item.description = data.value("DESCRIPTION").toString();
    item.type = data.value("TYPE").toString();
    item.price = data.value("PRICE").toInt();
    item.quantity = data.value("QUANTITY").toInt();

    if ( data.contains("STATS") )
        item.itemStats = stats( data.value("STATS").toMap() );

    return item;
}

ItemStatsData ItemCreator::stats(const QVariantMap &data)
{
    ItemStatsData stats;

    if ( data.contains("REPUTATION") )
        stats.reputation = data.value("REPUTATION").toInt();

    if ( data.contains("DURABILITY") )
        stats.durability = durability( data.value("DURABILITY").toMap() );

    if ( data.contains("LOCATIONS") ) {
        for ( const QVariant& tLocation : data.value("LOCATIONS").toList() )
            stats.locations.push_back( location(tLocation.toMap()) );
    }

    if ( data.contains("PENALTIES") ) {
        for ( const QVariant& tPenalty : data.value("PENALTIES").toList() )
            stats.penalties.push_back( penalty(tPenalty.toMap()) );
    }

    if ( data.contains("FEATURES") ) {
        for ( const QVariant& tFeature : data.value("FEATURES").toList() )
            stats.features.push_back( feature(tFeature.toMap()) );
    }

    if ( data.contains("DEXBONUS") ) {
        for ( const QVariant& tBonus : data.value("DEXBONUS").toList() )
            stats.bonuses.push_back( bonus(tBonus.toMap()) );
    }

    if ( data.contains("SPECIALS") ) {
        for ( const QVariant& tSpecial : data.value("SPECIALS").toList() )
            stats.specials.push_back( special(tSpecial.toMap()) );
    }

    if ( data.contains("DAMAGE") ) {
        for ( const QVariant& tDamage : data.value("DAMAGE").toList() )
            stats.damage.append( tDamage.toString() );
    }

    if ( data.contains("PENETRATION") )
        stats.penetration = data.value("PENETRATION").toInt();

    if ( data.contains("REQUIREMENT") )
        stats.requirement = requirement( data.value("REQUIREMENT").toMap() );

    if ( data.contains("AMMUNITION") )
        stats.ammunition = data.value("AMMUNITION").toInt();

    if ( data.contains("RATEOFFIRE") )
        stats.rateOfFire = data.value("RATEOFFIRE").toInt();

    if ( data.contains("BULLET") )
        stats.bullet = data.value("BULLET").toString();

    if ( data.contains("MAGAZINE") )
        stats.magazine = data.value("MAGAZINE").toInt();

    if ( data.contains("JAM") )
        stats.jam = data.value("JAM").toInt();

    return stats;
}

DurabilityData ItemCreator::durability(const QVariantMap &data)
{
    DurabilityData durability;
    durability.current = data.value("CURRENT").toInt();
    durability.max = data.value("MAX").toInt();
    return durability;
}

LocationData ItemCreator::location(const QVariantMap &data)
{
    LocationData location;
    location.name = data.value("LOCATION").toString();
    location.armor = data.value("ARMOR").toInt();
    location.cutting = data.value("CUTTING").toInt();
    return location;
}

PenaltyData ItemCreator::penalty(const QVariantMap &data)
{
    PenaltyData penalty;
    penalty.name = data.value("NAME").toString();
    penalty.type = data.value("TYPE").toString();
    penalty.value = data.value("VALUE").toInt();
    return penalty;
}

ArmorFeatureData ItemCreator::feature(const QVariantMap &data)
{
    ArmorFeatureData feature;
    feature.name = data.value("NAME").toString();
    feature.description = data.value("DESCRIPTION").toString();
    return feature;
}

DexterityBonusData ItemCreator::bonus(const QVariantMap &data)
{
    DexterityBonusData bonus;
    bonus.name = data.value("NAME").toString();
    bonus.value = data.value("VALUE").toInt();
    return bonus;
}

RequirementData ItemCreator::requirement(const QVariantMap &data)
{
    RequirementData requirement;
    requirement.name = data.value("NAME").toString();
    requirement.type = data.value("TYPE").toString();
    requirement.value = data.value("VALUE").toInt();
    requirement.optional = data.value("OPTIONAL").toBool();
    return requirement;
}

SpecialData ItemCreator::special(const QVariantMap &data)
{
    SpecialData special;
    special.name = data.value("NAME").toString();
    special.description = data.value("DESCRIPTION").toString();
    return special;
}
