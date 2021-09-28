#include "SkillEdit.h"
#include "../../Data/Stats/SkillData.h"

SkillEdit::SkillEdit(QObject *parent) : QObject(parent)
{

}

SkillEdit::SkillEdit(SkillData* data, QObject *parent)
    : QObject(parent)
    , m_data(data)
{

}

const QString &SkillEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

int SkillEdit::value() const
{
    return m_data ? m_data->value : 0;
}

void SkillEdit::setValue(int newValue)
{
    if (!m_data || m_data->value == newValue)
        return;

    m_data->value = newValue;
    emit valueChanged();
}

int SkillEdit::min() const
{
    return m_data ? m_data->value : 0;
}

int SkillEdit::max() const
{
    return m_data ? m_data->value + 1 : 0;
}

bool SkillEdit::used() const
{
    return m_data ? m_data->used : false;
}
