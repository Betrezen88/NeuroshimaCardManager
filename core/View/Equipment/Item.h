#ifndef ITEM_H
#define ITEM_H

#include <QObject>

#include "../../Data/Equipment/ItemData.h"

#include "core_global.h"

class ItemStats;

class CORE_EXPORT Item : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)
    Q_PROPERTY(int price READ price CONSTANT)
    Q_PROPERTY(int quantity READ quantity WRITE setQuantity NOTIFY quantityChanged)
    Q_PROPERTY(ItemStats* stats READ stats CONSTANT)

public:
    explicit Item(QObject *parent = nullptr);
    explicit Item(ItemData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;
    const QString &type() const;

    int price() const;
    int quantity() const;
    void setQuantity(int newQuantity);

    ItemStats *stats() const;

    const ItemData& data() const;
    const ItemData getData();

signals:
    void quantityChanged();

public slots:
    void increaseQuantity();
    void decreaseQuantity();

private:
    ItemData* m_data{nullptr};
    ItemStats *m_stats{nullptr};
};

#endif // ITEM_H
