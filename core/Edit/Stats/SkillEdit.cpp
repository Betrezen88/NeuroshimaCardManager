#include "SkillEdit.h"
#include "../../Data/Stats/SkillData.h"

#include <QDebug>

SkillEdit::SkillEdit(QObject *parent) : QObject(parent)
{

}

SkillEdit::SkillEdit(SkillData* data, QObject *parent)
    : QObject(parent)
    , m_data(data)
    , m_min(m_data->value)
    , m_max(m_data->value+1)
{

}

const QString &SkillEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int SkillEdit::value() const
{
    return m_data ? m_data->value : 0;
}

int SkillEdit::min() const
{
    return m_min;
}

int SkillEdit::max() const
{
    return m_max;
}

bool SkillEdit::used() const
{
    return m_data ? m_data->used : false;
}

bool SkillEdit::affordable() const
{
    return m_affordable;
}

void SkillEdit::setAffordable(bool newAffordable)
{
    if (m_affordable == newAffordable)
        return;
    m_affordable = newAffordable || m_data->value == m_max;
    emit affordableChanged();
}

void SkillEdit::increase()
{
    ++m_data->value;
    emit valueChanged();
    emit increased(m_data->value);
}

void SkillEdit::decrease()
{
    emit decreased(m_data->value);
    --m_data->value;
    emit valueChanged();
}

void SkillEdit::unuse()
{
    m_data->used = false;
}

int SkillEdit::cost() const
{
    return m_cost;
}

void SkillEdit::setCost(int newCost)
{

    if (m_cost == newCost)
        return;
    m_cost = newCost;
    emit costChanged();
}
