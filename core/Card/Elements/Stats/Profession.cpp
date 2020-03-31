#include "Profession.h"

Profession::Profession(const QString &name,
                       const QString &description,
                       QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString Profession::name() const
{
    return m_name;
}

QString Profession::description() const
{
    return m_description;
}
