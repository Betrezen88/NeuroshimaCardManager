#ifndef DEXTERITYBONUSDATA_H
#define DEXTERITYBONUSDATA_H

#include <QString>

#include "core_global.h"

struct CORE_EXPORT DexterityBonusData {
    QString name;
    int value{0};

    bool operator==(const DexterityBonusData& other) const {
        return name == other.name
                && value == other.value;
    }
};

#endif // DEXTERITYBONUSDATA_H
