#ifndef STATSWRAPPER_H
#define STATSWRAPPER_H

#include <QObject>

class StatsData;
class PersonalWrapper;

class StatsWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PersonalWrapper *personal READ personal CONSTANT)
public:
    explicit StatsWrapper(QObject *parent = nullptr);
    explicit StatsWrapper(StatsData *statsData, QObject *parent = nullptr);

    PersonalWrapper *personal() const;

private:
    StatsData *m_pStatsData{nullptr};
    PersonalWrapper *m_pPersonalWrapper{nullptr};
};

#endif // STATSWRAPPER_H
