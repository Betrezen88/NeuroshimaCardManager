#include "Durability.h"

Durability::Durability(QObject *parent) : QObject(parent)
{

}

Durability::Durability(DurabilityData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

int Durability::current() const
{
    return m_data ? m_data->current : 0;
}

void Durability::setCurrent(const int newCurrent)
{
    if ( m_data->current == newCurrent )
        return;

    m_data->current = newCurrent;
    emit currentChanged();
}

int Durability::max() const
{
    return m_data ? m_data->max : 0;
}
