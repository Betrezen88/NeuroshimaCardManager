#ifndef SKILLPACKDATA_H
#define SKILLPACKDATA_H

#include <QObject>
#include <QMap>

class SkillData;

class SkillpackData : public QObject
{
    Q_OBJECT
public:
    explicit SkillpackData(QObject *parent = nullptr);

    QString name() const;
    QStringList specializations() const;
    QMap<QString, SkillData*> skills() const;

    bool hasSpecialization(const QString &specialization) const;
    bool hasSkill(const QString &name);

signals:

public slots:
    void setName(const QString &name);
    void setSpecializations(const QStringList &specializations);
    void setSkills(const QMap<QString, SkillData*> &skills);

private:
    QString m_name;
    QStringList m_specializations;
    QMap<QString, SkillData*> m_skills;
};

#endif // SKILLPACKDATA_H
