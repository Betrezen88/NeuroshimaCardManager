#ifndef CARDDATA_H
#define CARDDATA_H

#include "core_global.h"

#include <QObject>

class StatsData;

class CORE_EXPORT CardData : public QObject
{
public:
    explicit CardData(QObject *parent = nullptr);

    StatsData *stats() const;

public slots:
    void setStats(StatsData *stats);

private:
    StatsData *m_stats{nullptr};
};

#endif // CARDDATA_H
