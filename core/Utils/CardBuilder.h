#ifndef CARDBUILDER_H
#define CARDBUILDER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QMap>

#include "core_global.h"

class CardData;
class StatsData;
class PersonalData;
class AttributeData;
class OtherSkillData;
class TrickData;

class CORE_EXPORT CardBuilder : public QObject
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
    QList<OtherSkillData *> otherSkills(const QJsonArray &otherSkills);
    QList<TrickData *> tricks(const QJsonArray &tricks);
};

#endif // CARDBUILDER_H
