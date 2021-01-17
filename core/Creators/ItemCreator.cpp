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
    Item::Type type = Item::stringToType(data.value("TYPE").toString());

    return new Item(type
                    , data.value("NAME").toString()
                    , data.value("DESCRIPTION").toString()
                    , data.value("PRICE").toInt()
                    , data.value("QUANTITY").toInt()
                    , data.value("STATS").toMap() );
}
