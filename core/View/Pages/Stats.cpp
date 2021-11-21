#include "Stats.h"

#include "../Stats/Attribute.h"
#include "../Stats/Origin.h"
#include "../Stats/Profession.h"
#include "../Stats/Specialization.h"
#include "../Stats/Disease.h"
#include "../Stats/Trick.h"
#include "../Stats/OtherSkill.h"
#include "../Stats/Reputation.h"
#include "../Stats/Wound.h"
#include "../Stats/Experience.h"

#include <QDebug>

Stats::Stats(QObject *parent) : Page(Page::Type::STATS, parent)
{
    connect(this, &Stats::statsChanged, this, &Stats::init);
}

Stats::Stats(const StatsData &data, QObject *parent)
    : Page(Page::Type::STATS, parent)
{
    connect(this, &Stats::statsChanged, this, &Stats::init);
    setStats( data );
}

const QString &Stats::name() const
{
    return m_data.name;
}

const QString &Stats::surname() const
{
    return m_data.surname;
}

const QString &Stats::nickname() const
{
    return m_data.surname;
}

QString Stats::fullname() const
{
    return m_data.name
            + (!m_data.nickname.isEmpty()
               ? " '" + m_data.nickname + "' " : "")
            + (!m_data.surname.isEmpty()
               ? " "+ m_data.surname : "");
}

Origin *Stats::origin() const
{
    return m_pOrigin;
}

Profession *Stats::profession() const
{
    return m_pProfession;
}

Specialization *Stats::specialization() const
{
    return m_pSpecialization;
}

Disease *Stats::disease() const
{
    return m_pDisease;
}

Experience *Stats::experience() const
{
    return m_pExperience;
}

QQmlListProperty<Trick> Stats::tricks()
{
    return QQmlListProperty<Trick>(this, this,
                                   &Stats::trickCount,
                                   &Stats::trick);
}

int Stats::trickCount() const
{
    return m_tricks.count();
}

Trick *Stats::trick(const int index) const
{
    if ( index < 0 || index > m_tricks.count() )
        return nullptr;

    return m_tricks.at(index);
}

QQmlListProperty<OtherSkill> Stats::otherSkills()
{
    return QQmlListProperty<OtherSkill>(this, this,
                                        &Stats::otherSkillCount,
                                        &Stats::otherSkill);
}

int Stats::otherSkillCount() const
{
    return m_otherSkills.count();
}

OtherSkill *Stats::otherSkill(const int index) const
{
    if ( index < 0 || index > m_otherSkills.count() )
        return nullptr;

    return m_otherSkills.at(index);
}

QQmlListProperty<Reputation> Stats::reputation()
{
    return QQmlListProperty<Reputation>(this, this,
                                        &Stats::reputationCount,
                                        &Stats::reputation);
}

int Stats::reputationCount() const
{
    return m_reputation.count();
}

Reputation *Stats::reputation(const int index) const
{
    if ( index < 0 || index > m_reputation.count() )
        return nullptr;

    return m_reputation.at(index);
}

QQmlListProperty<Wound> Stats::wounds()
{
    return QQmlListProperty<Wound>(this, this,
                                   &Stats::woundCount,
                                   &Stats::wound);
}

int Stats::woundCount() const
{
    return m_wounds.count();
}

Wound *Stats::wound(const int index) const
{
    if ( index < 0 || index > m_wounds.count() )
        return nullptr;

    return m_wounds.at(index);
}

const QStringList &Stats::locations() const
{
    return m_locations;
}

const QStringList &Stats::woundTypes() const
{
    return m_woundTypes;
}

const StatsData &Stats::data() const
{
    return m_data;
}

Attribute *Stats::attribute(const QString &name) {
    for ( Attribute* pAttribute: m_attributes )
        if ( name == pAttribute->name() )
            return pAttribute;

    return nullptr;
}

QString Stats::wound(const QString &location) const
{
    QString text;
    for ( const Wound* wound: m_wounds ) {
        if ( location == wound->location() ) {
            if ( !text.isEmpty() )
                text += ",";
            text += wound->type().at(0);
        }
    }
    return text;
}

void Stats::addWound(const QString &location, const QString &type, const bool passed)
{
    QPair<int, int> mod = m_woundMods.at( m_woundTypes.indexOf(type) );
    WoundData* pWound = new WoundData(location, type, passed ? mod.first : mod.second);

    addWound( pWound );

    emit woundsChanged();
}

void Stats::init()
{
    clear();

    m_pOrigin = new Origin(&m_data.origin, this);
    m_pProfession = new Profession(&m_data.profession, this);
    m_pSpecialization = new Specialization(&m_data.specialization, this);
    m_pDisease = new Disease(&m_data.disease, this);
    m_pExperience = new Experience(&m_data.experience, this);

    for ( AttributeData& attribute: m_data.attributes )
        m_attributes.append( new Attribute(&attribute, this) );

    for ( QSharedPointer<TrickData>& trick : m_data.tricks )
        m_tricks.append( new Trick(trick.get(), this) );

    for ( QSharedPointer<OtherSkillData>& otherSkill : m_data.otherSkills )
        m_otherSkills.append( new OtherSkill(otherSkill.get(), this) );

    for ( ReputationData& reputation : m_data.reputation )
        m_reputation.append( new Reputation(&reputation, this) );

    setWounds( m_data.wounds );
}

void Stats::addWound(WoundData* wound)
{
    m_data.wounds.push_back( QSharedPointer<WoundData>(wound) );
    m_wounds.append( new Wound(m_data.wounds.last().get(), this) );

    if ( wound->type != m_woundTypes.last() ) {
        WoundData* pWound = mergeWounds(wound->location, wound->type);
        if ( pWound )
            addWound( pWound );
    }
}

WoundData* Stats::mergeWounds(const QString &location, const QString &type)
{
    QVector<QSharedPointer<WoundData>*> wounds;
    if ( 3 == std::count_if(m_data.wounds.begin(), m_data.wounds.end(),
        [&wounds, &location, &type](QSharedPointer<WoundData>& wound){
            if ( wound->location == location && wound->type == type ) {
                wounds.append( &wound );
                return true;
            }
            return false;
        }) )
    {
        int nextType = m_woundTypes.indexOf(type) + 1;
        int modifier{0};

        for ( int i{wounds.count()-1}; i > -1; --i ) {
            modifier += wounds.at(i)->get()->modifier;
            int index{ m_data.wounds.indexOf(*wounds[i]) };
            m_wounds.takeAt( index )->deleteLater();
            m_data.wounds.takeAt( index );
        }
        return new WoundData(location, m_woundTypes.at(nextType), modifier);
    }
    return nullptr;
}

void Stats::setWounds(QVector<QSharedPointer<WoundData>> &wounds)
{
    for ( QSharedPointer<WoundData> &wound : wounds )
        m_wounds.append( new Wound(wound.get(), this) );
}

void Stats::clear()
{
    if ( m_pOrigin )
        m_pOrigin->deleteLater();
    if ( m_pProfession )
        m_pProfession->deleteLater();
    if ( m_pSpecialization )
        m_pSpecialization->deleteLater();
    if ( m_pDisease )
        m_pDisease->deleteLater();
    if ( m_pExperience )
        m_pExperience->deleteLater();

    if ( m_attributes.count() > 0 ) {
        qDeleteAll(m_attributes);
        m_attributes.clear();
    }
    if ( m_tricks.count() > 0 ) {
        qDeleteAll(m_tricks);
        m_tricks.clear();
    }
    if ( m_otherSkills.count() ) {
        qDeleteAll(m_otherSkills);
        m_otherSkills.clear();
    }
    if ( m_reputation.count() > 0 ) {
        qDeleteAll(m_reputation);
        m_reputation.clear();
    }
    if ( m_wounds.count() > 0 ) {
        qDeleteAll(m_wounds);
        m_wounds.clear();
    }
}

int Stats::trickCount(QQmlListProperty<Trick> *list)
{
    return reinterpret_cast<Stats*>(list->data)->trickCount();
}

Trick *Stats::trick(QQmlListProperty<Trick> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->trick(index);
}

int Stats::otherSkillCount(QQmlListProperty<OtherSkill> *list)
{
    return reinterpret_cast<Stats*>(list->data)->otherSkillCount();
}

OtherSkill *Stats::otherSkill(QQmlListProperty<OtherSkill> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->otherSkill(index);
}

int Stats::reputationCount(QQmlListProperty<Reputation> *list)
{
    return reinterpret_cast<Stats*>(list->data)->reputationCount();
}

Reputation *Stats::reputation(QQmlListProperty<Reputation> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->reputation(index);
}

int Stats::woundCount(QQmlListProperty<Wound> *list)
{
    return reinterpret_cast<Stats*>(list->data)->woundCount();
}

Wound *Stats::wound(QQmlListProperty<Wound> *list, int index)
{
    return reinterpret_cast<Stats*>(list->data)->wound(index);
}

const StatsData &Stats::stats() const
{
    return m_data;
}

void Stats::setStats(const StatsData &newStats)
{
    m_data = newStats;
    emit statsChanged();
}
