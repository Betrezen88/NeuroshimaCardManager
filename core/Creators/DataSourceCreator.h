#ifndef DATASOURCECREATOR_H
#define DATASOURCECREATOR_H

#include <QObject>
#include <QJsonDocument>

#include "../DataSources/Elements/Stats/HeroData.h"
#include "../DataSources/Elements/Stats/Bonus.h"

#include "../DataSources/DataSource.h"

class DataSource;
class StatsSource;

class DataSourceCreator : public QObject
{
    Q_OBJECT
public:
    explicit DataSourceCreator(QObject *parent = nullptr);

    DataSource* create(const DataSource::Type &type);

    StatsSource* stats();

    void addOrigins(StatsSource* source, const QString &dataFile);
    void addProfessions(StatsSource* source, const QString &dataFile);
    void addFeatures(HeroData* heroData, const QJsonArray &features);
    void addSpecializations(StatsSource* source, const QString &dataFile);
    void addDiseases(StatsSource* source, const QString &dataFile);

private:
    QJsonDocument loadData(const QString &dataFile);
    Bonus::Type bonusType(const QString &type);
};

#endif // DATASOURCECREATOR_H
