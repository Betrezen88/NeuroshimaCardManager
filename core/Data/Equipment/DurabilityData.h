#ifndef DURABILITYDATA_H
#define DURABILITYDATA_H

#include "core_global.h"

struct CORE_EXPORT DurabilityData {
    int current{0};
    int max{0};

    bool operator!=(const DurabilityData& other) const {
        return current != other.current
                || max != other.max;
    }
};

#endif // DURABILITYDATA_H
