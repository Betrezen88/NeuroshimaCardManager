#include "SkillpackData.h"
#include "SkillData.h"

SkillpackData::SkillpackData(const QString name, const QStringList &specializations)
    : m_name(name),
      m_specializations(specializations)
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

QList<SkillData *> SkillpackData::skills() const
{
    return m_skills;
}

bool SkillpackData::hasSpecialization(const QString &specialization) const
{
    return m_specializations.contains(specialization);
}

bool SkillpackData::hasSkill(const QString &name)
{
    for ( SkillData *pSkill: m_skills ) {
        if ( name == pSkill->name() )
            return true;
    }

    return false;
}

void SkillpackData::addSkill(SkillData *skill)
{
    m_skills.push_back( skill );
}
