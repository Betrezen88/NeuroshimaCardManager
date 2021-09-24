#ifndef OTHERSKILL_H
#define OTHERSKILL_H

#include <QObject>

#include "Skill.h"
#include "../../Data/Stats/OtherSkillData.h"

#include "core_global.h"

class CORE_EXPORT OtherSkill : public Skill
{
    Q_OBJECT
    Q_PROPERTY(QString attribute READ attribute CONSTANT)
    Q_PROPERTY(QString attributeShort READ attributeShort CONSTANT)

public:
    explicit OtherSkill(QObject *parent = nullptr);
    explicit OtherSkill(OtherSkillData* data, QObject *parent = nullptr);

    const QString &attribute() const;
    QString attributeShort() const;

private:
    OtherSkillData* m_data{nullptr};
};

#endif // OTHERSKILL_H
