#ifndef STATS_H
#define STATS_H

#include <QString>

#include "core_global.h"

class PersonalData;

class CORE_EXPORT StatsData
{
public:
    StatsData();

    PersonalData *personal();

    void setPersonal(PersonalData *personal);

private:
    PersonalData *m_personal{nullptr};
};

#endif // STATS_H
