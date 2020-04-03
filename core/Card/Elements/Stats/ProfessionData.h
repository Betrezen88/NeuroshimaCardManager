#ifndef PROFESSIONDATA_H
#define PROFESSIONDATA_H

#include <QString>

class ProfessionData
{
public:
    ProfessionData(const QString &name,
                   const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // PROFESSIONDATA_H
