#ifndef DISEASEWRAPPER_H
#define DISEASEWRAPPER_H

#include <QObject>

class DiseaseData;

class DiseaseWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString description READ description CONSTANT)

public:
    explicit DiseaseWrapper(QObject *parent = nullptr);
    explicit DiseaseWrapper(DiseaseData *diseaseData, QObject *parent = nullptr);

    QString name() const;
    QString description() const;

private:
    DiseaseData *m_pDiseaseData{nullptr};
};

#endif // DISEASEWRAPPER_H
