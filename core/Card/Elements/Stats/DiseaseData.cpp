#include "DiseaseData.h"

DiseaseData::DiseaseData(const QString &name,
                 const QString &description,
                 QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString DiseaseData::name() const
{
    return m_name;
}

QString DiseaseData::description() const
{
    return m_description;
}
