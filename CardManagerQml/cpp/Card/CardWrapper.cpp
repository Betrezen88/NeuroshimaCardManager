#include "CardWrapper.h"
#include "Card/CardData.h"
#include "cpp/Page/StatsWrapper.h"

CardWrapper::CardWrapper(QObject *parent) : QObject(parent)
{

}

CardWrapper::CardWrapper(const QString &filePath, CardData *cardData, QObject *parent)
    : QObject(parent),
      m_filePath(filePath),
      m_pCardData(cardData),
      m_pStatsWrapper(new StatsWrapper(cardData->stats(), this))
{

}

StatsWrapper *CardWrapper::stats() const
{
    return m_pStatsWrapper;
}

QString CardWrapper::filePath() const
{
    return m_filePath;
}
