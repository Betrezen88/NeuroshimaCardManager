#include "Origin.h"

Origin::Origin(const QString &name,
               const QString &description,
               QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString Origin::name() const
{
    return m_name;
}

QString Origin::description() const
{
    return m_description;
}
