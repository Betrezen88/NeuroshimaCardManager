#include "StatsWrapper.h"
#include "cpp/Section/PersonalWrapper.h"
#include "cpp/Element/AttributeWrapper.h"
#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/AttributeData.h"

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
