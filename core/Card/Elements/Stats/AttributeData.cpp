#include "AttributeData.h"
#include "SkillpackData.h"

AttributeData::AttributeData(const QString &name, const int value)
    : m_name(name),
      m_value(value)
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

QList<SkillpackData *> AttributeData::skillpacks() const
{
    return m_skillpacks;
}

bool AttributeData::hasSkillpack(const QString &name) const
{
    for ( SkillpackData *pSkillpack: m_skillpacks ) {
        if ( name == pSkillpack->name() )
            return true;
    }

    return false;
}

void AttributeData::setName(const QString &name)
{
    m_name = name;
}

void AttributeData::setValue(const int &value)
{
    m_value = value;
}

void AttributeData::addSkillpack(SkillpackData *skillpack)
{
    m_skillpacks.push_back( skillpack );
}
