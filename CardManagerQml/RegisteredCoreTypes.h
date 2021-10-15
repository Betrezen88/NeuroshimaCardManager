#ifndef REGISTEREDCORETYPES_H
#define REGISTEREDCORETYPES_H

#include "qqmlengine.h"

// Data
#include "Data/Stats/AttributeData.h"
#include "Data/Stats/DiseaseData.h"
#include "Data/Stats/FeatureData.h"
#include "Data/Stats/OriginData.h"
#include "Data/Stats/OtherSkillData.h"
#include "Data/Stats/ProfessionData.h"
#include "Data/Stats/ReputationData.h"
#include "Data/Stats/SkillData.h"
#include "Data/Stats/SkillpackData.h"
#include "Data/Stats/StatsData.h"
#include "Data/Stats/SymptomData.h"
#include "Data/Stats/TrickData.h"
#include "Data/Stats/WoundData.h"
#include "Data/Stats/ExperienceData.h"
#include "Data/Equipment/ArmorFeatureData.h"
#include "Data/Equipment/DexterityBonusData.h"
#include "Data/Equipment/DurabilityData.h"
#include "Data/Equipment/EquipmentData.h"
#include "Data/Equipment/ItemData.h"
#include "Data/Equipment/ItemStatsData.h"
#include "Data/Equipment/LocationData.h"
#include "Data/Equipment/SpecialData.h"

// View
#include "View/Common/Penalty.h"
#include "View/Common/Requirement.h"
#include "View/Stats/Attribute.h"
#include "View/Stats/Disease.h"
#include "View/Stats/Specialization.h"
#include "View/Stats/Feature.h"
#include "View/Stats/Origin.h"
#include "View/Stats/OtherSkill.h"
#include "View/Stats/Profession.h"
#include "View/Stats/Reputation.h"
#include "View/Stats/Skill.h"
#include "View/Stats/Skillpack.h"
#include "View/Stats/Symptom.h"
#include "View/Stats/Trick.h"
#include "View/Stats/Experience.h"
#include "View/Stats/Wound.h"
#include "View/Equipment/ArmorFeature.h"
#include "View/Equipment/DexterityBonus.h"
#include "View/Equipment/Durability.h"
#include "View/Equipment/Item.h"
#include "View/Equipment/ItemStats.h"
#include "View/Equipment/Location.h"
#include "View/Equipment/Special.h"
#include "View/Notes/Question.h"

#include "View/Pages/Page.h"
#include "View/Pages/Stats.h"
#include "View/Pages/Equipment.h"
#include "View/Pages/Notes.h"
#include "View/Card.h"

#include "Edit/Pages/StatsEditor.h"
#include "Edit/Stats/AttributeEdit.h"
#include "Edit/Stats/SkillpackEdit.h"
#include "Edit/Stats/SkillEdit.h"
#include "Edit/Stats/OtherSkillEdit.h"
#include "Edit/Stats/ExperienceEditor.h"

// Managers
#include "Managers/MainManager.h"
#include "Managers/CardManager.h"
#include "Managers/SettingsManager.h"

void registerMetaTypes() {
    qRegisterMetaType<StatsData*>();
    qRegisterMetaType<ExperienceData*>();
}

void registerQmlTypes() {
    qRegisterMetaType<Page::Type>("NSPage::Type");

    qmlRegisterType<Penalty>("core.view.NSPenalty", 1, 0, "NSPenalty");
    qmlRegisterType<Requirement>("core.view.NSRequirement", 1, 0, "NSRequirement");
    qmlRegisterType<Attribute>("core.view.NSAttribute", 1, 0, "NSAttribute");
    qmlRegisterType<Disease>("core.view.NSDisease", 1, 0, "NSDisease");
    qmlRegisterType<Specialization>("core.view.NSSpecialization", 1, 0, "NSSpecialization");
    qmlRegisterType<Feature>("core.view.NSFeature", 1, 0, "NSFeature");
    qmlRegisterType<Origin>("core.view.NSOrigin", 1, 0, "NSOrigin");
    qmlRegisterType<OtherSkill>("core.view.NSOtherSkill", 1, 0, "NSOtherSkill");
    qmlRegisterType<Profession>("core.view.NSProfession", 1, 0, "NSProfession");
    qmlRegisterType<Reputation>("core.view.NSReputation", 1, 0, "NSReputation");
    qmlRegisterType<Skill>("core.view.NSSkill", 1, 0, "NSSkill");
    qmlRegisterType<Skillpack>("core.view.NSSkillpack", 1, 0, "NSSkillpack");
    qmlRegisterType<Symptom>("core.view.NSSymptom", 1, 0, "NSSymptom");
    qmlRegisterType<Trick>("core.view.NSTrick", 1, 0, "NSTrick");
    qmlRegisterType<Wound>("core.view.NSWound", 1, 0, "NSWound");
    qmlRegisterType<Experience>("core.view.NSExperience", 1, 0, "NSExperience");

    qmlRegisterType<ArmorFeature>("core.view.NSArmorFeature", 1, 0, "NSArmorFeature");
    qmlRegisterType<DexterityBonus>("core.view.NSDexterityBonus", 1, 0, "NSDexterityBonus");
    qmlRegisterType<Durability>("core.view.NSDurability", 1, 0, "NSDurability");
    qmlRegisterType<Item>("core.view.NSItem", 1, 0, "NSItem");
    qmlRegisterType<ItemStats>("core.view.NSItemStats", 1, 0, "NSItemStats");
    qmlRegisterType<Location>("core.view.NSLocation", 1, 0, "NSLocation");
    qmlRegisterType<Special>("core.view.NSSpecial", 1, 0, "NSSpecial");

    qmlRegisterType<Question>("core.view.NSQuestion", 1, 0, "NSQuestion");

    qmlRegisterType<Page>("core.view.NSPage", 1, 0, "NSPage");
    qmlRegisterType<Stats>("core.view.NSStats", 1, 0, "NSStats");
    qmlRegisterType<Equipment>("core.view.NSEquipment", 1, 0, "NSEquipment");
    qmlRegisterType<Notes>("core.view.NSNotes", 1, 0, "NSNotes");
    qmlRegisterType<Card>("core.view.NSCard", 1, 0, "NSCard");

    qmlRegisterType<StatsEditor>("core.edit.NSStatsEditor", 1, 0, "NSStatsEditor");
    qmlRegisterType<AttributeEdit>("core.edit.NSAttributeEdit", 1, 0, "NSAttributeEdit");
    qmlRegisterType<SkillpackEdit>("core.edit.NSSkillpackEdit", 1, 0, "NSSkillpackEdit");
    qmlRegisterType<SkillEdit>("core.edit.NSSkillEdit", 1, 0, "NSSkillEdit");
    qmlRegisterType<OtherSkillEdit>("core.edit.NSOtherSkillEdit", 1, 0, "NSOtherSkillEdit");
    qmlRegisterType<ExperienceEditor>("core.edit.NSExperienceEditor", 1, 0, "NSExperienceEditor");

    qmlRegisterType<MainManager>("core.managers.NSMainManager", 1, 0, "NSMainManager");
    qmlRegisterType<CardManager>("core.managers.NSCardManager", 1, 0, "NSCardManager");
    qmlRegisterType<SettingsManager>("core.managers.NSSettingsManager", 1, 0, "NSSettingsManager");
}

#endif // REGISTEREDCORETYPES_H
