#include "OtherSkillWrapper.h"
#include "Card/Elements/Stats/OtherSkillData.h"

OtherSkillWrapper::OtherSkillWrapper(QObject *parent) : QObject(parent)
{

}

OtherSkillWrapper::OtherSkillWrapper(OtherSkillData *otherSkill, QObject *parent)
    : QObject(parent),
      m_pOtherSkillData(otherSkill)
{

}

QString OtherSkillWrapper::name() const
{
    return m_pOtherSkillData->name();
}

int OtherSkillWrapper::value() const
{
    return m_pOtherSkillData->value();
}

QString OtherSkillWrapper::attribute() const
{
    return m_pOtherSkillData->attribute();
}
