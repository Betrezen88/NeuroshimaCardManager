#ifndef NSTRICK_H
#define NSTRICK_H

#include "Card/Data.h"

#include <QQmlListProperty>

class Requirement;

class NSTrick : public Data
{
    Q_OBJECT
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<Requirement> requirements READ requirements CONSTANT)

public:
    explicit NSTrick(QObject *parent = nullptr);
    explicit NSTrick(const QString &name,
                     const QString &description,
                     const QString &action,
                     QVector<Requirement*> &requirements,
                     QObject *parent = nullptr);

    QString action() const;

    QQmlListProperty<Requirement> requirements();
    int requirementsCount() const;
    Requirement* requirement(const int &index) const;

private:
    static int requirementsCount(QQmlListProperty<Requirement> *list);
    static Requirement* requirement(QQmlListProperty<Requirement> *list, int index);

private:
    QString m_action;
    QVector<Requirement*> m_requirements;
};

#endif // NSTRICK_H
