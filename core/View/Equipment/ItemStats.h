#ifndef ITEMSTATS_H
#define ITEMSTATS_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Equipment/ItemStatsData.h"

#include "core_global.h"

class Durability;
class Location;
class Penalty;
class ArmorFeature;
class DexterityBonus;
class Special;
class Requirement;

class CORE_EXPORT ItemStats : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int reputation READ reputation CONSTANT)

    Q_PROPERTY(Durability* durability READ durability CONSTANT)
    Q_PROPERTY(QQmlListProperty<Location> locations READ locations CONSTANT)
    Q_PROPERTY(QQmlListProperty<Penalty> penalties READ penalties CONSTANT)
    Q_PROPERTY(QQmlListProperty<ArmorFeature> features READ features CONSTANT)

    Q_PROPERTY(QStringList damage READ damage CONSTANT)
    Q_PROPERTY(int penetration READ penetration CONSTANT)
    Q_PROPERTY(QQmlListProperty<DexterityBonus> bonuses READ bonuses CONSTANT)
    Q_PROPERTY(Requirement* requirement READ requirement CONSTANT)
    Q_PROPERTY(QQmlListProperty<Special> specials READ specials CONSTANT)

    Q_PROPERTY(int ammunition READ ammunition CONSTANT)
    Q_PROPERTY(int rateOfFire READ rateOfFire CONSTANT)
    Q_PROPERTY(QString bullet READ bullet CONSTANT)
    Q_PROPERTY(int magazine READ magazine CONSTANT)
    Q_PROPERTY(int jam READ jam CONSTANT)

public:
    explicit ItemStats(QObject *parent = nullptr);
    explicit ItemStats(ItemStatsData* data, QObject *parent = nullptr);

    int reputation() const;

    Durability *durability() const;

    QQmlListProperty<Location> locations();
    int locationCount() const;
    Location* location(const int index) const;

    QQmlListProperty<Penalty> penalties();
    int penaltyCount() const;
    Penalty* penalty(const int index) const;

    QQmlListProperty<ArmorFeature> features();
    int featureCount() const;
    ArmorFeature* feature(const int index) const;

    const QStringList &damage() const;
    int penetration() const;

    QQmlListProperty<DexterityBonus> bonuses();
    int bonusCount() const;
    DexterityBonus* bonus(const int index) const;

    Requirement *requirement() const;

    QQmlListProperty<Special> specials();
    int specialCount() const;
    Special* special(const int index) const;

    int ammunition() const;
    int rateOfFire() const;
    const QString &bullet() const;
    int magazine() const;
    int jam() const;

public slots:
    Location* location(const QString& name) const;

private:
    static int locationCount(QQmlListProperty<Location> *list);
    static Location* location(QQmlListProperty<Location> *list, int index);

    static int penaltyCount(QQmlListProperty<Penalty> *list);
    static Penalty* penalty(QQmlListProperty<Penalty> *list, int index);

    static int featureCount(QQmlListProperty<ArmorFeature> *list);
    static ArmorFeature* feature(QQmlListProperty<ArmorFeature> *list, int index);

    static int bonusCount(QQmlListProperty<DexterityBonus> *list);
    static DexterityBonus* bonus(QQmlListProperty<DexterityBonus> *list, int index);

    static int specialCount(QQmlListProperty<Special> *list);
    static Special* special(QQmlListProperty<Special> *list, int index);

private:
    ItemStatsData* m_data{nullptr};

    Durability *m_pDurability{nullptr};
    QVector<Location*> m_locations;
    QVector<Penalty*> m_penalties;
    QVector<ArmorFeature*> m_features;
    QVector<DexterityBonus*> m_bonuses;
    Requirement *m_pRequirement{nullptr};
    QVector<Special*> m_specials;
};

#endif // ITEMSTATS_H
