#include "Symptom.h"

#include "../Common/Penalty.h"

Symptom::Symptom(QObject *parent) : QObject(parent)
{

}

Symptom::Symptom(SymptomData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    for ( PenaltyData& penalty : m_data->penalties )
        m_penalties.append( new Penalty(&penalty, this) );
}

const QString &Symptom::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Symptom::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}

QQmlListProperty<Penalty> Symptom::penalties()
{
    return QQmlListProperty<Penalty>(this, this,
                                     &Symptom::penaltyCount,
                                     &Symptom::penalty);
}

int Symptom::penaltyCount() const
{
    return m_penalties.count();
}

Penalty *Symptom::penalty(const int index) const
{
    return m_penalties.at(index);
}

int Symptom::penaltyCount(QQmlListProperty<Penalty> *list)
{
    return reinterpret_cast<Symptom*>(list->data)->penaltyCount();
}

Penalty *Symptom::penalty(QQmlListProperty<Penalty> *list, int index)
{
    return reinterpret_cast<Symptom*>(list->data)->penalty(index);
}
