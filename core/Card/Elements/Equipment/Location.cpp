#include "Location.h"

Location::Location(QObject *parent) : QObject(parent)
{

}

Location::Location(const QString &location,
                   const int &armor,
                   const int &cutting,
                   QObject *parent)
    : QObject(parent)
    , m_location(location)
    , m_armor(armor)
    , m_cutting(cutting)
{

}

QString Location::location() const
{
    return m_location;
}

int Location::armor() const
{
    return m_armor;
}

int Location::cutting() const
{
    return m_cutting;
}

QStringList Location::locations()
{
    return QStringList{
        "Głowa",
        "Tułów",
        "Prawa Ręka",
        "Lewa Ręka",
        "Prawa Noga",
        "Lewa Noga"
    };
}
