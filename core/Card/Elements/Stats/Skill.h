﻿#ifndef SKILL_H
#define SKILL_H

#include <QObject>

#include "core_global.h"

class CORE_EXPORT Skill : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(int value READ value CONSTANT)

public:
    explicit Skill(QObject *parent = nullptr);
    explicit Skill(const QString &name,
                   const int &value,
                   QObject *parent = nullptr);

    QString name() const;
    int value() const;

private:
    QString m_name;
    int m_value;
};

#endif // SKILL_H
