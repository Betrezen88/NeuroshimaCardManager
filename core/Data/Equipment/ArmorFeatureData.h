#ifndef ARMORFEATUREDATA_H
#define ARMORFEATUREDATA_H

#include <QString>

#include "core_global.h"

struct CORE_EXPORT ArmorFeatureData {
    QString name;
    QString description;

    bool operator==(const ArmorFeatureData& other) const {
        return name == other.name
                && description == other.description;
    }
};

#endif // ARMORFEATUREDATA_H
