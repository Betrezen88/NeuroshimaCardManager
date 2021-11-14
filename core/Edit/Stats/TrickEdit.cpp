#include "TrickEdit.h"

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

int TrickEdit::requirementCount(QQmlListProperty<Requirement> *list)
{
    return reinterpret_cast<TrickEdit*>(list->data)->requirementCount();
}

Requirement *TrickEdit::requirement(QQmlListProperty<Requirement> *list, int index)
{
    return reinterpret_cast<TrickEdit*>(list->data)->requirement(index);
}
