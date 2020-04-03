#include "Stats.h"

#include "Card/Pages/StatsData.h"

Stats::Stats(StatsData *statsData, QObject *parent)
    : QObject(parent),
      m_pStatsData(statsData)
{

}
