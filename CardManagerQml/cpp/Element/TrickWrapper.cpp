#include "TrickWrapper.h"
#include "Card/Elements/Stats/TrickData.h"

TrickWrapper::TrickWrapper(QObject *parent) : QObject(parent)
{

}

TrickWrapper::TrickWrapper(TrickData *trickData, QObject *parent)
    : QObject(parent),
      m_pTrickData(trickData)
{

}

QString TrickWrapper::name() const
{
    return m_pTrickData->name();
}

QString TrickWrapper::description() const
{
    return m_pTrickData->description();
}

QString TrickWrapper::action() const
{
    return m_pTrickData->action();
}
