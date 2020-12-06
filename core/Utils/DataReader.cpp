#include "DataReader.h"

#include "CardBuilder.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonValue>
#include <QJsonParseError>

#include <QDebug>

DataReader::DataReader(QObject *parent) : QObject(parent)
{

}

std::tuple<bool, QJsonDocument, QString> DataReader::load(const QString &filePath)
{
    std::tuple<bool, QString> fileData = readFile(filePath);

    if (!std::get<0>(fileData)) {
        return std::make_tuple(false, QJsonDocument(), std::get<1>(fileData));
    }

    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(std::get<1>(fileData).toUtf8(), &error);

    if ( QJsonParseError::NoError != error.error ) {
        return std::make_tuple(false, QJsonDocument(),
                               "Błąd parsowania pliku: "+filePath +
                                "\n"+error.errorString()+"\nOffset:" + error.offset);
    }

    return std::make_tuple(true, json, filePath);
}

std::tuple<bool, QString> DataReader::readFile(const QString &filePath)
{
    if ( filePath.isEmpty() )
        return std::make_tuple(false, "Błąd pliku: "+filePath);

    QFile file(filePath);

    if ( !file.exists() ) {
        return std::make_tuple(false, "Plik nie istnieje: "+filePath);
    }

    if ( !file.open(QIODevice::ReadOnly) ) {
        return std::make_tuple(false, "Nie można otworzyć pliku: "+filePath);
    }

    return std::make_tuple(true, file.readAll());
}
