#include "ArmorFeature.h"

ArmorFeature::ArmorFeature(QObject *parent) : QObject(parent)
{

}

ArmorFeature::ArmorFeature(ArmorFeatureData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &ArmorFeature::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &ArmorFeature::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}
