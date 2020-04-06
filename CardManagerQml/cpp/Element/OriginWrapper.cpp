#include "OriginWrapper.h"
#include "Card/Elements/Stats/OriginData.h"

OriginWrapper::OriginWrapper(QObject *parent) : QObject(parent)
{

}

OriginWrapper::OriginWrapper(OriginData *originData, QObject *parent)
    : QObject(parent),
      m_pOriginData(originData)
{

}

QString OriginWrapper::name() const
{
    return m_pOriginData->name();
}

QString OriginWrapper::description() const
{
    return m_pOriginData->description();
}
