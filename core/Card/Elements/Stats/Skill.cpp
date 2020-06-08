#include "Skill.h"

Skill::Skill(QObject *parent)
    : QObject(parent)
{

}

Skill::Skill(const QString &name,
             const int &value,
             QObject *parent)
    : QObject(parent),
      m_name(name),
      m_value(value)
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
