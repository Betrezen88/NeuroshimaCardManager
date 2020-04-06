#include "CardBuilder.h"

#include "Card/CardData.h"
#include "Card/Pages/StatsData.h"
#include "Card/Elements/Stats/PersonalData.h"
#include "Card/Elements/Stats/OriginData.h"
#include "Card/Elements/Stats/ProfessionData.h"
#include "Card/Elements/Stats/SpecializationData.h"
#include "Card/Elements/Stats/DiseaseData.h"
#include "Card/Elements/Stats/FeatureData.h"

CardBuilder::CardBuilder(QObject *parent) : QObject(parent)
{

}

CardData *CardBuilder::build(const QJsonObject &json)
{
    CardData *pCard = new CardData();

    pCard->setStats( stats(json.value("stats").toObject()) );

    return pCard;
}

StatsData *CardBuilder::stats(const QJsonObject &stats)
{
    StatsData *pStats = new StatsData();

    pStats->setPersonal( personal(stats.value("personal").toObject()) );

    return pStats;
}

PersonalData *CardBuilder::personal(const QJsonObject &personal)
{
    PersonalData *pPersonal = new PersonalData();

    const QJsonObject &name = personal.value("name").toObject();
    pPersonal->setName( name.value("name").toString() );
    pPersonal->setNickname( name.value("nickname").toString() );
    pPersonal->setSurname( name.value("surname").toString() );

    const QJsonObject &origin = personal.value("origin").toObject();
    pPersonal->setOrigin( new OriginData(origin.value("name").toString(),
                                     origin.value("description").toString()) );

    const QJsonObject &profession = personal.value("profession").toObject();
    pPersonal->setProfession( new ProfessionData(profession.value("name").toString(),
                                             profession.value("description").toString()) );

    const QJsonObject &specialization = personal.value("specialization").toObject();
    pPersonal->setSpecialization( new SpecializationData(specialization.value("name").toString(),
                                                     specialization.value("description").toString()) );

    const QJsonObject &disease = personal.value("disease").toObject();
    pPersonal->setDisease( new DiseaseData(disease.value("name").toString(),
                                       disease.value("description").toString()) );

    const QJsonObject &features = personal.value("features").toObject();
    const QJsonObject &originFeature = features.value("origin").toObject();
    pPersonal->setOriginFeature( new FeatureData(originFeature.value("name").toString(),
                                                 originFeature.value("description").toString()) );

    const QJsonObject &professionFeature = features.value("profession").toObject();
    pPersonal->setProfessionFeature( new FeatureData(professionFeature.value("name").toString(),
                                                     professionFeature.value("description").toString()) );

    return pPersonal;
}
