#include "PersonalWrapper.h"
#include "../Element/OriginWrapper.h"
#include "../Element/ProfessionWrapper.h"
#include "../Element/SpecializationWrapper.h"
#include "../Element/DiseaseWrapper.h"
#include "../Element/FeatureWrapper.h"

#include "Card/Elements/Stats/PersonalData.h"
#include "Card/Elements/Stats/OriginData.h"
#include "Card/Elements/Stats/ProfessionData.h"
#include "Card/Elements/Stats/SpecializationData.h"
#include "Card/Elements/Stats/DiseaseData.h"
#include "Card/Elements/Stats/FeatureData.h"

PersonalWrapper::PersonalWrapper(QObject *parent) : QObject(parent)
{

}

PersonalWrapper::PersonalWrapper(PersonalData *personalData, QObject *parent)
    : QObject(parent),
      m_pPersonalData(personalData),
      m_pOriginWrapper(new OriginWrapper(personalData->origin(), this)),
      m_pProfessionWrapper(new ProfessionWrapper(personalData->profession(), this)),
      m_pSpecializationWrapper(new SpecializationWrapper(personalData->specialization(), this)),
      m_pDiseaseWrapper(new DiseaseWrapper(personalData->disease(), this)),
      m_pOriginFeature(new FeatureWrapper(personalData->originFeature(), this)),
      m_pProfessionFeature(new FeatureWrapper(personalData->professionFeature(), this))
{

}

QString PersonalWrapper::name() const
{
    return m_pPersonalData->name();
}

QString PersonalWrapper::surname() const
{
    return m_pPersonalData->surname();
}

QString PersonalWrapper::nickname() const
{
    return m_pPersonalData->nickname();
}

QString PersonalWrapper::fullname() const
{
    return m_pPersonalData->fullname();
}

OriginWrapper *PersonalWrapper::origin() const
{
    return m_pOriginWrapper;
}

ProfessionWrapper *PersonalWrapper::profession() const
{
    return m_pProfessionWrapper;
}

SpecializationWrapper *PersonalWrapper::specialization() const
{
    return m_pSpecializationWrapper;
}

DiseaseWrapper *PersonalWrapper::disease() const
{
    return m_pDiseaseWrapper;
}

FeatureWrapper *PersonalWrapper::originFeature() const
{
    return m_pOriginFeature;
}

FeatureWrapper *PersonalWrapper::professionFeature() const
{
    return m_pProfessionFeature;
}
