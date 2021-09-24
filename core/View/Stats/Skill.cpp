#include "Skill.h"

Skill::Skill(QObject *parent) : QObject(parent)
{

}

Skill::Skill(SkillData *data, QObject *parent)
    : QObject( parent )
    , m_data( data )
{

}

const QString &Skill::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int Skill::value() const
{
    if ( m_data )
        return m_data->value;
    return 0;
}

bool Skill::used() const
{
    if ( m_data )
        return m_data->used;
    return false;
}

void Skill::setUsed(bool newUsed)
{
    if ( !m_data || m_data->used == newUsed )
        return;
    m_data->used = newUsed;
    emit usedChanged( m_data->used );
}
