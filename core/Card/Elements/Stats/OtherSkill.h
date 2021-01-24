#ifndef OTHERSKILL_H
#define OTHERSKILL_H

#include "Skill.h"

#include "core_global.h"

class CORE_EXPORT OtherSkill : public Skill
{
    Q_OBJECT
    Q_PROPERTY(QString attribute READ attribute CONSTANT)

public:
    OtherSkill(QObject *parent = nullptr);
    OtherSkill(const QString &name,
               const int &value,
               const bool &used,
               const QString &attribute,
               QObject *parent = nullptr);

    QString attribute() const;

private:
    QString m_attribute;
};

#endif // OTHERSKILL_H
