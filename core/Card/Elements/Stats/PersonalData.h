#ifndef PERSONALDATA_H
#define PERSONALDATA_H

#include <QString>
#include <QMap>

#include "core_global.h"

class OriginData;
class ProfessionData;
class SpecializationData;
class DiseaseData;

class CORE_EXPORT PersonalData
{
public:
    PersonalData();

    QString name() const;
    QString surname() const;
    QString nickname() const;
    QString fullname() const;

    OriginData *origin() const;
    ProfessionData *profession() const;
    SpecializationData *specialization() const;
    DiseaseData *disease() const;

    void setName(const QString &name);
    void setSurname(const QString &surname);
    void setNickname(const QString &nickname);

    void setOrigin(OriginData *origin);
    void setProfession(ProfessionData *profession);
    void setSpecialization(SpecializationData *specialization);
    void setDisease(DiseaseData *disease);

    void setReputation(const QString &place, const int &value);

private:
    QString m_name;
    QString m_surname;
    QString m_nickname;

    OriginData *m_origin{nullptr};
    ProfessionData *m_profession{nullptr};
    SpecializationData *m_specialization{nullptr};
    DiseaseData *m_disease{nullptr};

    QMap<QString, int> m_reputation;
    int m_fame{0};
};

#endif // PERSONALDATA_H
