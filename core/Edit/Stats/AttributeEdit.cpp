#include "AttributeEdit.h"
#include "../../Data/Stats/AttributeData.h"

AttributeEdit::AttributeEdit(QObject *parent) : QObject(parent)
{

}

AttributeEdit::AttributeEdit(AttributeData *data, QObject *parent)
    : QObject(parent)
    , m_data(data)
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

void AttributeEdit::setValue(int newValue)
{
    if (!m_data || m_data->value == newValue)
        return;
    m_data->value = newValue;
    emit valueChanged();
}

int AttributeEdit::min() const
{
    if ( m_data )
        return m_data->value;
    return 0;
}

int AttributeEdit::max() const
{
    if ( m_data )
        return m_data->value + 1;
    return 0;
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

int AttributeEdit::skillpackCount(QQmlListProperty<SkillpackEdit> *list)
{
    return reinterpret_cast<AttributeEdit*>(list->data)->skillpackCount();
}

SkillpackEdit *AttributeEdit::skillpack(QQmlListProperty<SkillpackEdit> *list, int index)
{
    return reinterpret_cast<AttributeEdit*>(list->data)->skillpack(index);
}
