#include "ItemStats.h"

#include "../Common/Requirement.h"
#include "../Common/Penalty.h"
#include "Durability.h"
#include "Location.h"
#include "ArmorFeature.h"
#include "DexterityBonus.h"
#include "Special.h"

ItemStats::ItemStats(QObject *parent) : QObject(parent)
{

}

ItemStats::ItemStats(ItemStatsData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    if ( m_data->durability.max > 0 )
        m_pDurability = new Durability(&m_data->durability, this);

    if ( !m_data->requirement.name.isEmpty() )
        m_pRequirement = new Requirement(&m_data->requirement, this);

    for ( LocationData& location : m_data->locations )
        m_locations.append( new Location(&location, this) );

    for ( PenaltyData& penalty : m_data->penalties )
        m_penalties.append( new Penalty(&penalty, this) );

    for ( ArmorFeatureData& feature : m_data->features )
        m_features.append( new ArmorFeature(&feature, this) );

    for ( DexterityBonusData& bonus : m_data->bonuses )
        m_bonuses.append( new DexterityBonus(&bonus, this) );

    for ( SpecialData& special : m_data->specials )
        m_specials.append( new Special(&special, this) );
}

int ItemStats::reputation() const
{
    return m_data ? m_data->reputation : 0;
}

Durability *ItemStats::durability() const
{
    return m_pDurability;
}

QQmlListProperty<Location> ItemStats::locations()
{
    return QQmlListProperty<Location>(this, this,
                                      &ItemStats::locationCount,
                                      &ItemStats::location);
}

int ItemStats::locationCount() const
{
    return m_locations.count();
}

Location *ItemStats::location(const int index) const
{
    if ( index < 0 || index > m_locations.count() )
        return nullptr;

    return m_locations.at(index);
}

QQmlListProperty<Penalty> ItemStats::penalties()
{
    return QQmlListProperty<Penalty>(this, this,
                                     &ItemStats::penaltyCount,
                                     &ItemStats::penalty);
}

int ItemStats::penaltyCount() const
{
    return m_penalties.count();
}

Penalty *ItemStats::penalty(const int index) const
{
    if ( index < 0 || index > m_penalties.count() )
        return nullptr;

    return m_penalties.at(index);
}

QQmlListProperty<ArmorFeature> ItemStats::features()
{
    return QQmlListProperty<ArmorFeature>(this, this,
                                          &ItemStats::featureCount,
                                          &ItemStats::feature);
}

int ItemStats::featureCount() const
{
    return m_features.count();
}

ArmorFeature *ItemStats::feature(const int index) const
{
    if ( index < 0 || index > m_features.count() )
        return nullptr;

    return m_features.at(index);
}

const QStringList &ItemStats::damage() const
{
    if ( m_data )
        return m_data->damage;
    return std::move(QStringList());
}

int ItemStats::penetration() const
{
    return m_data ? m_data->penetration : 0;
}

QQmlListProperty<DexterityBonus> ItemStats::bonuses()
{
    return QQmlListProperty<DexterityBonus>(this, this,
                                            &ItemStats::bonusCount,
                                            &ItemStats::bonus);
}

int ItemStats::bonusCount() const
{
    return m_bonuses.count();
}

DexterityBonus *ItemStats::bonus(const int index) const
{
    if ( index < 0 || index > m_bonuses.count() )
        return nullptr;

    return m_bonuses.at(index);
}

Requirement *ItemStats::requirement() const
{
    return m_pRequirement;
}

QQmlListProperty<Special> ItemStats::specials()
{
    return QQmlListProperty<Special>(this, this,
                                     &ItemStats::specialCount,
                                     &ItemStats::special);
}

int ItemStats::specialCount() const
{
    return m_specials.count();
}

Special *ItemStats::special(const int index) const
{
    if ( index < 0 || index > m_specials.count() )
        return nullptr;

    return m_specials.at(index);
}

int ItemStats::ammunition() const
{
    return m_data ? m_data->ammunition : 0;
}

int ItemStats::rateOfFire() const
{
    return m_data ? m_data->rateOfFire : 0;
}

const QString &ItemStats::bullet() const
{
    if ( m_data )
        return m_data->bullet;
    return std::move(QString());
}

int ItemStats::magazine() const
{
    return m_data ? m_data->magazine : 0;
}

int ItemStats::jam() const
{
    return m_data ? m_data->jam : 0;
}

Location *ItemStats::location(const QString &name) const
{
    for ( Location* pLocation : m_locations )
        if ( name == pLocation->name() )
            return pLocation;
    return nullptr;
}

int ItemStats::locationCount(QQmlListProperty<Location> *list)
{
    return reinterpret_cast<ItemStats*>(list->data)->locationCount();
}

Location *ItemStats::location(QQmlListProperty<Location> *list, int index)
{
    return reinterpret_cast<ItemStats*>(list->data)->location(index);
}

int ItemStats::penaltyCount(QQmlListProperty<Penalty> *list)
{
    return reinterpret_cast<ItemStats*>(list->data)->penaltyCount();
}

Penalty *ItemStats::penalty(QQmlListProperty<Penalty> *list, int index)
{
    return reinterpret_cast<ItemStats*>(list->data)->penalty(index);
}

int ItemStats::featureCount(QQmlListProperty<ArmorFeature> *list)
{
    return reinterpret_cast<ItemStats*>(list->data)->featureCount();
}

ArmorFeature *ItemStats::feature(QQmlListProperty<ArmorFeature> *list, int index)
{
    return reinterpret_cast<ItemStats*>(list->data)->feature(index);
}

int ItemStats::bonusCount(QQmlListProperty<DexterityBonus> *list)
{
    return reinterpret_cast<ItemStats*>(list->data)->bonusCount();
}

DexterityBonus *ItemStats::bonus(QQmlListProperty<DexterityBonus> *list, int index)
{
    return reinterpret_cast<ItemStats*>(list->data)->bonus(index);
}

int ItemStats::specialCount(QQmlListProperty<Special> *list)
{
    return reinterpret_cast<ItemStats*>(list->data)->specialCount();
}

Special *ItemStats::special(QQmlListProperty<Special> *list, int index)
{
    return reinterpret_cast<ItemStats*>(list->data)->special(index);
}
