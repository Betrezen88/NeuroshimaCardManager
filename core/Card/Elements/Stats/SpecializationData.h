#ifndef SPECIALIZATION_H
#define SPECIALIZATION_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT SpecializationData
{
public:
    SpecializationData(const QString &name,
                       const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SPECIALIZATIONDATA_H
