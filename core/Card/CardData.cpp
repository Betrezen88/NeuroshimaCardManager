#include "CardData.h"
#include "Pages/StatsData.h"

CardData::CardData()
{

}

StatsData *CardData::stats() const
{
    return m_stats;
}

void CardData::setStats(StatsData *stats)
{
    m_stats = stats;
}
