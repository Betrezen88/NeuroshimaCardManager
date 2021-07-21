#include "Converter.h"

#include "../Card/Card.h"
#include "../Card/Data.h"

#include "../Card/Pages/Stats.h"
#include "../Card/Pages/Equipment.h"

#include "../Card/Elements/Stats/Disease.h"
#include "../Card/Elements/Stats/Symptom.h"
#include "../Card/Elements/Stats/Penalty.h"
#include "../Card/Elements/Stats/Skill.h"
#include "../Card/Elements/Stats/Skillpack.h"
#include "../Card/Elements/Stats/Attribute.h"
#include "../Card/Elements/Stats/Trick.h"
#include "../Card/Elements/Stats/OtherSkill.h"
#include "../Card/Elements/Stats/Wound.h"

#include "../Card/Elements/Equipment/Item.h"
#include "../Card/Elements/Equipment/DexterityBonus.h"
#include "../Card/Elements/Equipment/Durability.h"
#include "../Card/Elements/Equipment/Location.h"

#include "../DataSources/Elements/Stats/Requirement.h"

#include <QJsonArray>

Converter::Converter()
{
    qDebug() << "Converter::Converter()";
}

QJsonObject Converter::toJson(const Card *card)
{
    QJsonObject object;

    if ( card->hasPage(Page::Type::STATS) )
        object.insert( "stats", fromStats(card->stats()) );
    if ( card->hasPage(Page::Type::EQUIPMENT) )
        object.insert( "equipment", fromEquipment(card->equipment()) );

    return object;
}

QJsonObject Converter::fromStats(const Stats *stats)
{
    QJsonObject object;
    QJsonObject personal;

    QJsonObject name;
    name.insert( "name", stats->name() );
    name.insert( "surname", stats->surname() );
    name.insert( "nickname", stats->nickname() );

    personal.insert( "name", name );
    personal.insert( "origin", fromData(stats->origin()) );
    personal.insert( "profession", fromData(stats->profession()) );
    personal.insert( "specialization", fromData(stats->specialization()) );
    personal.insert( "disease", fromDisease(stats->disease()) );

    QJsonObject features;
    features.insert( "origin", fromData(stats->originFeature()) );
    features.insert( "profession", fromData(stats->professionFeature()) );
    personal.insert( "features", features );

    object.insert( "personal", personal );

    QJsonArray attributes;
    for ( const Attribute* attribute: stats->attributes() )
        attributes.append( fromAttribute(attribute) );
    object.insert( "attributes", attributes );

    QJsonArray tricks;
    for ( const Trick* trick: stats->tricks() )
        tricks.append( fromTrick(trick) );
    object.insert( "tricks", tricks );

    QJsonArray otherSkills;
    for ( const OtherSkill* otherSkill: stats->otherSkills() )
        otherSkills.append( fromOtherSkill(otherSkill) );
    object.insert( "otherSkills", otherSkills );

    QJsonObject experience;
    experience.insert( "gathered", stats->gathered() );
    experience.insert( "spended", stats->spended() );
    object.insert( "experience", experience );

    QJsonArray wounds;
    for ( const Wound* wound: stats->wounds() )
        wounds.append( fromWound(wound) );
    object.insert( "wounds", wounds );

    return object;
}

QJsonObject Converter::fromData(const Data *data)
{
    QJsonObject object;
    object.insert( "name", data->name() );
    object.insert( "description", data->description() );
    return object;
}

QJsonObject Converter::fromDisease(const Disease *disease)
{
    QJsonObject object;

    object.insert( "name", disease->name() );
    object.insert( "description", disease->description() );
    object.insert( "cure", disease->cure() );

    QJsonArray symptoms;
    for ( const Symptom* symptom: disease->symptoms() )
        symptoms.append( fromSymptom(symptom) );

    object.insert( "symptoms", symptoms );

    return object;
}

QJsonObject Converter::fromSymptom(const Symptom *symptom)
{
    QJsonObject object;
    object.insert( "name", symptom->name() );
    object.insert( "description", symptom->description() );

    QJsonArray penalties;
    for ( const Penalty* penalty: symptom->penalties() )
        penalties.append( fromPenalty(penalty) );

    return object;
}

QJsonObject Converter::fromPenalty(const Penalty *penalty)
{
    QJsonObject object;
    object.insert( "name", penalty->name() );
    object.insert( "value", penalty->value() );
//    object.insert( "type", penalty->type() );

    return object;
}

QJsonObject Converter::fromSkill(const Skill *skill)
{
    QJsonObject object;
    object.insert( "name", skill->name() );
    object.insert( "value", skill->value() );
    object.insert( "used", skill->used() );
    return object;
}

QJsonObject Converter::fromSkillpack(const Skillpack *skillpack)
{
    QJsonObject object;

    object.insert( "name", skillpack->name() );

    QJsonArray specializations;
    for ( const QString& specialization: skillpack->specializations() )
        specializations.append( specialization );
    object.insert( "specializations", specializations );

    QJsonArray skills;
    for ( const Skill* skill: skillpack->skills() )
        skills.append( fromSkill(skill) );
    object.insert( "skills", skills );

    return object;
}

QJsonObject Converter::fromAttribute(const Attribute *attribute)
{
    QJsonObject object;

    object.insert( "name", attribute->name() );
    object.insert( "value", attribute->value() );

    QJsonArray skillpacks;
    for ( const Skillpack* skillpack: attribute->skillpacks() )
        skillpacks.append( fromSkillpack(skillpack) );
    object.insert( "skillpacks", skillpacks );

    return object;
}

QJsonObject Converter::fromTrick(const Trick *trick)
{
    QJsonObject object;
    object.insert( "name", trick->name() );
    object.insert( "description", trick->description() );
    object.insert( "action", trick->action() );
    return object;
}

QJsonObject Converter::fromOtherSkill(const OtherSkill *otherSkill)
{
    QJsonObject object;
    object.insert( "name", otherSkill->name() );
    object.insert( "value", otherSkill->value() );
    object.insert( "attribute", otherSkill->attribute() );
    object.insert( "used", otherSkill->used() );
    return object;
}

QJsonObject Converter::fromWound(const Wound *wound)
{
    QJsonObject object;

    object.insert( "location", wound->location() );
    object.insert( "type", wound->type() );
    object.insert( "modifier", wound->modifier() );

    return object;
}

QJsonObject Converter::fromEquipment(const Equipment *equipment)
{
    QJsonObject object;

    QJsonArray backpack;
    for ( const Item* item: equipment->backpack() ) {
        if ( "EMPTY" != item->type() )
            backpack.append( fromItem(item) );
    }
    object.insert( "backpack", backpack );

    QJsonArray weapons;
    for ( const Item* item: equipment->weapons() ) {
        weapons.append( fromItem(item) );
    }
    object.insert( "weapons", weapons );

    QJsonObject supplies;
    supplies.insert( "drugs", equipment->drugs() );
    supplies.insert( "food", equipment->food() );
    supplies.insert( "water", equipment->water() );

    object.insert( "supplies", supplies );

    return object;
}

QJsonObject Converter::fromItem(const Item *item)
{
    QJsonObject object;
    object.insert( "NAME", item->name() );
    object.insert( "DESCRIPTION", item->description() );
    object.insert( "PRICE", item->price() );
    object.insert( "QUANTITY", item->quantity() );
    object.insert( "TYPE", item->type() );

    QJsonObject stats;

    if ( item->reputation() > 0 )
        stats.insert( "REPUTATION", item->reputation() );
    if ( item->requirement() ) {
        QJsonObject requirement;
        requirement.insert( "NAME", item->requirement()->name() );
        requirement.insert( "VALUE", item->requirement()->value() );
        requirement.insert( "TYPE", Requirement::stringToType(item->requirement()->type()) );
        stats.insert( "REQUIREMENT", requirement );
    }
    if ( item->penetration() > 0 )
        stats.insert( "PENETRATION", item->penetration() );
    if ( item->rateOfFire() > 0 )
        stats.insert( "RATEOFFIRE", item->rateOfFire() );
    if ( item->ammunition() > 0 )
        stats.insert( "AMMUNITION", item->ammunition() );
    if ( !item->magazine().isEmpty() )
        stats.insert( "MAGAZINE", item->magazine() );
    if ( !item->bullet().isEmpty() )
        stats.insert( "BULLET", item->bullet() );
    if ( !item->jam().isEmpty() )
        stats.insert( "JAM", item->jam() );
    if ( item->damage().count() > 0 ) {
        QJsonArray damage;
        for ( const QString& dmg: item->damage() )
            damage.append(dmg);
        stats.insert( "DAMAGE", damage);
    }
    if ( item->dexterityBonusesCount() > 0 ) {
        QJsonArray bonusList;
        for ( const DexterityBonus* bonus: item->dexterityBonuses() ) {
            QJsonObject tBonus;
            tBonus.insert( "NAME", bonus->name() );
            tBonus.insert( "VALUE", bonus->value() );
            bonusList.append( tBonus );
        }

        stats.insert( "DEXBONUS", bonusList );
    }
    if ( item->specialsCount() > 0 ) {
        QJsonArray specials;
        for ( const Data* special: item->specials() ) {
            QJsonObject tSpecial;
            tSpecial.insert( "NAME", special->name() );
            tSpecial.insert( "DESCRIPTION", special->description() );
        }
        stats.insert( "SPECIAL", specials );
    }
    if ( item->durability() ) {
        QJsonObject durability;
        durability.insert( "max", item->durability()->max() );
        durability.insert( "current", item->durability()->current() );
        stats.insert("DURABILITY", durability);
    }
    if ( item->locationsCount() > 0 ) {
        QJsonArray locations;
        for ( const Location* location: item->locations() ) {
            QJsonObject tLocation;
            tLocation.insert( "LOCATION", location->location() );
            tLocation.insert( "ARMOR", location->armor() );
            if ( 0 < location->cutting() )
                tLocation.insert( "CUTTING", location->cutting() );
            locations.append( tLocation );
        }
        stats.insert( "LOCATIONS", locations );
    }
    if ( item->penaltiesCount() > 0 ) {
        QJsonArray penalties;
        for ( const Penalty* penalty: item->penalties() ) {
            QJsonObject tPenalty;
            tPenalty.insert( "NAME", penalty->name() );
            tPenalty.insert( "VALUE", penalty->value() );
            tPenalty.insert( "TYPE", penalty->type() );
            penalties.append( tPenalty );
        }
        stats.insert( "PENALTIES", penalties );
    }
    if ( item->featuresCount() > 0 ) {
        QJsonArray features;
        for ( const Data* feature: item->features() ) {
            QJsonObject tFeature;
            tFeature.insert( "NAME", feature->name() );
            tFeature.insert( "DESCRIPTION", feature->description() );
            features.append( tFeature );
        }
        stats.insert( "FEATURES", features );
    }

    object.insert( "STATS", stats );

    return object;
}
