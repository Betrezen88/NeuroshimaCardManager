#include "Bonus.h"

Bonus::Bonus(QObject *parent) : QObject(parent)
{

}

Bonus::Bonus(const Bonus::Type &type,
             const QString &name,
             const int &value,
             const int &price,
             const QStringList &list,
             QObject *parent)
    : QObject(parent),
      m_type(type),
      m_name(name),
      m_value(value),
      m_price(price),
      m_list(list)
{

}

Bonus::Type Bonus::type() const
{
    return m_type;
}

QString Bonus::name() const
{
    return m_name;
}

int Bonus::value() const
{
    return m_value;
}

int Bonus::price() const
{
    return m_price;
}

QStringList Bonus::list() const
{
    return m_list;
}

void Bonus::setName(const QString &name)
{
    if ( m_name == name )
        return;

    emit nameChanged(this, m_name, name);
    m_name = name;
}
