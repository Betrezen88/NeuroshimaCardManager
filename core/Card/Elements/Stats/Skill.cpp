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

void Skill::setValue(const int &value)
{
    if ( m_value != value ) {
        m_value = value;
        emit valueChanged();
    }
}
