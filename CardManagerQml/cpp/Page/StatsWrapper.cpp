#include "StatsWrapper.h"
#include "cpp/Section/PersonalWrapper.h"
#include "Card/Pages/StatsData.h"

StatsWrapper::StatsWrapper(QObject *parent) : QObject(parent)
{

}

StatsWrapper::StatsWrapper(StatsData *statsData, QObject *parent)
    : QObject(parent),
      m_pStatsData(statsData),
      m_pPersonalWrapper(new PersonalWrapper(statsData->personal(), this))
{

}

PersonalWrapper *StatsWrapper::personal() const
{
    return m_pPersonalWrapper;
}
