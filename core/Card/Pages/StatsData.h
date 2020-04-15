#ifndef STATSDATA_H
#define STATSDATA_H

#include <QString>
#include <QList>

#include "core_global.h"

class PersonalData;
class AttributeData;

class CORE_EXPORT StatsData
{
public:
    StatsData();

    PersonalData *personal() const;
    QList<AttributeData*> attributes() const;

    void setPersonal(PersonalData *personal);
    void setAttributes(QList<AttributeData*> attributes);

private:
    PersonalData *m_personal{nullptr};
    QList<AttributeData*> m_attributes;
};

#endif // STATSDATA_H
