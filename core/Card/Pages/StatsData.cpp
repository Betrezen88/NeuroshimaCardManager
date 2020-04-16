#include "StatsData.h"
#include "../Elements/Stats/PersonalData.h"
#include "../Elements/Stats/AttributeData.h"
#include "../Elements/Stats/OtherSkillData.h"

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
