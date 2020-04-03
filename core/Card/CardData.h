#ifndef CARDDATA_H
#define CARDDATA_H

#include "core_global.h"

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

#endif // CARDDATA_H
