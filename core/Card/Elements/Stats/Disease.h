#ifndef DISEASE_H
#define DISEASE_H

#include "../../Data.h"

#include <QVector>
#include <QQmlListProperty>

#include "core_global.h"

class Symptom;

class CORE_EXPORT Disease : public Data
{
    Q_OBJECT
    Q_PROPERTY(QString cure READ cure CONSTANT)
    Q_PROPERTY(QQmlListProperty<Symptom> symptoms READ symptoms CONSTANT)

public:
    explicit Disease(QObject *parent = nullptr);
    explicit Disease(const QString &name,
                     const QString &description,
                     const QString &cure,
                     const QVector<Symptom*> &symptoms,
                     QObject *parent = nullptr);

    QString cure() const;
    QQmlListProperty<Symptom> symptoms();
    Symptom *symptom(int) const;
    int symptomsCount() const;

    QVector<Symptom*> symptoms() const;

private:
    static Symptom *symptom(QQmlListProperty<Symptom>*, int);
    static int symptomsCount(QQmlListProperty<Symptom>*);

private:
    QString m_cure;
    QVector<Symptom*> m_symptoms;
};

#endif // DISEASE_H
