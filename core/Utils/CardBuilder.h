#ifndef CARDBUILDER_H
#define CARDBUILDER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>

#include "core_global.h"

class Card;
class Stats;
class Equipment;
class Rules;

class CORE_EXPORT CardBuilder : public QObject
{
    Q_OBJECT
public:
    explicit CardBuilder(QObject *parent = nullptr);

    Rules* rulesPage(const QJsonArray &rules);

public slots:
    Card *build(const QString &filePath, const QJsonObject &json);

private:
    Stats *statsPage(const QJsonObject &stats);
    Equipment *equipmentPage(const QJsonObject &equipment);
};

#endif // CARDBUILDER_H
