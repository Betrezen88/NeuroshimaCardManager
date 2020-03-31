#include "Personal.h"

#include "Origin.h"
#include "Profession.h"
#include "Specialization.h"
#include "Disease.h"

Personal::Personal(QObject *parent) : QObject(parent)
{

}

QString Personal::name() const
{
    return m_name;
}

QString Personal::surname() const
{
    return m_surname;
}

QString Personal::nickname() const
{
    return m_nickname;
}

QString Personal::fullname() const
{
    QString full = m_name;
    if ( !m_nickname.isEmpty() )
        full += " '"+m_nickname+"'";
    if ( !m_surname.isEmpty() )
        full += " "+m_surname;
    return full;
}

Origin *Personal::origin() const
{
    return m_origin;
}

Profession *Personal::profession() const
{
    return m_profession;
}

Specialization *Personal::specialization() const
{
    return m_specialization;
}

Disease *Personal::disease() const
{
    return m_disease;
}

void Personal::setName(const QString &name)
{
    m_name = name;
}

void Personal::setSurname(const QString &surname)
{
    m_surname = surname;
}

void Personal::setNickname(const QString &nickname)
{
    m_nickname = nickname;
}

void Personal::setOrigin(Origin *origin)
{
    m_origin = origin;
}

void Personal::setProfession(Profession *profession)
{
    m_profession = profession;
}

void Personal::setSpecialization(Specialization *specialization)
{
    m_specialization = specialization;
}

void Personal::setDisease(Disease *disease)
{
    m_disease = disease;
}

void Personal::setReputation(const QString &place, const int &value)
{
    m_reputation.insert(place, value);
}
