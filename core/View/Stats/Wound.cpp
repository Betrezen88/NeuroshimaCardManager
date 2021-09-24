#include "Wound.h"

Wound::Wound(QObject *parent) : QObject(parent)
{

}

Wound::Wound(WoundData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Wound::location() const
{
    if ( m_data )
        return m_data->location;
    return std::move(QString());
}

const QString &Wound::type() const
{
    if ( m_data )
        return m_data->type;
    return std::move(QString());
}

int Wound::modifier() const
{
    return m_data ? m_data->modifier : 0;
}

const WoundData *Wound::data() const
{
    return m_data;
}
