#include "Attribute.h"

Attribute::Attribute(QObject *parent) : QObject(parent)
{

}

QString Attribute::name() const
{
    return m_name;
}

int Attribute::value() const
{
    return m_value;
}

void Attribute::setName(const QString &name)
{
    m_name = name;
}

void Attribute::setValue(const int &value)
{
    m_value = value;
}
