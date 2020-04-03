#include "AttributeData.h"
#include "SkillpackData.h"

AttributeData::AttributeData()
{

}

QString AttributeData::name() const
{
    return m_name;
}

int AttributeData::value() const
{
    return m_value;
}

QMap<QString, SkillpackData *> AttributeData::skillpacks() const
{
    return m_skillpacks;
}

bool AttributeData::hasSkillpack(const QString &name) const
{
    return m_skillpacks.contains(name);
}

void AttributeData::setName(const QString &name)
{
    m_name = name;
}

void AttributeData::setValue(const int &value)
{
    m_value = value;
}

void AttributeData::setSkillpacks(const QMap<QString, SkillpackData *> skillpacks)
{
    m_skillpacks = skillpacks;
}
