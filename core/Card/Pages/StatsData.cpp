#include "StatsData.h"

#include "../Elements/Stats/PersonalData.h"

StatsData::StatsData(QObject *parent) : QObject(parent)
{

}

PersonalData *StatsData::personal() const
{
    return m_personal;
}

void StatsData::setPersonal(PersonalData *personal)
{
    m_personal = personal;
}
