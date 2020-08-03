#ifndef STATSCREATOR_H
#define STATSCREATOR_H

#include <QMap>
#include <QPair>
#include <QQmlListProperty>

#include "PageCreator.h"
#include "../Card/Data.h"

#include "core_global.h"

class Attribute;
class Feature;
class Disease;
class OtherSkill;

class CORE_EXPORT StatsCreator : public PageCreator
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Attribute> attributes
               READ attributes
               NOTIFY attributesChanged)
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

    QQmlListProperty<Attribute> attributes();
    int attributesCount() const;
    Attribute* attribute(const int &index) const;

    Q_INVOKABLE Attribute* attribute(const QString &name);

signals:
    void nameChanged(const QString &name);
    void surnameChanged(const QString &surname);
    void nicknameChanged(const QString &nickname);
    void originBonusChanged(const QString &attribute, const int &value);
    void otherSkillsChanged();
    void attributesChanged();

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

private:
    static OtherSkill* otherSkill(QQmlListProperty<OtherSkill> *list, int index);
    static int otherSkillsCount(QQmlListProperty<OtherSkill> *list);

    static Attribute* attribute(QQmlListProperty<Attribute> *list, int index);
    static int attributesCount(QQmlListProperty<Attribute> *list);

private:
    QString m_name;
    QString m_surname;
    QString m_nickname;
    Data* m_pOrigin{nullptr};
    QPair<QString, int> m_originBonus{"", 0};
    Data* m_pProfession{nullptr};
    Data* m_pOriginFeature{nullptr};
    Data* m_pProfessionFeature{nullptr};
    Data* m_pSpecialization{nullptr};
    Disease* m_pDisease{nullptr};
    QMap<QString, int> m_reputation;
    QVector<OtherSkill*> m_otherSkills;
    QVector<Attribute*> m_attributes;
};

#endif // STATSCREATOR_H
