#ifndef SKILLPACKMOD_H
#define SKILLPACKMOD_H

#include <QObject>
#include <QQmlListProperty>

#include "core_global.h"

class Skillpack;
class Skill;
class SkillMod;

class CORE_EXPORT SkillpackMod : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<SkillMod> skills READ skills CONSTANT)
    Q_PROPERTY(Skillpack* skillpack READ skillpack CONSTANT)
    Q_PROPERTY(bool bougth READ bougth NOTIFY bougthChanged)
    Q_PROPERTY(bool enabled READ enabled NOTIFY enabledChanged)

public:
    explicit SkillpackMod(QObject *parent = nullptr);
    explicit SkillpackMod(Skillpack *skillpack, QObject *parent = nullptr);
//    ~SkillpackMod() = default;

    QQmlListProperty<SkillMod> skills();
    bool bougth() const;
    Skillpack* skillpack() const;
    QList<SkillMod*> skillList() const;
    bool enabled() const;

signals:
    void bougthChanged(bool bougth);
    void enabledChanged(bool enabled);

public slots:
    void buy();
    void sell();

private:
    Skillpack* m_pSkillpack{nullptr};
    bool m_bougth{false};
    QList<SkillMod*> m_skills;

};

#endif // SKILLPACKMOD_H
