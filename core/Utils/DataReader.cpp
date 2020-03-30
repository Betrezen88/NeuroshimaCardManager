#include "DataReader.h"

#include "Card/Personal.h"
#include "Card/Origin.h"
#include "Card/Profession.h"
#include "Card/Specialization.h"
#include "Card/Specialization.h"
#include "Card/Disease.h"

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

void DataReader::open(const QString &filePath)
{
    QFile file(filePath);

    if ( !file.exists() ) {
        qDebug() << "DataReader::open(): "+filePath;
        qDebug() << "File does not exist!";
    }

    if ( !file.open(QIODevice::ReadOnly) ) {
        qDebug() << "DataReader::open(): "+filePath;
        qDebug() << "Could not open file!";
        return;
    }

    QJsonParseError error;
    QJsonDocument json = QJsonDocument::fromJson(file.readAll(), &error);

    if ( QJsonParseError::NoError != error.error ) {
        qDebug() << "DataReader::open(): "+filePath;
        qDebug() << "Error parsing json: " << error.errorString();
        qDebug() << "Offset: " << error.offset;
        return;
    }
}

Personal *DataReader::personal(const QJsonObject &data)
{
    Personal *pPersonal = new Personal();

    const QJsonObject &name = data.value("name").toObject();
    pPersonal->setName( name.value("name").toString() );
    pPersonal->setNickname( name.value("nickname").toString() );
    pPersonal->setSurname( name.value("surname").toString() );

    const QJsonObject &origin = data.value("origin").toObject();
    pPersonal->setOrigin( new Origin(origin.value("name").toString(),
                                     origin.value("description").toString()) );

    const QJsonObject &profession = data.value("profession").toObject();
    pPersonal->setProfession( new Profession(profession.value("name").toString(),
                                             profession.value("description").toString()) );

    const QJsonObject &specialization = data.value("specialization").toObject();
    pPersonal->setSpecialization( new Specialization(specialization.value("name").toString(),
                                                     specialization.value("description").toString()) );

    const QJsonObject &disease = data.value("disease").toObject();
    pPersonal->setDisease( new Disease(disease.value("name").toString(),
                                       disease.value("description").toString()) );

    return pPersonal;
}
