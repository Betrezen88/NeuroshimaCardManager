#include "OtherSkill.h"

OtherSkill::OtherSkill(QObject *parent)
    : Skill(parent)
{

}

OtherSkill::OtherSkill(const QString &name,
                       const int &value,
                       const bool &used,
                       const QString &attribute,
                       QObject *parent)
    : Skill(name, value, used, parent),
      m_attribute(attribute)
{

}

QString OtherSkill::attribute() const
{
    return m_attribute;
}
