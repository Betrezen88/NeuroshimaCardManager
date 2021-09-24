#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/SymptomData.h"

#include "core_global.h"

class Penalty;

class CORE_EXPORT Symptom : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QQmlListProperty<Penalty> penalties READ penalties CONSTANT)

public:
    explicit Symptom(QObject *parent = nullptr);
    explicit Symptom(SymptomData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;
    QQmlListProperty<Penalty> penalties();
    int penaltyCount() const;
    Penalty* penalty(const int index) const;

private:
    static int penaltyCount(QQmlListProperty<Penalty> *list);
    static Penalty* penalty(QQmlListProperty<Penalty> *list, int index);

private:
    SymptomData* m_data{nullptr};
    QVector<Penalty*> m_penalties;
};

#endif // SYMPTOM_H
