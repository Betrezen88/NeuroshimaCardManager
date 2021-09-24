#include "Requirement.h"

Requirement::Requirement(QObject *parent) : QObject(parent)
{

}

Requirement::Requirement(RequirementData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Requirement::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int Requirement::value() const
{
    return m_data ? m_data->value : 0;
}

bool Requirement::optional() const
{
    return m_data ? m_data->optional : false;
}

const QString &Requirement::type() const
{
    if ( m_data )
        return m_data->type;
    return std::move(QString());
}
