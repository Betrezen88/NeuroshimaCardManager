#ifndef CARDBUILDER_H
#define CARDBUILDER_H

#include <QObject>
#include <QJsonObject>

class CardData;
class StatsData;
class PersonalData;

class CardBuilder : public QObject
{
    Q_OBJECT
public:
    explicit CardBuilder(QObject *parent = nullptr);

signals:

public slots:
    CardData *build(const QJsonObject &json);

private:
    StatsData *stats(const QJsonObject &stats);
    PersonalData *personal(const QJsonObject &personal);
};

#endif // CARDBUILDER_H
