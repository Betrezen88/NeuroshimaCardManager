#include "SkillpackData.h"
#include "SkillData.h"

SkillpackData::SkillpackData()
{

}

QString SkillpackData::name() const
{
    return m_name;
}

QStringList SkillpackData::specializations() const
{
    return m_specializations;
}

QMap<QString, SkillData *> SkillpackData::skills() const
{
    return m_skills;
}

bool SkillpackData::hasSpecialization(const QString &specialization) const
{
    return m_specializations.contains(specialization);
}

bool SkillpackData::hasSkill(const QString &name)
{
    return m_skills.contains(name);
}

void SkillpackData::setName(const QString &name)
{
    m_name = name;
}

void SkillpackData::setSpecializations(const QStringList &specializations)
{
    m_specializations = specializations;
}

void SkillpackData::setSkills(const QMap<QString, SkillData *> &skills)
{
    m_skills = skills;
}
