#include "Attribute.h"
#include "Skillpack.h"

Attribute::Attribute(QObject *parent) : QObject(parent)
{

}

QString Attribute::name() const
{
    return m_name;
}

int Attribute::value() const
{
    return m_value;
}

QMap<QString, Skillpack *> Attribute::skillpacks() const
{
    return m_skillpacks;
}

bool Attribute::hasSkillpack(const QString &name) const
{
    return m_skillpacks.contains(name);
}

void Attribute::setName(const QString &name)
{
    m_name = name;
}

void Attribute::setValue(const int &value)
{
    m_value = value;
}

void Attribute::setSkillpacks(const QMap<QString, Skillpack *> skillpacks)
{
    m_skillpacks = skillpacks;
}
