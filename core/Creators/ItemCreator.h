#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

#include <QObject>
#include <QVariantMap>

#include "../Data/Equipment/ItemData.h"

class ItemCreator : public QObject
{
    Q_OBJECT
public:
    explicit ItemCreator(QObject *parent = nullptr);

    ItemData create(const QVariantMap& data);

private:
    ItemStatsData stats(const QVariantMap& data);
    DurabilityData durability(const QVariantMap& data);
    LocationData location(const QVariantMap& data);
    PenaltyData penalty(const QVariantMap& data);
    ArmorFeatureData feature(const QVariantMap& data);
    DexterityBonusData bonus(const QVariantMap& data);
    RequirementData requirement(const QVariantMap& data);
    SpecialData special(const QVariantMap& data);
};

#endif // ITEMCREATOR_H
