#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"

#include "cpp/Creators/Data/HeroCreatorData.h"
#include "cpp/Creators/Data/Origin.h"
#include "cpp/Creators/Data/Feature.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

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
