#ifndef SKILLDATA_H
#define SKILLDATA_H

#include <QString>
#include "core_global.h"

struct CORE_EXPORT SkillData {
    QString name;
    int value;
    bool used;
};

#endif // SKILLDATA_H
