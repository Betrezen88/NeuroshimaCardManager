#ifndef CORE_H
#define CORE_H

#include "core_global.h"

#include <QString>

class StatsData;

class CORE_EXPORT CardData
{
public:
    CardData();

    StatsData *stats() const;

    void setStats(StatsData *stats);

private:
    StatsData *m_stats{nullptr};
};

#endif // CORE_H
