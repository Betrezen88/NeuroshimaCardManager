#include "StatsEditor.h"
#include "../Stats/ExperienceEditor.h"

#include "../../Utils/DataReader.h"

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

QHash<QString, SkillEdit *> StatsEditor::skills() const
{
    QHash<QString, SkillEdit*> skills;
    for ( AttributeEdit* attribute : m_attributes ) {
        for ( SkillpackEdit* skillpack : attribute->m_skillpacks )
            for ( SkillEdit* skill : skillpack->m_skills )
                skills.insert( skill->name(), skill );
    }
    return skills;
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

QQmlListProperty<ReputationEdit> StatsEditor::reputations()
{
    return QQmlListProperty<ReputationEdit>(this, this,
                                            &StatsEditor::reputationCount,
                                            &StatsEditor::reputation);
}

int StatsEditor::reputationCount() const
{
    return m_reputation.count();
}

ReputationEdit *StatsEditor::reputation(const int index) const
{
    if ( index < 0 || index > m_reputation.count() )
        return nullptr;

    return m_reputation.at(index);
}

QQmlListProperty<TrickEdit> StatsEditor::tricks()
{
    return QQmlListProperty<TrickEdit>(this, this,
                                       &StatsEditor::trickCount,
                                       &StatsEditor::trick);
}

int StatsEditor::trickCount() const
{
    return m_tricks.count();
}

TrickEdit *StatsEditor::trick(const int index) const
{
    if ( index < 0 || index > m_tricks.count() )
        return nullptr;

    return m_tricks.at(index);
}

bool StatsEditor::hasTrick(const QString &name) const
{
    for ( TrickEdit* trick : m_tricks ) {
        if ( trick->name() == name )
            return true;
    }
    return false;
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

    m_pExpEditor->skillIncreased(0, QStringList());

    emit otherSkillsChanged();
}

void StatsEditor::removeOtherSkill(OtherSkillEdit *otherSkill)
{
    const int index = m_otherSkills.indexOf( otherSkill );
    if ( index == -1 )
        return;

    m_otherSkills.takeAt( index )->deleteLater();
    m_data.otherSkills.takeAt( index );

    m_pExpEditor->skillDecreased(0, QStringList());

    emit otherSkillsChanged();
}

void StatsEditor::init(const StatsData &data,
                       const QString &costFile)
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

    for ( ReputationData& reputation : m_data.reputation )
        m_reputation.push_back( new ReputationEdit(&reputation, this) );

    for ( QSharedPointer<TrickData> trick : m_data.tricks )
        m_tricks.push_back( new TrickEdit(*trick, this) );


    setStatsConnections();
    setAffordableStats();
}

void StatsEditor::clearUsed()
{
    for ( AttributeEdit* pAttribute : m_attributes ) {
        for ( SkillpackEdit* pSkillpack : pAttribute->skillpackList() ) {
            for ( SkillEdit* pSkill : pSkillpack->skillList() ) {
                pSkill->unuse();
            }
        }
    }
}

void StatsEditor::addTrick(TrickEdit *trick)
{
    m_data.tricks.push_back( QSharedPointer<TrickData>(new TrickData(trick->data())) );
    m_tricks.push_back( new TrickEdit(trick->data(), true, this) );
    m_pExpEditor->trickBougth();

    emit tricksChanged();
}

void StatsEditor::removeTrick(TrickEdit *trick)
{
    const int index = m_tricks.indexOf( trick );

    if ( index < 0  )
        return;

    m_tricks.takeAt( index )->deleteLater();
    m_data.tricks.takeAt( index );
    m_pExpEditor->trickSold();

    emit tricksChanged();
}

void StatsEditor::setAffordableStats()
{
    for ( AttributeEdit* pAttribute : m_attributes ) {
        pAttribute->setAffordable(
                    m_pExpEditor->isAttributeAfordable(pAttribute->max()) );
        pAttribute->setCost( m_pExpEditor->attributeCost(pAttribute->max()) );
        for ( SkillpackEdit* pSkillpack : pAttribute->skillpackList() ) {
            for ( SkillEdit* pSkill : pSkillpack->skillList() ) {
                pSkill->setAffordable(
                            m_pExpEditor->isSkillAfordable(
                                pSkill->max(),
                                pSkillpack->specializations()) );
                pSkill->setCost(
                            m_pExpEditor->skillCost(
                                pSkill->max(),
                                pSkillpack->specializations().contains(m_data.specialization.name)));
            }
        }
    }

    for ( OtherSkillEdit* pOtherSkill : m_otherSkills ) {
        pOtherSkill->setIsAffordable( m_pExpEditor->isOtherSkillAfordable(pOtherSkill->max()) );
        pOtherSkill->setCost( m_pExpEditor->skillCost(pOtherSkill->max(), false) );
    }

    for ( ReputationEdit* pReputation : m_reputation ) {
        pReputation->setIsAffordable( m_pExpEditor->isReputationAffordable() );
        pReputation->setCost( m_pExpEditor->reputationCost() );
    }

    for ( TrickEdit* pTrick : m_tricks ) {
        pTrick->setIsAffordable( m_pExpEditor->isTrickAffordable() );
        pTrick->setCost( m_pExpEditor->trickCost() );
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

    for ( OtherSkillEdit* pOtherSkill : m_otherSkills ) {
        connect(pOtherSkill, &OtherSkillEdit::increased,
                m_pExpEditor, &ExperienceEditor::otherSkillIncreased);
        connect(pOtherSkill, &OtherSkillEdit::decreased,
                m_pExpEditor, &ExperienceEditor::otherSkillDecreased);
    }

    for ( ReputationEdit* pReputation : m_reputation ) {
        connect(pReputation, &ReputationEdit::increased,
                this, &StatsEditor::onReputationIncreased);
        connect(pReputation, &ReputationEdit::decreased,
                this, &StatsEditor::onReputationDecreased);
    }
}

void StatsEditor::onReputationIncreased(ReputationEdit *reputation)
{
    for ( ReputationEdit* pReputation : m_reputation )
        if ( pReputation != reputation )
            pReputation->decreaseMax();
    m_pExpEditor->reputationIncreased();
}

void StatsEditor::onReputationDecreased(ReputationEdit *reputation)
{
    for ( ReputationEdit* pReputation : m_reputation )
        if ( pReputation != reputation )
            pReputation->increaseMax();
    m_pExpEditor->reputationDecreased();
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

int StatsEditor::reputationCount(QQmlListProperty<ReputationEdit> *list)
{
    return reinterpret_cast<StatsEditor*>(list->data)->reputationCount();
}

ReputationEdit *StatsEditor::reputation(QQmlListProperty<ReputationEdit> *list, int index)
{
    return reinterpret_cast<StatsEditor*>(list->data)->reputation(index);
}

int StatsEditor::trickCount(QQmlListProperty<TrickEdit> *list)
{
    return reinterpret_cast<StatsEditor*>(list->data)->trickCount();
}

TrickEdit *StatsEditor::trick(QQmlListProperty<TrickEdit> *list, int index)
{
    return reinterpret_cast<StatsEditor*>(list->data)->trick(index);
}

const StatsData &StatsEditor::data() const
{
    return m_data;
}

ExperienceEditor *StatsEditor::experience() const
{
    return m_pExpEditor;
}
