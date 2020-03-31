#ifndef CARDBUILDER_H
#define CARDBUILDER_H

#include <QObject>
#include <QJsonObject>

class Card;
class Stats;
class Personal;

class CardBuilder : public QObject
{
    Q_OBJECT
public:
    explicit CardBuilder(QObject *parent = nullptr);

signals:

public slots:
    Card *build(const QJsonObject &json);

private:
    Stats *stats(const QJsonObject &stats);
    Personal *personal(const QJsonObject &personal);
};

#endif // CARDBUILDER_H
