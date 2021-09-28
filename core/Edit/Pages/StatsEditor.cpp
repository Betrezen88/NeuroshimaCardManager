#include "StatsEditor.h"

#include <QDebug>

StatsEditor::StatsEditor(QObject *parent) : QObject(parent)
{
    setConnections();
}

StatsEditor::StatsEditor(const StatsData &data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    setConnections();
    init();
}

QQmlListProperty<AttributeEdit> StatsEditor::attributes()
{
    return QQmlListProperty<AttributeEdit>(this, this,
                                           &StatsEditor::attributeCount,
                                           &StatsEditor::attribute);
}

int StatsEditor::attributeCount() const
{
    return m_attributes.count();
}

AttributeEdit *StatsEditor::attribute(const int index) const
{
    if ( index < 0 || index > m_attributes.count() )
        return nullptr;

    return m_attributes.at(index);
}

QQmlListProperty<OtherSkillEdit> StatsEditor::otherSkills()
{
    return QQmlListProperty<OtherSkillEdit>(this, this,
                                            &StatsEditor::otherSkillCount,
                                            &StatsEditor::otherSkill);
}

int StatsEditor::otherSkillCount() const
{
    return m_otherSkills.count();
}

OtherSkillEdit *StatsEditor::otherSkill(const int index) const
{
    if ( index < 0 || index > m_otherSkills.count() )
        return nullptr;

    return m_otherSkills.at(index);
}

void StatsEditor::setStats(Stats *stats)
{
    clear();
    m_data = stats->data();
    emit dataChanged();
}

AttributeEdit *StatsEditor::attribute(const QString &name)
{
    for ( AttributeEdit* pAttribute : m_attributes )
        if ( name == pAttribute->name() )
            return pAttribute;

    return nullptr;
}

QStringList StatsEditor::attributesNames() const
{
    QStringList names;

    for ( AttributeEdit* pAttribute : m_attributes )
        names.push_back( pAttribute->name() );

    return names;
}

void StatsEditor::addOtherSkill(const QString &name, const QString &attribute)
{
    auto otherSkillIt = std::find_if(m_otherSkills.begin(), m_otherSkills.end(),
                                     [&name, &attribute](const OtherSkillEdit* skill){
        return skill->name() == name && skill->attribute() == attribute;
    });

    if ( otherSkillIt != m_otherSkills.end() ) {
        qDebug() << "StatsEditor::addOtherSkill(): This skill already exist.";
        return;
    }

    OtherSkillData data;
    data.name = name;
    data.attribute = attribute;
    data.value = 1;
    data.used = false;

    m_data.otherSkills.push_back( QSharedPointer<OtherSkillData>(new OtherSkillData(data)) );
    m_otherSkills.push_back( new OtherSkillEdit(m_data.otherSkills.last().get(), true, this) );

    emit otherSkillsChanged();
}

void StatsEditor::removeOtherSkill(OtherSkillEdit *otherSkill)
{
    const int index = m_otherSkills.indexOf( otherSkill );
    if ( index == -1 )
        return;

    m_otherSkills.takeAt( index )->deleteLater();
    m_data.otherSkills.takeAt( index );

    emit otherSkillsChanged();
}

void StatsEditor::init()
{
    for ( AttributeData& attribute : m_data.attributes )
        m_attributes.push_back( new AttributeEdit(&attribute, this) );

    for ( QSharedPointer<OtherSkillData>& otherSkill : m_data.otherSkills )
        m_otherSkills.push_back( new OtherSkillEdit(otherSkill.get(), false, this) );
}

void StatsEditor::clear()
{
    qDeleteAll(m_attributes);
}

void StatsEditor::setConnections()
{
    connect(this, &StatsEditor::dataChanged, this, &StatsEditor::init);
}

int StatsEditor::attributeCount(QQmlListProperty<AttributeEdit> *list)
{
    return reinterpret_cast<StatsEditor*>(list->data)->attributeCount();
}

AttributeEdit *StatsEditor::attribute(QQmlListProperty<AttributeEdit> *list, int index)
{
    return reinterpret_cast<StatsEditor*>(list->data)->attribute(index);
}

int StatsEditor::otherSkillCount(QQmlListProperty<OtherSkillEdit> *list)
{
    return reinterpret_cast<StatsEditor*>(list->data)->otherSkillCount();
}

OtherSkillEdit *StatsEditor::otherSkill(QQmlListProperty<OtherSkillEdit> *list, int index)
{
    return reinterpret_cast<StatsEditor*>(list->data)->otherSkill(index);
}
