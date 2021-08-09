#ifndef STATSEDITOR_H
#define STATSEDITOR_H

#include <QObject>
#include <QQmlListProperty>

#include "core_global.h"

class Stats;
class AttributeMod;
class OtherSkillMod;

class CORE_EXPORT StatsEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Stats* stats READ stats WRITE setStats NOTIFY statsChanged)
    Q_PROPERTY(QStringList attributesNames READ attributesNames CONSTANT)
    Q_PROPERTY(QQmlListProperty<OtherSkillMod> otherSkills READ otherSkills NOTIFY otherSkillsChanged)

public:
    explicit StatsEditor(QObject *parent = nullptr);

    Stats *stats() const;
    void setStats(Stats *newStats);

    Q_INVOKABLE AttributeMod* attributeMod(const QString& name) const;
    const QStringList &attributesNames() const;

    QQmlListProperty<OtherSkillMod> otherSkills();
    int otherSkillsCount() const;
    OtherSkillMod* otherSkill(const int index) const;

    Q_INVOKABLE void addOtherSkill(const QString& name, const QString& attribute);

signals:
    void statsChanged();
    void otherSkillsChanged();

private slots:
    void init();

private:
    static int otherSkillsCount(QQmlListProperty<OtherSkillMod> *list);
    static OtherSkillMod* otherSkill(QQmlListProperty<OtherSkillMod> *list, const int index);

private:
    Stats* m_pStats{nullptr};
    QVector<AttributeMod*> m_attributes;
    QStringList m_attributesNames;
    QVector<OtherSkillMod*> m_otherSkills;
};

#endif // STATSEDITOR_H
