#include "AttributeMod.h"
#include "../../../Card/Elements/Stats/Attribute.h"
#include "SkillpackMod.h"

AttributeMod::AttributeMod(QObject *parent)
    : QObject(parent)
{

}

AttributeMod::AttributeMod(Attribute *attribute,
                           QObject *parent)
    : QObject(parent)
    , m_pAttribute(attribute)
    , m_range(attribute->value(), attribute->value()+1)
{
    init();
}

AttributeMod::AttributeMod(Attribute *attribute,
                           const int &min,
                           const int &max,
                           QObject *parent)
    : QObject(parent)
    , m_pAttribute(attribute)
    , m_range(QPair<int, int>(min, max))
{
    init();
}

Attribute *AttributeMod::attribute() const
{
    return m_pAttribute;
}

int AttributeMod::min() const
{
    return m_range.first;
}

int AttributeMod::max() const
{
    return m_range.second;
}

QQmlListProperty<SkillpackMod> AttributeMod::skillpacks()
{
    return QQmlListProperty<SkillpackMod>(this, m_skillpacks);
}

void AttributeMod::setMin(int min)
{
    if (m_range.first == min)
        return;

    m_range.first = min;
    emit minChanged(m_range.first);
}

void AttributeMod::setMax(int max)
{
    if (m_range.second == max)
        return;

    m_range.second = max;
    emit maxChanged(m_range.second);
}

void AttributeMod::setValue(const int &value)
{
    if ( m_pAttribute->value() == value )
        return;

    m_pAttribute->m_value = value;
    emit m_pAttribute->valueChanged(m_pAttribute->m_value);
}

void AttributeMod::init()
{
    for ( Skillpack* skillpack: m_pAttribute->m_skillpacks )
        m_skillpacks.append(new SkillpackMod(skillpack));
}
