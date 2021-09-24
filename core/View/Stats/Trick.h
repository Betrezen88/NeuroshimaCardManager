#ifndef TRICK_H
#define TRICK_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/TrickData.h"

#include "core_global.h"

class Requirement;

class CORE_EXPORT Trick : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString action READ action CONSTANT)
    Q_PROPERTY(QQmlListProperty<Requirement> requirements READ requirements CONSTANT)

public:
    explicit Trick(QObject *parent = nullptr);
    explicit Trick(TrickData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;
    const QString &action() const;
    QQmlListProperty<Requirement> requirements();
    int requirementCount() const;
    Requirement* requirement(const int index) const;

private:
    static int requirementCount(QQmlListProperty<Requirement> *list);
    static Requirement* requirement(QQmlListProperty<Requirement> *list, int index);

private:
    TrickData* m_data{nullptr};
    QVector<Requirement*> m_requirements;
};

#endif // TRICK_H
