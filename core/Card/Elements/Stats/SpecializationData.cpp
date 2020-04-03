#include "SpecializationData.h"

SpecializationData::SpecializationData(const QString &name,
                                       const QString &description)
    : m_name(name),
      m_description(description)
{

}

QString SpecializationData::name() const
{
    return m_name;
}

QString SpecializationData::description() const
{
    return m_description;
}
