#ifndef CORE_H
#define CORE_H

#include "core_global.h"

#include <QObject>

class Stats;

class CORE_EXPORT Card : public QObject
{
public:
    explicit Card(QObject *parent = nullptr);

    Stats *stats() const;

public slots:
    void setStats(Stats *stats);

private:
    Stats *m_stats{nullptr};
};

#endif // CORE_H
