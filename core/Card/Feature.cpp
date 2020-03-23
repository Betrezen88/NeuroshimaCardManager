#include "Feature.h"

Feature::Feature(QObject *parent) : QObject(parent)
{

}

QString Feature::name() const
{
    return m_name;
}

QString Feature::description() const
{
    return m_description;
}

void Feature::setName(const QString &name)
{
    m_name = name;
}

void Feature::setDescription(const QString &description)
{
    m_description = description;
}
