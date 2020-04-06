#include "DiseaseWrapper.h"
#include "Card/Elements/Stats/DiseaseData.h"

DiseaseWrapper::DiseaseWrapper(QObject *parent) : QObject(parent)
{

}

DiseaseWrapper::DiseaseWrapper(DiseaseData *diseaseData, QObject *parent)
    : QObject(parent),
      m_pDiseaseData(diseaseData)
{

}

QString DiseaseWrapper::name() const
{
    return m_pDiseaseData->name();
}

QString DiseaseWrapper::description() const
{
    return m_pDiseaseData->description();
}
