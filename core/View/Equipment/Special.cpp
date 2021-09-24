#include "Special.h"

Special::Special(QObject *parent) : QObject(parent)
{

}

Special::Special(SpecialData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Special::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Special::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}
