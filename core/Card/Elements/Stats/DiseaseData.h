#ifndef DISEASEDATA_H
#define DISEASEDATA_H

#include <QObject>

class DiseaseData : public QObject
{
    Q_OBJECT
public:
    explicit DiseaseData(const QString &name,
                         const QString &description,
                         QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    QString m_name;
    QString m_description;
};

#endif // DISEASEDATA_H
