#ifndef ITEMCREATOR_H
#define ITEMCREATOR_H

#include <QObject>
#include <QMap>
#include <QVariant>

class Item;

class ItemCreator : public QObject
{
    Q_OBJECT
public:
    explicit ItemCreator(QObject *parent = nullptr);

    Item* create(const QJsonObject& data);
    Item* create(const QVariantMap& data);

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
