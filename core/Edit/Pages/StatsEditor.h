#ifndef STATSEDITOR_H
#define STATSEDITOR_H

#include <QObject>
#include <QQmlListProperty>

#include "../../Data/Stats/StatsData.h"
#include "../Stats/AttributeEdit.h"
#include "../Stats/OtherSkillEdit.h"
#include "../Stats/ReputationEdit.h"
#include "../Stats/TrickEdit.h"
#include "../../View/Pages/Stats.h"

#include "core_global.h"

class ExperienceEditor;

class CORE_EXPORT StatsEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AttributeEdit> attributes READ attributes CONSTANT)
    Q_PROPERTY(QQmlListProperty<OtherSkillEdit> otherSkills READ otherSkills NOTIFY otherSkillsChanged)
    Q_PROPERTY(QQmlListProperty<ReputationEdit> reputations READ reputations CONSTANT)
    Q_PROPERTY(QQmlListProperty<TrickEdit> tricks READ tricks CONSTANT)
    Q_PROPERTY(StatsData data READ data CONSTANT)
    Q_PROPERTY(ExperienceEditor* experience READ experience CONSTANT)

public:
    explicit StatsEditor(QObject* parent = nullptr);

    QQmlListProperty<AttributeEdit> attributes();
    int attributeCount() const;
    AttributeEdit* attribute(const int index) const;

    QQmlListProperty<OtherSkillEdit> otherSkills();
    int otherSkillCount() const;
    OtherSkillEdit* otherSkill(const int index) const;

    QQmlListProperty<ReputationEdit> reputations();
    int reputationCount() const;
    ReputationEdit* reputation(const int index) const;

    QQmlListProperty<TrickEdit> tricks();
    int trickCount() const;
    TrickEdit* trick(const int index) const;

    const StatsData &data() const;
    ExperienceEditor *experience() const;

public slots:
    AttributeEdit* attribute(const QString& name);
    QStringList attributesNames() const;
    void addOtherSkill(const QString& name, const QString& attribute);
    void removeOtherSkill(OtherSkillEdit* otherSkill);
    void init(const StatsData& data, const QString& costFile);
    void clearUsed();

signals:
    void otherSkillsChanged();
    void tricksModelChanged();

private slots:
    void setAffordableStats();
    void setStatsConnections();
    void onReputationIncreased(ReputationEdit* reputation);
    void onReputationDecreased(ReputationEdit* reputation);

private:
    static int attributeCount(QQmlListProperty<AttributeEdit>* list);
    static AttributeEdit* attribute(QQmlListProperty<AttributeEdit>* list, int index);

    static int otherSkillCount(QQmlListProperty<OtherSkillEdit>* list);
    static OtherSkillEdit* otherSkill(QQmlListProperty<OtherSkillEdit>* list, int index);

    static int reputationCount(QQmlListProperty<ReputationEdit>* list);
    static ReputationEdit* reputation(QQmlListProperty<ReputationEdit>* list, int index);

    static int trickCount(QQmlListProperty<TrickEdit>* list);
    static TrickEdit* trick(QQmlListProperty<TrickEdit>* list, int index);

private:
    StatsData m_data;
    ExperienceEditor* m_pExpEditor{nullptr};
    QVector<AttributeEdit*> m_attributes;
    QVector<OtherSkillEdit*> m_otherSkills;
    QVector<ReputationEdit*> m_reputation;
    QVector<TrickEdit*> m_tricks;
};

#endif // STATSEDITOR_H
