﻿#include "StatsCreator.h"

#include "../Card/Elements/Stats/Attribute.h"
#include "../Card/Elements/Stats/Skillpack.h"
#include "../Card/Elements/Stats/OtherSkill.h"
#include "../Card/Elements/Stats/Skill.h"
#include "../Card/Elements/Stats/Trick.h"

#include "../Managers/CreationPointsManager.h"

#include "../DataSources/Elements/Stats/AttributeMod.h"
#include "../DataSources/Elements/Stats/SkillpackMod.h"
#include "../DataSources/Elements/Stats/SkillMod.h"

#include "../Utils/DataReader.h"

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>

StatsCreator::StatsCreator(QObject *parent)
    : PageCreator(PageCreator::Type::STATS, parent)
    , m_pPointsManager(new CreationPointsManager(this))
{
    DataReader reader;
    std::tuple<bool, QJsonDocument, QString> data =
            reader.load(":/json/resources/json/Attributes.json");
    for ( const QJsonValue &attribute: std::get<1>(data).array() ) {
        const QJsonObject &tAttribute = attribute.toObject();

        QVector<Skillpack*> skillpacks;
        for ( const QJsonValue &skillpack: tAttribute.value("skillpacks").toArray() ) {
            const QJsonObject &tSkillpack = skillpack.toObject();

            QStringList specs;
            for ( const QJsonValue &specialization: tSkillpack.value("specializations").toArray() ) {
                specs << specialization.toString();
            }

            QVector<Skill*> skills;
            for ( const QJsonValue &skill: tSkillpack.value("skills").toArray() ) {
                Skill *pSkill = new Skill(skill.toString(), 0);
                connect(pSkill, &Skill::valueChanged,
                        this, &StatsCreator::statsChanged);
                skills.push_back(pSkill);
                m_skills.push_back(skills.last());
            }

            const Skillpack::Type &type = (skills.count() != 3)
                    ? Skillpack::Type::CHOOSABLE
                    : Skillpack::Type::CONSTANT;

            skillpacks.push_back( new Skillpack(tSkillpack.value("name").toString(),
                                                specs,
                                                skills,
                                                type) );
        }

        Attribute *pAttribute = new Attribute(tAttribute.value("name").toString(),
                                              6, skillpacks);
        connect(pAttribute, &Attribute::valueChanged,
                this, &StatsCreator::statsChanged);
        m_attributes.append( new AttributeMod(pAttribute, 6, 18, this) );
        emit attributesChanged();
    }
}

QQmlListProperty<OtherSkill> StatsCreator::otherSkills()
{
    return QQmlListProperty<OtherSkill>(reinterpret_cast<PageCreator*>(this), this,
                                        &StatsCreator::otherSkillsCount,
                                        &StatsCreator::otherSkill);
}

OtherSkill *StatsCreator::otherSkill(const int &index) const
{
    return m_otherSkills.at(index);
}

int StatsCreator::otherSkillsCount() const
{
    return m_otherSkills.count();
}

void StatsCreator::addOtherSkill(const QString &name,
                                 const QString &attribute,
                                 const int &value)
{
    m_otherSkills.push_back(new OtherSkill(name, value, attribute));
    emit otherSkillsChanged();
}

void StatsCreator::removeOtherSkill(const QString &name)
{
    for (int i=0; i<m_otherSkills.count(); ++i)
        if ( name == m_otherSkills.at(i)->name() ) {
            OtherSkill* pOtherSkill = m_otherSkills.takeAt(i);
            delete pOtherSkill;
            emit otherSkillsChanged();
            break;
        }
}

QQmlListProperty<AttributeMod> StatsCreator::attributes()
{
    return QQmlListProperty<AttributeMod>(reinterpret_cast<PageCreator*>(this), this,
                                       &StatsCreator::attributesCount,
                                       &StatsCreator::attribute);
}

int StatsCreator::attributesCount() const
{
    return m_attributes.count();
}

AttributeMod *StatsCreator::attribute(const int &index) const
{
    return m_attributes.at(index);
}

AttributeMod *StatsCreator::attribute(const QString &name)
{
    for ( AttributeMod* pAttribute: m_attributes )
        if ( name == pAttribute->attribute()->name() )
            return pAttribute;

    return nullptr;
}

AttributeMod *StatsCreator::getAttribute(const QString &name) const
{
    for ( AttributeMod* pAttribute: m_attributes )
        if ( name == pAttribute->attribute()->name() )
            return pAttribute;

    return nullptr;
}

QVector<AttributeMod*> StatsCreator::attributes() const
{
    return m_attributes;
}

QQmlListProperty<Trick> StatsCreator::tricks()
{
    return QQmlListProperty<Trick>(reinterpret_cast<PageCreator*>(this), this,
                                       &StatsCreator::tricksCount,
                                       &StatsCreator::trick);
}

int StatsCreator::trickCount() const
{
    return m_tricks.count();
}

Trick *StatsCreator::trick(const int &index) const
{
    return m_tricks.at(index);
}

void StatsCreator::addTrick(Trick *trick)
{
    m_tricks.push_back(trick);
    emit tricksChanged();
}

void StatsCreator::removeTrick(Trick *trick)
{
    m_tricks.removeOne(trick);
    emit tricksChanged();
}

Skill *StatsCreator::getSkill(const QString &name) const
{
    for ( Skill* skill: m_skills )
        if ( name == skill->name() )
            return skill;

    return nullptr;
}

QString StatsCreator::profession() const
{
    return m_pProfession->name();
}

QString StatsCreator::specialization() const
{
    return m_pSpecialization->name();
}

void StatsCreator::setName(const QString &name)
{
    m_name = name;
    emit nameChanged(m_name);
}

void StatsCreator::setSurname(const QString &surname)
{
    m_surname = surname;
    emit surnameChanged(m_surname);
}

void StatsCreator::setNickname(const QString &nickname)
{
    m_nickname = nickname;
    emit nicknameChanged(m_nickname);
}

void StatsCreator::setOrigin(const QString &name, const QString &description)
{
    if ( m_pOrigin != nullptr )
        delete m_pOrigin;

    m_pOrigin = new Data(name, description);
}

void StatsCreator::setOriginBonus(const QString &attribute, const int &value)
{
    m_originBonus = QPair<QString, int>(attribute, value);
    emit originBonusChanged(m_originBonus.first, m_originBonus.second);
}

void StatsCreator::setProfession(const QString &name, const QString &description)
{
    if ( m_pProfession != nullptr )
        delete m_pProfession;

    m_pProfession = new Data(name, description);
    emit statsChanged();
}

void StatsCreator::setSpecialization(const QString &name, const QString &description)
{
    if ( m_pSpecialization != nullptr )
        delete m_pSpecialization;

    m_pSpecialization = new Data(name, description);
}

void StatsCreator::setOriginFeature(Feature *feature)
{

}

void StatsCreator::setProfessionFeature(Feature *feature)
{

}

void StatsCreator::setDisease(Disease *disease)
{
    m_pDisease = disease;
}

void StatsCreator::setReputation(const QString &place, const int &value)
{
    m_reputation.insert(place, value);
}

void StatsCreator::attributeUp(AttributeMod *attributeMod)
{
    if ( m_pPointsManager->spendAttribute(1) )
        attributeMod->setValue(attributeMod->attribute()->value()+1);
}

void StatsCreator::attributeDown(AttributeMod *attributeMod)
{
    m_pPointsManager->refundAttribute(1);
    attributeMod->setValue(attributeMod->attribute()->value()-1);
}

void StatsCreator::buySkillpack(SkillpackMod *skillpackMod)
{
    bool spend = (skillpackMod->skillpack()->specializations().contains(m_pSpecialization->name()))
            ? m_pPointsManager->spendSpecializationPoints(5)
            : m_pPointsManager->spendFreeSkillpoints(5);
    if ( spend )
        skillpackMod->buy();
}

void StatsCreator::sellSkillpack(SkillpackMod *skillpackMod)
{
    if ( skillpackMod->skillpack()->specializations().contains(m_pSpecialization->name()) )
        m_pPointsManager->refundSpecializationPoints(5);
    else
        m_pPointsManager->refundFreeSkillpoints(5);
    skillpackMod->sell();
}

void StatsCreator::skillUp(SkillpackMod *skillpackMod, SkillMod *skillMod)
{
    bool spend = ( skillpackMod->skillpack()->specializations().contains(m_pSpecialization->name()))
            ? m_pPointsManager->spendSpecializationPoints(skillMod->skill()->value()+1)
            : m_pPointsManager->spendFreeSkillpoints(skillMod->skill()->value()+1);
    if ( spend )
        skillMod->setValue(skillMod->skill()->value()+1);
}

void StatsCreator::skillDown(SkillpackMod *skillpackMod, SkillMod *skillMod)
{
    if ( skillpackMod->skillpack()->specializations().contains(m_pSpecialization->name()) )
        m_pPointsManager->refundSpecializationPoints(skillMod->skill()->value());
    else
        m_pPointsManager->refundFreeSkillpoints(skillMod->skill()->value());
    skillMod->setValue(skillMod->skill()->value()-1);
}

OtherSkill *StatsCreator::otherSkill(QQmlListProperty<OtherSkill> *list, int index)
{
    return reinterpret_cast<StatsCreator*>(list->data)->otherSkill(index);
}

int StatsCreator::otherSkillsCount(QQmlListProperty<OtherSkill> *list)
{
    return reinterpret_cast<StatsCreator*>(list->data)->otherSkillsCount();
}

AttributeMod *StatsCreator::attribute(QQmlListProperty<AttributeMod> *list, int index)
{
    return reinterpret_cast<StatsCreator*>(list->data)->attribute(index);
}

int StatsCreator::attributesCount(QQmlListProperty<AttributeMod> *list)
{
    return reinterpret_cast<StatsCreator*>(list->data)->attributesCount();
}

Trick *StatsCreator::trick(QQmlListProperty<Trick> *list, int index)
{
    return reinterpret_cast<StatsCreator*>(list->data)->trick(index);
}

int StatsCreator::tricksCount(QQmlListProperty<Trick> *list)
{
    return reinterpret_cast<StatsCreator*>(list->data)->trickCount();
}
