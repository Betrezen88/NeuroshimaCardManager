#include "Item.h"

#include "ItemStats.h"

Item::Item(QObject *parent) : QObject(parent)
{

}

Item::Item(ItemData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
    , m_stats( new ItemStats(&m_data->itemStats, this) )
{

}

const QString &Item::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Item::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}

const QString &Item::type() const
{
    if ( m_data )
        return m_data->type;
    return std::move(QString());
}

int Item::price() const
{
    return m_data ? m_data->price : 0;
}

int Item::quantity() const
{
    return m_data ? m_data->quantity : 0;
}

void Item::setQuantity(int newQuantity)
{
    if (!m_data || m_data->quantity == newQuantity)
        return;
    m_data->quantity = newQuantity;
    emit quantityChanged();
    emit wasModified();
}

ItemStats *Item::stats() const
{
    return m_stats;
}

const ItemData &Item::data() const
{
    return *m_data;
}

const ItemData Item::getData()
{
    ItemData data = *m_data;
    data.quantity = 1;
    decreaseQuantity();
    return data;
}

void Item::increaseQuantity()
{
    ++m_data->quantity;
    emit quantityChanged();
    emit wasModified();
}

void Item::decreaseQuantity()
{
    --m_data->quantity;
    emit quantityChanged();
    emit wasModified();
}
