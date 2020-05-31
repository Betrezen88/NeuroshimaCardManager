#include "HeroCreatorData.h"

#include "Utils/DataReader.h"

#include "Origin.h"
#include "Feature.h"

#include <QDebug>

#include <QJsonArray>
#include <QJsonDocument>

HeroCreatorData::HeroCreatorData(QObject *parent) : QObject(parent)
{
    qDebug() << "HeroCreatorData constructed.";
    DataReader reader;

    std::tuple<bool, QJsonDocument, QString> ret =
            reader.load(":/json/resources/json/Origins.json");

    if ( std::get<0>(ret) ) {
        for ( const QJsonValue origin: std::get<1>(ret).array() ) {
            const QJsonObject &tOrigin = origin.toObject();
            const QJsonObject &tBonus = tOrigin.value("bonus").toObject();
            Origin *pOrigin = new Origin(tOrigin.value("name").toString(),
                                         tOrigin.value("description").toString(),
                                         tBonus.value("name").toString(),
                                         tBonus.value("value").toInt(),
                                         tOrigin.value("image").toString());

            for ( const QJsonValue feature: tOrigin.value("features").toArray() ) {
                const QJsonObject &tFeature = feature.toObject();
                Feature *pFeature = new Feature( tFeature.value("name").toString(),
                                                 tFeature.value("description").toString(),
                                                 pOrigin);
                pOrigin->appendFeature(pFeature);
            }
            appendOrigin(pOrigin);
        }
    }
    else {
        emit errorMessage(std::get<2>(ret));
    }
}

QQmlListProperty<Origin> HeroCreatorData::origins()
{
    return QQmlListProperty<Origin>(this, this,
                                    &HeroCreatorData::appendOrigin,
                                    &HeroCreatorData::originsCount,
                                    &HeroCreatorData::origin,
                                    &HeroCreatorData::clearOrigins);
}

void HeroCreatorData::appendOrigin(Origin *origin)
{
    m_origins.push_back(origin);
    emit originsChanged();
}

int HeroCreatorData::originsCount() const
{
    return m_origins.count();
}

Origin *HeroCreatorData::origin(int index) const
{
    return m_origins.at(index);
}

void HeroCreatorData::clearOrigins()
{
    m_origins.clear();
    emit originsChanged();
}

void HeroCreatorData::appendOrigin(QQmlListProperty<Origin> *list, Origin *origin)
{
    reinterpret_cast<HeroCreatorData*>(list->data)->appendOrigin(origin);
}

int HeroCreatorData::originsCount(QQmlListProperty<Origin> *list)
{
    return reinterpret_cast<HeroCreatorData*>(list->data)->originsCount();
}

Origin *HeroCreatorData::origin(QQmlListProperty<Origin> *list, int index)
{
    return reinterpret_cast<HeroCreatorData*>(list->data)->origin(index);
}

void HeroCreatorData::clearOrigins(QQmlListProperty<Origin> *list)
{
    reinterpret_cast<HeroCreatorData*>(list->data)->clearOrigins();
}
