#ifndef ATTRIBUTEDATA_H
#define ATTRIBUTEDATA_H

#include <QString>
#include <QVector>

#include "SkillpackData.h"
#include "core_global.h"

struct CORE_EXPORT AttributeData {
    QString name;
    int value;
    QVector<SkillpackData> skillpacks;
};

#endif // ATTRIBUTEDATA_H
