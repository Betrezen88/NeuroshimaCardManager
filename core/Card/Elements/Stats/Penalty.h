#ifndef PENALTY_H
#define PENALTY_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Penalty : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(Type type READ type CONSTANT)

public:
    enum class Type { ATTRIBUTE, TEST };
    Q_ENUM(Type)

    Penalty(QObject *parent = nullptr);
    Penalty(const QString &name,
            const int &value,
            const Type &type,
            QObject *parent = nullptr);

    Type type() const;
    QString name() const;
    int value() const;

private:
    Type m_type;
    QString m_name;
    int m_value{0};
};

#endif // PENALTY_H
