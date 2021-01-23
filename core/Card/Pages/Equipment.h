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

public:
    explicit Equipment(QObject *parent = nullptr);
    explicit Equipment(const QList<Item*>& backpack, QObject* parent = nullptr);

    void addItemToBackpack(Item *item);
    Q_INVOKABLE void addItemToBackpack(const QVariantMap& itemData);
    QQmlListProperty<Item> backpack();
    Q_INVOKABLE Item* getItemFromBackpack(const int &index);
    QList<Item*> backpack() const;

signals:
    void backpackChanged();

private:
    Item* findItemInBackpack(const QString& name);
    int findEmptyInBackpack();

private:
    QList<Item*> m_backpack;
};

#endif // EQUIPMENT_H
