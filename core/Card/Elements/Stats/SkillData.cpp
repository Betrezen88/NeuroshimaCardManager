#include "SkillData.h"

SkillData::SkillData(const QString &name, const int value)
    : m_name(name),
      m_value(value)
{

}

QString SkillData::name() const
{
    return m_name;
}

int SkillData::value() const
{
    return m_value;
}

void SkillData::setName(const QString &name)
{
    m_name = name;
}

void SkillData::setValue(const int &value)
{
    m_value = value;
}
