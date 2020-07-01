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
#include "DataSources/Elements/Stats/OriginBonus.h"
#include "DataSources/Elements/Stats/Profession.h"
#include "DataSources/Elements/Stats/Feature.h"
#include "DataSources/Elements/Stats/Bonus.h"

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

    qmlRegisterType<MainManager>("core.NSMainManager", 1, 0, "NSMainManager");
    qmlRegisterType<CardManager>("core.NSCardManager", 1, 0, "NSCardManager");
    qmlRegisterType<CardCreator>("core.NSCardCreator", 1, 0, "NSCardCreator");
    qmlRegisterType<PageCreator>("core.NSPageCreator", 1, 0, "NSPageCreator");
    qRegisterMetaType<PageCreator::Type>("NSPageCreator::Type");
    qmlRegisterType<DataSource>("core.NSDataSource", 1, 0, "NSDataSource");
    qmlRegisterType<StatsSource>("core.NSStatsSource", 1, 0, "NSStatsSource");
    qRegisterMetaType<DataSource::Type>("NSDataSource::Type");
    qmlRegisterType<HeroData>("core.NSHeroData", 1, 0, "NSHeroData");
    qmlRegisterType<Origin>("core.NSOrigin", 1, 0, "NSOrigin");
    qmlRegisterType<OriginBonus>("core.NSOriginBonus", 1, 0, "NSOriginBonus");
    qmlRegisterType<Profession>("core.NSProfession", 1, 0, "NSProfession");
    qmlRegisterType<Feature>("core.NSFeature", 1, 0, "NSFeature");
    qmlRegisterType<Bonus>("core.NSBonus", 1, 0, "NSBonus");
    qRegisterMetaType<Bonus::Type>("NSBonus::Type");
    qmlRegisterType<Data>("core.NSData", 1, 0, "NSData");
    qmlRegisterType<Card>("core.NSCard", 1, 0, "NSCard");
    qRegisterMetaType<Page::Type>("Page::Type");
    qmlRegisterType<Page>("core.NSPage", 1, 0, "NSPage");
    qmlRegisterType<Stats>("core.NSStats", 1, 0, "NSStats");
    qmlRegisterType<Attribute>("core.NSAttribute", 1, 0, "NSAttribute");
    qmlRegisterType<Disease>("core.NSDisease", 1, 0, "NSDisease");
    qmlRegisterType<OtherSkill>("core.NSOtherSkill", 1, 0, "NSOtherSkill");
    qmlRegisterType<Penalty>("core.NSPenalty", 1, 0, "NSPenalty");
    qRegisterMetaType<Page::Type>("Penalty::Type");
    qmlRegisterType<Skillpack>("core.NSSkillpack", 1, 0, "NSSkillpack");
    qmlRegisterType<Skill>("core.NSSkill", 1, 0, "NSSkill");
    qmlRegisterType<Symptom>("core.NSSymptom", 1, 0, "NSSymptom");
    qmlRegisterType<Trick>("core.NSTrick", 1, 0, "NSTrick");

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
