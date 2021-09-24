#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QObject>

#include "Data/Stats/SpecializationData.h"

#include "core_global.h"

class CORE_EXPORT Specialization : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Specialization(QObject *parent = nullptr);
    explicit Specialization(SpecializationData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;

private:
    SpecializationData* m_data{nullptr};
};

#endif // SPECIALIZATION_H
