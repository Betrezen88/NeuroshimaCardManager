#include "PersonalData.h"

#include "OriginData.h"
#include "ProfessionData.h"
#include "SpecializationData.h"
#include "DiseaseData.h"

PersonalData::PersonalData()
{

}

QString PersonalData::name() const
{
    return m_name;
}

QString PersonalData::surname() const
{
    return m_surname;
}

QString PersonalData::nickname() const
{
    return m_nickname;
}

QString PersonalData::fullname() const
{
    QString full = m_name;
    if ( !m_nickname.isEmpty() )
        full += " '"+m_nickname+"'";
    if ( !m_surname.isEmpty() )
        full += " "+m_surname;
    return full;
}

OriginData *PersonalData::origin() const
{
    return m_origin;
}

ProfessionData *PersonalData::profession() const
{
    return m_profession;
}

SpecializationData *PersonalData::specialization() const
{
    return m_specialization;
}

DiseaseData *PersonalData::disease() const
{
    return m_disease;
}

void PersonalData::setName(const QString &name)
{
    m_name = name;
}

void PersonalData::setSurname(const QString &surname)
{
    m_surname = surname;
}

void PersonalData::setNickname(const QString &nickname)
{
    m_nickname = nickname;
}

void PersonalData::setOrigin(OriginData *origin)
{
    m_origin = origin;
}

void PersonalData::setProfession(ProfessionData *profession)
{
    m_profession = profession;
}

void PersonalData::setSpecialization(SpecializationData *specialization)
{
    m_specialization = specialization;
}

void PersonalData::setDisease(DiseaseData *disease)
{
    m_disease = disease;
}

void PersonalData::setReputation(const QString &place, const int &value)
{
    m_reputation.insert(place, value);
}
