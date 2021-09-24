#include "Disease.h"
#include "Symptom.h"

Disease::Disease(QObject *parent) : QObject(parent)
{

}

Disease::Disease(DiseaseData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    for ( SymptomData& symptom : m_data->symptoms )
        m_symptoms.append( new Symptom(&symptom, this) );
}

const QString &Disease::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Disease::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}

const QString &Disease::cure() const
{
    if ( m_data )
        return m_data->cure;
    return std::move(QString());
}

QQmlListProperty<Symptom> Disease::symptoms()
{
    return QQmlListProperty<Symptom>(this, this,
                                     &Disease::symptomCount,
                                     &Disease::symptom);
}

int Disease::symptomCount() const
{
    return m_symptoms.count();
}

Symptom *Disease::symptom(const int index) const
{
    if ( index < 0 || index > m_symptoms.count() )
        return nullptr;

    return m_symptoms.at(index);
}

int Disease::symptomCount(QQmlListProperty<Symptom> *list)
{
    return reinterpret_cast<Disease*>(list->data)->symptomCount();
}

Symptom *Disease::symptom(QQmlListProperty<Symptom> *list, int index)
{
    return reinterpret_cast<Disease*>(list->data)->symptom(index);
}
