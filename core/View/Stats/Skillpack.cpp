#include "Skillpack.h"

Skillpack::Skillpack(QObject *parent) : QObject(parent)
{

}

Skillpack::Skillpack(SkillpackData *data,
                     QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    for ( SkillData& skill: m_data->skills )
        m_skills.append( new Skill(&skill, this) );
}

const QString &Skillpack::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QStringList &Skillpack::specializations() const
{
    if ( m_data )
        return m_data->specializations;
    return std::move(QStringList());
}

QString Skillpack::specializationsShort() const
{
    if ( !m_data )
        return QString();

    QString specs{};
    for ( const QString& spec: m_data->specializations ) {
        specs.append( spec.at(0).toUpper() );
        if ( spec != m_data->specializations.last() )
            specs.append(",");
    }
    return specs;
}

QQmlListProperty<Skill> Skillpack::skills()
{
    return QQmlListProperty<Skill>(this, this,
                                   &Skillpack::skillCount,
                                   &Skillpack::skill);
}

int Skillpack::skillCount() const
{
    return m_skills.count();
}

Skill *Skillpack::skill(int index) const
{
    if ( index < 0 || index > m_skills.count() )
        return nullptr;

    return m_skills.at(index);
}

int Skillpack::skillCount(QQmlListProperty<Skill> *list)
{
    return reinterpret_cast<Skillpack*>(list->data)->skillCount();
}

Skill *Skillpack::skill(QQmlListProperty<Skill> *list, int index)
{
    return reinterpret_cast<Skillpack*>(list->data)->skill(index);
}
