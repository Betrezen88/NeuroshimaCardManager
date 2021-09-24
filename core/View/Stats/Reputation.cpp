#include "Reputation.h"

Reputation::Reputation(QObject *parent) : QObject(parent)
{

}

Reputation::Reputation(ReputationData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Reputation::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int Reputation::value() const
{
    return m_data ? m_data->value : 0;
}
