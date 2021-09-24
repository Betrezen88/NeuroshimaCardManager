#ifndef REQUIREMENTDATA_H
#define REQUIREMENTDATA_H

#include <QString>
#include "core_global.h"

struct CORE_EXPORT RequirementData {
    QString name;
    int value{0};
    bool optional{false};
    QString type;

    bool operator!=(const RequirementData& other) const {
        return name != other.name
                || value != other.value
                || optional != other.optional
                || type != other.type;
    }
};

#endif // REQUIREMENTDATA_H
