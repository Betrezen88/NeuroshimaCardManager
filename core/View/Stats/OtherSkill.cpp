#include "OtherSkill.h"

OtherSkill::OtherSkill(QObject *parent) : Skill(parent)
{

}

OtherSkill::OtherSkill(OtherSkillData *data, QObject *parent)
    : Skill(data, parent)
    , m_data(data)
{

}

const QString &OtherSkill::attribute() const
{
    if ( m_data )
        return m_data->attribute;
    return std::move(QString());
}

QString OtherSkill::attributeShort() const
{
    const QString &attribute = m_data->attribute;
    if ( "Budowa" == attribute )
        return "Bd";
    if ( "Zręczność" == attribute )
        return "Zr";
    if ( "Charakter" == attribute )
        return "Ch";
    if ( "Percepcja" == attribute )
        return "Pe";
    if ( "Spryt" == attribute )
        return "Sp";

    return "--";
}
