#ifndef PENALTYDATA_H
#define PENALTYDATA_H

#include <QString>
#include "core_global.h"

struct CORE_EXPORT PenaltyData {
    QString name;
    int value;
    QString type;

    bool operator==(const PenaltyData& other) const {
        return name == other.name
                && value == other.value
                && type == other.type;
    }
};

#endif // PENALTYDATA_H
