#include "Card.h"
#include "../Page/Stats.h"

#include "Card/CardData.h"

#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/PersonalData.h"

Card::Card(QObject *parent) : QObject(parent)
{

}

Card::Card(CardData *cardData, QObject *parent)
    : QObject(parent),
      m_pCardData(cardData)
{
    m_pStats = new Stats(cardData->stats(), this);
}

QString Card::fullname()
{
    return m_pCardData->stats()->personal()->fullname();
}

Stats *Card::stats() const
{
    return m_pStats;
}
