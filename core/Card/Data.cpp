#include "Data.h"

Data::Data(QObject *parent) : QObject(parent)
{

}

Data::Data(const QString &name,
           const QString &description,
           QObject *parent)
    : QObject(parent),
      m_name(name),
      m_description(description)
{

}

QString Data::name() const
{
    return m_name;
}

QString Data::description() const
{
    return m_description;
}
