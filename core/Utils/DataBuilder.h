#ifndef DATABUILDER_H
#define DATABUILDER_H

#include <QObject>
#include <QJsonObject>

#include "../Data/Stats/StatsData.h"
#include "../Data/Equipment/EquipmentData.h"
#include "../Data/Notes/NotesData.h"

class DataBuilder : public QObject
{
    Q_OBJECT
public:
    explicit DataBuilder(QObject *parent = nullptr);

    StatsData statsData(const QJsonObject &json);
    EquipmentData equipmentData(const QJsonObject &json);
    NotesData notesData(const QJsonObject &json);

private:
    OriginData origin(const QJsonObject& json);
    ProfessionData profession(const QJsonObject& json);
    FeatureData feature(const QJsonObject& json);
    SpecializationData specialization(const QJsonObject& json);
    DiseaseData disease(const QJsonObject& json);
    SymptomData symptom(const QJsonObject& json);
    PenaltyData penalty(const QJsonObject& json);
    AttributeData attribute(const QJsonObject& json);
    SkillpackData skillpack(const QJsonObject& json);
    SkillData skill(const QJsonObject& json);
    OtherSkillData otherSkill(const QJsonObject& json);
    TrickData trick(const QJsonObject& json);
    WoundData wound(const QJsonObject& json);
    ReputationData reputation(const QJsonObject& json);
    RequirementData requirement(const QJsonObject& json);
    ExperienceData experience(const QJsonObject& json);

    ItemData item(const QJsonObject& json);
    ItemStatsData itemStats(const QJsonObject& json);
    LocationData location(const QJsonObject& json);
    ArmorFeatureData armorFeature(const QJsonObject& json);
    DurabilityData durability(const QJsonObject& json);
    DexterityBonusData bonus(const QJsonObject& json);
    SpecialData special(const QJsonObject& json);

    QuestionData question(const QJsonObject& json);
};

#endif // DATABUILDER_H
