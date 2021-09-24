#include "CardBuilder.h"

#include "DataBuilder.h"

#include "View/Card.h"
#include "View/Pages/Stats.h"
#include "View/Pages/Equipment.h"
#include "View/Pages/Notes.h"

#include <QJsonValue>

CardBuilder::CardBuilder(QObject *parent) : QObject(parent)
{

}

Card *CardBuilder::build(const QString &filePath, const QJsonObject &json)
{
    Card *pCard = new Card(filePath);
    DataBuilder builder;

    if ( json.contains("stats") )
        pCard->addPage( new Stats( builder.statsData(json.value("stats").toObject()),
                            pCard) );
    if ( json.contains("equipment") )
        pCard->addPage( new Equipment( builder.equipmentData(json.value("equipment").toObject()),
                                       pCard ) );
    if ( json.contains("notes") )
        pCard->addPage( new Notes( builder.notesData(json.value("notes").toObject()),
                                   pCard ) );

    return pCard;
}
