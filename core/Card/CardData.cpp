#include "CardData.h"

#include "Pages/StatsData.h"

CardData::CardData(QObject *parent) : QObject(parent)
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
