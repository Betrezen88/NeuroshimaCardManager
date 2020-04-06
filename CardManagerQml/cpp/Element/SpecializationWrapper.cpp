#include "SpecializationWrapper.h"
#include "Card/Elements/Stats/SpecializationData.h"

SpecializationWrapper::SpecializationWrapper(QObject *parent) : QObject(parent)
{

}

SpecializationWrapper::SpecializationWrapper(SpecializationData *specializationData,
                                             QObject *parent)
    : QObject(parent),
      m_pSpecializationData(specializationData)
{

}

QString SpecializationWrapper::name() const
{
    return m_pSpecializationData->name();
}

QString SpecializationWrapper::description() const
{
    return m_pSpecializationData->description();
}
