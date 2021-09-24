#ifndef LOCATIONDATA_H
#define LOCATIONDATA_H

#include <QString>

#include "core_global.h"

struct CORE_EXPORT LocationData {
    QString name;
    int armor{0};
    int cutting{0};

    bool operator==(const LocationData& other) const {
        return name == other.name
                && armor == other.armor
                && cutting == other.cutting;
    }
};

#endif // LOCATIONDATA_H
