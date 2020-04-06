#include "ProfessionWrapper.h"
#include "Card/Elements/Stats/ProfessionData.h"

ProfessionWrapper::ProfessionWrapper(QObject *parent) : QObject(parent)
{

}

ProfessionWrapper::ProfessionWrapper(ProfessionData *professionData, QObject *parent)
    : QObject(parent),
      m_pProfessionData(professionData)
{

}

QString ProfessionWrapper::name() const
{
    return m_pProfessionData->name();
}

QString ProfessionWrapper::description() const
{
    return m_pProfessionData->description();
}
