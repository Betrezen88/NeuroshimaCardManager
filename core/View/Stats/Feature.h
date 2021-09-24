#ifndef FEATURE_H
#define FEATURE_H

#include <QObject>

#include "../../Data/Stats/FeatureData.h"

#include "core_global.h"

class CORE_EXPORT Feature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit Feature(QObject *parent = nullptr);
    explicit Feature(FeatureData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;

private:
    FeatureData* m_data{nullptr};
};

#endif // FEATURE_H
