#include "Trick.h"

Trick::Trick(QObject *parent) : QObject(parent)
{

}

Trick::Trick(TrickData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &Trick::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString &Trick::description() const
{
    if ( m_data )
        return m_data->description;
    return std::move(QString());
}

const QString &Trick::action() const
{
    if ( m_data )
        return m_data->action;
    return std::move(QString());
}

QQmlListProperty<Requirement> Trick::requirements()
{
    return QQmlListProperty<Requirement>(this, this,
                                         &Trick::requirementCount,
                                         &Trick::requirement);
}

int Trick::requirementCount() const
{
    return m_requirements.count();
}

Requirement *Trick::requirement(const int index) const
{
    if ( index < 0 || index > m_requirements.count() )
        return nullptr;

    return m_requirements.at(index);
}

int Trick::requirementCount(QQmlListProperty<Requirement> *list)
{
    return reinterpret_cast<Trick*>(list->data)->requirementCount();
}

Requirement *Trick::requirement(QQmlListProperty<Requirement> *list, int index)
{
    return reinterpret_cast<Trick*>(list->data)->requirement(index);
}
