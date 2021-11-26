#ifndef EXPERIENCEEDITOR_H
#define EXPERIENCEEDITOR_H

#include <QObject>

#include "core_global.h"

class ExperienceData;
class SpecializationData;

class CORE_EXPORT ExperienceEditor : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int available READ available NOTIFY availableChanged)
    Q_PROPERTY(int spended READ spended NOTIFY spendedChanged)
    Q_PROPERTY(bool isNewSkillAffortable READ isNewSkillAffortable NOTIFY isNewSkillAffortableChanged)
    Q_PROPERTY(bool isNewTrickAffortable READ isNewTrickAffortable NOTIFY isNewTrickAffortableChanged)

public:
    explicit ExperienceEditor(QObject *parent = nullptr);
    explicit ExperienceEditor(const QString& costFile,
                              ExperienceData* data,
                              SpecializationData* specialization,
                              QObject* parent = nullptr);

    int available() const;
    int spended() const;
    bool isNewSkillAffortable() const;
    bool isNewTrickAffortable() const;

signals:
    void availableChanged();
    void spendedChanged();
    void isNewSkillAffortableChanged();
    void isNewTrickAffortableChanged();

public slots:
    bool isAttributeAfordable(const int level) const;
    bool isSkillAfordable(const int level, const QStringList& specializations) const;
    bool isOtherSkillAfordable(const int level) const;
    bool isReputationAffordable() const;
    bool isTrickAffordable() const;

    void attributeIncreased(const int level);
    void attributeDecreased(const int level);

    void skillIncreased(const int level, const QStringList& specializations);
    void skillDecreased(const int level, const QStringList& specializations);

    void otherSkillIncreased(const int level);
    void otherSkillDecreased(const int level);

    void reputationIncreased();
    void reputationDecreased();

    void increaseSpended(const int value);
    void decreaseSpended(const int value);

    int attributeCost(const int level) const;
    int skillCost(const int level, const bool discount) const;
    int reputationCost() const;

    void trickBougth();
    void trickSold();
    int trickCost();

private slots:
    void checkIfNewSkillIsAffortable();
    void checkIfNewTrickIsAffortable();

private:
    void loadCostData(const QString& costFile);

    // Method calculates proper discount value
    int calculateDiscount(const int cost) const;

private:
    QString m_costFile;
    ExperienceData* m_data{nullptr};
    SpecializationData* m_specialization{nullptr};

    QVector<int> m_skillCost;
    QVector<int> m_attributeCost;

    int m_reputationCost{0};
    QPair<int, int> m_reputationPoints;

    int m_trickCost{0};
    QPair<int, int> m_trickPoints;

    const double m_discount{0.2};
    bool m_isNewSkillAffortable{false};
    bool m_isNewTrickAffortable{false};
};

#endif // EXPERIENCEEDITOR_H
