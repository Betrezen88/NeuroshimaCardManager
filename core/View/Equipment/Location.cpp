#include "Location.h"

Location::Location(QObject *parent) : QObject(parent)
{

}

Location::Location(LocationData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Location::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int Location::armor() const
{
    return m_data ? m_data->armor : 0;
}

int Location::cutting() const
{
    return m_data ? m_data->cutting : 0;
}
