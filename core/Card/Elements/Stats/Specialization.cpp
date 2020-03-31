#include "Specialization.h"

Specialization::Specialization(const QString &name,
                               const QString &description,
                               QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString Specialization::name() const
{
    return m_name;
}

QString Specialization::description() const
{
    return m_description;
}
