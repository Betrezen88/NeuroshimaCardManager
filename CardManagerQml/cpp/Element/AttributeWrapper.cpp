#include "AttributeWrapper.h"
#include "SkillpackWrapper.h"
#include "Card/Elements/Stats/AttributeData.h"
#include "Card/Elements/Stats/SkillpackData.h"

AttributeWrapper::AttributeWrapper(QObject *parent) : QObject(parent)
{

}

AttributeWrapper::AttributeWrapper(AttributeData *attributeData, QObject *parent)
    : QObject(parent),
      m_pAttributeData(attributeData)
{
    for ( SkillpackData *pSkillpack: m_pAttributeData->skillpacks() ) {
        appendSkillpack( new SkillpackWrapper(pSkillpack, this));
    }
}

QString AttributeWrapper::name() const
{
    return m_pAttributeData->name();
}

int AttributeWrapper::value() const
{
    return m_pAttributeData->value();
}

QQmlListProperty<SkillpackWrapper> AttributeWrapper::skillpacks()
{
    return QQmlListProperty<SkillpackWrapper>(this, this,
                                          &AttributeWrapper::appendSkillpack,
                                          &AttributeWrapper::skillpackCount,
                                          &AttributeWrapper::skillpack,
                                          &AttributeWrapper::clearSkillpacks);
}

void AttributeWrapper::appendSkillpack(SkillpackWrapper *skillpack)
{
    m_skillpacks.push_back(skillpack);
    emit skillpacksChanged();
}

int AttributeWrapper::skillpackCount() const
{
    return m_skillpacks.count();
}

SkillpackWrapper *AttributeWrapper::skillpack(int index) const
{
    return m_skillpacks.at(index);
}

void AttributeWrapper::clearSkillpacks()
{
    m_skillpacks.clear();
}

bool AttributeWrapper::hasSkillpack(const QString &name) const
{
    return m_pAttributeData->hasSkillpack(name);
}

void AttributeWrapper::appendSkillpack(QQmlListProperty<SkillpackWrapper> *list, SkillpackWrapper *skillpack)
{
    reinterpret_cast<AttributeWrapper*>(list->data)->appendSkillpack(skillpack);
}

int AttributeWrapper::skillpackCount(QQmlListProperty<SkillpackWrapper> *list)
{
    return reinterpret_cast<AttributeWrapper*>(list->data)->skillpackCount();
}

SkillpackWrapper *AttributeWrapper::skillpack(QQmlListProperty<SkillpackWrapper> *list, int index)
{
    return reinterpret_cast<AttributeWrapper*>(list->data)->skillpack(index);
}

void AttributeWrapper::clearSkillpacks(QQmlListProperty<SkillpackWrapper> *list)
{
    reinterpret_cast<AttributeWrapper*>(list->data)->clearSkillpacks();
}
