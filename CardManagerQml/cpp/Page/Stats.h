#ifndef STATS_H
#define STATS_H

#include <QObject>

class StatsData;

class Stats : public QObject
{
    Q_OBJECT
public:
    explicit Stats(StatsData *statsData, QObject *parent = nullptr);

private:
    StatsData *m_pStatsData{nullptr};
};

#endif // STATS_H
