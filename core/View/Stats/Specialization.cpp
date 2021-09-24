#include "Specialization.h"

Specialization::Specialization(QObject *parent) : QObject(parent)
{

}

Specialization::Specialization(SpecializationData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Specialization::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Specialization::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}
