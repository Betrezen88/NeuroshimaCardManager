#include "Requirement.h"

Requirement::Requirement(QObject *parent): QObject(parent)
{

}

Requirement::Requirement(const QString &name,
                         const int &value,
                         const bool &optional,
                         Type type,
                         QObject *parent)
    : QObject(parent),
      m_name(name),
      m_value(value),
      m_optional(optional),
      m_type(type)
{

}

QString Requirement::name() const
{
    return m_name;
}

int Requirement::value() const
{
    return m_value;
}

bool Requirement::optional() const
{
    return m_optional;
}

Requirement::Type Requirement::type() const
{
    return m_type;
}
