#ifndef CARDWRAPPER_H
#define CARDWRAPPER_H

#include <QObject>

class CardData;
class StatsWrapper;

class CardWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(StatsWrapper* stats READ stats CONSTANT)
public:
    explicit CardWrapper(QObject *parent = nullptr);
    explicit CardWrapper(CardData *cardData, QObject *parent = nullptr);

    StatsWrapper* stats() const;

private:
    CardData *m_pCardData{nullptr};
    StatsWrapper *m_pStatsWrapper{nullptr};
};

#endif // CARDWRAPPER_H
