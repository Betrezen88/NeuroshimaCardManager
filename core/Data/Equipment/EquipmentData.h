#ifndef EQUIPMENTDATA_H
#define EQUIPMENTDATA_H

#include <QVector>
#include <QSharedPointer>

#include "ItemData.h"

#include "core_global.h"

struct CORE_EXPORT EquipmentData {
    QVector<QSharedPointer<ItemData>> backpack;
    QVector<QSharedPointer<ItemData>> weapon;
    QVector<QSharedPointer<ItemData>> armor;
    int food{0};
    int water{0};
    int drugs{0};
};

#endif // EQUIPMENTDATA_H
