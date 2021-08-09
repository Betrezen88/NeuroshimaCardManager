#ifndef OTHERSKILLMOD_H
#define OTHERSKILLMOD_H

#include <QObject>

#include "core_global.h"

class OtherSkill;

class CORE_EXPORT OtherSkillMod : public QObject
{
    Q_OBJECT
    Q_PROPERTY(OtherSkill* otherSkill READ otherSkill CONSTANT)
    Q_PROPERTY(int min READ min CONSTANT)
    Q_PROPERTY(int max READ max CONSTANT)

public:
    friend class OtherSkill;

    explicit OtherSkillMod(QObject *parent = nullptr);
    explicit OtherSkillMod(OtherSkill* otherSkill,
                           QObject *parent = nullptr);

    OtherSkill *otherSkill() const;

    int min() const;
    int max() const;

signals:

public slots:
    void setValue(const int &value);

private:
    OtherSkill *m_otherSkill;
    QPair<int, int> m_range;
};

#endif // OTHERSKILLMOD_H
