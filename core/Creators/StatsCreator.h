#ifndef STATSCREATOR_H
#define STATSCREATOR_H

#include <QMap>
#include <QQmlListProperty>

#include "PageCreator.h"
#include "../Card/Data.h"

#include "core_global.h"

class Origin;
class Profession;
class Feature;
class Disease;
class OtherSkill;

class CORE_EXPORT StatsCreator : public PageCreator
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<OtherSkill> otherSkills
               READ otherSkills
               NOTIFY otherSkillsChanged)

public:
    explicit StatsCreator(QObject *parent = nullptr);

    QQmlListProperty<OtherSkill> otherSkills();
    OtherSkill* otherSkill(const int &index) const;
    int otherSkillsCount() const;

    Q_INVOKABLE void addOtherSkill(const QString &name,
                                   const QString &attribute,
                                   const int &value);
    Q_INVOKABLE void removeOtherSkill(const QString &name);

signals:
    void otherSkillsChanged();

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
    static OtherSkill* otherSkill(QQmlListProperty<OtherSkill> *list, int index);
    static int otherSkillsCount(QQmlListProperty<OtherSkill> *list);

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
    QVector<OtherSkill*> m_otherSkills;
};

#endif // STATSCREATOR_H
