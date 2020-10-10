#include "CreationPointsManager.h"

CreationPointsManager::CreationPointsManager(QObject *parent) : QObject(parent)
{

}

int CreationPointsManager::attributes() const
{
    return m_attributes;
}

int CreationPointsManager::freeSkillpoints() const
{
    return m_freeSkillpoints;
}

int CreationPointsManager::specializationSkillpoints() const
{
    return m_specializationSkillpoints;
}

int CreationPointsManager::money() const
{
    return m_money;
}

int CreationPointsManager::tricks() const
{
    return m_tricks;
}

void CreationPointsManager::spendAttributes(const int &value)
{
    m_attributes -= value;
    emit attributesChanged(m_attributes);
}

void CreationPointsManager::refundAttributes(const int &value)
{
    m_attributes += value;
    emit attributesChanged(m_attributes);
}

void CreationPointsManager::spendFreeSkillpoints(const int &value)
{
    m_freeSkillpoints -= value;
    emit freeSkillpointsChanged(m_freeSkillpoints);
}

void CreationPointsManager::refundFreeSkillpoints(const int &value)
{
    m_freeSkillpoints += value;
    emit freeSkillpointsChanged(m_freeSkillpoints);
}

void CreationPointsManager::spendSpecializationSkillpoints(const int &value)
{
    m_specializationSkillpoints -= value;
    emit specializationSkillpointsChanged(m_specializationSkillpoints);
}

void CreationPointsManager::refundSpecializationSkillpoints(const int &value)
{
    m_specializationSkillpoints += value;
    emit specializationSkillpointsChanged(m_specializationSkillpoints);
}

void CreationPointsManager::spendMoney(const int &value)
{
    m_money -= value;
    emit moneyChanged(m_money);
}

void CreationPointsManager::refundMoney(const int &value)
{
    m_money += value;
    emit moneyChanged(m_money);
}

void CreationPointsManager::spendTrick(const int &value)
{
    m_tricks -= value;
    emit tricksChanged(m_tricks);
}

void CreationPointsManager::refundTrick(const int &value)
{
    m_tricks += value;
    emit tricksChanged(m_tricks);
}
