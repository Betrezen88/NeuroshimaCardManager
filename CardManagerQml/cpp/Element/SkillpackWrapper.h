#ifndef SKILLPACKWRAPPER_H
#define SKILLPACKWRAPPER_H

#include <QObject>
#include <QMap>
#include <QQmlListProperty>

class SkillWrapper;
class SkillpackData;

class SkillpackWrapper : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QStringList specializations READ specializations CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillWrapper> skills READ skills NOTIFY skillsChanged)

public:
    explicit SkillpackWrapper(QObject *parent = nullptr);
    explicit SkillpackWrapper(SkillpackData *skillpackData, QObject *parent = nullptr);

    QString name() const;
    QStringList specializations() const;

    QQmlListProperty<SkillWrapper> skills();
    void appendSkill(SkillWrapper*);
    int skillCount() const;
    SkillWrapper *skill(int) const;
    void clearSkills();

    bool hasSpecialization(const QString &specialization) const;
    bool hasSkill(const QString &name);

signals:
    void skillsChanged();

private:
    static void appendSkill(QQmlListProperty<SkillWrapper>*, SkillWrapper*);
    static int skillCount(QQmlListProperty<SkillWrapper>*);
    static SkillWrapper *skill(QQmlListProperty<SkillWrapper>*, int);
    static void clearSkills(QQmlListProperty<SkillWrapper>*);

private:
    SkillpackData *m_pSkillpackData{nullptr};
    QList<SkillWrapper*> m_skills;
};

#endif // SKILLPACKWRAPPER_H
