#ifndef PENALTY_H
#define PENALTY_H

#include <QObject>

#include "../../Data/Common/PenaltyData.h"

#include "core_global.h"

class CORE_EXPORT Penalty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)

public:
    explicit Penalty(QObject *parent = nullptr);
    explicit Penalty(PenaltyData* data, QObject *parent = nullptr);

    const QString &name() const;
    int value() const;
    const QString &type() const;

private:
    PenaltyData* m_data;
};

#endif // PENALTY_H
