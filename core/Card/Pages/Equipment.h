#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include<QQmlListProperty>

#include "Page.h"
#include "../Elements/Equipment/Item.h"
#include "core_global.h"

class CORE_EXPORT Equipment : public Page
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Item> backpack
               READ backpack
               NOTIFY backpackChanged)
    Q_PROPERTY(QQmlListProperty<Item> weapons
               READ weapons
               NOTIFY weaponsChanged)

public:
    explicit Equipment(QObject *parent = nullptr);
    explicit Equipment(const QList<Item*>& backpack, QObject* parent = nullptr);

    void addItemToBackpack(Item *item);
    Q_INVOKABLE void addItemToBackpack(const QVariantMap& itemData);
    QQmlListProperty<Item> backpack();
    Q_INVOKABLE Item* backpackItem(const int& index) const;
    QList<Item*> backpack() const;

    QQmlListProperty<Item> weapons();
    QList<Item*> weapons() const;
    Q_INVOKABLE Item* weaponAt(const int& index) const;
    void addWeaponItem(Item* item);

    Q_INVOKABLE void equipWeapon(const int& index);
    Q_INVOKABLE void unequipWeapon(const int& index);
    Q_INVOKABLE void throwWeapon(const int& index);

signals:
    void backpackChanged();
    void weaponsChanged();

private:
    Item* findItemInBackpack(const QString& name);
    int findEmptyInBackpack();

private:
    QList<Item*> m_backpack;
    QList<Item*> m_weapons;
};

#endif // EQUIPMENT_H
