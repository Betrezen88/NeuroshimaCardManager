#ifndef SPECIALIZATIONDATA_H
#define SPECIALIZATIONDATA_H

#include <QString>

class SpecializationData
{
public:
    SpecializationData(const QString &name,
                       const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // SPECIALIZATIONDATA_H
