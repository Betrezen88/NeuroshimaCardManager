#ifndef ITEMDATA_H
#define ITEMDATA_H

#include <QString>

#include "ItemStatsData.h"

#include "core_global.h"

struct CORE_EXPORT ItemData {
    QString type;
    QString name;
    QString description;
    int price;
    int quantity;

    ItemStatsData itemStats;

    bool operator==(const ItemData& other) const {
        if ( name != other.name )
            return false;
        if ( type != other.type )
            return false;
        if ( description != other.description )
            return false;
        if ( price != other.price )
            return false;
        if ( itemStats != other.itemStats )
            return false;

        return true;
    }
};

#endif // ITEMDATA_H
