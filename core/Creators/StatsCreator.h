#ifndef STATSCREATOR_H
#define STATSCREATOR_H

#include <QMap>
#include <QPair>
#include <QQmlListProperty>

#include "PageCreator.h"
#include "../Card/Data.h"

#include "core_global.h"

class AttributeMod;
class Attribute;
class SkillpackMod;
class SkillMod;
class Bonus;
class Feature;
class Disease;
class OtherSkill;
class Trick;
class Skill;
class CreationPointsManager;

class CORE_EXPORT StatsCreator : public PageCreator
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeMod> attributes
               READ attributes
               NOTIFY attributesChanged)
    Q_PROPERTY(QQmlListProperty<OtherSkill> otherSkills
               READ otherSkills
               NOTIFY otherSkillsChanged)
    Q_PROPERTY(QQmlListProperty<Trick> tricks
               READ tricks
               NOTIFY tricksChanged)
    Q_PROPERTY(QString specialization
               READ specialization
               NOTIFY specializationChanged)

public:
    explicit StatsCreator(QObject *parent = nullptr);

    QQmlListProperty<OtherSkill> otherSkills();
    OtherSkill* otherSkill(const int &index) const;
    int otherSkillsCount() const;

    Q_INVOKABLE void addOtherSkill(const QString &name,
                                   const QString &attribute,
                                   const int &value);
    Q_INVOKABLE void removeOtherSkill(const QString &name);

    QQmlListProperty<AttributeMod> attributes();
    int attributesCount() const;
    AttributeMod *attribute(const int &index) const;

    Q_INVOKABLE AttributeMod* attribute(const QString &name);
    AttributeMod* getAttribute(const QString &name) const;

    QVector<AttributeMod *> attributes() const;

    QQmlListProperty<Trick> tricks();
    int trickCount() const;
    Trick* trick(const int &index) const;

    Q_INVOKABLE void addTrick(Trick *trick);
    Q_INVOKABLE void removeTrick(Trick *trick);

    Skill *getSkill(const QString &name) const;

    QString profession() const;
    QString specialization() const;

signals:
    void nameChanged(const QString &name);
    void surnameChanged(const QString &surname);
    void nicknameChanged(const QString &nickname);
    void originBonusChanged(const QString &attribute, const int &value);
    void specializationChanged(const QString &specialization);
    void otherSkillsChanged();
    void attributesChanged();
    void tricksChanged();
    void statsChanged();

    void requestBonusTrick(const QString& trickName);

public slots:
    void setName(const QString &name);
    void setSurname(const QString &surname);
    void setNickname(const QString &nickname);
    void setOrigin(const QString &name, const QString &description);
    void setOriginBonus(const QString &attribute, const int &value);
    void setProfession(const QString &name, const QString &description);
    void setSpecialization(const QString &name, const QString &description);
    void setOriginFeature(Feature* feature);
    void setProfessionFeature(Feature* feature);
    void setDisease(Disease* disease);
    void setReputation(const QString &place, const int &value);

    void attributeUp(AttributeMod* attributeMod);
    void attributeDown(AttributeMod* attributeMod);
    void buySkillpack(SkillpackMod* skillpackMod);
    void sellSkillpack(SkillpackMod* skillpackMod);
    void skillUp(SkillpackMod* skillpackMod, SkillMod* skillMod);
    void skillDown(SkillpackMod* skillpackMod, SkillMod* skillMod);
    void addBonusTrick(Trick* bonusTrick);
    void removeBonusTrick(const QString& trickName);

private:
    SkillpackMod* findSkillpack(const QString& name);
    void setOriginFeatureBonus(Bonus* bonus);
    void setProfessionFeatureBonus(Bonus* bonus);
    void addBonus(Bonus* bonus);
    void removeBonus(Bonus* bonus);

    void addSkillpackBonus(const QString& name, const int& value);
    void removeSkillpackBonus(const QString& name, const int& value);
    void replaceSkillpackBonus(const QString& oldName,
                               const QString& newName,
                               const int &value);

    static OtherSkill* otherSkill(QQmlListProperty<OtherSkill> *list, int index);
    static int otherSkillsCount(QQmlListProperty<OtherSkill> *list);

    static AttributeMod* attribute(QQmlListProperty<AttributeMod> *list, int index);
    static int attributesCount(QQmlListProperty<AttributeMod> *list);

    static Trick* trick(QQmlListProperty<Trick> *list, int index);
    static int tricksCount(QQmlListProperty<Trick> *list);

private:
    CreationPointsManager* m_pPointsManager{nullptr};
    QString m_name;
    QString m_surname;
    QString m_nickname;
    Data* m_pOrigin{nullptr};
    QPair<QString, int> m_originBonus{"", 0};
    Data* m_pProfession{nullptr};
    Feature* m_pOriginFeature{nullptr};
    Bonus* m_pOriginFeatureBonus{nullptr};
    Feature* m_pProfessionFeature{nullptr};
    Bonus* m_pProfessionFeatureBonus{nullptr};
    Data* m_pSpecialization{nullptr};
    Disease* m_pDisease{nullptr};
    QMap<QString, int> m_reputation;
    QVector<OtherSkill*> m_otherSkills;
    QVector<AttributeMod*> m_attributes;
    QVector<Trick*> m_tricks;
    QVector<Skill*> m_skills;
};

#endif // STATSCREATOR_H
