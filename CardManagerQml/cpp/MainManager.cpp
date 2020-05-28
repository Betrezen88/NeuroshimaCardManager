#include "MainManager.h"

#include "CardManager.h"
#include "Creators/HeroCreatorManager.h"

MainManager::MainManager(QObject *parent)
    : QObject(parent),
      m_pCardManager(new CardManager(this))
{

}

CardManager *MainManager::cardManager() const
{
    return m_pCardManager;
}

HeroCreatorManager *MainManager::heroCreator()
{
    if (nullptr == m_pHeroCreatorManager)
        m_pHeroCreatorManager = new HeroCreatorManager(this);

    return m_pHeroCreatorManager;
}
