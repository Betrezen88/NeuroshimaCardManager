#ifndef DISEASEDATA_H
#define DISEASEDATA_H

#include <QString>

class DiseaseData
{
public:
    DiseaseData(const QString &name,
                const QString &description);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // DISEASEDATA_H
