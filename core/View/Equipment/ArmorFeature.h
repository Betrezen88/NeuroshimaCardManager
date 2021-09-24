#ifndef ARMORFEATURE_H
#define ARMORFEATURE_H

#include <QObject>

#include "../../Data/Equipment/ArmorFeatureData.h"

#include "core_global.h"

class CORE_EXPORT ArmorFeature : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit ArmorFeature(QObject *parent = nullptr);
    explicit ArmorFeature(ArmorFeatureData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;

private:
    ArmorFeatureData* m_data{nullptr};
};

#endif // ARMORFEATURE_H
