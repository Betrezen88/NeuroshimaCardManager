#ifndef WOUNDDATA_H
#define WOUNDDATA_H

#include <QString>
#include "core_global.h"

struct CORE_EXPORT WoundData {
    WoundData() = default;
    WoundData(const WoundData& other) = default;
    WoundData(WoundData&& other) = default;
    WoundData& operator=(const WoundData& other) = default;
    WoundData& operator=(WoundData&& other) = default;
    ~WoundData() = default;

    WoundData(const QString& location, const QString& type, const int modifier)
        : location(location)
        , type(type)
        , modifier(modifier)
    {}

    QString location;
    QString type;
    int modifier;
};

#endif // WOUNDDATA_H
