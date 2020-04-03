#include "StatsData.h"

#include "../Elements/Stats/PersonalData.h"

StatsData::StatsData()
{

}

PersonalData *StatsData::personal()
{
    return m_personal;
}

void StatsData::setPersonal(PersonalData *personal)
{
    m_personal = personal;
}
