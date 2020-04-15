#include "StatsData.h"
#include "../Elements/Stats/PersonalData.h"

StatsData::StatsData()
{

}

PersonalData *StatsData::personal() const
{
    return m_personal;
}

QList<AttributeData *> StatsData::attributes() const
{
    return m_attributes;
}

void StatsData::setPersonal(PersonalData *personal)
{
    m_personal = personal;
}

void StatsData::setAttributes(QList<AttributeData *> attributes)
{
    m_attributes = attributes;
}
