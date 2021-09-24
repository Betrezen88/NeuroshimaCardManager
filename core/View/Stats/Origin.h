#ifndef ORIGIN_H
#define ORIGIN_H

#include <QObject>

#include "../../Data/Stats/OriginData.h"

#include "core_global.h"

class Feature;

class CORE_EXPORT Origin : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(Feature* feature READ feature CONSTANT)

public:
    explicit Origin(QObject *parent = nullptr);
    explicit Origin(OriginData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;

    Feature *feature() const;

private:
    OriginData* m_data{nullptr};
    Feature* m_pFeature{nullptr};
};

#endif // ORIGIN_H
