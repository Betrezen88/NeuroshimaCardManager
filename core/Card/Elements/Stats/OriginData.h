#ifndef ORIGIN_H
#define ORIGIN_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT OriginData
{
public:
    OriginData(const QString &name,
               const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // ORIGIN_H
