#ifndef STATSCREATOR_H
#define STATSCREATOR_H

#include <QMap>

#include "PageCreator.h"
#include "../Card/Data.h"

#include "core_global.h"

class Origin;
class Profession;
class Feature;
class Disease;

class CORE_EXPORT StatsCreator : public PageCreator
{
    Q_OBJECT

public:
    explicit StatsCreator(QObject *parent = nullptr);

signals:

public slots:
    void setName(const QString &name);
    void setSurname(const QString &surname);
    void setNickname(const QString &nickname);
    void setOrigin(Origin* origin);
    void setProfession(Profession* profession);
    void setSpecialization(Data* specialization);
    void setOriginFeature(Feature* feature);
    void setProfessionFeature(Feature* feature);
    void setDisease(Disease* disease);
    void setReputation(const QString &place, const int &value);

private:
    QString m_name;
    QString m_surname;
    QString m_nickname;
    Data* m_pOrigin;
    Data* m_pProfession;
    Data* m_pOriginFeature;
    Data* m_pProfessionFeature;
    Data* m_pSpecialization;
    Disease* m_pDisease;
    QMap<QString, int> m_reputation;
};

#endif // STATSCREATOR_H
