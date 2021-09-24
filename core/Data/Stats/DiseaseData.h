#ifndef DISEASEDATA_H
#define DISEASEDATA_H

#include <QString>
#include <QVector>

#include "SymptomData.h"
#include "core_global.h"

struct CORE_EXPORT DiseaseData {
    QString name;
    QString description;
    QString cure;
    QVector<SymptomData> symptoms;
};

#endif // DISEASEDATA_H
