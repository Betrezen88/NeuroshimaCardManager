#include "Profession.h"

Profession::Profession(QObject *parent)
    : HeroData(parent)
{

}

Profession::Profession(const QString &name,
                       const QString &description,
                       const QString &image,
                       const QString &quote,
                       QObject *parent)
    : HeroData(name, description, image, parent),
      m_quote(quote)
{

}

QString Profession::quote() const
{
    return m_quote;
}
