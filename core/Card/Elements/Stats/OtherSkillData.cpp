#include "OtherSkillData.h"

OtherSkillData::OtherSkillData(const QString &name,
                               const int &value,
                               const QString &attribute)
    : m_name(name),
      m_value(value),
      m_attribute(attribute)
{

}

QString OtherSkillData::name() const
{
    return m_name;
}

int OtherSkillData::value() const
{
    return m_value;
}

QString OtherSkillData::attribute() const
{
    return m_attribute;
}
