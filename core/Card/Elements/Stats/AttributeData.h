#ifndef ATTRIBUTEDATA_H
#define ATTRIBUTEDATA_H

#include <QString>
#include <QList>

#include "core_global.h"

class SkillpackData;

class CORE_EXPORT AttributeData
{
public:
    AttributeData(const QString &name, const int value);

    QString name() const;
    int value() const;

    QList<SkillpackData*> skillpacks() const;

    bool hasSkillpack(const QString &name) const;

    void setName(const QString &name);
    void setValue(const int &value);
    void addSkillpack(SkillpackData *skillpack);

private:
    QString m_name;
    int m_value;
    QList<SkillpackData*> m_skillpacks;
};

#endif // ATTRIBUTEDATA_H
