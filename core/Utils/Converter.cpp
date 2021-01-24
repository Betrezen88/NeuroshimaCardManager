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

#include "../Card/Elements/Equipment/Item.h"

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

QJsonObject Converter::fromEquipment(const Equipment *equipment)
{
    QJsonObject object;

    QJsonArray backpack;
    for ( const Item* item: equipment->backpack() ) {
        if ( Item::Type::EMPTY != item->type() )
            backpack.append( fromItem(item) );
    }
    object.insert( "backpack", backpack );

    return object;
}

QJsonObject Converter::fromItem(const Item *item)
{
    QJsonObject object;
    object.insert( "NAME", item->name() );
    object.insert( "DESCRIPTION", item->description() );
    object.insert( "PRICE", item->price() );
    object.insert( "QUANTITY", item->quantity() );
    object.insert( "TYPE", Item::typeToString(item->type()) );

    QJsonObject stats;

    if ( item->hasStat("REPUTATION") )
        stats.insert( "REPUTATION", item->reputation() );
    if ( item->hasStat("REQUIREMENT") )
        stats.insert( "REQUIREMENT", item->requiredBody() );
    if ( item->hasStat("PENETRATION") )
        stats.insert( "PENETRATION", item->penetration() );
    if ( item->hasStat("DURABILITY") )
        stats.insert( "DURABILITY", item->durability() );
    if ( item->hasStat("RATEOFFIRE") )
        stats.insert( "RATEOFFIRE", item->rateOfFire() );
    if ( item->hasStat("AMMUNITION") )
        stats.insert( "AMMUNITION", item->ammunition() );
    if ( item->hasStat("MAGAZINE") )
        stats.insert( "MAGAZINE", item->magazine() );
    if ( item->hasStat("BULLET") )
        stats.insert( "BULLET", item->bullet() );
    if ( item->hasStat("DAMAGE") ) {
        QJsonArray damage;
        for ( const QString& dmg: item->damage() )
            damage.append(dmg);
        stats.insert( "DAMAGE", damage);
    }
    if ( item->hasStat("DEXBONUS") ) {
        QJsonObject dexbonus;
        const QMap<QString, QVariant> tDexBonus = item->dexBonus();
        for ( const QString& key: tDexBonus.keys() )
            dexbonus.insert( key, tDexBonus.value(key).toInt() );
        stats.insert( "DEXBONUS", dexbonus );
    }
    if ( item->hasStat("SPECIAL") ) {
        QJsonArray specials;
        for ( const QVariant& special: item->special() )
            specials.append( special.toJsonObject() );
        stats.insert( "SPECIAL", specials );
    }
    if ( item->hasStat("LOCATIONS") ) {
        QJsonObject locations;
        const QMap<QString, QVariant> tLocations = item->locations();
        for ( const QString& key: tLocations.keys() )
            locations.insert( key, tLocations.value(key).toInt() );
        stats.insert( "LOCATIONS", locations );
    }
    if ( item->hasStat("PENALTIES") ) {
        QJsonArray penalties;
        for ( const QVariant& penalty: item->penalties() )
            penalties.append(penalty.toJsonObject());
        stats.insert( "PENALTIES", penalties );
    }
    if ( item->hasStat("FEATURES") ) {
        QJsonArray features;
        for ( const QVariant& feature: item->features() )
            features.append(feature.toJsonObject());
        stats.insert( "FEATURES", features );
    }

    object.insert( "STATS", stats );

    return object;
}
