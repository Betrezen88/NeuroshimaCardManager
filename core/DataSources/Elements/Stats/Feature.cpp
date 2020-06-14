#include "Feature.h"
#include "Bonus.h"

Feature::Feature(QObject *parent) : Data(parent)
{

}

Feature::Feature(const QString &name,
                 const QString &description,
                 Bonus *bonus,
                 QObject *parent)
    : Data(name, description, parent),
      m_bonus(bonus)
{

}

Bonus *Feature::bonus() const
{
    return m_bonus;
}

bool Feature::hasBonus() const
{
    return (m_bonus != nullptr);
}
