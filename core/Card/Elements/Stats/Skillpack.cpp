#include "Skillpack.h"

Skillpack::Skillpack(QObject *parent) : QObject(parent)
{

}

Skillpack::Skillpack(const QString &name,
                     const QStringList &specializations,
                     const QVector<Skill *> &skills,
                     QObject *parent)
    : QObject(parent),
      m_name(name),
      m_specializations(specializations),
      m_skills(skills)
{

}

QString Skillpack::name() const
{
    return m_name;
}

QStringList Skillpack::specializations() const
{
    return m_specializations;
}

QString Skillpack::fullname() const
{
    QString tName = m_name;
    tName += " (";
    for ( const QString& spec: m_specializations ) {
        tName += spec.at(0);
        if ( spec != m_specializations.last() )
            tName += ", ";
    }
    tName += ")";
    return tName;
}

QQmlListProperty<Skill> Skillpack::skills()
{
    return QQmlListProperty<Skill>(this, this,
                                   &Skillpack::skillsCount,
                                   &Skillpack::skill);
}

int Skillpack::skillsCount() const
{
    return m_skills.count();
}

Skill *Skillpack::skill(int index) const
{
    return m_skills.at(index);
}

int Skillpack::skillsCount(QQmlListProperty<Skill> *list)
{
    return reinterpret_cast<Skillpack*>(list->data)->skillsCount();
}

Skill *Skillpack::skill(QQmlListProperty<Skill> *list, int index)
{
    return reinterpret_cast<Skillpack*>(list->data)->skill(index);
}
