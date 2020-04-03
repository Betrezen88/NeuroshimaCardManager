#ifndef FEATUREDATA_H
#define FEATUREDATA_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT FeatureData
{
public:
    FeatureData();

    QString name() const;
    QString description() const;

    void setName(const QString &name);
    void setDescription(const QString &description);

private:
    QString m_name;
    QString m_description;
};

#endif // FEATUREDATA_H
