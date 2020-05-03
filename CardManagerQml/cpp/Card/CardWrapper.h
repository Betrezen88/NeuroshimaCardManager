#ifndef CARDWRAPPER_H
#define CARDWRAPPER_H

#include <QObject>

class CardData;
class StatsWrapper;

class CardWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(StatsWrapper* stats READ stats CONSTANT)
    Q_PROPERTY(QString filePath READ filePath CONSTANT)
public:
    explicit CardWrapper(QObject *parent = nullptr);
    explicit CardWrapper(const QString &filePath, CardData *cardData, QObject *parent = nullptr);

    StatsWrapper* stats() const;

    QString filePath() const;

private:
    QString m_filePath;
    CardData *m_pCardData{nullptr};
    StatsWrapper *m_pStatsWrapper{nullptr};
};

#endif // CARDWRAPPER_H
