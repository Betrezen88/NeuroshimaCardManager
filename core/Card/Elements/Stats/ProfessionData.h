#ifndef PROFESSION_H
#define PROFESSION_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT ProfessionData
{
public:
    ProfessionData(const QString &name,
                   const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // PROFESSION_H
