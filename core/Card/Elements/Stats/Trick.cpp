#include "Trick.h"

#include "../../../DataSources/Elements/Stats/Requirement.h"

Trick::Trick(QObject *parent)
    : Data(parent)
{

}

Trick::Trick(const QString &name,
             const QString &description,
             const QString &action,
             QObject *parent)
    : Data(name, description, parent),
      m_action(action)
{

}

Trick::Trick(const QString &name,
             const QString &description,
             const QString &action,
             QVector<Requirement *> &requirements,
             QObject *parent)
    : Data(name, description, parent),
      m_action(action),
      m_requirements(requirements)
{

}

QString Trick::action() const
{
    return m_action;
}

QQmlListProperty<Requirement> Trick::requirements()
{
    return QQmlListProperty<Requirement>(reinterpret_cast<Data*>(this), this,
                                         &Trick::requirementsCount,
                                         &Trick::requirement);
}

int Trick::requirementsCount() const
{
    return m_requirements.count();
}

Requirement *Trick::requirement(const int &index) const
{
    return m_requirements.at(index);
}

bool Trick::hasRequirements() const
{
    return m_requirements.count() > 0;
}

int Trick::requirementsCount(QQmlListProperty<Requirement> *list)
{
    return reinterpret_cast<Trick*>(list->data)->requirementsCount();
}

Requirement *Trick::requirement(QQmlListProperty<Requirement> *list, int index)
{
    return reinterpret_cast<Trick*>(list->data)->requirement(index);
}
