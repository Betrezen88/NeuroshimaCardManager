#include "StatsEditor.h"
#include "../Stats/ExperienceEditor.h"

#include <QUrl>

#include <QDebug>

StatsEditor::StatsEditor(QObject *parent) : QObject(parent)
{

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

void StatsEditor::init(const StatsData &data, const QString &costFile)
{
    m_data = data;
    m_pExpEditor = new ExperienceEditor( costFile,
                                         &m_data.experience,
                                         &m_data.specialization,
                                         this );

    connect(m_pExpEditor, &ExperienceEditor::availableChanged,
            this, &StatsEditor::setAffordableStats);

    for ( AttributeData& attribute : m_data.attributes )
        m_attributes.push_back( new AttributeEdit(&attribute, this) );

    for ( QSharedPointer<OtherSkillData>& otherSkill : m_data.otherSkills )
        m_otherSkills.push_back( new OtherSkillEdit(otherSkill.get(), false, this) );

    setStatsConnections();
    setAffordableStats();
}

void StatsEditor::setAffordableStats()
{
    for ( AttributeEdit* pAttribute : m_attributes ) {
        pAttribute->setAffordable(
                    m_pExpEditor->isAttributeAfordable(pAttribute->max()) );
        for ( SkillpackEdit* pSkillpack : pAttribute->skillpackList() ) {
            for ( SkillEdit* pSkill : pSkillpack->skillList() ) {
                pSkill->setAffordable(
                            m_pExpEditor->isSkillAfordable(
                                pSkill->max(),
                                pSkillpack->specializations()) );
            }
        }
    }
}

void StatsEditor::setStatsConnections()
{
    for ( AttributeEdit* pAttribute : m_attributes ) {
        connect(pAttribute, &AttributeEdit::increased,
                m_pExpEditor, &ExperienceEditor::attributeIncreased);
        connect(pAttribute, &AttributeEdit::decreased,
                m_pExpEditor, &ExperienceEditor::attributeDecreased);

        for ( SkillpackEdit* pSkillpack : pAttribute->skillpackList() ) {
            connect(pSkillpack, &SkillpackEdit::increased,
                    m_pExpEditor, &ExperienceEditor::skillIncreased);
            connect(pSkillpack, &SkillpackEdit::decreased,
                    m_pExpEditor, &ExperienceEditor::skillDecreased);
        }
    }
}

void StatsEditor::clear()
{
    qDebug() << "StatsEditor::clear()";
    qDeleteAll(m_attributes);
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

const StatsData &StatsEditor::data() const
{
    return m_data;
}

ExperienceEditor *StatsEditor::experience() const
{
    return m_pExpEditor;
}
