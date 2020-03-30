#include "Disease.h"

Disease::Disease(const QString &name,
                 const QString &description,
                 QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString Disease::name() const
{
    return m_name;
}

QString Disease::description() const
{
    return m_description;
}
