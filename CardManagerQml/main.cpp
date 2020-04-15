#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"

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

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

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

    QGuiApplication app(argc, argv);

    DataReader reader;
    CardWrapper *pCard = new CardWrapper(reader.loadCard("c:/Users/Michał/Documents/!NsHeroes/Nick 'Happy' Sax.json"), &app);

    QQmlApplicationEngine engine;

    engine.rootContext()->setContextProperty("pCardData", pCard);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
