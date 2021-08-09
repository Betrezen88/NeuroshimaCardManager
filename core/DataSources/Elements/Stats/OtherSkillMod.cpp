#include "OtherSkillMod.h"

#include "../../../Card/Elements/Stats/OtherSkill.h"

OtherSkillMod::OtherSkillMod(QObject *parent) : QObject(parent)
{

}

OtherSkillMod::OtherSkillMod(OtherSkill *otherSkill,
                             QObject *parent)
    : QObject(parent)
    , m_otherSkill(otherSkill)
    , m_range(QPair<int, int>(otherSkill->value(), otherSkill->value()+1))
{

}

OtherSkill *OtherSkillMod::otherSkill() const
{
    return m_otherSkill;
}

int OtherSkillMod::min() const
{
    return m_range.first;
}

int OtherSkillMod::max() const
{
    return m_range.second;
}

void OtherSkillMod::setValue(const int &value)
{
    if ( m_otherSkill->m_value == value )
        return;

    m_otherSkill->m_value = value;
    emit m_otherSkill->valueChanged( m_otherSkill->m_value );
}
