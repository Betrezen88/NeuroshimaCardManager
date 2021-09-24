#ifndef ORIGINDATA_H
#define ORIGINDATA_H

#include <QString>

#include "FeatureData.h"
#include "core_global.h"

struct CORE_EXPORT OriginData {
    QString name;
    QString description;
    FeatureData feature;
};

#endif // ORIGINDATA_H
