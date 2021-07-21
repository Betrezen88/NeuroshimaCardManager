#ifndef ITEM_H
#define ITEM_H

#include <QMap>
#include <QVariant>
#include <QQmlListProperty>

#include "../../Data.h"
#include "core_global.h"

class DexterityBonus;
class Durability;
class Location;
class Penalty;
class Requirement;

class CORE_EXPORT Item : public Data
{
    Q_OBJECT
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(int price READ price CONSTANT)
    Q_PROPERTY(int quantity
               READ quantity
               WRITE setQuantity
               NOTIFY quantityChanged)
    Q_PROPERTY(int reputation READ reputation CONSTANT)
    Q_PROPERTY(QStringList damage READ damage CONSTANT)
    Q_PROPERTY(int penetration READ penetration CONSTANT)
    Q_PROPERTY(QQmlListProperty<Data> specials READ specials CONSTANT)
    Q_PROPERTY(QQmlListProperty<DexterityBonus> dexterityBonuses READ dexterityBonuses CONSTANT)
    Q_PROPERTY(int ammunition READ ammunition CONSTANT)
    Q_PROPERTY(int rateOfFire READ rateOfFire CONSTANT)
    Q_PROPERTY(QString bullet READ bullet CONSTANT)
    Q_PROPERTY(QString magazine READ magazine CONSTANT)
    Q_PROPERTY(QString jam READ jam CONSTANT)
    Q_PROPERTY(Requirement* requirement READ requirement CONSTANT)
    Q_PROPERTY(Durability* durability READ durability CONSTANT)
    Q_PROPERTY(QQmlListProperty<Location> locations READ locations CONSTANT)
    Q_PROPERTY(QQmlListProperty<Penalty> penalties READ penalties CONSTANT)
    Q_PROPERTY(QQmlListProperty<Data> features READ features CONSTANT)
    Q_PROPERTY(int armor READ armor CONSTANT)

public:
    friend class ItemCreator;

    explicit Item(QObject* parent = nullptr);
    explicit Item(const QString& type,
                  const QString& name,
                  const QString& description,
                  const int& price,
                  const int& quantity,
                  QObject* parent = nullptr);

    // Basic stats
    QString type() const;
    int price() const;
    int quantity() const;
    int reputation() const;

    // Weapon stats
    QStringList damage() const;
    int penetration() const;

    QQmlListProperty<Data> specials();
    QList<Data*> specials() const;
    int specialsCount() const;
    Data* special(const int index) const;

    // Hand weapon stats
    QQmlListProperty<DexterityBonus> dexterityBonuses();
    QList<DexterityBonus*> dexterityBonuses() const;
    int dexterityBonusesCount() const;
    DexterityBonus* dexterityBonus(const int index) const;

    // Ranged weapon stats
    int ammunition() const;
    int rateOfFire() const;
    QString bullet() const;
    QString magazine() const;
    QString jam() const;
    Requirement* requirement() const;

    // Armor stats
    Durability* durability() const;
    QQmlListProperty<Location> locations();
    QList<Location*> locations() const;
    int locationsCount() const;
    Location* location(const int index) const;

    Q_INVOKABLE bool coversLocation(const QString& location) const;
    Q_INVOKABLE Location* location(const QString& name) const;

    QQmlListProperty<Penalty> penalties();
    QList<Penalty*> penalties() const;
    int penaltiesCount() const;
    Penalty* penalty(const int index) const;

    QQmlListProperty<Data> features();
    QList<Data*> features() const;
    int featuresCount() const;
    Data* feature(int index) const;

    // Shield stats
    int armor() const;

signals:
    void quantityChanged(int quantity);
    void currentDurabilityChanged(int currentDurability);

public slots:
    void setQuantity(const int quantity);

private:
    static int specialsCount(QQmlListProperty<Data>* list);
    static Data* special(QQmlListProperty<Data>* list, int index);

    static int dexterityBonusesCount(QQmlListProperty<DexterityBonus>* list);
    static DexterityBonus* dexterityBonus(QQmlListProperty<DexterityBonus>* list, int index);

    static int locationsCount(QQmlListProperty<Location>* list);
    static Location* location(QQmlListProperty<Location>* list, int index);

    static int penaltiesCount(QQmlListProperty<Penalty>* list);
    static Penalty* penalty(QQmlListProperty<Penalty>* list, int index);

    static int featuresCount(QQmlListProperty<Data>* list);
    static Data* feature(QQmlListProperty<Data>* list, int index);

private:
    QString m_type;
    int m_price{0};
    int m_quantity{0};
    int m_reputation{0};

    // Weapon stats
    QStringList m_damage;
    int m_penetration{0};
    QList<Data*> m_specials;

    // Hand weapon stats
    QList<DexterityBonus*> m_dexterityBonus;

    // Ranged weapon stats
    int m_amunition{0};
    int m_rateOfFire{0};
    QString m_bullet{};
    QString m_magazine{};
    QString m_jam{};
    Requirement* m_pRequirement{nullptr};

    // Armor stats
    Durability* m_pDurability{nullptr};
    QList<Location*> m_locations;
    QList<Penalty*> m_penalties;
    QList<Data*> m_features;

    // Shield stats
    int m_armor{0};
};

#endif // ITEM_H
