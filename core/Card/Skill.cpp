#include "Skill.h"

Skill::Skill(QObject *parent) : QObject(parent)
{

}

QString Skill::name() const
{
    return m_name;
}

int Skill::value() const
{
    return m_value;
}

void Skill::setName(const QString &name)
{
    m_name = name;
}

void Skill::setValue(const int &value)
{
    m_value = value;
}
