#include "Card.h"

Card::Card(QObject *parent) : QObject(parent)
{

}

Stats *Card::stats() const
{
    return m_stats;
}

void Card::setStats(Stats *stats)
{
    m_stats = stats;
}
