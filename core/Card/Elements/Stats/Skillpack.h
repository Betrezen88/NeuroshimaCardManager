#ifndef SKILLPACK_H
#define SKILLPACK_H

#include <QObject>
#include <QMap>

class Skill;

class Skillpack : public QObject
{
    Q_OBJECT
public:
    explicit Skillpack(QObject *parent = nullptr);

    QString name() const;
    QStringList specializations() const;
    QMap<QString, Skill*> skills() const;

    bool hasSpecialization(const QString &specialization) const;
    bool hasSkill(const QString &name);

signals:

public slots:
    void setName(const QString &name);
    void setSpecializations(const QStringList &specializations);
    void setSkills(const QMap<QString, Skill*> &skills);

private:
    QString m_name;
    QStringList m_specializations;
    QMap<QString, Skill*> m_skills;
};

#endif // SKILLPACK_H
