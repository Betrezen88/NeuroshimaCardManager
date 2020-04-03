#ifndef STATSDATA_H
#define STATSDATA_H

#include "core_global.h"

class PersonalData;

class CORE_EXPORT StatsData
{
public:
    StatsData();

    PersonalData *personal() const;
    void setPersonal(PersonalData *personal);

private:
    PersonalData *m_personal{nullptr};
};

#endif // STATSDATA_H
