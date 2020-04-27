﻿#include "DataReader.h"

#include "CardBuilder.h"
#include "Card/CardData.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>

#include <QDebug>

DataReader::DataReader(QObject *parent) : QObject(parent)
{

}

std::tuple<bool, QJsonObject, QString> DataReader::load(const QString &filePath)
{
    QFile file(filePath);
    QString errorStr;

    if ( !file.exists() ) {
        errorStr = "Plik nie istnieje: "+filePath;
        return std::make_tuple(false, QJsonObject(), errorStr);
    }

    if ( !file.open(QIODevice::ReadOnly) ) {
        errorStr = "Nie można otworzyć pliku: "+filePath;
        return std::make_tuple(false, QJsonObject(), errorStr);
    }

    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(), &error);

    if ( QJsonParseError::NoError != error.error ) {
        errorStr = "Błąd parsowania pliku: "+filePath +
                "\n"+error.errorString()+"\nOffset:" + error.offset;
        return std::make_tuple(false, QJsonObject(), errorStr);
    }

    return std::make_tuple(true, json.object(), filePath);
}

CardData *DataReader::loadCard(const QString &filePath)
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
