#include "Stats.h"
#include "../Element/Personal.h"

#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/PersonalData.h"

Stats::Stats(QObject *parent)
{

}

Stats::Stats(StatsData *statsData, QObject *parent)
    : QObject(parent),
      m_pStatsData(statsData)
{
    m_pPersonal = new Personal(m_pStatsData->personal(), this);
}

Personal *Stats::personal() const
{
    return m_pPersonal;
}
