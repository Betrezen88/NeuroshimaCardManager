#ifndef ITEM_H
#define ITEM_H

#include <QMap>
#include <QVariant>

#include "../../Data.h"
#include "core_global.h"

class CORE_EXPORT Item : public Data
{
    Q_OBJECT
    Q_PROPERTY(Type type READ type CONSTANT)
    Q_PROPERTY(int price READ price CONSTANT)
    Q_PROPERTY(int quantity
               READ quantity
               WRITE setQuantity
               NOTIFY quantityChanged)

public:
    enum class Type {
        ARMOR,
        HANDWEAPON,
        RANGEDWEAPON,
        SHIELD,
        CONSUMABLE,
        OTHER,
        EMPTY
    };
    Q_ENUM(Type)

    enum class Stat {
        AMMO,
        MAGAZINE,
        RATEOFFIRE,
        DEXBONUS,
        ARMOR,
        DURABILITY,
        REPUTATION,
        LOCATIONS,
        DAMAGE,
        PENALTY,
        SPECIALS,
        REQUIREMENT,
        PENETRATION
    };
    Q_ENUM(Stat)

    explicit Item(QObject* parent = nullptr);
    explicit Item(const Type& type,
                  const QString& name,
                  const QString& description,
                  const int& price,
                  const int& quantity,
                  const QMap<Stat, QVariant>& stats = QMap<Stat, QVariant>(),
                  QObject* parent = nullptr);

    int price() const;
    int quantity() const;
    Type type() const;

    static Type stringToType(const QString& type);

    Q_INVOKABLE QVariant stat(const Stat& stat) const;
    Q_INVOKABLE bool hasStat(const Stat& stat) const;

signals:
    void quantityChanged(int quantity);

public slots:
    void setQuantity(int quantity);

private:
    Type m_type;
    int m_price{0};
    int m_quantity{0};
    QMap<Stat, QVariant> m_stats;
};

#endif // ITEM_H
