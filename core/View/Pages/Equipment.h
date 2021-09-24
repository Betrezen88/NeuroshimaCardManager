#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <QObject>
#include <QQmlListProperty>

#include "Page.h"
#include "../../Data/Equipment/EquipmentData.h"

#include "core_global.h"

class Item;

class CORE_EXPORT Equipment : public Page
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Item> backpack READ backpack NOTIFY backpackChanged)
    Q_PROPERTY(QQmlListProperty<Item> weapons READ weapons NOTIFY weaponsChanged)
    Q_PROPERTY(QQmlListProperty<Item> armor READ armor NOTIFY armorChanged)

    Q_PROPERTY(int drugs READ drugs CONSTANT)
    Q_PROPERTY(int food READ food CONSTANT)
    Q_PROPERTY(int water READ water CONSTANT)

public:
    explicit Equipment(QObject *parent = nullptr);
    explicit Equipment(const EquipmentData& data, QObject *parent = nullptr);

    QQmlListProperty<Item> backpack();
    int backpackCount() const;
    Item* backpackItem(const int index) const;

    QQmlListProperty<Item> weapons();
    int weaponCount() const;
    Item* weapon(const int index) const;

    QQmlListProperty<Item> armor();
    int armorCount() const;
    Item* armorItem(const int index) const;

    int drugs() const;
    int food() const;
    int water() const;

    const EquipmentData& data() const;

signals:
    void backpackChanged();
    void weaponsChanged();
    void armorChanged();

public slots:
    Item* armorItem(const QString& location);
    void addItemToBackpack(const QVariantMap& data);
    void removeItemFromBackpack(const int index);
    void equipWeapon(const int index);
    void unequipWeapon(const int index);
    void removeWeapon(const int index);
    void equipArmor(const int index);
    void unequipArmor(Item *armor);
    void removeArmor(Item *armor);

private:
    void addBackpackItem(const ItemData &data);
    void addWeapon(const ItemData& data);
    void addArmor(const ItemData& data);
    void eraseBackpackItem(const int index);
    void eraseWeapon(const int index);
    void eraseArmor(const int index);
    void removeCollidedArmor(ItemData *armor);

    static int backpackCount(QQmlListProperty<Item> *list);
    static Item* backpackItem(QQmlListProperty<Item> *list, int index);

    static int weaponCount(QQmlListProperty<Item> *list);
    static Item* weapon(QQmlListProperty<Item> *list, int index);

    static int armorCount(QQmlListProperty<Item> *list);
    static Item* armorItem(QQmlListProperty<Item> *list, int index);

private:
    EquipmentData m_data;

    QVector<Item*> m_backpack;
    QVector<Item*> m_weapons;
    QVector<Item*> m_armor;

    int m_drugs;
    int m_food;
    int m_water;
};

#endif // EQUIPMENT_H
