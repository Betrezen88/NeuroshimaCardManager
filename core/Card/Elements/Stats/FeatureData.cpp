#include "FeatureData.h"

FeatureData::FeatureData(const QString &name, const QString &description)
    : m_name(name),
      m_description(description)
{

}

QString FeatureData::name() const
{
    return m_name;
}

QString FeatureData::description() const
{
    return m_description;
}

void FeatureData::setName(const QString &name)
{
    m_name = name;
}

void FeatureData::setDescription(const QString &description)
{
    m_description = description;
}
