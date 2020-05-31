#include "Feature.h"

Feature::Feature(QObject *parent) : QObject(parent)
{

}

Feature::Feature(const QString &name,
                 const QString &description,
                 QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
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
