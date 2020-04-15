#ifndef SKILLPACKDATA_H
#define SKILLPACKDATA_H

#include <QString>
#include <QList>

#include "core_global.h"

class SkillData;

class CORE_EXPORT SkillpackData
{
public:
    SkillpackData(const QString name, const QStringList &specializations);

    QString name() const;
    QStringList specializations() const;
    QList<SkillData*> skills() const;

    bool hasSpecialization(const QString &specialization) const;
    bool hasSkill(const QString &name);

    void addSkill(SkillData *skill);

private:
    QString m_name;
    QStringList m_specializations;
    QList<SkillData*> m_skills;
};

#endif // SKILLPACKDATA_H
