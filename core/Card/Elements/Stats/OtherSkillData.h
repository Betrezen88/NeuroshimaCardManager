#ifndef OTHERSKILLDATA_H
#define OTHERSKILLDATA_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT OtherSkillData
{
public:
    OtherSkillData(const QString &name, const int &value, const QString &attribute);

    QString name() const;
    int value() const;
    QString attribute() const;

private:
    QString m_name;
    int m_value{0};
    QString m_attribute;
};

#endif // OTHERSKILLDATA_H
