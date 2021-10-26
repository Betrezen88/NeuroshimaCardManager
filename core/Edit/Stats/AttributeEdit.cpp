#include "AttributeEdit.h"
#include "../../Data/Stats/AttributeData.h"

#include <QDebug>

AttributeEdit::AttributeEdit(QObject *parent) : QObject(parent)
{

}

AttributeEdit::AttributeEdit(AttributeData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
    , m_min(m_data->value)
    , m_max(m_data->value+1)
{
    for ( SkillpackData& skillpack : m_data->skillpacks )
        m_skillpacks.push_back( new SkillpackEdit(&skillpack, this) );
}

const QString &AttributeEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int AttributeEdit::value() const
{
    if ( m_data )
        return m_data->value;
    return 0;
}

int AttributeEdit::min() const
{
    return m_min;
}

int AttributeEdit::max() const
{
    return m_max;
}

QQmlListProperty<SkillpackEdit> AttributeEdit::skillpacks()
{
    return QQmlListProperty<SkillpackEdit>(this, this,
                                           &AttributeEdit::skillpackCount,
                                           &AttributeEdit::skillpack);
}

int AttributeEdit::skillpackCount() const
{
    return m_skillpacks.count();
}

SkillpackEdit *AttributeEdit::skillpack(const int index) const
{
    if ( index < 0 || index > m_skillpacks.count() )
        return nullptr;

    return m_skillpacks.at(index);
}

QVector<SkillpackEdit *> AttributeEdit::skillpackList()
{
    return m_skillpacks;
}

bool AttributeEdit::affordable() const
{
    return m_affordable;
}

void AttributeEdit::setAffordable(bool newAffordable)
{
    if (m_affordable == newAffordable)
        return;

    m_affordable =  newAffordable || m_data->value == m_max;
    emit affordableChanged();
}

void AttributeEdit::increase()
{
    if ( !m_affordable )
        return;

    ++m_data->value;
    emit valueChanged();
    emit increased( m_data->value );
}

void AttributeEdit::decrease()
{
    if ( m_data->value <= m_min )
        return;

    emit decreased( m_data->value );
    --m_data->value;
    emit valueChanged();
}

int AttributeEdit::skillpackCount(QQmlListProperty<SkillpackEdit> *list)
{
    return reinterpret_cast<AttributeEdit*>(list->data)->skillpackCount();
}

SkillpackEdit *AttributeEdit::skillpack(QQmlListProperty<SkillpackEdit> *list, int index)
{
    return reinterpret_cast<AttributeEdit*>(list->data)->skillpack(index);
}

int AttributeEdit::cost() const
{
    return m_cost;
}

void AttributeEdit::setCost(int newCost)
{
    if (m_cost == newCost)
        return;
    m_cost = newCost;
    emit costChanged();
}
