#ifndef STATS_H
#define STATS_H

#include <QObject>

class StatsData;
class Personal;

class Stats : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Personal *personal READ personal CONSTANT)

public:
    Stats(QObject *parent = nullptr);
    explicit Stats(StatsData *statsData, QObject *parent = nullptr);

    Personal *personal() const;

private:
    StatsData *m_pStatsData{nullptr};
    Personal *m_pPersonal{nullptr};
};

#endif // STATS_H
