#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "Utils/DataReader.h"
#include "Utils/CardBuilder.h"

#include "RegisteredCoreTypes.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    registerQmlTypes();

    QGuiApplication app(argc, argv);

    app.setApplicationDisplayName("Neuroshima Card Manager");
    app.setApplicationName("NeuroshimaCardManager");
    app.setApplicationVersion("1.0");
    app.setOrganizationName("BetrezenSoftware");
    app.setOrganizationDomain("NeuroshimaCardManager.com");

    SettingsManager settingsMng{&app};
    MainManager manager{&app};

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
