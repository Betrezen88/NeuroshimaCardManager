#ifndef STATSWRAPPER_H
#define STATSWRAPPER_H

#include <QObject>
#include <QList>
#include <QQmlListProperty>

class StatsData;
class PersonalWrapper;
class AttributeWrapper;
class OtherSkillWrapper;

class StatsWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(PersonalWrapper *personal READ personal NOTIFY attributesChanged)
    Q_PROPERTY(QQmlListProperty<AttributeWrapper> attributes READ attributes NOTIFY attributesChanged)
    Q_PROPERTY(QQmlListProperty<OtherSkillWrapper> otherSkills READ otherSkills NOTIFY otherSkillsChanged)

public:
    explicit StatsWrapper(QObject *parent = nullptr);
    explicit StatsWrapper(StatsData *statsData, QObject *parent = nullptr);

    PersonalWrapper *personal() const;

    QQmlListProperty<AttributeWrapper> attributes();
    void appendAttribute(AttributeWrapper*);
    int attributeCount() const;
    AttributeWrapper *attribute(int) const;
    void clearAttributes();

    QQmlListProperty<OtherSkillWrapper> otherSkills();
    void appendOtherSkill(OtherSkillWrapper*);
    int otherSkillsCount() const;
    OtherSkillWrapper *otherSkill(int) const;
    void clearOtherSkills();

signals:
    void attributesChanged();
    void otherSkillsChanged();

private:
    static void appendAttribute(QQmlListProperty<AttributeWrapper> *, AttributeWrapper *);
    static int attributeCount(QQmlListProperty<AttributeWrapper>*);
    static AttributeWrapper *attribute(QQmlListProperty<AttributeWrapper>*, int);
    static void clearAttributes(QQmlListProperty<AttributeWrapper>*);

    static void appendOtherSkill(QQmlListProperty<OtherSkillWrapper> *, OtherSkillWrapper *);
    static int otherSkillsCount(QQmlListProperty<OtherSkillWrapper> *);
    static OtherSkillWrapper *otherSkill(QQmlListProperty<OtherSkillWrapper> *, int);
    static void clearOtherSkills(QQmlListProperty<OtherSkillWrapper> *);

private:
    StatsData *m_pStatsData{nullptr};
    PersonalWrapper *m_pPersonalWrapper{nullptr};
    QList<AttributeWrapper*> m_attributes;
    QList<OtherSkillWrapper*> m_otherSkills;
};

#endif // STATSWRAPPER_H
