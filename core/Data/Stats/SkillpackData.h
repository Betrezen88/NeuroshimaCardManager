#ifndef SKILLPACKDATA_H
#define SKILLPACKDATA_H

#include <QString>
#include <QStringList>
#include <QVarLengthArray>

#include "SkillData.h"
#include "core_global.h"

struct CORE_EXPORT SkillpackData {
    QString name;
    QStringList specializations;
    QVarLengthArray<SkillData, 3> skills;
    bool constant;
};

#endif // SKILLPACKDATA_H
