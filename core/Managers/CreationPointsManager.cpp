#include "CreationPointsManager.h"

CreationPointsManager::CreationPointsManager(QObject *parent)
    : QObject(parent)
{

}

int CreationPointsManager::attributes() const
{
    return m_attributes.first;
}

int CreationPointsManager::freeSkillpoints() const
{
    return m_freePoints.first;
}

int CreationPointsManager::specializationSkillpoints() const
{
    return m_specPoints.first;
}

int CreationPointsManager::money() const
{
    return m_money.first;
}

int CreationPointsManager::tricks() const
{
    return m_tricks.first;
}

bool CreationPointsManager::spendAttribute(const int &value)
{
    if ( m_attributes.first >= value ) {
        m_attributes.first -= value;
        emit attributesChanged(m_attributes.first);
        return true;
    }
    return false;
}

bool CreationPointsManager::spendSpecializationPoints(const int &value)
{
    if ( m_specPoints.first >= value ) {
        m_specPoints.first -= value;
        emit specializationSkillpointsChanged(m_specPoints.first);
        return true;
    }
    else if ( m_specPoints.first + m_freePoints.first >= value ) {
        int val = value - m_specPoints.first;
        m_specPoints.first = 0;
        m_freePoints.first -= val;
        emit specializationSkillpointsChanged(m_specPoints.first);
        emit freeSkillpointsChanged(m_freePoints.first);
        return true;
    }
    return false;
}

bool CreationPointsManager::spendFreeSkillpoints(const int &value)
{
    if ( m_freePoints.first >= value ) {
        m_freePoints.first -= value;
        emit freeSkillpointsChanged(m_freePoints.first);
        return true;
    }
    return false;
}

void CreationPointsManager::refundAttribute(const int &value)
{
    m_attributes.first += value;
    emit attributesChanged(m_attributes.first);
}

void CreationPointsManager::refundSpecializationPoints(const int &value)
{
    if ( m_specPoints.first + value > m_specPoints.second ) {
        int val = m_specPoints.first + value;
        m_specPoints.first = m_specPoints.second;
        m_freePoints.first = val - m_specPoints.first;
        emit freeSkillpointsChanged(m_freePoints.first);
    } else
        m_specPoints.first += value;
    emit specializationSkillpointsChanged(m_specPoints.first);
}

void CreationPointsManager::refundFreeSkillpoints(const int &value)
{
    if ( m_freePoints.first + value > m_freePoints.second ) {
        int val = m_freePoints.first + value;
        m_freePoints.first = m_freePoints.second;
        m_specPoints.first = val - m_freePoints.first;
        emit specializationSkillpointsChanged(m_specPoints.first);
    } else
        m_freePoints.first += value;
    emit freeSkillpointsChanged(m_freePoints.first);
}

void CreationPointsManager::spendMoney(const int &value)
{
    m_money.first -= value;
    emit moneyChanged(m_money.first);
}

void CreationPointsManager::refundMoney(const int &value)
{
    m_money.first += value;
    emit moneyChanged(m_money.first);
}

void CreationPointsManager::spendTrick(const int &value)
{
    m_tricks.first -= value;
    emit tricksChanged(m_tricks.first);
}

void CreationPointsManager::refundTrick(const int &value)
{
    m_tricks.first += value;
    emit tricksChanged(m_tricks.first);
}
