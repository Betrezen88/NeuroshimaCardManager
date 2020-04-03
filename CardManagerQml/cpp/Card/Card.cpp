#include "Card.h"

#include "Card/CardData.h"

#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/PersonalData.h"

Card::Card(CardData *cardData, QObject *parent)
    : QObject(parent),
      m_pCardData(cardData)
{

}

QString Card::fullname()
{
    return m_pCardData->stats()->personal()->fullname();
}
