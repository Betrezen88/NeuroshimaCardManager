#include "Skillpack.h"
#include "Skill.h"

Skillpack::Skillpack(QObject *parent) : QObject(parent)
{

}

QString Skillpack::name() const
{
    return m_name;
}

QStringList Skillpack::specializations() const
{
    return m_specializations;
}

QMap<QString, Skill *> Skillpack::skills() const
{
    return m_skills;
}

bool Skillpack::hasSpecialization(const QString &specialization) const
{
    return m_specializations.contains(specialization);
}

bool Skillpack::hasSkill(const QString &name)
{
    return m_skills.contains(name);
}

void Skillpack::setName(const QString &name)
{
    m_name = name;
}

void Skillpack::setSpecializations(const QStringList &specializations)
{
    m_specializations = specializations;
}

void Skillpack::setSkills(const QMap<QString, Skill *> &skills)
{
    m_skills = skills;
}
