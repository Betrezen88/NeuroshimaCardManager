#include "Trick.h"

Trick::Trick(const QString &name, const QString &description, const QString &action)
    : m_name(name),
      m_description(description),
      m_action(action)
{

}

QString Trick::name() const
{
    return m_name;
}

QString Trick::description() const
{
    return m_description;
}

QString Trick::action() const
{
    return m_action;
}
