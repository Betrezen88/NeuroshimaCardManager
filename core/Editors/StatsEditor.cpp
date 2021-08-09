#include "StatsEditor.h"

#include "../Card/Pages/Stats.h"
#include "../Card/Elements/Stats/Attribute.h"
#include "../Card/Elements/Stats/OtherSkill.h"

#include "../DataSources/Elements/Stats/AttributeMod.h"
#include "../DataSources/Elements/Stats/OtherSkillMod.h"

StatsEditor::StatsEditor(QObject *parent) : QObject(parent)
{
    connect(this, &StatsEditor::statsChanged, this, &StatsEditor::init);
}

Stats *StatsEditor::stats() const
{
    return m_pStats;
}

void StatsEditor::setStats(Stats *newStats)
{
    if (m_pStats == newStats)
        return;
    m_pStats = newStats;
    emit statsChanged();
}

AttributeMod *StatsEditor::attributeMod(const QString &name) const
{
    for ( AttributeMod* attributeMod: m_attributes )
        if ( attributeMod->attribute()->name() == name )
            return attributeMod;

    return nullptr;
}

void StatsEditor::init()
{
    for ( Attribute* attribute: const_cast<const Stats*>(m_pStats)->attributes() ) {
        m_attributesNames.push_back( attribute->name() );
        m_attributes.append( new AttributeMod(attribute, this) );
    }

    for ( OtherSkill* otherSkill: const_cast<const Stats*>(m_pStats)->otherSkills() )
        m_otherSkills.append( new OtherSkillMod(otherSkill, this) );
}

const QStringList &StatsEditor::attributesNames() const
{
    return m_attributesNames;
}

QQmlListProperty<OtherSkillMod> StatsEditor::otherSkills()
{
    return QQmlListProperty<OtherSkillMod>(this, this,
                                           &StatsEditor::otherSkillsCount,
                                           &StatsEditor::otherSkill);
}

int StatsEditor::otherSkillsCount() const
{
    return m_otherSkills.count();
}

OtherSkillMod *StatsEditor::otherSkill(const int index) const
{
    return m_otherSkills.at(index);
}

void StatsEditor::addOtherSkill(const QString &name, const QString &attribute)
{
    m_otherSkills.append( new OtherSkillMod( new OtherSkill(name, 1, false, attribute), this) );
    emit otherSkillsChanged();
}

int StatsEditor::otherSkillsCount(QQmlListProperty<OtherSkillMod> *list)
{
    return reinterpret_cast<StatsEditor*>(list->data)->otherSkillsCount();
}

OtherSkillMod *StatsEditor::otherSkill(QQmlListProperty<OtherSkillMod> *list, const int index)
{
    return reinterpret_cast<StatsEditor*>(list->data)->otherSkill(index);
}
