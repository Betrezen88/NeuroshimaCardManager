#ifndef REQUIREMENT_H
#define REQUIREMENT_H

#include <QObject>

#include "../../Data/Common/RequirementData.h"

#include "core_global.h"

class CORE_EXPORT Requirement : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(bool optional READ optional CONSTANT)
    Q_PROPERTY(QString type READ type CONSTANT)

public:
    explicit Requirement(QObject *parent = nullptr);
    explicit Requirement(RequirementData* data, QObject *parent = nullptr);

    const QString &name() const;
    int value() const;
    bool optional() const;
    const QString &type() const;

private:
    RequirementData* m_data{nullptr};
};

#endif // REQUIREMENT_H
