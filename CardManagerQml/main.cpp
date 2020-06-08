﻿#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"

#include "cpp/Creators/Data/HeroCreatorData.h"
#include "cpp/Creators/Data/Origin.h"
#include "cpp/Creators/Data/Feature.h"

#include "Managers/MainManager.h"
#include "Managers/CardManager.h"

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

    qmlRegisterType<HeroCreatorData>("cpp", 1, 0, "HeroCreatorData");
    qmlRegisterType<Origin>("cpp", 1, 0, "Origin");
    qmlRegisterType<Feature>("cpp", 1, 0, "Feature");

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
