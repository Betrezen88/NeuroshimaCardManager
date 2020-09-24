#ifndef TRICK_H
#define TRICK_H

#include "../../Data.h"

#include "core_global.h"

#include <QQmlListProperty>

class Requirement;

class CORE_EXPORT Trick : public Data
{
    Q_OBJECT
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<Requirement> requirements READ requirements CONSTANT)
public:
    explicit Trick(QObject *parent = nullptr);
    explicit Trick(const QString &name,
                   const QString &description,
                   const QString &action,
                   QObject *parent = nullptr);
    explicit Trick(const QString &name,
                   const QString &description,
                   const QString &action,
                   QVector<Requirement*> &requirements,
                   QObject *parent = nullptr);

    QString action() const;

    QQmlListProperty<Requirement> requirements();
    int requirementsCount() const;
    Requirement* requirement(const int &index) const;

    Q_INVOKABLE bool hasRequirements() const;

private:
    static int requirementsCount(QQmlListProperty<Requirement> *list);
    static Requirement* requirement(QQmlListProperty<Requirement> *list, int index);

private:
    QString m_action;
    QVector<Requirement*> m_requirements;
};

#endif // TRICK_H
