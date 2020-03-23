#include "Stats.h"

#include "../Personal.h"

Stats::Stats(QObject *parent) : QObject(parent)
{

}

Personal *Stats::personal() const
{
    return m_personal;
}

void Stats::setPersonal(Personal *personal)
{
    m_personal = personal;
}
