#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"

#include "Managers/MainManager.h"
#include "Managers/CardManager.h"

#include "Creators/CardCreator.h"
#include "Creators/PageCreator.h"

#include "DataSources/DataSource.h"
#include "DataSources/StatsSource.h"

#include "DataSources/Elements/Stats/HeroData.h"
#include "DataSources/Elements/Stats/Origin.h"
#include "DataSources/Elements/Stats/Profession.h"
#include "DataSources/Elements/Stats/Feature.h"

#include "Card/Data.h"
#include "Card/Card.h"
#include "Card/Pages/Stats.h"
#include "Card/Elements/Stats/Attribute.h"
#include "Card/Elements/Stats/Disease.h"
#include "Card/Elements/Stats/OtherSkill.h"
#include "Card/Elements/Stats/Penalty.h"
#include "Card/Elements/Stats/Skillpack.h"
#include "Card/Elements/Stats/Skill.h"
#include "Card/Elements/Stats/Symptom.h"
#include "Card/Elements/Stats/Trick.h"

#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qmlRegisterType<MainManager>("core", 1, 0, "NSMainManager");
    qmlRegisterType<CardManager>("core", 1, 0, "NSCardManager");
    qmlRegisterType<CardCreator>("core", 1, 0, "NSCardCreator");
    qmlRegisterType<PageCreator>("core", 1, 0, "NSPageCreator");
    qRegisterMetaType<PageCreator::Type>("NSPageCreator::Type");
    qmlRegisterType<DataSource>("core", 1, 0, "NSDataSource");
    qmlRegisterType<StatsSource>("core.NSStatsSource", 1, 0, "NSStatsSource");
    qRegisterMetaType<DataSource::Type>("NSDataSource::Type");
    qmlRegisterType<HeroData>("core.NSHeroData", 1, 0, "NSHeroData");
    qmlRegisterType<Origin>("core.NSOrigin", 1, 0, "NSOrigin");
    qmlRegisterType<Profession>("core.NSProfession", 1, 0, "NSProfession");
    qmlRegisterType<Feature>("core.NSFeature", 1, 0, "NSFeature");
    qmlRegisterType<Data>("core", 1, 0, "NSData");
    qmlRegisterType<Card>("core", 1, 0, "NSCard");
    qRegisterMetaType<Page::Type>("Page::Type");
    qmlRegisterType<Page>("core", 1, 0, "NSPage");
    qmlRegisterType<Stats>("core", 1, 0, "NSStats");
    qmlRegisterType<Attribute>("core", 1, 0, "NSAttribute");
    qmlRegisterType<Disease>("core", 1, 0, "NSDisease");
    qmlRegisterType<OtherSkill>("core", 1, 0, "NSOtherSkill");
    qmlRegisterType<Penalty>("core", 1, 0, "NSPenalty");
    qmlRegisterType<Skillpack>("core", 1, 0, "NSSkillpack");
    qmlRegisterType<Skill>("core", 1, 0, "NSSkill");
    qmlRegisterType<Symptom>("core", 1, 0, "NSSymptom");
    qmlRegisterType<Trick>("core", 1, 0, "NSTrick");

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
