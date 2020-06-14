#include "Origin.h"

Origin::Origin(QObject *parent) : HeroData(parent)
{

}

Origin::Origin(const QString &name,
               const QString &description,
               const QString &image,
               const QString &attribute,
               const int &value,
               QObject *parent)
    : HeroData(name, description, image, parent),
    m_bonus(attribute, value)
{

}

QString Origin::attribute() const
{
    return m_bonus.first;
}

int Origin::value() const
{
    return m_bonus.second;
}
