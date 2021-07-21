#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

#include <QObject>
#include <QMap>
#include <QVariant>

class Item;
class Data;
class Penalty;
class Location;
class DexterityBonus;

class ItemCreator : public QObject
{
    Q_OBJECT
public:
    explicit ItemCreator(QObject *parent = nullptr);

    Item* create(const QJsonObject& data);
    Item* create(const QVariantMap& data);
    Item* create(const Item* item);

private:
    void setStats(Item* item, const QVariantMap& stats);
    Data* createData(const QMap<QString, QVariant>& input, Item* parent);
    Penalty* createPenalty(const QMap<QString, QVariant>& input, Item* parent);
    Location* createLocation(const QMap<QString, QVariant>& input, Item* parent);
    DexterityBonus *createDexbonus(const QMap<QString, QVariant>& input, Item* parent);

private:
    const QStringList m_types{
        "ARMOR",
        "HANDWEAPON",
        "RANGEDWEAPON",
        "SHIELD",
        "CONSUMABLE",
        "OTHER",
        "EMPTY"
    };
};

#endif // ITEMCREATOR_H
