#include "Personal.h"

#include "Card/Elements/Stats/PersonalData.h"

Personal::Personal(QObject *parent) : QObject(parent)
{

}

Personal::Personal(PersonalData *personalData, QObject *parent)
    : QObject(parent),
      m_pPersonalData(personalData)
{

}

QString Personal::name() const
{
    return m_pPersonalData->name();
}

QString Personal::surname() const
{
    return m_pPersonalData->surname();
}

QString Personal::nickname() const
{
    return m_pPersonalData->nickname();
}

QString Personal::fullname() const
{
    return m_pPersonalData->fullname();
}
