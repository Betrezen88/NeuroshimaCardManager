#ifndef SYMPTOM_H
#define SYMPTOM_H

#include "../../Data.h"

#include <QVector>
#include <QQmlListProperty>

#include "core_global.h"

class Penalty;

class CORE_EXPORT Symptom : public Data
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Penalty> penalties READ penalties CONSTANT)

public:
    Symptom(QObject *parent = nullptr);
    Symptom(const QString &name,
            const QString &description,
            const QVector<Penalty *> &penalties,
            QObject *parent = nullptr);

    QQmlListProperty<Penalty> penalties();
    Penalty *penalty(int) const;
    int penaltyCount() const;

private:
    static Penalty *penalty(QQmlListProperty<Penalty>*, int);
    static int penaltyCount(QQmlListProperty<Penalty>*);

private:
    QVector<Penalty*> m_penalties;
};

#endif // SYMPTOM_H
