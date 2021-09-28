#include "Converter.h"

#include "../View/Card.h"
#include "../View/Pages/Stats.h"
#include "../View/Pages/Equipment.h"
#include "../View/Pages/Notes.h"

#include <QJsonArray>

Converter::Converter()
{

}

QJsonObject Converter::toJson(const Card *card)
{
    QJsonObject json;

    if ( card->hasPage(Page::Type::STATS) )
        json.insert( "stats", stats(card->stats()->data()) );
    if ( card->hasPage(Page::Type::EQUIPMENT) )
        json.insert( "equipment", equipment(card->equipment()->data()) );
    if ( card->hasPage(Page::Type::NOTES) )
        json.insert( "notes", notes(card->notes()->data()) );

    return json;
}

QJsonObject Converter::stats(const StatsData &data)
{
    QJsonObject json;

    QJsonObject name;
    name.insert( "name", data.name );
    name.insert( "surname", data.surname );
    name.insert( "nickname", data.nickname );

    QJsonArray reputations;
    for ( const ReputationData& tReputation : data.reputation )
        reputations.append( reputation(tReputation) );

    QJsonObject personal;
    personal.insert( "name", name );
    personal.insert( "origin", origin(data.origin) );
    personal.insert( "profession", profession(data.profession) );
    personal.insert( "specialization", specialization(data.specialization) );
    personal.insert( "disease", disease(data.disease) );
    personal.insert( "reputation", reputations );

    QJsonArray attributes;
    for ( const AttributeData& tAttribute : data.attributes )
        attributes.append( attribute(tAttribute) );

    QJsonArray otherSkills;
    for ( const QSharedPointer<OtherSkillData>& tOtherSkill : data.otherSkills )
        otherSkills.append( otherSkill(*tOtherSkill) );

    QJsonArray tricks;
    for ( const TrickData& tTrick : data.tricks )
        tricks.append( trick(tTrick) );

    json.insert( "personal", personal );
    json.insert( "attributes", attributes );
    json.insert( "otherSkills", otherSkills );
    json.insert( "tricks", tricks );
    json.insert( "experience", experience(data.experience) );

    return json;
}

QJsonObject Converter::origin(const OriginData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    json.insert( "feature", feature(data.feature) );
    return json;
}

QJsonObject Converter::profession(const ProfessionData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    json.insert( "feature", feature(data.feature) );
    return json;
}

QJsonObject Converter::feature(const FeatureData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    return json;
}

QJsonObject Converter::specialization(const SpecializationData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    return json;
}

QJsonObject Converter::disease(const DiseaseData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    json.insert( "cure", data.cure );
    QJsonArray symptoms;
    for ( const SymptomData& tSymptom : data.symptoms )
        symptoms.append( symptom(tSymptom) );
    json.insert( "symptoms", symptoms );
    return json;
}

QJsonObject Converter::symptom(const SymptomData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    QJsonArray penalties;
    for ( const PenaltyData& tPenalty : data.penalties )
        penalties.append( penalty(tPenalty) );
    json.insert( "penalties", penalties );
    return json;
}

QJsonObject Converter::penalty(const PenaltyData &data)
{
    QJsonObject json;
    json.insert( "NAME", data.name );
    json.insert( "TYPE", data.type );
    json.insert( "VALUE", data.value );
    return json;
}

QJsonObject Converter::reputation(const ReputationData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "value", data.value );
    return json;
}

QJsonObject Converter::attribute(const AttributeData &data)
{
    QJsonObject json;
    QJsonArray skillpacks;

    for ( const SkillpackData& tSkillpack : data.skillpacks )
        skillpacks.append( skillpack(tSkillpack) );

    json.insert( "name", data.name );
    json.insert( "value", data.value );
    json.insert( "skillpacks", skillpacks );
    return json;
}

QJsonObject Converter::skillpack(const SkillpackData &data)
{
    QJsonObject json;
    QJsonArray specializations;
    QJsonArray skills;
    for ( const QString& spec : data.specializations )
        specializations.append( spec );
    for ( const SkillData& tSkill : data.skills )
        skills.append( skill(tSkill) );

    json.insert( "name", data.name );
    json.insert( "specializations", specializations );
    json.insert( "constant", data.constant );
    json.insert( "skills", skills );
    return json;
}

QJsonObject Converter::skill(const SkillData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "value", data.value );
    json.insert( "used", data.used );
    return json;
}

QJsonObject Converter::otherSkill(const OtherSkillData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "value", data.value );
    json.insert( "attribute", data.attribute );
    json.insert( "used", data.used );
    return json;
}

QJsonObject Converter::trick(const TrickData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "description", data.description );
    json.insert( "action", data.action );
    QJsonArray requirements;
    for ( const RequirementData& tRequirement : data.requirements )
        requirements.append( requirement(tRequirement) );
    json.insert( "requirements", requirements);
    return json;
}

QJsonObject Converter::requirement(const RequirementData &data)
{
    QJsonObject json;
    json.insert( "name", data.name );
    json.insert( "type", data.type );
    json.insert( "value", data.value );
    json.insert( "optional", data.optional );
    return json;
}

QJsonObject Converter::experience(const ExperienceData &data)
{
    QJsonObject json;
    json.insert( "gathered", data.gathered );
    json.insert( "spended", data.spended );
    return json;
}

QJsonObject Converter::equipment(const EquipmentData &data)
{
    QJsonObject json;

    QJsonObject supplies;
    supplies.insert( "drugs", data.drugs );
    supplies.insert( "food", data.food );
    supplies.insert( "water", data.water );

    QJsonArray backpack;
    for ( const QSharedPointer<ItemData>& tItem : data.backpack )
        backpack.append( item(*tItem) );
    QJsonArray armor;
    for ( const QSharedPointer<ItemData>& tItem : data.armor )
        armor.append( item(*tItem) );
    QJsonArray weapons;
    for ( const QSharedPointer<ItemData>& tItem : data.weapon )
        weapons.append( item(*tItem) );

    json.insert( "supplies", supplies );
    json.insert( "backpack", backpack );
    json.insert( "armor", armor );
    json.insert( "weapons", weapons );

    return json;
}

QJsonObject Converter::item(const ItemData &data)
{
    QJsonObject json;
    json.insert( "NAME", data.name );
    json.insert( "DESCRIPTION", data.description );
    json.insert( "TYPE", data.type );
    json.insert( "PRICE", data.price );
    json.insert( "QUANTITY", data.quantity );
    json.insert( "STATS", itemStats(data.itemStats) );

    return json;
}

QJsonObject Converter::itemStats(const ItemStatsData &data)
{
    QJsonObject json;

    if ( data.reputation > 0 )
        json.insert( "REPUTATION", data.reputation );
    if ( data.durability.max > 0 ) {
        QJsonObject durability;
        durability.insert( "MAX", data.durability.max );
        durability.insert( "CURRENT", data.durability.current );
        json.insert( "DURABILITY", durability );
    }
    if ( 0 < data.locations.count() ) {
        QJsonArray locations;
        for ( const LocationData& tLocation : data.locations )
            locations.append( location(tLocation) );
        json.insert( "LOCATIONS", locations );
    }
    if ( 0 < data.penalties.count() ) {
        QJsonArray penalties;
        for ( const PenaltyData& tPenalty : data.penalties )
            penalties.append( penalty(tPenalty) );
        json.insert( "PENALTIES", penalties );
    }
    if ( 0 < data.features.count() ) {
        QJsonArray features;
        for ( const ArmorFeatureData& tFeature : data.features )
            features.append( armorFeature(tFeature) );
        json.insert( "FEATURES", features );
    }
    if ( 0 < data.bonuses.count() ) {
        QJsonArray bonuses;
        for ( const DexterityBonusData& tBonus : data.bonuses )
            bonuses.append( dexterityBonus(tBonus) );
        json.insert( "DEXBONUS", bonuses );
    }
    if ( 0 < data.specials.count() ) {
        QJsonArray specials;
        for ( const SpecialData& tSpecial : data.specials )
            specials.append( special(tSpecial) );
        json.insert( "SPECIALS", specials );
    }
    if ( 0 < data.penetration )
        json.insert( "PENETRATION", data.penetration );
    if ( 0 < data.damage.count() ) {
        QJsonArray damage;
        for ( const QString& tDamage : data.damage )
            damage.append( tDamage );
        json.insert( "DAMAGE", damage );
    }
    if ( !data.requirement.name.isEmpty() )
        json.insert( "REQUIREMENT", requirement(data.requirement) );
    if ( 0 < data.magazine ) {
        json.insert( "MAGAZINE", data.magazine );
        json.insert( "AMMUNITION", data.ammunition );
    }
    if ( 0 < data.rateOfFire )
        json.insert( "RATEOFFIRE", data.rateOfFire );
    if ( 0 < data.jam )
        json.insert( "JAM", data.jam );
    if ( !data.bullet.isEmpty() )
        json.insert( "BULLET", data.bullet );

    return json;
}

QJsonObject Converter::location(const LocationData &data)
{
    QJsonObject json;
    json.insert( "NAME", data.name );
    json.insert( "ARMOR", data.armor );
    json.insert( "CUTTING", data.cutting );
    return json;
}

QJsonObject Converter::armorFeature(const ArmorFeatureData &data)
{
    QJsonObject json;
    json.insert( "NAME", data.name );
    json.insert( "DESCRIPTION", data.description );
    return json;
}

QJsonObject Converter::dexterityBonus(const DexterityBonusData &data)
{
    QJsonObject json;
    json.insert( "NAME", data.name );
    json.insert( "VALUE", data.value );
    return json;
}

QJsonObject Converter::special(const SpecialData &data)
{
    QJsonObject json;
    json.insert( "NAME", data.name );
    json.insert( "DESCRIPTION", data.description );
    return json;
}

QJsonObject Converter::notes(const NotesData &data)
{
    QJsonObject json;
    QJsonArray questions;
    for ( const QuestionData& tQuestion : data.questions )
        questions.append( question(tQuestion) );

    json.insert( "biography", data.biography );
    json.insert( "notes", data.notes );
    json.insert( "questions", questions );
    return json;
}

QJsonObject Converter::question(const QuestionData &data)
{
    QJsonObject json;
    json.insert( "question", data.question );
    json.insert( "subquestion", data.subquestion );
    json.insert( "answer", data.answer );
    return json;
}
