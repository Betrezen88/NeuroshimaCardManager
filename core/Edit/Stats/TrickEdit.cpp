#include "TrickEdit.h"

#include <QDebug>

TrickEdit::TrickEdit(QObject *parent) : QObject(parent)
{

}

TrickEdit::TrickEdit(const TrickData& data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    for ( RequirementData& requirement : m_data.requirements )
        m_requirements.push_back( new Requirement(&requirement, this));
}

TrickEdit::TrickEdit(const TrickData &data, const bool isNew, QObject *parent)
    : QObject(parent)
    , m_data(data)
    , m_isNew(isNew)
{
    for ( RequirementData& requirement : m_data.requirements )
        m_requirements.push_back( new Requirement(&requirement, this));
}

const QString &TrickEdit::name() const
{
    return m_data.name;
}

const QString &TrickEdit::description() const
{
    return m_data.description;
}

const QString &TrickEdit::action() const
{
    return m_data.action;
}

QQmlListProperty<Requirement> TrickEdit::requirements()
{
    return QQmlListProperty<Requirement>(this, this,
                                         &TrickEdit::requirementCount,
                                         &TrickEdit::requirement);
}

int TrickEdit::requirementCount() const
{
    return m_requirements.count();
}

Requirement *TrickEdit::requirement(const int index) const
{
    if ( index < 0 || index > m_requirements.count() )
        return nullptr;

    return m_requirements.at(index);
}

QVector<Requirement *> TrickEdit::attributes() const
{
    QVector<Requirement*> attributes;
    for ( Requirement* requirement : qAsConst(m_requirements) )
        if ( "attribute" == requirement->type() )
            attributes.push_back(requirement);
    return attributes;
}

QVector<Requirement *> TrickEdit::skills(const bool optional = false) const
{
    QVector<Requirement*> skills;
    for ( Requirement* requirement : qAsConst(m_requirements) )
        if ( "skill" == requirement->type() && optional == requirement->optional() )
            skills.push_back( requirement );
    return skills;
}

int TrickEdit::requirementCount(QQmlListProperty<Requirement> *list)
{
    return reinterpret_cast<TrickEdit*>(list->data)->requirementCount();
}

Requirement *TrickEdit::requirement(QQmlListProperty<Requirement> *list, int index)
{
    return reinterpret_cast<TrickEdit*>(list->data)->requirement(index);
}

bool TrickEdit::meetsRequirements() const
{
    return m_meetsRequirements;
}

void TrickEdit::setMeetsRequirements(const bool meetsRequirements)
{
    if ( m_meetsRequirements == meetsRequirements )
        return;
    m_meetsRequirements = meetsRequirements;
    emit meetsRequirementsChanged();
}

const TrickData &TrickEdit::data() const
{
    return m_data;
}

bool TrickEdit::isAffordable() const
{
    return m_isAffordable;
}

void TrickEdit::setIsAffordable(bool newIsAffordable)
{
    if (m_isAffordable == newIsAffordable)
        return;
    m_isAffordable = newIsAffordable;
    emit isAffordableChanged();
}

int TrickEdit::cost() const
{
    return m_cost;
}

void TrickEdit::setCost(int newCost)
{
    if (m_cost == newCost)
        return;
    m_cost = newCost;
    emit costChanged();
}

bool TrickEdit::isNew() const
{
    return m_isNew;
}
