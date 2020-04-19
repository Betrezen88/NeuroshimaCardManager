#ifndef STATSDATA_H
#define STATSDATA_H

#include <QString>
#include <QList>

#include "core_global.h"

class PersonalData;
class AttributeData;
class OtherSkillData;
class TrickData;

class CORE_EXPORT StatsData
{
public:
    StatsData();

    PersonalData *personal() const;
    QList<AttributeData*> attributes() const;
    QList<OtherSkillData*> otherSkills() const;
    QList<TrickData*> tricks() const;

    void setPersonal(PersonalData *personal);
    void setAttributes(QList<AttributeData*> attributes);
    void setOtherSkills(QList<OtherSkillData*> otherSkills);
    void setTricks(QList<TrickData*> tricks);

private:
    PersonalData *m_personal{nullptr};
    QList<AttributeData*> m_attributes;
    QList<OtherSkillData*> m_otherSkills;
    QList<TrickData*> m_tricks;
};

#endif // STATSDATA_H
