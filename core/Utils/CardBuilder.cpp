#include "CardBuilder.h"

#include "Card/Card.h"
#include "Card/Pages/Stats.h"
#include "Card/Elements/Stats/Personal.h"
#include "Card/Elements/Stats/Origin.h"
#include "Card/Elements/Stats/Profession.h"
#include "Card/Elements/Stats/Specialization.h"
#include "Card/Elements/Stats/Disease.h"

CardBuilder::CardBuilder(QObject *parent) : QObject(parent)
{

}

Card *CardBuilder::build(const QJsonObject &json)
{
    Card *pCard = new Card();

    pCard->setStats( stats(json.value("stats").toObject()) );

    return pCard;
}

Stats *CardBuilder::stats(const QJsonObject &stats)
{
    Stats *pStats = new Stats();

    pStats->setPersonal( personal(stats.value("personal").toObject()) );

    return pStats;
}

Personal *CardBuilder::personal(const QJsonObject &personal)
{
    Personal *pPersonal = new Personal();

    const QJsonObject &name = personal.value("name").toObject();
    pPersonal->setName( name.value("name").toString() );
    pPersonal->setNickname( name.value("nickname").toString() );
    pPersonal->setSurname( name.value("surname").toString() );

    const QJsonObject &origin = personal.value("origin").toObject();
    pPersonal->setOrigin( new Origin(origin.value("name").toString(),
                                     origin.value("description").toString()) );

    const QJsonObject &profession = personal.value("profession").toObject();
    pPersonal->setProfession( new Profession(profession.value("name").toString(),
                                             profession.value("description").toString()) );

    const QJsonObject &specialization = personal.value("specialization").toObject();
    pPersonal->setSpecialization( new Specialization(specialization.value("name").toString(),
                                                     specialization.value("description").toString()) );

    const QJsonObject &disease = personal.value("disease").toObject();
    pPersonal->setDisease( new Disease(disease.value("name").toString(),
                                       disease.value("description").toString()) );

    return pPersonal;
}
