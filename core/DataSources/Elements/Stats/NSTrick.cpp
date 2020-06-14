#include "NSTrick.h"

NSTrick::NSTrick(QObject *parent) : Data(parent)
{

}

NSTrick::NSTrick(const QString &name,
                 const QString &description,
                 const QString &action,
                 QVector<Requirement *> &requirements,
                 QObject *parent)
    : Data(name, description, parent),
      m_action(action),
      m_requirements(requirements)
{

}

QString NSTrick::action() const
{
    return m_action;
}

QQmlListProperty<Requirement> NSTrick::requirements()
{
    return QQmlListProperty<Requirement>(reinterpret_cast<Data*>(this), this,
                                         &NSTrick::requirementsCount,
                                         &NSTrick::requirement);
}

int NSTrick::requirementsCount() const
{
    return m_requirements.count();
}

Requirement *NSTrick::requirement(const int &index) const
{
    return m_requirements.at(index);
}

int NSTrick::requirementsCount(QQmlListProperty<Requirement> *list)
{
    return reinterpret_cast<NSTrick*>(list->data)->requirementsCount();
}

Requirement *NSTrick::requirement(QQmlListProperty<Requirement> *list, int index)
{
    return reinterpret_cast<NSTrick*>(list->data)->requirement(index);
}
