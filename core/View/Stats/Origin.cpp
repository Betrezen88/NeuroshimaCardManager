#include "Origin.h"

#include "Feature.h"

Origin::Origin(QObject *parent) : QObject(parent)
{

}

Origin::Origin(OriginData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    m_pFeature = new Feature(&m_data->feature, this);
}

const QString &Origin::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Origin::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}

Feature *Origin::feature() const
{
    return m_pFeature;
}
