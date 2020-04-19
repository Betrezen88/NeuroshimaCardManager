#ifndef TRICK_H
#define TRICK_H

#include <QString>
#include <QMap>

#include "core_global.h"

class CORE_EXPORT TrickData
{
public:
    TrickData(const QString &name, const QString &description, const QString &action);

    QString name() const;
    QString description() const;
    QString action() const;

private:
    QString m_name;
    QString m_description;
    QString m_action;

    QMap<QString, int> m_attributes;
    QMap<QString, int> m_skills;
    QMap<QString, int> m_orSkills;
};

#endif // TRICK_H
