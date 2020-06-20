#include "MainManager.h"
#include "CardManager.h"

#include "Creators/CardCreator.h"
#include "Creators/DataSourceCreator.h"

MainManager::MainManager(QObject *parent)
    : QObject(parent),
      m_pCardManager(new CardManager(this))
{

}

CardManager *MainManager::cardManager() const
{
    return m_pCardManager;
}

CardCreator *MainManager::cardCreator()
{
    if ( nullptr == m_pCardCreator )
        m_pCardCreator = new CardCreator(this);

    return m_pCardCreator;
}

DataSourceCreator *MainManager::dataSourceCreator()
{
    if ( nullptr == m_pDataSourceCreator )
        m_pDataSourceCreator = new DataSourceCreator(this);

    return m_pDataSourceCreator;
}
