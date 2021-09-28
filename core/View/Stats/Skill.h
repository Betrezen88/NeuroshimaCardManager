#ifndef SKILL_H
#define SKILL_H

#include <QObject>

#include "core_global.h"

class SkillData;

class CORE_EXPORT Skill : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)
    Q_PROPERTY(bool used READ used WRITE setUsed NOTIFY usedChanged)

public:
    explicit Skill(QObject *parent = nullptr);
    explicit Skill(SkillData* data, QObject *parent = nullptr);

    const QString &name() const;
    int value() const;
    bool used() const;
    void setUsed(bool newUsed);

signals:
    void usedChanged(const bool used);

protected:
    SkillData* m_data{nullptr};
};

#endif // SKILL_H
