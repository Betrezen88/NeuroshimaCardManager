#include "Attribute.h"

Attribute::Attribute(QObject *parent) : QObject(parent)
{

}

Attribute::Attribute(const QString &name,
                     const int &value,
                     const QVector<Skillpack *> &skillpacks,
                     QObject *parent)
    : QObject(parent),
      m_name(name),
      m_value(value),
      m_skillpacks(skillpacks)
{

}

QString Attribute::name() const
{
    return m_name;
}

int Attribute::value() const
{
    return m_value;
}

QQmlListProperty<Skillpack> Attribute::skillpacks()
{
    return QQmlListProperty<Skillpack>(this, this,
                                       &Attribute::skillpacksCount,
                                       &Attribute::skillpack);
}

int Attribute::skillpacksCount() const
{
    return m_skillpacks.count();
}

Skillpack *Attribute::skillpack(const int &index) const
{
    return m_skillpacks.at(index);
}

QVector<Skillpack *> Attribute::skillpacks() const
{
    return m_skillpacks;
}

int Attribute::skillpacksCount(QQmlListProperty<Skillpack> *list)
{
    return reinterpret_cast<Attribute*>(list->data)->skillpacksCount();
}

Skillpack *Attribute::skillpack(QQmlListProperty<Skillpack> *list, int index)
{
    return reinterpret_cast<Attribute*>(list->data)->skillpack(index);
}
