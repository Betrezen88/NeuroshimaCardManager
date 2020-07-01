#include "DataSourceCreator.h"

#include "../DataSources/StatsSource.h"

#include "../DataSources/Elements/Stats/Origin.h"
#include "../DataSources/Elements/Stats/OriginBonus.h"
#include "../DataSources/Elements/Stats/Profession.h"
#include "../DataSources/Elements/Stats/Feature.h"

#include "../Card/Elements/Stats/Attribute.h"
#include "../Card/Elements/Stats/Skillpack.h"
#include "../Card/Elements/Stats/Skill.h"
#include "../Card/Elements/Stats/Disease.h"
#include "../Card/Elements/Stats/Symptom.h"

#include "../Utils/DataReader.h"

#include <QJsonArray>

#include <QDebug>

DataSourceCreator::DataSourceCreator(QObject *parent) : QObject(parent)
{

}

DataSource *DataSourceCreator::create(const DataSource::Type &type, const QVariantMap &dataFiles)
{
    switch (type) {
    case DataSource::Type::STATS:
    {
        StatsSource *pStatsSource = new StatsSource();

        addOrigins(pStatsSource, dataFiles.value("origins").toString());
        addProfessions(pStatsSource, dataFiles.value("professions").toString());
        addAttributes(pStatsSource, dataFiles.value("attributes").toString());
        addSpecializations(pStatsSource, dataFiles.value("specializations").toString());
        addDiseases(pStatsSource, dataFiles.value("diseases").toString());

        return pStatsSource;
        break;
    }
    case DataSource::Type::NOTES:
        return nullptr;
        break;
    case DataSource::Type::EQUIPMENT:
        return nullptr;
        break;
    case DataSource::Type::BEAST:
        return nullptr;
        break;
    case DataSource::Type::FRIEND:
        return nullptr;
        break;
    case DataSource::Type::MACHINE:
        return nullptr;
        break;
    case DataSource::Type::VEHICLE:
        return nullptr;
        break;
    default:
        return nullptr;
    }
}

void DataSourceCreator::addOrigins(StatsSource *source, const QString &dataFile)
{
    for ( const QJsonValue &origin: loadData(dataFile).array() ) {
        const QJsonObject &tOrigin = origin.toObject();
        const QJsonObject &tBonus = tOrigin.value("bonus").toObject();

        QStringList attributes;
        for ( const QJsonValue &attribute: tBonus.value("name").toArray() ) {
            attributes.append(attribute.toString());
        }

        OriginBonus* pBonus = new OriginBonus(attributes,
                                              tBonus.value("value").toInt());

        Origin* pOrigin = new Origin(tOrigin.value("name").toString(),
                                     tOrigin.value("description").toString(),
                                     tOrigin.value("image").toString(),
                                     pBonus);

        addFeatures(pOrigin, tOrigin.value("features").toArray());

        source->addOrigin(pOrigin);
    }
}

void DataSourceCreator::addProfessions(StatsSource *source, const QString &dataFile)
{
    for ( const QJsonValue &professions: loadData(dataFile).array() ) {
        const QJsonObject &tProfession = professions.toObject();

        Profession* pProfession = new Profession(tProfession.value("name").toString(),
                                                 tProfession.value("description").toString(),
                                                 tProfession.value("picture").toString(),
                                                 tProfession.value("quote").toString());

        addFeatures(pProfession, tProfession.value("features").toArray());

        source->addProfession(pProfession);
    }
}

void DataSourceCreator::addFeatures(HeroData *heroData, const QJsonArray &features)
{
    for ( const QJsonValue &feature: features ) {
        const QJsonObject &tFeature = feature.toObject();

        Bonus* pBonus = nullptr;
        if ( tFeature.contains("bonus") ) {
            const QJsonObject &tFeatureBonus = tFeature.value("bonus").toObject();
            const QString &name = (tFeatureBonus.contains("name"))
                    ? tFeatureBonus.value("name").toString() : "";
            const int &value = (tFeatureBonus.contains("value"))
                    ? tFeatureBonus.value("value").toInt() : 0;
            const int &price = (tFeatureBonus.contains("price"))
                    ? tFeatureBonus.value("price").toInt() : 0;
            QStringList list;
            if ( tFeatureBonus.contains("list") ) {
                for ( const QJsonValue &element: tFeatureBonus.value("list").toArray() ) {
                    list << element.toString();
                }
            }

            pBonus = new Bonus(bonusType(tFeatureBonus.value("type").toString()),
                              name, value, price, list);
        }

        Feature* pFeature = new Feature(tFeature.value("name").toString(),
                                        tFeature.value("description").toString(),
                                        pBonus);
        heroData->addFeature(pFeature);
    }
}

void DataSourceCreator::addSpecializations(StatsSource *source, const QString &dataFile)
{
    for ( const QJsonValue &specialization: loadData(dataFile).array() ) {
        const QJsonObject &tSpec = specialization.toObject();

        Data* pSpecialization = new Data(tSpec.value("name").toString(),
                                         tSpec.value("description").toString());
        source->addSpecialization(pSpecialization);
    }
}

void DataSourceCreator::addDiseases(StatsSource *source, const QString &dataFile)
{
    for ( const QJsonValue &disease: loadData(dataFile).array() ) {
        const QJsonObject &tDisease = disease.toObject();

        QVector<Symptom*> symptoms;
        for ( const QJsonValue &symptom: tDisease.value("symptoms").toArray() ) {
            const QJsonObject &tSymptom = symptom.toObject();

            QVector<Penalty*> penalties;
            for ( const QJsonValue &penalty: tSymptom.value("penalties").toArray() ) {
                const QJsonObject &tPenalty = penalty.toObject();
                const QString &type = tPenalty.value("type").toString();

                penalties.push_back( new Penalty(tPenalty.value("name").toString(),
                                                tPenalty.value("value").toInt(),
                                                penaltyType(type)) );
            }

            symptoms.push_back( new Symptom(tSymptom.value("name").toString(),
                                            tSymptom.value("description").toString(),
                                            penalties) );
        }

        source->addDisease( new Disease(tDisease.value("name").toString(),
                                        tDisease.value("description").toString(),
                                        tDisease.value("cure").toString(),
                                        symptoms) );
    }
}

void DataSourceCreator::addAttributes(StatsSource *source, const QString &dataFile)
{
    for ( const QJsonValue &attribute: loadData(dataFile).array() ) {
        const QJsonObject &tAttribute = attribute.toObject();

        QVector<Skillpack*> skillpacks;
        for ( const QJsonValue &skillpack: tAttribute.value("skillpacks").toArray() ) {
            const QJsonObject &tSkillpack = skillpack.toObject();

            QStringList specs;
            for ( const QJsonValue &specialization: tSkillpack.value("specializations").toArray() ) {
                specs << specialization.toString();
            }

            QVector<Skill*> skills;
            for ( const QJsonValue &skill: tSkillpack.value("skills").toArray() ) {
                const QJsonObject &tSkill = skill.toObject();

                skills.push_back(new Skill(tSkill.value("name").toString(), 0));
            }

            skillpacks.push_back( new Skillpack(tSkillpack.value("name").toString(),
                                                specs,
                                                skills) );
        }

        source->addAttribute( new Attribute(tAttribute.value("name").toString(),
                                            0,
                                            skillpacks) );
    }
}

QJsonDocument DataSourceCreator::loadData(const QString &dataFile)
{
    DataReader reader;
    std::tuple<bool, QJsonDocument, QString> data = reader.load(dataFile);

    if ( !std::get<0>(data) ) {
        qDebug() << std::get<2>(data);
        return QJsonDocument();
    }

    return std::get<1>(data);
}

Bonus::Type DataSourceCreator::bonusType(const QString &type)
{
    if ( "Skillpack" == type ) {
        return Bonus::Type::SKILLPACK;
    }
    if ( "Pet" == type ) {
        return Bonus::Type::PET;
    }
    if ( "Fame" == type ) {
        return Bonus::Type::FAME;
    }
    if ( "Totem" == type ) {
        return Bonus::Type::TOTEM;
    }
    if ( "Trick" == type ) {
        return Bonus::Type::TRICK;
    }
    if ( "Health" == type ) {
        return Bonus::Type::HEALTH;
    }
    if ( "Skills" == type ) {
        return Bonus::Type::SKILLS;
    }
    if ( "Feature" == type ) {
        return Bonus::Type::FEATURE;
    }
    if ( "Reputation" == type ) {
        return Bonus::Type::REPUTATION;
    }
    if ( "Connections" == type ) {
        return Bonus::Type::CONNECTIONS;
    }
    if ( "Skillpoints" == type ) {
        return Bonus::Type::SKILLPOINTS;
    }
    if ( "SkillpackPT" == type ) {
        return Bonus::Type::SKILLPACKPT;
    }
    return Bonus::Type::SKILLPACK;
}

Penalty::Type DataSourceCreator::penaltyType(const QString &type)
{
    if ( "Attribute" == type ) {
        return Penalty::Type::ATTRIBUTE;
    }
    else {
        return Penalty::Type::TEST;
    }
}
