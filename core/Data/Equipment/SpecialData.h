#ifndef SPECIALDATA_H
#define SPECIALDATA_H

#include <QString>

#include "core_global.h"

struct CORE_EXPORT SpecialData {
    QString name;
    QString description;

    bool operator==(const SpecialData& other) const {
        return name == other.name
                && description == other.description;
    }
};

#endif // SPECIALDATA_H
