#ifndef CARD_H
#define CARD_H

#include <QObject>

class CardData;

class Stats;

class Card : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString fullname READ fullname CONSTANT)
    Q_PROPERTY(Stats *stats READ stats CONSTANT)

public:
    explicit Card(CardData *cardData, QObject *parent = nullptr);

    QString fullname();

    Stats *stats() const;

signals:

protected:
    Card(QObject *parent = nullptr);

private:
    CardData *m_pCardData{nullptr};
    Stats *m_pStats{nullptr};
};

#endif // CARD_H
