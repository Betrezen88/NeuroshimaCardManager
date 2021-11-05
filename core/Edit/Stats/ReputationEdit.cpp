#include "ReputationEdit.h"

ReputationEdit::ReputationEdit(QObject *parent) : QObject(parent)
{

}

ReputationEdit::ReputationEdit(ReputationData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
    , m_min(m_data->value)
    , m_max(m_data->value+5)
{

}

const QString &ReputationEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int ReputationEdit::value() const
{
    return m_data ? m_data->value : 0;
}

void ReputationEdit::setValue(int newValue)
{
    if (m_data && m_data->value == newValue)
        return;
    m_data->value = newValue;
    emit valueChanged();
}

int ReputationEdit::min() const
{
    return m_min;
}

int ReputationEdit::max() const
{
    return m_max;
}

void ReputationEdit::increaseMax()
{
    ++m_max;
    emit maxChanged();
}

void ReputationEdit::decreaseMax()
{
    --m_max;
    emit maxChanged();
}

bool ReputationEdit::isAffordable() const
{
    return m_isAffordable;
}

void ReputationEdit::setIsAffordable(bool newIsAffordable)
{
    if (m_isAffordable == newIsAffordable)
        return;
    m_isAffordable = newIsAffordable || m_data->value > m_min;
    emit isAffordableChanged();
}

int ReputationEdit::cost() const
{
    return m_cost;
}

void ReputationEdit::setCost(int newCost)
{
    if (m_cost == newCost)
        return;
    m_cost = newCost;
    emit costChanged();
}

void ReputationEdit::increase()
{
    ++m_data->value;
    emit valueChanged();
    emit increased(this);
}

void ReputationEdit::decrease()
{
    emit decreased(this);
    --m_data->value;
    emit valueChanged();
}
