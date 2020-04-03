#ifndef DISEASE_H
#define DISEASE_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT DiseaseData
{
public:
    DiseaseData(const QString &name,
            const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // DISEASE_H
