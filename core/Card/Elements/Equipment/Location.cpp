#include "Location.h"

Location::Location(QObject *parent) : QObject(parent)
{

}

Location::Location(const Location::Type &type,
                   const int &value,
                   const QPair<int, QString> &special,
                   QObject *parent)
    : QObject(parent)
    , m_type(type)
    , m_value(value)
    , m_special(special)
{

}

Location::Type Location::stringToType(const QString& type)
{
    if ( type.toUpper() == "HEAD" ) {
        return Type::HEAD;
    }
    else if ( type.toUpper() == "TORSO" ) {
        return Type::TORSO;
    }
    else if ( type.toUpper() == "LEFTHAND" ) {
        return Type::LEFT_HAND;
    }
    else if ( type.toUpper() == "RIGHTHAND" ) {
        return Type::RIGHT_HAND;
    }
    else if ( type.toUpper() == "LEFTLEG" ) {
        return Type::LEFT_LEG;
    }
    else /*if ( type.toUpper() == "RIGHTLEG" )*/ {
        return Type::RIGHT_LEG;
    }
}

Location::Type Location::type() const
{
    return m_type;
}

int Location::value() const
{
    return m_value;
}

int Location::specialValue() const
{
    return m_specialValue;
}

QString Location::specialDescription() const
{
    return m_specialDescription;
}
