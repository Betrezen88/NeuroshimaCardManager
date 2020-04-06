#ifndef PERSONALWRAPPER_H
#define PERSONALWRAPPER_H

#include <QObject>

class PersonalData;
class OriginWrapper;
class ProfessionWrapper;
class SpecializationWrapper;
class DiseaseWrapper;
class FeatureWrapper;

class PersonalWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString surname READ surname CONSTANT)
    Q_PROPERTY(QString nickname READ nickname CONSTANT)
    Q_PROPERTY(QString fullname READ fullname CONSTANT)
    Q_PROPERTY(OriginWrapper *origin READ origin CONSTANT)
    Q_PROPERTY(ProfessionWrapper *profession READ profession CONSTANT)
    Q_PROPERTY(SpecializationWrapper *specialization READ specialization CONSTANT)
    Q_PROPERTY(DiseaseWrapper *disease READ disease CONSTANT)
    Q_PROPERTY(FeatureWrapper *originFeature READ originFeature CONSTANT)
    Q_PROPERTY(FeatureWrapper *professionFeature READ professionFeature CONSTANT)

public:
    explicit PersonalWrapper(QObject *parent = nullptr);
    explicit PersonalWrapper(PersonalData *personalData, QObject *parent = nullptr);

    QString name() const;
    QString surname() const;
    QString nickname() const;
    QString fullname() const;

    OriginWrapper *origin() const;
    ProfessionWrapper *profession() const;
    SpecializationWrapper *specialization() const;
    DiseaseWrapper *disease() const;
    FeatureWrapper *originFeature() const;
    FeatureWrapper *professionFeature() const;

private:
    PersonalData *m_pPersonalData{nullptr};
    OriginWrapper *m_pOriginWrapper{nullptr};
    ProfessionWrapper *m_pProfessionWrapper{nullptr};
    SpecializationWrapper *m_pSpecializationWrapper{nullptr};
    DiseaseWrapper *m_pDiseaseWrapper{nullptr};
    FeatureWrapper *m_pOriginFeature{nullptr};
    FeatureWrapper *m_pProfessionFeature{nullptr};
};

#endif // PERSONALWRAPPER_H
