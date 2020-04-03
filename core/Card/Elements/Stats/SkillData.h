#ifndef SKILLDATA_H
#define SKILLDATA_H

#include <QString>

class SkillData
{
public:
    SkillData();

    QString name() const;
    int value() const;

    void setName(const QString &name);
    void setValue(const int &value);

private:
    QString m_name;
    int m_value{0};
};

#endif // SKILLDATA_H
