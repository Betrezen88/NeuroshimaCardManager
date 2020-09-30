#ifndef TRICKVALIDATOR_H
#define TRICKVALIDATOR_H

#include <QObject>

#include "core_global.h"

class Trick;
class Requirement;
class StatsCreator;

class CORE_EXPORT TrickValidator : public QObject
{
    Q_OBJECT
public:
    explicit TrickValidator(QObject *parent = nullptr);

    Q_INVOKABLE bool fulfillsRequirements(StatsCreator *stats,
                                          Trick *trick);

private:
    bool fullfilsOptional(StatsCreator *stats,
                          QVector<Requirement *> requirements);
};

#endif // TRICKVALIDATOR_H
