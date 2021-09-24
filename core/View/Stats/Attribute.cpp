#include "Attribute.h"

Attribute::Attribute(QObject *parent) : QObject(parent)
{

}

Attribute::Attribute(AttributeData* data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{
    for ( SkillpackData& skillpack: m_data->skillpacks )
        m_skillpacks.append( new Skillpack(&skillpack, this) );
}

const QString &Attribute::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString(""));
}

int Attribute::value() const
{
    if ( m_data )
        return m_data->value;
    return 0;
}

QQmlListProperty<Skillpack> Attribute::skillpacks()
{
    return QQmlListProperty<Skillpack>(this, this,
                                       &Attribute::skillpackCount,
                                       &Attribute::skillpack);
}

int Attribute::skillpackCount() const
{
    return m_skillpacks.count();
}

Skillpack *Attribute::skillpack(const int index) const
{
    if ( index < 0 || index > m_skillpacks.count() )
        return nullptr;

    return m_skillpacks.at(index);
}

int Attribute::skillpackCount(QQmlListProperty<Skillpack> *list)
{
    return reinterpret_cast<Attribute*>(list->data)->skillpackCount();
}

Skillpack *Attribute::skillpack(QQmlListProperty<Skillpack> *list, int index)
{
    return reinterpret_cast<Attribute*>(list->data)->skillpack(index);
}
