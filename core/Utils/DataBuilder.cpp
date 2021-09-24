#include "DataBuilder.h"

#include <QJsonArray>
#include <QJsonValue>

#include <QDebug>

DataBuilder::DataBuilder(QObject *parent) : QObject(parent)
{

}

StatsData DataBuilder::statsData(const QJsonObject &json)
{
    StatsData data;
    const QJsonObject& personal = json.value("personal").toObject();
    const QJsonObject& name = personal.value("name").toObject();
    data.name = name.value("name").toString();
    data.surname = name.value("surname").toString();
    data.nickname = name.value("nickname").toString();

    data.origin = origin( personal.value("origin").toObject() );
    data.profession = profession( personal.value("profession").toObject() );
    data.specialization = specialization( personal.value("specialization").toObject() );
    data.disease = disease( personal.value("disease").toObject() );
    data.experience = experience( json.value("experience").toObject() );

    for ( const QJsonValue& tAttribute: json.value("attributes").toArray() )
        data.attributes.append( attribute(tAttribute.toObject()) );

    for ( const QJsonValue& tOtherSkill: json.value("otherSkills").toArray() )
        data.otherSkills.append( otherSkill(tOtherSkill.toObject()) );

    for ( const QJsonValue& tTrick: json.value("tricks").toArray() )
        data.tricks.append( trick(tTrick.toObject()) );

    for ( const QJsonValue& tWound: json.value("wounds").toArray() )
        data.wounds.push_back( QSharedPointer<WoundData>(
                                   new WoundData(wound(tWound.toObject()))
                               ) );

    for ( const QJsonValue& tReputation: personal.value("reputation").toArray() )
        data.reputation.append( reputation(tReputation.toObject()) );

    return data;
}

EquipmentData DataBuilder::equipmentData(const QJsonObject &json)
{
    EquipmentData data;

    for ( const QJsonValue& tItem: json.value("backpack").toArray() )
        data.backpack.push_back( QSharedPointer<ItemData>(new ItemData(item(tItem.toObject()))) );

    for ( const QJsonValue& tArmor: json.value("armor").toArray() )
        data.armor.append( QSharedPointer<ItemData>(new ItemData(item(tArmor.toObject()))) );

    for ( const QJsonValue& tWeapon: json.value("weapons").toArray() )
        data.weapon.append( QSharedPointer<ItemData>(new ItemData(item(tWeapon.toObject()))) );

    const QJsonObject& supplies = json.value("supplies").toObject();

    data.drugs = supplies.value("drugs").toInt();
    data.food = supplies.value("food").toInt();
    data.water = supplies.value("water").toInt();
    return data;
}

NotesData DataBuilder::notesData(const QJsonObject &json)
{
    NotesData data;

    data.biography = json.value("biography").toString();
    data.notes = json.value("notes").toString();
    for ( const QJsonValue& tQuestion : json.value("questions").toArray() )
        data.questions.append( question(tQuestion.toObject()) );

    return data;
}

OriginData DataBuilder::origin(const QJsonObject &json)
{
    OriginData origin;
    origin.name = json.value("name").toString();
    origin.description = json.value("description").toString();
    origin.feature = feature( json.value("feature").toObject() );
    return origin;
}

ProfessionData DataBuilder::profession(const QJsonObject &json)
{
    ProfessionData profession;
    profession.name = json.value("name").toString();
    profession.description = json.value("description").toString();
    profession.feature = feature( json.value("feature").toObject() );
    return profession;
}

FeatureData DataBuilder::feature(const QJsonObject &json)
{
    FeatureData feature;
    feature.name = json.value("name").toString();
    feature.description = json.value("description").toString();
    return feature;
}

SpecializationData DataBuilder::specialization(const QJsonObject &json)
{
    SpecializationData specialization;
    specialization.name = json.value("name").toString();
    specialization.description = json.value("description").toString();
    return specialization;
}

DiseaseData DataBuilder::disease(const QJsonObject &json)
{
    DiseaseData disease;
    disease.name = json.value("name").toString();
    disease.description = json.value("description").toString();
    disease.cure = json.value("cure").toString();
    for ( const QJsonValue& tSymptom: json.value("symptoms").toArray() )
        disease.symptoms.append( symptom(tSymptom.toObject()) );
    return disease;
}

SymptomData DataBuilder::symptom(const QJsonObject &json)
{
    SymptomData symptom;
    symptom.name = json.value("name").toString();
    symptom.description = json.value("description").toString();

    for ( const QJsonValue& tPenalty: json.value("penalties").toArray() )
        symptom.penalties.append( penalty(tPenalty.toObject()) );

    return symptom;
}

PenaltyData DataBuilder::penalty(const QJsonObject &json)
{
    PenaltyData penalty;
    penalty.name = json.value("NAME").toString();
    penalty.value = json.value("VALUE").toInt();
    penalty.type = json.value("TYPE").toString();
    return penalty;
}

AttributeData DataBuilder::attribute(const QJsonObject &json)
{
    AttributeData attribute;
    attribute.name = json.value("name").toString();
    attribute.value = json.value("value").toInt();
    for ( const QJsonValue& tSkillpack: json.value("skillpacks").toArray() )
        attribute.skillpacks.append( skillpack(tSkillpack.toObject()) );
    return attribute;
}

SkillpackData DataBuilder::skillpack(const QJsonObject &json)
{
    SkillpackData skillpack;
    skillpack.name = json.value("name").toString();
    skillpack.constant = json.value("constant").toBool();
    for ( const QJsonValue& specialization: json.value("specializations").toArray() )
        skillpack.specializations.append( specialization.toString() );
    for ( const QJsonValue& tSkill: json.value("skills").toArray() )
        skillpack.skills.append( skill(tSkill.toObject()) );
    return skillpack;
}

SkillData DataBuilder::skill(const QJsonObject &json)
{
    SkillData skill;
    skill.name = json.value("name").toString();
    skill.value = json.value("value").toInt();
    skill.used = json.value("used").toBool();
    return skill;
}

OtherSkillData DataBuilder::otherSkill(const QJsonObject &json)
{
    OtherSkillData otherSkill;
    otherSkill.name = json.value("name").toString();
    otherSkill.value = json.value("value").toInt();
    otherSkill.used = json.value("used").toBool();
    otherSkill.attribute = json.value("attribute").toString();
    return otherSkill;
}

TrickData DataBuilder::trick(const QJsonObject &json)
{
    TrickData trick;
    trick.name = json.value("name").toString();
    trick.description = json.value("description").toString();
    trick.action = json.value("action").toString();
    for ( const QJsonValue& tRequirement: json.value("requirements").toArray() )
        trick.requirements.append( requirement(tRequirement.toObject()) );
    return trick;
}

WoundData DataBuilder::wound(const QJsonObject &json)
{
    WoundData wound;
    wound.location = json.value("location").toString();
    wound.type = json.value("type").toString();
    wound.modifier = json.value("modifier").toInt();
    return wound;
}

ReputationData DataBuilder::reputation(const QJsonObject &json)
{
    ReputationData reputation;
    reputation.name = json.value("name").toString();
    reputation.value = json.value("value").toInt();
    return reputation;
}

RequirementData DataBuilder::requirement(const QJsonObject &json)
{
    RequirementData requirement;
    requirement.name = json.value("NAME").toString();
    requirement.type = json.value("TYPE").toString();
    requirement.value = json.value("VALUE").toInt();
    requirement.optional = json.value("OPTIONAL").toBool();
    return requirement;
}

ExperienceData DataBuilder::experience(const QJsonObject &json)
{
    ExperienceData experience;
    experience.gathered = json.value("gathered").toInt();
    experience.spended = json.value("spended").toInt();
    return experience;
}

ItemData DataBuilder::item(const QJsonObject &json)
{
    ItemData data;
    data.type = json.value("TYPE").toString();
    data.name = json.value("NAME").toString();
    data.description = json.value("DESCRIPTION").toString();
    data.price = json.value("PRICE").toInt();
    data.quantity = json.value("QUANTITY").toInt();

    data.itemStats = itemStats( json.value("STATS").toObject() );
    return data;
}

ItemStatsData DataBuilder::itemStats(const QJsonObject &json)
{
    ItemStatsData data;
    data.reputation = json.value("REPUTATION").toInt();

    if ( json.contains("PENETRATION") )
        data.penetration = json.value("PENETRATION").toInt();

    if ( json.contains("DAMAGE") )
        for ( const QJsonValue& tDamage : json.value("DAMAGE").toArray() )
            data.damage.append( tDamage.toString() );

    if ( json.contains("DEXBONUS") )
        for ( const QJsonValue& tBonus : json.value("DEXBONUS").toArray() ) {
            data.bonuses.append( bonus(tBonus.toObject()) );
        }

    if ( json.contains("REQUIREMENT") )
        data.requirement = requirement( json.value("REQUIREMENT").toObject() );

    if ( json.contains("SPECIAL") )
        for ( const QJsonValue& tSpecial : json.value("SPECIAL").toArray() )
            data.specials.append( special(tSpecial.toObject()) );

    if ( json.contains("AMMUNITION") )
        data.ammunition = json.value("AMMUNITION").toInt();

    if ( json.contains("RATEOFFIRE") )
        data.rateOfFire = json.value("RATEOFFIRE").toInt();

    if ( json.contains("MAGAZINE") )
        data.magazine = json.value("MAGAZINE").toInt();

    if ( json.contains("JAM") )
        data.jam = json.value("JAM").toInt();

    if ( json.contains("BULLET") )
        data.bullet = json.value("BULLET").toString();

    if ( json.contains("DURABILITY") )
        data.durability = durability( json.value("DURABILITY").toObject() );

    if ( json.contains("LOCATIONS") )
        for ( const QJsonValue& tLocation : json.value("LOCATIONS").toArray() )
            data.locations.append( location(tLocation.toObject()) );

    if ( json.contains("PENALTIES") )
        for ( const QJsonValue& tPenalty : json.value("PENALTIES").toArray() )
            data.penalties.append( penalty(tPenalty.toObject()) );

    if ( json.contains("FEATURES") )
        for ( const QJsonValue& tFeature : json.value("FEATURES").toArray() )
            data.features.append( armorFeature(tFeature.toObject()) );

    return data;
}

LocationData DataBuilder::location(const QJsonObject &json)
{
    LocationData data;
    data.name = json.value("NAME").toString();
    data.armor = json.value("ARMOR").toInt();
    data.cutting = json.value("CUTTING").toInt();
    return data;
}

ArmorFeatureData DataBuilder::armorFeature(const QJsonObject &json)
{
    ArmorFeatureData data;
    data.name = json.value("NAME").toString();
    data.description = json.value("DESCRIPTION").toString();
    return data;
}

DurabilityData DataBuilder::durability(const QJsonObject &json)
{
    DurabilityData data;
    data.current = json.value("CURRENT").toInt();
    data.max = json.value("MAX").toInt();
    return data;
}

DexterityBonusData DataBuilder::bonus(const QJsonObject &json)
{
    DexterityBonusData data;
    data.name = json.value("NAME").toString();
    data.value = json.value("VALUE").toInt();
    return data;
}

SpecialData DataBuilder::special(const QJsonObject &json)
{
    SpecialData data;
    data.name = json.value("NAME").toString();
    data.description = json.value("DESCRIPTION").toString();
    return data;
}

QuestionData DataBuilder::question(const QJsonObject &json)
{
    QuestionData data;
    data.question = json.value("question").toString();
    data.subquestion = json.value("subquestion").toString();
    data.answer = json.value("answer").toString();
    return data;
}
