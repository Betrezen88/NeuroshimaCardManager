#include "TrickValidator.h"

#include "../Creators/StatsCreator.h"
#include "../Card/Elements/Stats/Attribute.h"
#include "../Card/Elements/Stats/Skillpack.h"
#include "../Card/Elements/Stats/Skill.h"
#include "../Card/Elements/Stats/Trick.h"

#include "../DataSources/Elements/Stats/AttributeMod.h"
#include "../DataSources/Elements/Stats/Requirement.h"

#include <QDebug>

TrickValidator::TrickValidator(QObject *parent) : QObject(parent)
{

}

bool TrickValidator::fulfillsRequirements(StatsCreator *stats,
                                          Trick *trick)
{
    QVector<Requirement*> optionalSkills;
    for ( Requirement *pRequirement: const_cast<const Trick*>(trick)->requirements() ) {
        if ( Requirement::Type::SKILL == pRequirement->type() ) {
            if ( pRequirement->optional() )
                optionalSkills.push_back(pRequirement);
            else if ( pRequirement->value()
                      > stats->getSkill(pRequirement->name())->value() )
                return false;
        }
        if ( Requirement::Type::ATTRIBUTE == pRequirement->type() ) {
            if ( pRequirement->value()
                 > stats->getAttribute(pRequirement->name())->attribute()->value() )
                return false;
        }
        if ( Requirement::Type::PROFESSION == pRequirement->type() ) {
            if ( pRequirement->name() != stats->profession() )
                return false;
        }
        if ( Requirement::Type::SKILLPACK == pRequirement->type() ) {
            int sum{0};
            for ( int i=0; i<stats->attributesCount(); ++i ) {
                for ( int j=0; j<stats->attribute(i)->attribute()->skillpacksCount(); ++j ) {
                    Skillpack *pSkillpack = stats->attribute(i)->attribute()->skillpack(j);
                    if ( pSkillpack->name() == pRequirement->name() )
                       for ( int k=0; k<pSkillpack->skillsCount(); ++k )
                           sum += pSkillpack->skill(k)->value();
                }
            }
            if ( sum < pRequirement->value() )
                return false;
        }
    }

    if ( 0 < optionalSkills.count() )
        return fullfilsOptional(stats, optionalSkills);

    return true;
}

bool TrickValidator::fullfilsOptional(StatsCreator *stats,
                                      QVector<Requirement *> requirements)
{
    for ( const Requirement *pRequirement: requirements ) {
        if ( pRequirement->value() <= stats->getSkill(pRequirement->name())->value() )
            return true;
    }
    return false;
}
