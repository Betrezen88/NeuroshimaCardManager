#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "cpp/Card/Card.h"
#include "cpp/Page/Stats.h"
#include "cpp/Element/Personal.h"

#include "Utils/DataReader.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    qmlRegisterType<Card>("cpp.card", 1, 0, "CppCard");
    qmlRegisterType<Stats>("cpp.card", 1, 0, "CppStats");
    qmlRegisterType<Personal>("cpp.card", 1, 0, "CppPersonal");

    DataReader reader;
    Card *pCard = new Card( reader.loadCard("c:/Users/Michał/Documents/!NsHeroes/Nick 'Happy' Sax.json") );

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("pCard", pCard);

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
