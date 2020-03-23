#include "Personal.h"

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
