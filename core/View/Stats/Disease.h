#ifndef DISEASE_H
#define DISEASE_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/DiseaseData.h"

#include "core_global.h"

class Symptom;

class CORE_EXPORT Disease : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)
    Q_PROPERTY(QString cure READ cure CONSTANT)
    Q_PROPERTY(QQmlListProperty<Symptom> symptoms READ symptoms CONSTANT)

public:
    explicit Disease(QObject *parent = nullptr);
    explicit Disease(DiseaseData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QString &description() const;
    const QString &cure() const;
    QQmlListProperty<Symptom> symptoms();
    int symptomCount() const;
    Symptom* symptom(const int index) const;

private:
    static int symptomCount(QQmlListProperty<Symptom> *list);
    static Symptom* symptom(QQmlListProperty<Symptom> *list, int index);

private:
    DiseaseData* m_data{nullptr};
    QVector<Symptom*> m_symptoms;
};

#endif // DISEASE_H
