#ifndef SKILLMOD_H
#define SKILLMOD_H

#include <QObject>

#include "../../../Card/Elements/Stats/Skill.h"

#include "core_global.h"

class Skill;

class CORE_EXPORT SkillMod : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Skill* skill READ skill CONSTANT)
    Q_PROPERTY(int min READ min NOTIFY minChanged)
    Q_PROPERTY(int max READ max NOTIFY maxChanged)

public:
    explicit SkillMod(QObject *parent = nullptr);
    explicit SkillMod(Skill* skill,
                      QObject *parent = nullptr);
    explicit SkillMod(Skill* skill,
                      const QPair<int,int> &range,
                      QObject *parent = nullptr);
    ~SkillMod() {}

    Skill* skill() const;
    int min() const;
    int max() const { return m_range.second; }
    void setMin(const int &value);
    void setMax(const int &value);

signals:
    void minChanged(const int &min);
    void maxChanged(const int &max);

public slots:
    void setValue(const int &value);

private:
    Skill* m_skill;
    QPair<int, int> m_range;
};

#endif // SKILLMOD_H
