﻿#ifndef SKILLPACKDATA_H
#define SKILLPACKDATA_H

#include <QObject>
#include <QMap>

#include "core_global.h"

class SkillData;

class CORE_EXPORT SkillpackData
{
public:
    SkillpackData();

    QString name() const;
    QStringList specializations() const;
    QMap<QString, SkillData*> skills() const;

    bool hasSpecialization(const QString &specialization) const;
    bool hasSkill(const QString &name);

    void setName(const QString &name);
    void setSpecializations(const QStringList &specializations);
    void setSkills(const QMap<QString, SkillData*> &skills);

private:
    QString m_name;
    QStringList m_specializations;
    QMap<QString, SkillData*> m_skills;
};

#endif // SKILLPACKDATA_H
