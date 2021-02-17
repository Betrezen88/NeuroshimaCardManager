#include "Stats.h"
#include "../Data.h"
#include "Card/Elements/Stats/Attribute.h"
#include "Card/Elements/Stats/Trick.h"
#include "Card/Elements/Stats/OtherSkill.h"
#include "Card/Elements/Stats/Wound.h"

Stats::Stats(QObject *parent) : Page(Page::Type::STATS, parent)
{

}

Stats::Stats(const QString &name,
             const QString &surname,
             const QString &nickname,
             Data *origin,
             Data *profession,
             Data *originFeature,
             Data *professionFeature,
             Data *specialization,
             Disease *disease,
             const QVector<Attribute *> &attributes,
             const QVector<Trick *> &tricks,
             const QVector<OtherSkill*> &otherSkills,
             const QPair<int, int> &experience,
             const QVector<Wound *> &wounds,
             QObject *parent)
    : Page(Page::Type::STATS, parent),
      m_name(name),
      m_surname(surname),
      m_nickname(nickname),
      m_pOrigin(origin),
      m_pProfession(profession),
      m_pOriginFeature(originFeature),
      m_pProfessionFeature(professionFeature),
      m_pSpecialization(specialization),
      m_pDisease(disease),
      m_attributes(attributes),
      m_tricks(tricks),
      m_otherSkills(otherSkills),
      m_experience(experience),
      m_wounds(wounds)
{

}

QString Stats::name() const
{
    return m_name;
}

QString Stats::surname() const
{
    return m_surname;
}

QString Stats::nickname() const
{
    return m_nickname;
}

QString Stats::fullname() const
{
    QString tFullname = m_name;
    if ( !m_nickname.isEmpty() ) tFullname.append(" "+m_nickname);
    if ( !m_surname.isEmpty() ) tFullname.append(" "+m_surname);
    return tFullname;
}

Data *Stats::origin() const
{
    return m_pOrigin;
}

Data *Stats::profession() const
{
    return m_pProfession;
}

Data *Stats::originFeature() const
{
    return m_pOriginFeature;
}

Data *Stats::professionFeature() const
{
    return m_pProfessionFeature;
}

Data *Stats::specialization() const
{
    return m_pSpecialization;
}

Disease *Stats::disease() const
{
    return m_pDisease;
}

int Stats::fame() const
{
    int tFame = 0;

    for ( const int &value: m_reputation.values() )
        if ( 20 == value )
            ++tFame;
    return tFame;
}

QQmlListProperty<Attribute> Stats::attributes()
{
    return QQmlListProperty<Attribute>(this, this,
                                       &Stats::attributesCount,
                                       &Stats::attribute);
}

int Stats::attributesCount() const
{
    return m_attributes.count();
}

Attribute *Stats::attribute(const int &index) const
{
    return m_attributes.at(index);
}

Attribute *Stats::attribute(const QString &name)
{
    for ( Attribute* pAttribute: m_attributes )
        if ( name == pAttribute->name() )
            return pAttribute;
    return nullptr;
}

QVector<Attribute *> Stats::attributes() const
{
    return m_attributes;
}

QQmlListProperty<Trick> Stats::tricks()
{
    return QQmlListProperty<Trick>(this, this,
                                   &Stats::tricksCount,
                                   &Stats::trick);
}

int Stats::tricksCount() const
{
    return m_tricks.count();
}

Trick *Stats::trick(const int &index) const
{
    return m_tricks.at(index);
}

QVector<Trick *> Stats::tricks() const
{
    return m_tricks;
}

QQmlListProperty<OtherSkill> Stats::otherSkills()
{
    return QQmlListProperty<OtherSkill>(this, this,
                                        &Stats::otherSkillsCount,
                                        &Stats::otherSkill);
}

int Stats::otherSkillsCount() const
{
    return m_otherSkills.count();
}

OtherSkill *Stats::otherSkill(const int &index) const
{
    return m_otherSkills.at(index);
}

QVector<OtherSkill*> Stats::otherSkills() const
{
    return m_otherSkills;
}

void Stats::addExperience(const int &points)
{
    m_experience.first += points;
    emit gatheredChanged(m_experience.first);
}

int Stats::gathered() const
{
    return m_experience.first;
}

int Stats::spended() const
{
    return m_experience.second;
}

QQmlListProperty<Wound> Stats::wounds()
{
    return QQmlListProperty<Wound>(this, this,
                                   &Stats::woundsCount,
                                   &Stats::wound);
}

int Stats::woundsCount() const
{
    return m_wounds.count();
}

Wound *Stats::wound(const int &index) const
{
    return m_wounds.at(index);
}

void Stats::addWound(const QString &location, const QString &type, const bool& passed)
{
    const QPair<int, int> &mod = m_woundMods.at(m_woundType.indexOf(type));
    const int& modifier = passed ? mod.first : mod.second;

    m_wounds.append( new Wound(location, type, modifier) );
    mergeWounds(location, type);
    emit woundsChanged();
}

QVector<Wound *> Stats::wounds() const
{
    return m_wounds;
}

QStringList Stats::woundLocations() const
{
    return m_woundLocation;
}

QStringList Stats::woundType() const
{
    return m_woundType;
}

void Stats::mergeWounds(const QString &location, const QString &type)
{
    QVector<Wound*> wounds;
    for ( Wound* wound: m_wounds ) {
        if ( location == wound->location() && type == wound->type() )
            wounds.append(wound);
    }

    if ( 3 == wounds.count() ) {
        int modifier = 0;
        const QString& tType = m_woundType.at(m_woundType.indexOf(type)+1);
        for ( Wound* wound: wounds ) {
            modifier += wound->modifier();
            m_wounds.removeOne(wound);
        }
        m_wounds.append( new Wound(location, tType, modifier) );
        mergeWounds(location, tType);
    }
}

int Stats::attributesCount(QQmlListProperty<Attribute> *list)
{
    return reinterpret_cast<Stats*>(list->data)->attributesCount();
}

Attribute *Stats::attribute(QQmlListProperty<Attribute> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->attribute(index);
}

int Stats::tricksCount(QQmlListProperty<Trick> *list)
{
    return reinterpret_cast<Stats*>(list->data)->tricksCount();
}

Trick *Stats::trick(QQmlListProperty<Trick> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->trick(index);
}

int Stats::otherSkillsCount(QQmlListProperty<OtherSkill> *list)
{
    return reinterpret_cast<Stats*>(list->data)->otherSkillsCount();
}

OtherSkill *Stats::otherSkill(QQmlListProperty<OtherSkill> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->otherSkill(index);
}

int Stats::woundsCount(QQmlListProperty<Wound> *list)
{
    return reinterpret_cast<Stats*>(list->data)->woundsCount();
}

Wound *Stats::wound(QQmlListProperty<Wound> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->wound(index);
}
