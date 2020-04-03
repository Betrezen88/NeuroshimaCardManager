#include "FeatureData.h"

FeatureData::FeatureData()
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
