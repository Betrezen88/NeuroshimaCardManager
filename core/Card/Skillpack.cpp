#include "Skillpack.h"

Skillpack::Skillpack(QObject *parent) : QObject(parent)
{

}

QString Skillpack::name() const
{
    return m_name;
}

QStringList Skillpack::specializations() const
{
    return m_specializations;
}

bool Skillpack::hasSpecialization(const QString &specialization) const
{
    return m_specializations.contains(specialization);
}

void Skillpack::setName(const QString &name)
{
    m_name = name;
}

void Skillpack::setSpecializations(const QStringList &specializations)
{
    m_specializations = specializations;
}
