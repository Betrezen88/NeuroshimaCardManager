#include "Specialization.h"

Specialization::Specialization(QObject *parent) : QObject(parent)
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

void Specialization::setName(const QString &name)
{
    m_name = name;
}

void Specialization::setDescription(const QString &description)
{
    m_description = description;
}
