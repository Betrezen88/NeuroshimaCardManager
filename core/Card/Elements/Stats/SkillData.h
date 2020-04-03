#ifndef SKILL_H
#define SKILL_H

#include <QString>

#include "core_global.h"

class CORE_EXPORT SkillData
{
public:
    SkillData();

    QString name() const;
    int value() const;

    void setName(const QString &name);
    void setValue(const int &value);

private:
    QString m_name;
    int m_value{0};
};

#endif // SKILL_H
