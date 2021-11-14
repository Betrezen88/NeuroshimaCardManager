#include "TricksEditModel.h"

#include "../Edit/Pages/StatsEditor.h"
#include "../Edit/Stats/TrickEdit.h"
#include "../Utils/DataReader.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QDebug>

TricksEditModel::TricksEditModel(QObject *parent) : QObject(parent)
{
    connect( this, &TricksEditModel::sourceFileChanged,
             this, &TricksEditModel::loadTricks );
}

const QString &TricksEditModel::sourceFile() const
{
    return m_sourceFile;
}

void TricksEditModel::setSourceFile(const QString &newSourceFile)
{
    if (m_sourceFile == newSourceFile)
        return;
    m_sourceFile = newSourceFile;
    emit sourceFileChanged(m_sourceFile);
}

StatsEditor *TricksEditModel::stats() const
{
    return m_pStatsEditor;
}

void TricksEditModel::setStats(StatsEditor *newStats)
{
    if (m_pStatsEditor == newStats)
        return;
    m_pStatsEditor = newStats;
    emit statsChanged();
}

QQmlListProperty<TrickEdit> TricksEditModel::model()
{
    return QQmlListProperty<TrickEdit>(this, this,
                                       &TricksEditModel::modelCount,
                                       &TricksEditModel::modelItem);
}

int TricksEditModel::modelCount() const
{
    return m_model.count();
}

TrickEdit *TricksEditModel::modelItem(const int index) const
{
    if ( index < 0 || index > m_model.count() )
        return nullptr;

    return m_model.at(index);
}

void TricksEditModel::loadTricks(const QString &file)
{
    DataReader reader;
    std::tuple<bool, QJsonDocument, QString> data = reader.load(file);

    if ( !std::get<0>(data) ) {
        qDebug() << std::get<2>(data);
        return;
    }

    const QJsonArray json = std::get<1>(data).array();

    for ( const QJsonValue& tTrick : json ) {
        const QJsonObject& trick = tTrick.toObject();

        QVector<RequirementData> requirements;
        for ( const QJsonValue& tRequirement : trick.value("requirements").toArray() ) {
            const QJsonObject& requirement = tRequirement.toObject();
            RequirementData req;
            req.name = requirement.value("name").toString();
            req.optional = requirement.value("optional").toBool();
            req.value = requirement.value("value").toInt();
            req.type = requirement.value("type").toString();
            requirements.push_back( req );
        }

        m_model.push_back( new TrickEdit({.name = trick.value("name").toString(),
                             .description = trick.value("description").toString(),
                             .action = trick.value("action").toString(),
                             .requirements = requirements}, this) );
    }
}

int TricksEditModel::modelCount(QQmlListProperty<TrickEdit> *list)
{
    return reinterpret_cast<TricksEditModel*>(list->data)->modelCount();
}

TrickEdit *TricksEditModel::modelItem(QQmlListProperty<TrickEdit> *list, int index)
{
    return reinterpret_cast<TricksEditModel*>(list->data)->modelItem(index);
}
