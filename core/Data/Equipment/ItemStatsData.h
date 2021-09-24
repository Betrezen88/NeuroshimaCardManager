#ifndef ITEMSTATSDATA_H
#define ITEMSTATSDATA_H

#include <QStringList>
#include <QVector>

#include "DurabilityData.h"
#include "LocationData.h"
#include "ArmorFeatureData.h"
#include "DexterityBonusData.h"
#include "SpecialData.h"
#include "../Common/RequirementData.h"
#include "../Common/PenaltyData.h"

#include "core_global.h"

#include <QDebug>

struct CORE_EXPORT ItemStatsData {
    int reputation{0};

    DurabilityData durability;
    QVector<LocationData> locations;
    QVector<PenaltyData> penalties;
    QVector<ArmorFeatureData> features;

    QStringList damage;
    int penetration{0};
    QVector<DexterityBonusData> bonuses;
    RequirementData requirement;
    QVector<SpecialData> specials;

    int ammunition{0};
    int rateOfFire{0};
    QString bullet;
    int magazine{0};
    int jam{0};

    bool operator!=(const ItemStatsData& other) const {
        if ( reputation != other.reputation )
            return true;

        if ( damage != other.damage )
            return true;

        if ( penetration != other.penetration )
            return true;

        if ( ammunition != other.ammunition )
            return true;

        if ( rateOfFire != other.rateOfFire )
            return true;

        if ( bullet != other.bullet )
            return true;

        if ( magazine != other.magazine )
            return true;

        if ( jam != other.jam )
            return true;

        if ( durability != other.durability )
            return true;

        if ( requirement != other.requirement )
            return true;

        if ( locations.count() == other.locations.count()
             && !std::equal(locations.begin(), locations.end(), other.locations.begin()) )
                return true;
        if( penalties.count() == other.penalties.count()
                && !std::equal(penalties.begin(), penalties.end(), other.penalties.begin()) )
            return true;

        if( features.count() == other.features.count()
                && !std::equal(features.begin(), features.end(), other.features.begin()) )
            return true;

        if( bonuses.count() == other.bonuses.count()
                && !std::equal(bonuses.begin(), bonuses.end(), other.bonuses.begin()) )
            return true;

        if( specials.count() == other.specials.count()
                && !std::equal(specials.begin(), specials.end(), other.specials.begin()) )
            return true;

        return false;
    }
};

#endif // ITEMSTATSDATA_H
