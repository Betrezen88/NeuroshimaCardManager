#ifndef REPUTATION_H
#define REPUTATION_H

#include <QObject>

#include "../../Data/Stats/ReputationData.h"

#include "core_global.h"

class CORE_EXPORT Reputation : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit Reputation(QObject *parent = nullptr);
    explicit Reputation(ReputationData* data, QObject *parent = nullptr);

    const QString &name() const;
    int value() const;

private:
    ReputationData* m_data{nullptr};
};

#endif // REPUTATION_H
