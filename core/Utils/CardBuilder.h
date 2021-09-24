#ifndef CARDBUILDER_H
#define CARDBUILDER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>

#include "core_global.h"

class Card;
class Stats;
class Equipment;
class Notes;
class Rules;

class CORE_EXPORT CardBuilder : public QObject
{
    Q_OBJECT
public:
    explicit CardBuilder(QObject *parent = nullptr);

public slots:
    Card *build(const QString &filePath, const QJsonObject &json);

private:
};

#endif // CARDBUILDER_H
