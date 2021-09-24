#include "Profession.h"
#include "Feature.h"

Profession::Profession(QObject *parent) : QObject(parent)
{

}

Profession::Profession(ProfessionData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    m_pFeature = new Feature(&m_data->feature, this);
}

const QString &Profession::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Profession::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}

Feature *Profession::feature() const
{
    return m_pFeature;
}
