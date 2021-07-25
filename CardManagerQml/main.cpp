#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"

#include "Managers/MainManager.h"
#include "Managers/CardManager.h"
#include "Managers/CreationPointsManager.h"
#include "Managers/SettingsManager.h"

#include "Creators/CardCreator.h"
#include "Creators/PageCreator.h"
#include "Creators/StatsCreator.h"

#include "DataSources/DataSource.h"
#include "DataSources/StatsSource.h"

#include "DataSources/Elements/Stats/HeroData.h"
#include "DataSources/Elements/Stats/Origin.h"
#include "DataSources/Elements/Stats/OriginBonus.h"
#include "DataSources/Elements/Stats/Profession.h"
#include "DataSources/Elements/Stats/Feature.h"
#include "DataSources/Elements/Stats/Bonus.h"
#include "DataSources/Elements/Stats/Requirement.h"
#include "DataSources/Elements/Stats/AttributeMod.h"
#include "DataSources/Elements/Stats/SkillMod.h"
#include "DataSources/Elements/Stats/SkillpackMod.h"
#include "DataSources/Elements/Stats/TricksSortFilterModel.h"

#include "Card/Data.h"
#include "Card/Card.h"
#include "Card/Pages/Stats.h"
#include "Card/Pages/Equipment.h"
#include "Card/Pages/Rules.h"
#include "Card/Elements/Stats/Attribute.h"
#include "Card/Elements/Stats/Disease.h"
#include "Card/Elements/Stats/Difficulty.h"
#include "Card/Elements/Stats/OtherSkill.h"
#include "Card/Elements/Stats/Penalty.h"
#include "Card/Elements/Stats/Skillpack.h"
#include "Card/Elements/Stats/Skill.h"
#include "Card/Elements/Stats/Symptom.h"
#include "Card/Elements/Stats/Trick.h"
#include "Card/Elements/Stats/Wound.h"
#include "Card/Elements/Equipment/Item.h"
#include "Card/Elements/Equipment/DexterityBonus.h"
#include "Card/Elements/Equipment/Durability.h"
#include "Card/Elements/Equipment/Location.h"
#include "Card/Elements/Rules/RulesSection.h"

#include "Validators/TrickValidator.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    qRegisterMetaType<PageCreator::Type>("NSPageCreator::Type");
    qRegisterMetaType<DataSource::Type>("NSDataSource::Type");
    qRegisterMetaType<Bonus::Type>("NSBonus::Type");
    qRegisterMetaType<Page::Type>("Page::Type");
    qRegisterMetaType<Skillpack::Type>("NSSkillpack::Type");

    qmlRegisterType<MainManager>("core.NSMainManager", 1, 0, "NSMainManager");
    qmlRegisterType<CardManager>("core.NSCardManager", 1, 0, "NSCardManager");
    qmlRegisterType<CardCreator>("core.NSCardCreator", 1, 0, "NSCardCreator");
    qmlRegisterType<CardCreator>("core.NSSettingsManager", 1, 0, "NSSettingsManager");
    qmlRegisterType<CreationPointsManager>("core.NSCreationPointsManager",
                                           1, 0, "NSCreationPointsManager");
    qmlRegisterType<PageCreator>("core.NSPageCreator", 1, 0, "NSPageCreator");
    qmlRegisterType<StatsCreator>("core.NSStatsCreator", 1, 0, "NSStatsCreator");
    qmlRegisterType<DataSource>("core.NSDataSource", 1, 0, "NSDataSource");
    qmlRegisterType<StatsSource>("core.NSStatsSource", 1, 0, "NSStatsSource");
    qmlRegisterType<HeroData>("core.NSHeroData", 1, 0, "NSHeroData");
    qmlRegisterType<Origin>("core.NSOrigin", 1, 0, "NSOrigin");
    qmlRegisterType<OriginBonus>("core.NSOriginBonus", 1, 0, "NSOriginBonus");
    qmlRegisterType<Profession>("core.NSProfession", 1, 0, "NSProfession");
    qmlRegisterType<Feature>("core.NSFeature", 1, 0, "NSFeature");
    qmlRegisterType<Bonus>("core.NSBonus", 1, 0, "NSBonus");
    qmlRegisterType<Requirement>("core.NSRequirement", 1, 0, "NSRequirement");
    qmlRegisterType<AttributeMod>("core.NSAttributeMod", 1, 0, "NSAttributeMod");
    qmlRegisterType<SkillpackMod>("core.NSSkillpackMod", 1, 0, "NSSkillpackMod");
    qmlRegisterType<SkillMod>("core.NSSkillMod", 1, 0, "NSSkillMod");
    qmlRegisterType<TricksSortFilterModel>("core.NSTricksSortFilterModel",
                                           1, 0, "NSTricksSortFilterModel");
    qmlRegisterType<Data>("core.NSData", 1, 0, "NSData");
    qmlRegisterType<Card>("core.NSCard", 1, 0, "NSCard");
    qmlRegisterType<Page>("core.NSPage", 1, 0, "NSPage");
    qmlRegisterType<Stats>("core.NSStats", 1, 0, "NSStats");
    qmlRegisterType<Equipment>("core.NSEquipment", 1, 0, "NSEquipment");
    qmlRegisterType<Rules>("core.NSRules", 1, 0, "NSRules");
    qmlRegisterType<Attribute>("core.NSAttribute", 1, 0, "NSAttribute");
    qmlRegisterType<Disease>("core.NSDisease", 1, 0, "NSDisease");
    qmlRegisterType<Difficulty>("core.NSDifficulty", 1, 0, "NSDifficulty");
    qmlRegisterType<OtherSkill>("core.NSOtherSkill", 1, 0, "NSOtherSkill");
    qmlRegisterType<Penalty>("core.NSPenalty", 1, 0, "NSPenalty");
    qmlRegisterType<Skillpack>("core.NSSkillpack", 1, 0, "NSSkillpack");
    qmlRegisterType<Skill>("core.NSSkill", 1, 0, "NSSkill");
    qmlRegisterType<Symptom>("core.NSSymptom", 1, 0, "NSSymptom");
    qmlRegisterType<Trick>("core.NSTrick", 1, 0, "NSTrick");
    qmlRegisterType<Wound>("core.NSWound", 1, 0, "NSWound");
    qmlRegisterType<TrickValidator>("core.NSTrickValidator",
                                    1, 0, "NSTrickValidator");
    qmlRegisterType<Item>("core.NSItem", 1, 0, "NSItem");
    qmlRegisterType<DexterityBonus>("core.NSDexterityBonus", 1, 0, "NSDexterityBonus");
    qmlRegisterType<Durability>("core.NSDurability", 1, 0, "NSDurability");
    qmlRegisterType<Location>("core.NSLocation", 1, 0, "NSLocation");
    qmlRegisterType<RulesSection>("core.NSRulesSection", 1, 0, "NSRulesSection");

    QGuiApplication app(argc, argv);

    app.setApplicationDisplayName("Neuroshima Card Manager");
    app.setApplicationName("NeuroshimaCardManager");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("BetrezenSoftware");
    app.setOrganizationDomain("NeuroshimaCardManager.com");

    SettingsManager settingsMng{&app};
    MainManager manager;

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("manager", &manager);
    engine.rootContext()->setContextProperty("appSettings", &settingsMng);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
