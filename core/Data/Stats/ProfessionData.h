#ifndef PROFESSIONDATA_H
#define PROFESSIONDATA_H

#include <QString>

#include "FeatureData.h"
#include "core_global.h"

struct CORE_EXPORT ProfessionData {
    QString name;
    QString description;
    FeatureData feature;
};

#endif // PROFESSIONDATA_H
