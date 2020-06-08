#include "Symptom.h"
#include "Penalty.h"

Symptom::Symptom(QObject *parent)
    : Data(parent)
{

}

Symptom::Symptom(const QString &name,
                 const QString &description,
                 const QVector<Penalty *> &penalties,
                 QObject *parent)
    : Data(name, description, parent),
      m_penalties(penalties)
{

}

QQmlListProperty<Penalty> Symptom::penalties()
{
    return QQmlListProperty<Penalty>(this, this,
                                     &Symptom::penaltyCount,
                                     &Symptom::penalty);
}

Penalty *Symptom::penalty(int index) const
{
    return m_penalties.at(index);
}

int Symptom::penaltyCount() const
{
    return m_penalties.count();
}

Penalty *Symptom::penalty(QQmlListProperty<Penalty> *list, int index)
{
    return reinterpret_cast<Symptom*>(list->data)->penalty(index);
}

int Symptom::penaltyCount(QQmlListProperty<Penalty> *list)
{
    return reinterpret_cast<Symptom*>(list->data)->penaltyCount();
}
