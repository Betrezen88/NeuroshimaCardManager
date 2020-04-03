#include "Personal.h"

#include "Card/Elements/Stats/PersonalData.h"

Personal::Personal(PersonalData *personalData, QObject *parent)
    : QObject(parent),
      m_pPersonalData(personalData)
{

}

QString Personal::name() const
{
    return m_pPersonalData->name();
}
