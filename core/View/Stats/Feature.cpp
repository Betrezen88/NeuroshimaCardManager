#include "Feature.h"

Feature::Feature(QObject *parent) : QObject(parent)
{

}

Feature::Feature(FeatureData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Feature::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Feature::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}
