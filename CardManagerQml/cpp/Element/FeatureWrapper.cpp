#include "FeatureWrapper.h"
#include "Card/Elements/Stats/FeatureData.h"

FeatureWrapper::FeatureWrapper(QObject *parent) : QObject(parent)
{

}

FeatureWrapper::FeatureWrapper(FeatureData *featureData, QObject *parent)
    : QObject(parent),
      m_pFeatureData(featureData)
{

}

QString FeatureWrapper::name() const
{
    return m_pFeatureData->name();
}

QString FeatureWrapper::description() const
{
    return m_pFeatureData->description();
}
