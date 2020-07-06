#ifndef DATASOURCECREATOR_H
#define DATASOURCECREATOR_H

#include <QObject>
#include <QJsonDocument>

#include "../DataSources/Elements/Stats/HeroData.h"
#include "../DataSources/Elements/Stats/Bonus.h"

#include "../Card/Elements/Stats/Penalty.h"

#include "../DataSources/DataSource.h"

class DataSource;
class StatsSource;

class DataSourceCreator : public QObject
{
    Q_OBJECT

public:
    explicit DataSourceCreator(QObject *parent = nullptr);

    Q_INVOKABLE DataSource* create(const DataSource::Type &type, const QVariantMap &dataFiles);

    void addOrigins(StatsSource* source, const QString &dataFile);
    void addProfessions(StatsSource* source, const QString &dataFile);
    void addFeatures(HeroData* heroData, const QJsonArray &features);
    void addSpecializations(StatsSource* source, const QString &dataFile);
    void addDiseases(StatsSource* source, const QString &dataFile);
    void addAttributes(StatsSource* source, const QString &dataFile);
    void addDifficulty(StatsSource* source, const QString &dataFile);

private:
    QJsonDocument loadData(const QString &dataFile);
    Bonus::Type bonusType(const QString &type);
    Penalty::Type penaltyType(const QString &type);
};

#endif // DATASOURCECREATOR_H
