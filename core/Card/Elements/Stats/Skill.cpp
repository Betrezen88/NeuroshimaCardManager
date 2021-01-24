#include "Skill.h"

Skill::Skill(QObject *parent)
    : QObject(parent)
{

}

Skill::Skill(const QString &name,
             const int &value,
             const bool &used,
             QObject *parent)
    : QObject(parent),
      m_name(name),
      m_value(value),
      m_used(used)
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

bool Skill::used() const
{
    return m_used;
}

void Skill::setUsed(bool used)
{
    if (m_used == used)
        return;

    m_used = used;
    emit usedChanged(m_used);
}
