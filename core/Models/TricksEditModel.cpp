#include "TricksEditModel.h"

#include "../Edit/Pages/StatsEditor.h"
#include "../Edit/Stats/TrickEdit.h"
#include "../Utils/DataReader.h"
#include "../Validators/TrickValidator.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonValue>

#include <QDebug>

TricksEditModel::TricksEditModel(QObject *parent) : QObject(parent)
{
    connect( this, &TricksEditModel::sourceFileChanged,
             this, &TricksEditModel::loadTricks );
    connect( this, &TricksEditModel::statsChanged,
             this, &TricksEditModel::validateTricks );
    connect( this, &TricksEditModel::onlyAvailableChanged,
             this, &TricksEditModel::showAvailable );
    connect( this, &TricksEditModel::ascendingChanged,
             this, &TricksEditModel::sort );
    connect( this, &TricksEditModel::patternChanged,
             this, &TricksEditModel::filter );
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

void TricksEditModel::init(StatsEditor *statsEditor, const QString &sourceFile)
{
    m_pStatsEditor = statsEditor;
    m_sourceFile = sourceFile;

    loadTricks( m_sourceFile );
    validateTricks();
}

void TricksEditModel::showAvailable(const bool available)
{
    m_model.clear();

    for ( TrickEdit* trick : qAsConst(m_fullModel) ) {
        if ( m_pStatsEditor && !m_pStatsEditor->hasTrick(trick->name()) ) {
            if ( available ) {
                if ( trick->meetsRequirements() )
                    m_model.push_back( trick );
            }
            else {
                m_model.push_back( trick );
            }
        }
    }
    sort( m_ascending );
}

void TricksEditModel::filter(const QString &pattern)
{
    m_model.clear();

    for ( TrickEdit* trick : m_fullModel ) {
        if ( m_onlyAvailable && trick->meetsRequirements()
            && trick->name().toUpper().contains(pattern.toUpper()) ) {
                 m_model.push_back( trick );
        }
        else {
            if ( trick->name().toUpper().contains(pattern.toUpper()) )
                m_model.push_back( trick );
        }
    }
    emit modelChanged();
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

        m_fullModel.push_back( new TrickEdit({.name = trick.value("name").toString(),
                                .description = trick.value("description").toString(),
                                .action = trick.value("action").toString(),
                                .requirements = requirements}, this) );
    }
    showAvailable( m_onlyAvailable );
}

void TricksEditModel::validateTricks()
{
    if ( !m_pStatsEditor )
        return;

    TrickValidator validator(m_pStatsEditor, this);
    for ( TrickEdit* trick : m_fullModel )
        trick->setMeetsRequirements( validator.trickMeetsRequirements(trick) );
}

void TricksEditModel::sort(const bool ascending)
{
    std::sort(m_model.begin(), m_model.end(), [&ascending](const TrickEdit* first, const TrickEdit* second){
        if ( ascending )
            return first->name() < second->name();
        return first->name() > second->name();
    });
    emit modelChanged();
}

int TricksEditModel::modelCount(QQmlListProperty<TrickEdit> *list)
{
    return reinterpret_cast<TricksEditModel*>(list->data)->modelCount();
}

TrickEdit *TricksEditModel::modelItem(QQmlListProperty<TrickEdit> *list, int index)
{
    return reinterpret_cast<TricksEditModel*>(list->data)->modelItem(index);
}

bool TricksEditModel::ascending() const
{
    return m_ascending;
}

void TricksEditModel::setAscending(bool newAscending)
{
    if (m_ascending == newAscending)
        return;
    m_ascending = newAscending;
    emit ascendingChanged( m_ascending );
}

const QString &TricksEditModel::pattern() const
{
    return m_pattern;
}

void TricksEditModel::setPattern(const QString &newPattern)
{
    if (m_pattern == newPattern)
        return;
    m_pattern = newPattern;
    emit patternChanged( m_pattern );
}

bool TricksEditModel::onlyAvailable() const
{
    return m_onlyAvailable;
}

void TricksEditModel::setOnlyAvailable(bool newOnlyAvailable)
{
    if (m_onlyAvailable == newOnlyAvailable)
        return;
    m_onlyAvailable = newOnlyAvailable;
    emit onlyAvailableChanged( m_onlyAvailable );
}
