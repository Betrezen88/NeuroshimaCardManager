#include "StatsData.h"
#include "../Elements/Stats/PersonalData.h"
#include "../Elements/Stats/AttributeData.h"
#include "../Elements/Stats/OtherSkillData.h"
#include "../Elements/Stats/TrickData.h"

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

QList<OtherSkillData *> StatsData::otherSkills() const
{
    return m_otherSkills;
}

QList<TrickData *> StatsData::tricks() const
{
    return m_tricks;
}

void StatsData::setPersonal(PersonalData *personal)
{
    m_personal = personal;
}

void StatsData::setAttributes(QList<AttributeData *> attributes)
{
    m_attributes = attributes;
}

void StatsData::setOtherSkills(QList<OtherSkillData *> otherSkills)
{
    m_otherSkills = otherSkills;
}

void StatsData::setTricks(QList<TrickData *> tricks)
{
    m_tricks = tricks;
}
