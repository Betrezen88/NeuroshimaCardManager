#ifndef STATSEDITOR_H
#define STATSEDITOR_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/StatsData.h"
#include "../Stats/AttributeEdit.h"
#include "../Stats/OtherSkillEdit.h"
#include "../../View/Pages/Stats.h"

#include "core_global.h"

class CORE_EXPORT  StatsEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeEdit> attributes READ attributes CONSTANT)
    Q_PROPERTY(QQmlListProperty<OtherSkillEdit> otherSkills READ otherSkills NOTIFY otherSkillsChanged)

public:
    explicit StatsEditor(QObject* parent = nullptr);
    explicit StatsEditor(const StatsData& data, QObject* parent = nullptr);

    QQmlListProperty<AttributeEdit> attributes();
    int attributeCount() const;
    AttributeEdit* attribute(const int index) const;

    QQmlListProperty<OtherSkillEdit> otherSkills();
    int otherSkillCount() const;
    OtherSkillEdit* otherSkill(const int index) const;

public slots:
    void setStats(Stats* stats);
    AttributeEdit* attribute(const QString& name);
    QStringList attributesNames() const;
    void addOtherSkill(const QString& name, const QString& attribute);
    void removeOtherSkill(OtherSkillEdit* otherSkill);

signals:
    void dataChanged();
    void otherSkillsChanged();

private slots:
    void init();

private:
    void clear();
    void setConnections();

    static int attributeCount(QQmlListProperty<AttributeEdit>* list);
    static AttributeEdit* attribute(QQmlListProperty<AttributeEdit>* list, int index);

    static int otherSkillCount(QQmlListProperty<OtherSkillEdit>* list);
    static OtherSkillEdit* otherSkill(QQmlListProperty<OtherSkillEdit>* list, int index);

private:
    StatsData m_data;
    QVector<AttributeEdit*> m_attributes;
    QVector<OtherSkillEdit*> m_otherSkills;
};

#endif // STATSEDITOR_H
