#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"

#include "cpp/MainManager.h"
#include "cpp/CardManager.h"
#include "cpp/Creators/HeroCreatorManager.h"

#include "cpp/Creators/Data/HeroCreatorData.h"
#include "cpp/Creators/Data/Origin.h"
#include "cpp/Creators/Data/Feature.h"

#include "cpp/Card/CardWrapper.h"
#include "cpp/Page/StatsWrapper.h"
#include "cpp/Section/PersonalWrapper.h"
#include "cpp/Element/DiseaseWrapper.h"
#include "cpp/Element/OriginWrapper.h"
#include "cpp/Element/ProfessionWrapper.h"
#include "cpp/Element/SpecializationWrapper.h"
#include "cpp/Element/FeatureWrapper.h"
#include "cpp/Element/AttributeWrapper.h"
#include "cpp/Element/SkillpackWrapper.h"
#include "cpp/Element/SkillWrapper.h"
#include "cpp/Element/OtherSkillWrapper.h"
#include "cpp/Element/TrickWrapper.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<HeroCreatorData>("cpp", 1, 0, "HeroCreatorData");
    qmlRegisterType<Origin>("cpp", 1, 0, "Origin");
    qmlRegisterType<Feature>("cpp", 1, 0, "Feature");
    qmlRegisterType<MainManager>("cpp", 1, 0, "MainManager");
    qmlRegisterType<HeroCreatorManager>("cpp", 1, 0, "HeroCreatorManager");
    qmlRegisterType<CardManager>("cpp", 1, 0, "CardManager");
    qmlRegisterType<CardWrapper>("cpp", 1, 0, "CardWrapper");
    qmlRegisterType<StatsWrapper>("cpp", 1, 0, "StatsWrapper");
    qmlRegisterType<PersonalWrapper>("cpp", 1, 0, "PersonalWrapper");
    qmlRegisterType<DiseaseWrapper>("cpp", 1, 0, "DiseaseWrapper");
    qmlRegisterType<OriginWrapper>("cpp", 1, 0, "OriginWrapper");
    qmlRegisterType<ProfessionWrapper>("cpp", 1, 0, "ProfessionWrapper");
    qmlRegisterType<SpecializationWrapper>("cpp", 1, 0, "SpecializationWrapper");
    qmlRegisterType<FeatureWrapper>("cpp", 1, 0, "FeatureWrapper");
    qmlRegisterType<AttributeWrapper>("cpp", 1, 0, "AttributeWrapper");
    qmlRegisterType<SkillpackWrapper>("cpp", 1, 0, "SkillpackWrapper");
    qmlRegisterType<SkillWrapper>("cpp", 1, 0, "SkillWrapper");
    qmlRegisterType<OtherSkillWrapper>("cpp", 1, 0, "OtherSkillWrapper");
    qmlRegisterType<TrickWrapper>("cpp", 1, 0, "TrickWrapper");

    QGuiApplication app(argc, argv);

    MainManager manager;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("manager", &manager);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
