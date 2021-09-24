#ifndef SYMPTOMDATA_H
#define SYMPTOMDATA_H

#include <QString>
#include <QVector>

#include "../Common/PenaltyData.h"
#include "core_global.h"

struct CORE_EXPORT SymptomData {
    QString name;
    QString description;
    QVector<PenaltyData> penalties;
};

#endif // SYMPTOMDATA_H
