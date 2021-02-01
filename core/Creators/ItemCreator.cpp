#include "ItemCreator.h"

#include "../Card/Elements/Equipment/Item.h"

#include <QJsonObject>

ItemCreator::ItemCreator(QObject *parent) : QObject(parent)
{

}

Item *ItemCreator::create(const QJsonObject &data)
{
    return create(data.toVariantMap());
}

Item *ItemCreator::create(const QVariantMap &data)
{
    const int& index = m_types.indexOf(data.value("TYPE").toString().toUpper());
    const QString& type = (index>-1) ? m_types.at(index) : m_types.at(6);

    return new Item(type
                    , data.value("NAME").toString()
                    , data.value("DESCRIPTION").toString()
                    , data.value("PRICE").toInt()
                    , data.value("QUANTITY").toInt()
                    , data.value("STATS").toMap() );
}

Item *ItemCreator::create(const Item *item)
{
    return new Item( item->m_type,
                     item->name(),
                     item->description(),
                     item->m_price,
                     item->m_quantity,
                     item->m_stats );
}
