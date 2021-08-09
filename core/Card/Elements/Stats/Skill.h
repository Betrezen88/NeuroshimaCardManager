#ifndef SKILL_H
#define SKILL_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Skill : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value NOTIFY valueChanged)
    Q_PROPERTY(bool used READ used WRITE setUsed NOTIFY usedChanged)

public:
    friend class SkillMod;
    friend class OtherSkillMod;

    explicit Skill(QObject *parent = nullptr);
    explicit Skill(const QString &name,
                   const int &value,
                   const bool &used = false,
                   QObject *parent = nullptr);

    QString name() const;
    int value() const;
    bool used() const;

public slots:
    void setUsed(bool used);

signals:
    void valueChanged(const int& value);
    void usedChanged(const bool& used);

private:
    QString m_name;
    int m_value;
    bool m_used;
};

#endif // SKILL_H
