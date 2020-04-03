#ifndef ATTRIBUTEDATA_H
#define ATTRIBUTEDATA_H

#include <QString>
#include <QMap>

#include "core_global.h"

class SkillpackData;

class CORE_EXPORT AttributeData
{
public:
    AttributeData();

    QString name() const;
    int value() const;

    QMap<QString, SkillpackData*> skillpacks() const;

    bool hasSkillpack(const QString &name) const;

    void setName(const QString &name);
    void setValue(const int &value);
    void setSkillpacks(const QMap<QString, SkillpackData*> skillpacks);

private:
    QString m_name;
    int m_value;
    QMap<QString, SkillpackData*> m_skillpacks;
};

#endif // ATTRIBUTEDATA_H
