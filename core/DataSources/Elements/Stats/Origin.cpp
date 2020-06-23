#include "Origin.h"
#include "OriginBonus.h"

Origin::Origin(QObject *parent) : HeroData(parent)
{

}

Origin::Origin(const QString &name,
               const QString &description,
               const QString &image,
               OriginBonus *bonus,
               QObject *parent)
    : HeroData(name, description, image, parent),
      m_pBonus(bonus)
{

}

OriginBonus *Origin::bonus() const
{
    return m_pBonus;
}
