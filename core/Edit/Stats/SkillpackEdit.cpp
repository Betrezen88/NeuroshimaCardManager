#include "SkillpackEdit.h"
#include "../../Data/Stats/SkillpackData.h"

SkillpackEdit::SkillpackEdit(QObject *parent) : QObject(parent)
{

}

SkillpackEdit::SkillpackEdit(SkillpackData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    for ( SkillData& skill : m_data->skills )
        m_skills.push_back( new SkillEdit(&skill, this) );
}

const QString &SkillpackEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QStringList &SkillpackEdit::specializations() const
{
    if ( m_data )
        return m_data->specializations;
    return std::move(QStringList());
}

QString SkillpackEdit::specializationsShort() const
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

QQmlListProperty<SkillEdit> SkillpackEdit::skills()
{
    return QQmlListProperty<SkillEdit>(this, this,
                                       &SkillpackEdit::skillCount,
                                       &SkillpackEdit::skill);
}

int SkillpackEdit::skillCount() const
{
    return m_skills.count();
}

SkillEdit *SkillpackEdit::skill(const int index) const
{
    if ( index < 0 || index > m_skills.count() )
        return nullptr;

    return m_skills.at( index );
}

QVector<SkillEdit *> SkillpackEdit::skillList()
{
    return m_skills;
}

int SkillpackEdit::skillCount(QQmlListProperty<SkillEdit> *list)
{
    return reinterpret_cast<SkillpackEdit*>(list->data)->skillCount();
}

SkillEdit *SkillpackEdit::skill(QQmlListProperty<SkillEdit> *list, int index)
{
    return reinterpret_cast<SkillpackEdit*>(list->data)->skill(index);
}
