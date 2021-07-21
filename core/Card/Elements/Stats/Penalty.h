#ifndef PENALTY_H
#define PENALTY_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Penalty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)

public:
    Penalty(QObject *parent = nullptr);
    Penalty(const QString &name,
            const int &value,
            const QString &type,
            QObject *parent = nullptr);

    QString type() const;
    QString name() const;
    int value() const;

private:
    QString m_type;
    QString m_name;
    int m_value{0};
};

#endif // PENALTY_H
