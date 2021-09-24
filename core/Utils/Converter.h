#ifndef CONVERTER_H
#define CONVERTER_H

#include <QJsonObject>

#include "../Data/Stats/StatsData.h"
#include "../Data/Equipment/EquipmentData.h"
#include "../Data/Notes/NotesData.h"

class Card;

class Converter
{
public:
    Converter();
    ~Converter() = default;

    QJsonObject toJson(const Card* card);

private:
    QJsonObject stats(const StatsData& data);
    QJsonObject origin(const OriginData& data);
    QJsonObject profession(const ProfessionData& data);
    QJsonObject feature(const FeatureData& data);
    QJsonObject specialization(const SpecializationData& data);
    QJsonObject disease(const DiseaseData& data);
    QJsonObject symptom(const SymptomData& data);
    QJsonObject penalty(const PenaltyData& data);
    QJsonObject reputation(const ReputationData& data);
    QJsonObject attribute(const AttributeData& data);
    QJsonObject skillpack(const SkillpackData& data);
    QJsonObject skill(const SkillData& data);
    QJsonObject otherSkill(const OtherSkillData& data);
    QJsonObject trick(const TrickData& data);
    QJsonObject requirement(const RequirementData& data);
    QJsonObject experience(const ExperienceData& data);

    QJsonObject equipment(const EquipmentData& data);
    QJsonObject item(const ItemData& data);
    QJsonObject itemStats(const ItemStatsData& data);
    QJsonObject location(const LocationData& data);
    QJsonObject armorFeature(const ArmorFeatureData& data);
    QJsonObject dexterityBonus(const DexterityBonusData& data);
    QJsonObject special(const SpecialData& data);

    QJsonObject notes(const NotesData& data);
    QJsonObject question(const QuestionData& data);
};

#endif // CONVERTER_H
