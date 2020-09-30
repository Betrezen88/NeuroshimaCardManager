#ifndef SKILLPACK_H
#define SKILLPACK_H

#include <QObject>
#include <QQmlListProperty>

#include "core_global.h"

class Skill;

class CORE_EXPORT Skillpack : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QStringList specializations READ specializations CONSTANT)
    Q_PROPERTY(QQmlListProperty<Skill> skills READ skills CONSTANT)
    Q_PROPERTY(Type type READ type CONSTANT)

public:
    enum class Type { CONSTANT, CHOOSABLE };
    Q_ENUM(Type)

    explicit Skillpack(QObject *parent = nullptr);
    explicit Skillpack(const QString &name,
                       const QStringList &specializations,
                       const QVector<Skill*> &skills,
                       const Type &type,
                       QObject *parent = nullptr);

    QString name() const;
    QStringList specializations() const;
    Q_INVOKABLE QString fullname() const;

    QQmlListProperty<Skill> skills();
    int skillsCount() const;
    Skill* skill(int index) const;

    QVector<Skill*> skills() const;

    Type type() const;

private:
    static int skillsCount(QQmlListProperty<Skill> *list);
    static Skill* skill(QQmlListProperty<Skill> *list, int index);

private:
    QString m_name;
    QStringList m_specializations;
    QVector<Skill*> m_skills;
    Type m_type;
};

#endif // SKILLPACK_H
