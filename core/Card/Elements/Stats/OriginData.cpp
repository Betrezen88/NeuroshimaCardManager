#include "OriginData.h"

OriginData::OriginData(const QString &name,
                       const QString &description,
                       QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString OriginData::name() const
{
    return m_name;
}

QString OriginData::description() const
{
    return m_description;
}
