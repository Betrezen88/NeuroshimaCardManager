#include "Penalty.h"

Penalty::Penalty(QObject *parent) : QObject(parent)
{

}

Penalty::Penalty(PenaltyData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Penalty::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int Penalty::value() const
{
    if ( m_data )
        return m_data->value;
    return 0;
}

const QString &Penalty::type() const
{
    if ( m_data )
        return m_data->type;
    return std::move(QString());
}
