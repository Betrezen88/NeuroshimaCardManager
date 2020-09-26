#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Requirement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(bool optional READ optional CONSTANT)
    Q_PROPERTY(Type type READ type CONSTANT)

public:
    enum class Type { ATTRIBUTE, SKILL, PROFESSION };
    Q_ENUM(Type)

    explicit Requirement(QObject *parent = nullptr);
    explicit Requirement(const QString &name,
                         const int &value,
                         const bool &optional,
                         Type type,
                         QObject *parent = nullptr);

    QString name() const;
    int value() const;
    bool optional() const;
    Type type() const;

private:
    QString m_name;
    int m_value;
    bool m_optional;
    Type m_type;
};

#endif // REQUIREMENT_H
