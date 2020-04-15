#ifndef CARDBUILDER_H
#define CARDBUILDER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>

class CardData;
class StatsData;
class PersonalData;
class AttributeData;

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
    QList<AttributeData *> attributes(const QJsonArray &attributes);
};

#endif // CARDBUILDER_H
