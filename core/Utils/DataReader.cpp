#include "DataReader.h"

#include "CardBuilder.h"
#include "Card/Card.h"
#include "Card/Pages/Stats.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>

#include <QDebug>

DataReader::DataReader(QObject *parent) : QObject(parent)
{

}

Card *DataReader::loadCard(const QString &filePath)
{
    QFile file(filePath);

    if ( !file.exists() ) {
        qDebug() << "DataReader::open(): "+filePath;
        qDebug() << "File does not exist!";
        return nullptr;
    }

    if ( !file.open(QIODevice::ReadOnly) ) {
        qDebug() << "DataReader::open(): "+filePath;
        qDebug() << "Could not open file!";
        return nullptr;
    }

    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(), &error);

    if ( QJsonParseError::NoError != error.error ) {
        qDebug() << "DataReader::open(): "+filePath;
        qDebug() << "Error parsing json: " << error.errorString();
        qDebug() << "Offset: " << error.offset;
        return nullptr;
    }

    CardBuilder builder;

    return builder.build( json.object() );
}
