#ifndef STATS_H
#define STATS_H

#include <QObject>
#include <QQmlListProperty>

#include "Page.h"
#include "../../Data/Stats/StatsData.h"

#include "core_global.h"

class Attribute;
class Origin;
class Profession;
class Specialization;
class Disease;
class Trick;
class OtherSkill;
class Reputation;
class Wound;
class Experience;

class CORE_EXPORT Stats : public Page
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString surname READ surname CONSTANT)
    Q_PROPERTY(QString nickname READ nickname CONSTANT)
    Q_PROPERTY(QString fullname READ fullname CONSTANT)
    Q_PROPERTY(Origin* origin READ origin CONSTANT)
    Q_PROPERTY(Profession* profession READ profession CONSTANT)
    Q_PROPERTY(Specialization* specialization READ specialization CONSTANT)
    Q_PROPERTY(Disease* disease READ disease CONSTANT)
    Q_PROPERTY(Experience* experience READ experience CONSTANT)
    Q_PROPERTY(QQmlListProperty<Trick> tricks READ tricks CONSTANT)
    Q_PROPERTY(QQmlListProperty<OtherSkill> otherSkills READ otherSkills CONSTANT)
    Q_PROPERTY(QQmlListProperty<Reputation> reputation READ reputation CONSTANT)
    Q_PROPERTY(QQmlListProperty<Wound> wounds READ wounds NOTIFY woundsChanged)

    Q_PROPERTY(QStringList locations READ locations CONSTANT)
    Q_PROPERTY(QStringList woundTypes READ woundTypes CONSTANT)

    Q_PROPERTY(StatsData stats READ stats WRITE setStats NOTIFY statsChanged)

public:
    explicit Stats(QObject *parent = nullptr);
    explicit Stats(const StatsData& data, QObject *parent);

    const QString &name() const;
    const QString &surname() const;
    const QString &nickname() const;
    QString fullname() const;
    Origin *origin() const;
    Profession *profession() const;
    Specialization *specialization() const;
    Disease *disease() const;
    Experience *experience() const;

    QQmlListProperty<Trick> tricks();
    int trickCount() const;
    Trick* trick(const int index) const;

    QQmlListProperty<OtherSkill> otherSkills();
    int otherSkillCount() const;
    OtherSkill* otherSkill(const int index) const;

    QQmlListProperty<Reputation> reputation();
    int reputationCount() const;
    Reputation* reputation(const int index) const;

    QQmlListProperty<Wound> wounds();
    int woundCount() const;
    Wound* wound(const int index) const;

    const QStringList &locations() const;
    const QStringList &woundTypes() const;

    const StatsData& data() const;

    const StatsData &stats() const;
    void setStats(const StatsData &newStats);

signals:
    void woundsChanged();

    void statsChanged();

public slots:
    Attribute *attribute(const QString& name);
    QString wound(const QString& location) const;
    void addWound(const QString& location, const QString& type, const bool passed);

private:
    void addWound(WoundData *wound);
    WoundData *mergeWounds(const QString& location, const QString &type);
    void setWounds(QVector<QSharedPointer<WoundData>>& wounds);

    static int trickCount(QQmlListProperty<Trick> *list);
    static Trick* trick(QQmlListProperty<Trick> *list, int index);

    static int otherSkillCount(QQmlListProperty<OtherSkill> *list);
    static OtherSkill* otherSkill(QQmlListProperty<OtherSkill> *list, int index);

    static int reputationCount(QQmlListProperty<Reputation> *list);
    static Reputation* reputation(QQmlListProperty<Reputation> *list, int index);

    static int woundCount(QQmlListProperty<Wound> *list);
    static Wound *wound(QQmlListProperty<Wound> *list, int index);

private:
    StatsData m_data;
    Origin* m_pOrigin{nullptr};
    Profession* m_pProfession{nullptr};
    Specialization *m_pSpecialization{nullptr};
    Disease* m_pDisease{nullptr};
    Experience* m_pExperience{nullptr};

    QVector<Attribute*>m_attributes;
    QVector<Trick*> m_tricks;
    QVector<OtherSkill*> m_otherSkills;
    QVector<Reputation*> m_reputation;
    QVector<Wound*> m_wounds;

    const QStringList m_locations {
        "Głowa",
        "Tułów",
        "Lewa ręka",
        "Prawa ręka",
        "Lewa noga",
        "Prawa noga"
    };

    const QStringList m_woundTypes {
        "Draśnięcie",
        "Lekka",
        "Ciężka",
        "Krytyczna"
    };

    const QVector<QPair<int, int>> m_woundMods {
        QPair<int, int>{5, 10},
        QPair<int, int>{15, 30},
        QPair<int, int>{30, 60},
        QPair<int, int>{160, 160}
    };
    Experience *m_experience;
};

#endif // STATS_H
