#ifndef SKILLPACKEDIT_H
#define SKILLPACKEDIT_H

#include <QObject>
#include <QQmlListProperty>

#include "SkillEdit.h"

#include "core_global.h"

class SkillpackData;

class CORE_EXPORT SkillpackEdit : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString specializationsShort READ specializationsShort CONSTANT)
    Q_PROPERTY(QQmlListProperty<SkillEdit> skills READ skills CONSTANT)

public:
    friend class StatsEditor;

    explicit SkillpackEdit(QObject* parent = nullptr);
    explicit SkillpackEdit(SkillpackData* data, QObject* parent = nullptr);

    const QString &name() const;
    const QStringList &specializations() const;
    QString specializationsShort() const;

    QQmlListProperty<SkillEdit> skills();
    int skillCount() const;
    SkillEdit* skill(const int index) const;
    QVector<SkillEdit*> skillList();

signals:
    void increased(const int value, const QStringList specializations);
    void decreased(const int value, const QStringList specializations);

private:
    static int skillCount(QQmlListProperty<SkillEdit>* list);
    static SkillEdit* skill(QQmlListProperty<SkillEdit>* list, int index);

private:
    SkillpackData* m_data{nullptr};
    QVector<SkillEdit*> m_skills;
};

#endif // SKILLPACKEDIT_H
