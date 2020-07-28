#include "CardCreator.h"
#include "DataSourceCreator.h"
#include "../Creators/StatsCreator.h"

CardCreator::CardCreator(QObject *parent) : QObject(parent)
{

}

PageCreator *CardCreator::pageCreator(const PageCreator::Type &type)
{
    if ( !m_pageCreators.contains(type) )
        m_pageCreators.insert( type, createPageCreator(type) );

    return m_pageCreators.value(type);
}

DataSource *CardCreator::dataSource(const DataSource::Type &type)
{
    return m_dataSources.value(type);
}

void CardCreator::createDataSource(const DataSource::Type &type,
                                   const QVariantMap &dataFiles)
{
    DataSourceCreator dsCreator;
    m_dataSources.insert(type, dsCreator.create(type, dataFiles));
}

int CardCreator::diceRoll() const
{
    return m_d20.roll();
}

PageCreator *CardCreator::createPageCreator(const PageCreator::Type &type)
{
    switch (type) {
        case PageCreator::Type::STATS:
            return new StatsCreator(this);
            break;
        case PageCreator::Type::NOTES:
            return nullptr;
            break;
        case PageCreator::Type::EQUIPMENT:
            return nullptr;
            break;
        case PageCreator::Type::FRIEND:
            return nullptr;
            break;
        case PageCreator::Type::BEAST:
            return nullptr;
            break;
        case PageCreator::Type::MACHINE:
            return nullptr;
            break;
        case PageCreator::Type::VEHICLE:
            return nullptr;
            break;
        default:
            return nullptr;
    }
}
