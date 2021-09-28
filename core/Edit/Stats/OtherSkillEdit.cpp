#include "OtherSkillEdit.h"
#include "../../Data/Stats/OtherSkillData.h"

OtherSkillEdit::OtherSkillEdit(QObject *parent) : QObject(parent)
{

}

OtherSkillEdit::OtherSkillEdit(OtherSkillData *data,
                               const bool &isNew,
                               QObject *parent)
    : QObject(parent)
    , m_data(data)
    , m_isNew(isNew)
{

}

const QString &OtherSkillEdit::name() const
{
    if ( m_data )
        return m_data->name;
    return std::move(QString());
}

const QString& OtherSkillEdit::attribute() const
{
    if ( m_data )
        return m_data->attribute;
    return std::move(QString());
}

QString OtherSkillEdit::attributeShort() const
{
    QString text{"--"};
    if ( m_data ) {
        if ( "Budowa" == m_data->attribute )
            text = "Bd";
        else if ( "Zręczność" == m_data->attribute )
            text = "Zr";
        else if ( "Charakter" == m_data->attribute )
            text = "Ch";
        else if ( "Percepcja" == m_data->attribute )
            text = "Pe";
        else if ( "Spryt" == m_data->attribute )
            text = "Sp";
    }
    return text;
}

int OtherSkillEdit::value() const
{
    return m_data ? m_data->value : 0;
}

void OtherSkillEdit::setValue(int newValue)
{
    if (m_data->value == newValue)
        return;
    m_data->value = newValue;
    emit valueChanged();
}

bool OtherSkillEdit::used() const
{
    return m_data ? m_data->used : false;
}

int OtherSkillEdit::min() const
{
    return m_data ? m_data->value : 0;
}

int OtherSkillEdit::max() const
{
    return m_data ? m_data->value + 1 : 0;
}

bool OtherSkillEdit::isNew() const
{
    return m_isNew;
}
