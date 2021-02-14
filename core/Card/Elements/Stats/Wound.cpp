#include "Wound.h"

Wound::Wound(QObject *parent) : QObject(parent)
{

}

Wound::Wound(const QString &location,
             const QString &type,
             const int &modifier,
             QObject *parent)
    : QObject(parent)
    , m_location(location)
    , m_type(type)
    , m_modifier(modifier)
{

}

QString Wound::location() const
{
    return m_location;
}

QString Wound::type() const
{
    return m_type;
}

int Wound::modifier() const
{
    return m_modifier;
}

void Wound::setModifier(int modifier)
{
    if (m_modifier == modifier)
        return;

    m_modifier = modifier;
    emit modifierChanged(m_modifier);
}
