#include "StatsWrapper.h"
#include "cpp/Section/PersonalWrapper.h"
#include "cpp/Element/AttributeWrapper.h"
#include "cpp/Element/OtherSkillWrapper.h"
#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/AttributeData.h"
#include "Card/Elements/Stats/OtherSkillData.h"

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
