#ifndef ITEM_H
#define ITEM_H

#include "../../Data.h"
#include "core_global.h"

class CORE_EXPORT Item : public Data
{
    Q_OBJECT
    Q_PROPERTY(int price READ price CONSTANT)

public:
    enum class Type {
        ARMOR,
        WEAPON,
        CONSUMABLE,
        OTHER
    };

    explicit Item(QObject* parent = nullptr);
    explicit Item(const QString& name,
                  const QString& description,
                  const int& price,
                  QObject* parent = nullptr);

    int price() const;

private:
    int m_price;
};

#endif // ITEM_H
