#include "Penalty.h"

Penalty::Penalty(QObject *parent)
    : QObject(parent)
{

}

Penalty::Penalty(const QString &name,
                 const int &value,
                 const QString &type,
                 QObject *parent)
    : QObject(parent),
      m_type(type),
      m_name(name),
      m_value(value)
{

}

QString Penalty::type() const
{
    return m_type;
}

QString Penalty::name() const
{
    return m_name;
}

int Penalty::value() const
{
    return m_value;
}
