#include "SkillMod.h"

SkillMod::SkillMod(QObject *parent) : QObject(parent)
{

}

SkillMod::SkillMod(Skill *skill, QObject *parent)
    : QObject(parent),
      m_skill(skill),
      m_range(QPair<int, int>(skill->value(),skill->value()))
{

}

SkillMod::SkillMod(Skill *skill,
                   const QPair<int, int> &range,
                   QObject *parent)
    : QObject(parent),
      m_skill(skill),
      m_range(range)
{

}

Skill *SkillMod::skill() const
{
    return m_skill;
}

int SkillMod::min() const
{
    return m_range.first;
}

void SkillMod::setMin(const int &value)
{
    if ( m_range.first == value )
        return;

    m_range.first = value;
    emit minChanged(m_range.first);
}

void SkillMod::setMax(const int &value)
{
    if ( m_range.second == value )
        return;

    m_range.second = value;
    emit maxChanged(m_range.second);
}

void SkillMod::setValue(const int &value)
{
    if ( m_skill->m_value == value )
        return;

    m_skill->m_value = value;
    emit m_skill->valueChanged(m_skill->m_value);
}
