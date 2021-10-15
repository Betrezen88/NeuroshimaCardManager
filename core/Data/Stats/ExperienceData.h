#ifndef EXPERIENCEDATA_H
#define EXPERIENCEDATA_H

#include <QObject>

#include "core_global.h"

struct CORE_EXPORT ExperienceData {
    Q_GADGET
public:
    int gathered;
    int spended;
};
Q_DECLARE_METATYPE(ExperienceData)

#endif // EXPERIENCEDATA_H
