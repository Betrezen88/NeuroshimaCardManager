#include "Disease.h"

Disease::Disease(QObject *parent)
    : Data("", "", parent)
{

}

Disease::Disease(const QString &name,
                 const QString &description,
                 const QString &cure,
                 const QVector<Symptom*> &symptoms,
                 QObject *parent)
    : Data(name, description, parent),
      m_cure(cure),
      m_symptoms(symptoms)
{

}

QString Disease::cure() const
{
    return m_cure;
}

QQmlListProperty<Symptom> Disease::symptoms()
{
    return QQmlListProperty<Symptom>(this, this,
                                     &Disease::symptomsCount,
                                     &Disease::symptom);
}

Symptom *Disease::symptom(int index) const
{
    return m_symptoms.at(index);
}

int Disease::symptomsCount() const
{
    return m_symptoms.count();
}

Symptom *Disease::symptom(QQmlListProperty<Symptom> *list, int index)
{
    return reinterpret_cast<Disease*>(list->data)->symptom(index);
}

int Disease::symptomsCount(QQmlListProperty<Symptom> *list)
{
    return reinterpret_cast<Disease*>(list->data)->symptomsCount();
}
