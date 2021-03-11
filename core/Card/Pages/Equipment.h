#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include<QQmlListProperty>

#include "Page.h"
#include "../Elements/Equipment/Item.h"
#include "core_global.h"

class CORE_EXPORT Equipment : public Page
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Item> backpack READ backpack NOTIFY backpackChanged)
    Q_PROPERTY(QQmlListProperty<Item> weapons READ weapons NOTIFY weaponsChanged)
    Q_PROPERTY(int drugs READ drugs WRITE setDrugs NOTIFY drugsChanged)
    Q_PROPERTY(int food READ food WRITE setFood NOTIFY foodChanged)
    Q_PROPERTY(int water READ water WRITE setWater NOTIFY waterChanged)

public:
    explicit Equipment(QObject *parent = nullptr);
    explicit Equipment(const QList<Item*>& backpack,
                       const QList<Item*>& weapons,
                       const int& drugs = 0,
                       const int& food = 0,
                       const int& water = 0,
                       QObject* parent = nullptr);

    void addItemToBackpack(Item *item);
    Q_INVOKABLE void addItemToBackpack(const QVariantMap& itemData);
    Q_INVOKABLE void throwBackpackItem(const int& index);
    QList<Item*> backpack() const;

    QQmlListProperty<Item> backpack();
    int backpackCount() const;
    Item* backpackItem(const int& index) const;

    QQmlListProperty<Item> weapons();
    QList<Item*> weapons() const;

    int weaponsCount() const;
    Item* weapon(const int& index) const;

    Q_INVOKABLE void equipWeapon(const int& index);
    Q_INVOKABLE void unequipWeapon(const int& index);
    Q_INVOKABLE void throwWeapon(const int& index);

    Q_INVOKABLE void equipArmor(const int& index);
    Q_INVOKABLE Item* getArmor(const QString& location);

    int drugs() const;
    int food() const;
    int water() const;

public slots:
    void setDrugs(int drugs);
    void setFood(int food);
    void setWater(int water);

signals:
    void backpackChanged();
    void weaponsChanged();
    void armorChanged();
    void drugsChanged(int drugs);
    void foodChanged(int food);
    void waterChanged(int water);

private:
    Item* findItemInBackpack(const QString& name);
    int findEmptyInBackpack();

    static int backpackCount(QQmlListProperty<Item> *list);
    static Item* backpackItem(QQmlListProperty<Item> *list, int index);

    static int weaponsCount(QQmlListProperty<Item> *list);
    static Item* weapon(QQmlListProperty<Item> *list, int index);

private:
    QList<Item*> m_backpack;
    QList<Item*> m_weapons;
    QList<Item*> m_armor;
    int m_drugs;
    int m_food;
    int m_water;
};

#endif // EQUIPMENT_H
