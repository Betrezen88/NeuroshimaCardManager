#include "StatsWrapper.h"
#include "cpp/Section/PersonalWrapper.h"
#include "cpp/Element/AttributeWrapper.h"
#include "cpp/Element/OtherSkillWrapper.h"
#include "cpp/Element/TrickWrapper.h"
#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/AttributeData.h"
#include "Card/Elements/Stats/OtherSkillData.h"
#include "Card/Elements/Stats/TrickData.h"

StatsWrapper::StatsWrapper(QObject *parent) : QObject(parent)
{

}

StatsWrapper::StatsWrapper(StatsData *statsData, QObject *parent)
    : QObject(parent),
      m_pStatsData(statsData),
      m_pPersonalWrapper(new PersonalWrapper(statsData->personal(), this))
{
    for ( AttributeData *pAttributeData: m_pStatsData->attributes() ) {
        appendAttribute( new AttributeWrapper(pAttributeData, this) );
    }
    for ( OtherSkillData *pOtherSkill: m_pStatsData->otherSkills() ) {
        appendOtherSkill( new OtherSkillWrapper(pOtherSkill, this) );
    }
    for ( TrickData *pTrick: m_pStatsData->tricks() ) {
        appendTrick( new TrickWrapper(pTrick, this) );
    }
}

PersonalWrapper *StatsWrapper::personal() const
{
    return m_pPersonalWrapper;
}

QQmlListProperty<AttributeWrapper> StatsWrapper::attributes()
{
    return QQmlListProperty<AttributeWrapper>(this, this,
                                              &StatsWrapper::appendAttribute,
                                              &StatsWrapper::attributeCount,
                                              &StatsWrapper::attribute,
                                              &StatsWrapper::clearAttributes);
}

void StatsWrapper::appendAttribute(AttributeWrapper *a)
{
    m_attributes.push_back(a);
}

int StatsWrapper::attributeCount() const
{
    return m_attributes.count();
}

AttributeWrapper *StatsWrapper::attribute(int index) const
{
    return m_attributes.at(index);
}

void StatsWrapper::clearAttributes()
{
    m_attributes.clear();
}

QQmlListProperty<OtherSkillWrapper> StatsWrapper::otherSkills()
{
    return QQmlListProperty<OtherSkillWrapper>(this, this,
                                               &StatsWrapper::appendOtherSkill,
                                               &StatsWrapper::otherSkillsCount,
                                               &StatsWrapper::otherSkill,
                                               &StatsWrapper::clearOtherSkills);
}

void StatsWrapper::appendOtherSkill(OtherSkillWrapper *otherSkill)
{
    m_otherSkills.push_back(otherSkill);
}

int StatsWrapper::otherSkillsCount() const
{
    return m_otherSkills.count();
}

OtherSkillWrapper *StatsWrapper::otherSkill(int index) const
{
    return m_otherSkills.at(index);
}

void StatsWrapper::clearOtherSkills()
{
    m_otherSkills.clear();
}

QQmlListProperty<TrickWrapper> StatsWrapper::tricks()
{
    return QQmlListProperty<TrickWrapper>(this, this,
                                          &StatsWrapper::appendTrick,
                                          &StatsWrapper::tricksCount,
                                          &StatsWrapper::trick,
                                          &StatsWrapper::clearTricks);
}

void StatsWrapper::appendTrick(TrickWrapper *trick)
{
    m_tricks.push_back(trick);
}

int StatsWrapper::tricksCount() const
{
    return m_tricks.count();
}

TrickWrapper *StatsWrapper::trick(int index) const
{
    return m_tricks.at(index);
}

void StatsWrapper::clearTricks()
{
    m_tricks.clear();
}

void StatsWrapper::appendAttribute(QQmlListProperty<AttributeWrapper> *list, AttributeWrapper *attribute)
{
    reinterpret_cast<StatsWrapper*>(list->data)->appendAttribute(attribute);
}

int StatsWrapper::attributeCount(QQmlListProperty<AttributeWrapper> *list)
{
    return reinterpret_cast<StatsWrapper*>(list->data)->attributeCount();
}

AttributeWrapper *StatsWrapper::attribute(QQmlListProperty<AttributeWrapper> *list, int index)
{
    return reinterpret_cast<StatsWrapper*>(list->data)->attribute(index);
}

void StatsWrapper::clearAttributes(QQmlListProperty<AttributeWrapper> *list)
{
    reinterpret_cast<StatsWrapper*>(list->data)->clearAttributes();
}

void StatsWrapper::appendOtherSkill(QQmlListProperty<OtherSkillWrapper> *list, OtherSkillWrapper *otherSkill)
{
    reinterpret_cast<StatsWrapper*>(list->data)->appendOtherSkill(otherSkill);
}

int StatsWrapper::otherSkillsCount(QQmlListProperty<OtherSkillWrapper> *list)
{
    return reinterpret_cast<StatsWrapper*>(list->data)->otherSkillsCount();
}

OtherSkillWrapper *StatsWrapper::otherSkill(QQmlListProperty<OtherSkillWrapper> *list, int index)
{
    return reinterpret_cast<StatsWrapper*>(list->data)->otherSkill(index);
}

void StatsWrapper::clearOtherSkills(QQmlListProperty<OtherSkillWrapper> *list)
{
    reinterpret_cast<StatsWrapper*>(list->data)->clearOtherSkills();
}

void StatsWrapper::appendTrick(QQmlListProperty<TrickWrapper> *list, TrickWrapper *trick)
{
    reinterpret_cast<StatsWrapper*>(list->data)->appendTrick(trick);
}

int StatsWrapper::tricksCount(QQmlListProperty<TrickWrapper> *list)
{
    return reinterpret_cast<StatsWrapper*>(list->data)->tricksCount();
}

TrickWrapper *StatsWrapper::trick(QQmlListProperty<TrickWrapper> *list, int index)
{
    return reinterpret_cast<StatsWrapper*>(list->data)->trick(index);
}

void StatsWrapper::clearTricks(QQmlListProperty<TrickWrapper> *list)
{
    reinterpret_cast<StatsWrapper*>(list->data)->clearTricks();
}
