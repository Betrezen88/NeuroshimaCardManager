#include "Difficulty.h"

Difficulty::Difficulty(QObject *parent) : QObject(parent)
{

}

Difficulty::Difficulty(const QString &name,
                       const QString &shortname,
                       const int &value,
                       QObject *parent)
    : QObject(parent),
      m_name(name),
      m_shortname(shortname),
      m_value(value)
{

}

QString Difficulty::name() const
{
    return m_name;
}

QString Difficulty::shortname() const
{
    return m_shortname;
}

int Difficulty::value() const
{
    return m_value;
}
