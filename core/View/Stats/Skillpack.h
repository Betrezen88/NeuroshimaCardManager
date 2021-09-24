#ifndef SKILLPACK_H
#define SKILLPACK_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/SkillpackData.h"
#include "Skill.h"

#include "core_global.h"

class CORE_EXPORT Skillpack : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QStringList specializations READ specializations CONSTANT)
    Q_PROPERTY(QString specializationsShort READ specializationsShort CONSTANT)
    Q_PROPERTY(QQmlListProperty<Skill> skills READ skills CONSTANT)

public:
    explicit Skillpack(QObject *parent = nullptr);
    explicit Skillpack(SkillpackData* data, QObject *parent = nullptr);

    const QString &name() const;
    const QStringList &specializations() const;
    QString specializationsShort() const;
    QQmlListProperty<Skill> skills();
    int skillCount() const;
    Skill* skill(const int index) const;

private:
    static int skillCount(QQmlListProperty<Skill> *list);
    static Skill* skill(QQmlListProperty<Skill> *list, int index);

private:
    SkillpackData* m_data{nullptr};
    QVector<Skill*> m_skills;
};

#endif // SKILLPACK_H
