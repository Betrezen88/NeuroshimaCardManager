#ifndef STATS_H
#define STATS_H

#include <QObject>
#include <QQmlListProperty>

#include "Page.h"

#include "core_global.h"

class Data;
class Disease;
class Attribute;
class Trick;
class OtherSkill;
class Wound;

class CORE_EXPORT Stats : public Page
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString surname READ surname CONSTANT)
    Q_PROPERTY(QString nickname READ nickname CONSTANT)
    Q_PROPERTY(QString fullname READ fullname CONSTANT)
    Q_PROPERTY(Data *origin READ origin CONSTANT)
    Q_PROPERTY(Data *profession READ profession CONSTANT)
    Q_PROPERTY(Data *originFeature READ originFeature CONSTANT)
    Q_PROPERTY(Data *professionFeature READ professionFeature CONSTANT)
    Q_PROPERTY(Data *specialization READ specialization CONSTANT)
    Q_PROPERTY(Disease *disease READ disease CONSTANT)
    Q_PROPERTY(int fame READ fame CONSTANT)
    Q_PROPERTY(QQmlListProperty<Attribute> attributes READ attributes CONSTANT)
    Q_PROPERTY(QQmlListProperty<Trick> tricks READ tricks CONSTANT)
    Q_PROPERTY(QQmlListProperty<OtherSkill> otherSkills READ otherSkills CONSTANT)
    Q_PROPERTY(int gathered READ gathered NOTIFY gatheredChanged)
    Q_PROPERTY(int spended READ spended NOTIFY spendedChanged)
    Q_PROPERTY(QQmlListProperty<Wound> wounds READ wounds NOTIFY woundsChanged)
    Q_PROPERTY(QStringList woundLocations READ woundLocations CONSTANT)
    Q_PROPERTY(QStringList woundType READ woundType CONSTANT)

public:
    explicit Stats(QObject *parent = nullptr);
    explicit Stats(const QString &name,
                   const QString &surname,
                   const QString &nickname,
                   Data *origin,
                   Data *profession,
                   Data *originFeature,
                   Data *professionFeature,
                   Data *specialization,
                   Disease *disease,
                   const QVector<Attribute*> &attributes,
                   const QVector<Trick*> &tricks,
                   const QVector<OtherSkill*> &otherSkills,
                   const QPair<int, int> &experience = QPair<int, int>(0, 0),
                   const QVector<Wound*> &wounds = QVector<Wound*>(),
                   QObject *parent = nullptr);

    QString name() const;
    QString surname() const;
    QString fullname() const;
    QString nickname() const;
    Data *origin() const;
    Data *profession() const;
    Data *originFeature() const;
    Data *professionFeature() const;
    Data *specialization() const;
    Disease *disease() const;
    int fame() const;

    QQmlListProperty<Attribute> attributes();
    int attributesCount() const;
    Attribute* attribute(const int &index) const;
    Q_INVOKABLE Attribute* attribute(const QString &name);
    QVector<Attribute*> attributes() const;

    QQmlListProperty<Trick> tricks();
    int tricksCount() const;
    Trick* trick(const int &index) const;
    QVector<Trick*> tricks() const;

    QQmlListProperty<OtherSkill> otherSkills();
    int otherSkillsCount() const;
    OtherSkill* otherSkill(const int &index) const;
    QVector<OtherSkill *> otherSkills() const;

    Q_INVOKABLE void addExperience(const int &points);
    int gathered() const;
    int spended() const;

    QQmlListProperty<Wound> wounds();
    int woundsCount() const;
    Wound* wound(const int& index) const;
    Q_INVOKABLE void addWound(const QString& location,
                              const QString& type,
                              const bool &passed);
    QVector<Wound*> wounds() const;

    QStringList woundLocations() const;
    QStringList woundType() const;

signals:
    void gatheredChanged(const int& value);
    void spendedChanged(const int& value);
    void woundsChanged();

private:
    void mergeWounds(const QString &location, const QString &type);

    static int attributesCount(QQmlListProperty<Attribute> *list);
    static Attribute* attribute(QQmlListProperty<Attribute> *list, int index);

    static int tricksCount(QQmlListProperty<Trick> *list);
    static Trick *trick(QQmlListProperty<Trick> *list, int index);

    static int otherSkillsCount(QQmlListProperty<OtherSkill> *list);
    static OtherSkill* otherSkill(QQmlListProperty<OtherSkill> *list, int index);

    static int woundsCount(QQmlListProperty<Wound> *list);
    static Wound* wound(QQmlListProperty<Wound> *list, int index);

private:
    QString m_name;
    QString m_surname;
    QString m_nickname;
    Data *m_pOrigin{nullptr};
    Data *m_pProfession{nullptr};
    Data *m_pOriginFeature{nullptr};
    Data *m_pProfessionFeature{nullptr};
    Data *m_pSpecialization{nullptr};
    Disease *m_pDisease{nullptr};
    QMap<QString, int> m_reputation;

    QVector<Attribute*> m_attributes;
    QVector<Trick*> m_tricks;
    QVector<OtherSkill*> m_otherSkills;

    QPair<int, int> m_experience;

    QVector<Wound*> m_wounds;

    const QStringList m_woundLocation{
        "Głowa",
        "Lewa ręka",
        "Prawa ręka",
        "Tułów",
        "Lewa noga",
        "Prawa noga"
    };
    const QStringList m_woundType {
        "Draśnięcie",
        "Lekka",
        "Ciężka",
        "Krytyczna"
    };
    const QList<QPair<int, int>> m_woundMods {
        QPair<int, int>(5, 10),
        QPair<int, int>(15, 30),
        QPair<int, int>(30, 60),
        QPair<int, int>(160, 160)
    };

};

#endif // STATS_H
