#ifndef TRICKDATA_H
#define TRICKDATA_H

#include <QString>
#include <QVector>

#include "../Common/RequirementData.h"
#include "core_global.h"

struct CORE_EXPORT TrickData {
    QString name;
    QString description;
    QString action;
    QVector<RequirementData> requirements;
};

#endif // TRICKDATA_H
