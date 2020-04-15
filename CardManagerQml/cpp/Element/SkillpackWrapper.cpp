#include "SkillpackWrapper.h"
#include "SkillWrapper.h"
#include "Card/Elements/Stats/SkillpackData.h"

SkillpackWrapper::SkillpackWrapper(QObject *parent) : QObject(parent)
{

}

SkillpackWrapper::SkillpackWrapper(SkillpackData *skillpackData, QObject *parent)
    : QObject(parent),
      m_pSkillpackData(skillpackData)
{
    for ( SkillData *pSkill: m_pSkillpackData->skills() ) {
        appendSkill( new SkillWrapper(pSkill, this) );
    }
}

QString SkillpackWrapper::name() const
{
    return m_pSkillpackData->name();
}

QStringList SkillpackWrapper::specializations() const
{
    return m_pSkillpackData->specializations();
}

QQmlListProperty<SkillWrapper> SkillpackWrapper::skills()
{
    return QQmlListProperty<SkillWrapper>(this, this,
                                          &SkillpackWrapper::appendSkill,
                                          &SkillpackWrapper::skillCount,
                                          &SkillpackWrapper::skill,
                                          &SkillpackWrapper::clearSkills);
}

void SkillpackWrapper::appendSkill(SkillWrapper *skill)
{
    m_skills.append(skill);
    emit skillsChanged();
}

int SkillpackWrapper::skillCount() const
{
    return m_skills.count();
}

SkillWrapper *SkillpackWrapper::skill(int index) const
{
    return m_skills.at(index);
}

void SkillpackWrapper::clearSkills()
{
    m_skills.clear();
}

bool SkillpackWrapper::hasSpecialization(const QString &specialization) const
{
    return m_pSkillpackData->hasSpecialization(specialization);
}

bool SkillpackWrapper::hasSkill(const QString &name)
{
    return m_pSkillpackData->hasSkill(name);
}

void SkillpackWrapper::appendSkill(QQmlListProperty<SkillWrapper> *list, SkillWrapper *skill)
{
    reinterpret_cast<SkillpackWrapper*>(list->data)->appendSkill(skill);
}

int SkillpackWrapper::skillCount(QQmlListProperty<SkillWrapper> *list)
{
    return reinterpret_cast<SkillpackWrapper*>(list->data)->skillCount();
}

SkillWrapper *SkillpackWrapper::skill(QQmlListProperty<SkillWrapper> *list, int index)
{
    return reinterpret_cast<SkillpackWrapper*>(list->data)->skill(index);
}

void SkillpackWrapper::clearSkills(QQmlListProperty<SkillWrapper> *list)
{
    reinterpret_cast<SkillpackWrapper*>(list->data)->clearSkills();
}
