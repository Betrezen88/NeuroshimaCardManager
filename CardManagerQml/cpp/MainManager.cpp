#include "MainManager.h"

#include "CardManager.h"

MainManager::MainManager(QObject *parent)
    : QObject(parent),
      m_pCardManager(new CardManager(this))
{

}

CardManager *MainManager::cardManager() const
{
    return m_pCardManager;
}
