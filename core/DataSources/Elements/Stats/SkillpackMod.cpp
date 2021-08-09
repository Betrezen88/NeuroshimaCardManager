﻿#include "SkillpackMod.h"

#include "SkillMod.h"
#include "../../../Card/Elements/Stats/Skillpack.h"
#include "../../../Card/Elements/Stats/Skill.h"

SkillpackMod::SkillpackMod(QObject *parent) : QObject(parent)
{

}

SkillpackMod::SkillpackMod(Skillpack *skillpack,
                           const bool& edit = false,
                           QObject *parent)
    : QObject(parent)
    , m_pSkillpack(skillpack)
    , m_edit(edit)
{
    for ( Skill* skill: qAsConst(m_pSkillpack->m_skills) ) {
        QPair<int, int> range = m_edit ? QPair<int, int>(skill->value(), skill->value()+1)
                                       : QPair<int, int>(0, 5);
        m_skills.append(new SkillMod(skill, range, this));
        connect(skill, &Skill::valueChanged, this, [this](){
            emit enabledChanged(enabled());
        });
    }
}

QQmlListProperty<SkillMod> SkillpackMod::skills()
{
    return QQmlListProperty<SkillMod>(this, &m_skills);
}

bool SkillpackMod::bougth() const
{
    return m_bougth;
}

Skillpack *SkillpackMod::skillpack() const
{
    return m_pSkillpack;
}

QList<SkillMod *> SkillpackMod::skillList() const
{
    return m_skills;
}

bool SkillpackMod::enabled() const
{
    for ( SkillMod* skillMod: m_skills )
        if (skillMod->min() != skillMod->skill()->value())
            return false;
    return true;
}

void SkillpackMod::buy()
{
    for ( SkillMod *skill: qAsConst(m_skills) ) {
        skill->setMin(1);
        skill->setValue(1);
    }
    m_bougth = true;
    emit bougthChanged(m_bougth);
}

void SkillpackMod::sell()
{
    for ( SkillMod *skill: qAsConst(m_skills) ) {
        skill->setMin(0);
        skill->setValue(0);
    }
    m_bougth = false;
    emit bougthChanged(m_bougth);
}

void SkillpackMod::addBonus(const int &value)
{
    for ( SkillMod* skill: qAsConst(m_skills) ) {
        skill->setMin(skill->min()+value);
        skill->setValue(skill->skill()->value()+value);
    }
}

void SkillpackMod::removeBonus(const int &value)
{
    for ( SkillMod* skill: qAsConst(m_skills) ) {
        skill->setMin(skill->min()-value);
        skill->setValue(skill->skill()->value()-value);
    }
}
