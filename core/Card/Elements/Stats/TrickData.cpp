#include "TrickData.h"

TrickData::TrickData(const QString &name, const QString &description, const QString &action)
    : m_name(name),
      m_description(description),
      m_action(action)
{

}

QString TrickData::name() const
{
    return m_name;
}

QString TrickData::description() const
{
    return m_description;
}

QString TrickData::action() const
{
    return m_action;
}
