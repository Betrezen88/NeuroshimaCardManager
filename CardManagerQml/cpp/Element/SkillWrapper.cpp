#include "SkillWrapper.h"
#include "Card/Elements/Stats/SkillData.h"

SkillWrapper::SkillWrapper(QObject *parent) : QObject(parent)
{

}

SkillWrapper::SkillWrapper(SkillData *skillData, QObject *parent)
    : QObject(parent),
      m_pSkillData(skillData)
{

}

QString SkillWrapper::name() const
{
    return m_pSkillData->name();
}

int SkillWrapper::value() const
{
    return m_pSkillData->value();
}
